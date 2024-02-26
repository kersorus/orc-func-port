#include <emmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_add_f64_sse(double *ORC_RESTRICT d1, const double *ORC_RESTRICT s1, int n)
{
  int i = 0;

  for (i = 0; i < n - 1; i += 2)
  {
    __m128d src_vec = _mm_loadu_pd(&s1[i]);
    __m128d dst_vec = _mm_loadu_pd(&d1[i]);
    __m128d result = _mm_add_pd(dst_vec, src_vec);
    _mm_storeu_pd(&d1[i], result);
  }

  for (; i < n; i++)
  {
    d1[i] += s1[i];
  }
}
