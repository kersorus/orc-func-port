#include <immintrin.h>
#include <emmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_volume_f64_sse(double *ORC_RESTRICT d1, double p1, int n)
{
  int i;

  __m128d volume_vec = _mm_set1_pd(p1);

  for (i = 0; i < n - 1; i += 2)
  {
    __m128d dst_vec = _mm_loadu_pd(&d1[i]);
    dst_vec = _mm_mul_pd(dst_vec, volume_vec);
    _mm_storeu_pd(&d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] *= p1;
  }
}
