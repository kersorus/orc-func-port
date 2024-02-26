#include <immintrin.h>
#include <xmmintrin.h>
#include "../dest_files/gstaudiomixerorc-dist.h"

void audiomixer_orc_add_volume_f64_sse(double *ORC_RESTRICT d1, const double *ORC_RESTRICT s1, double p1, int n)
{
  int i;

  __m128d volume_vec = _mm_set1_pd(p1);
 
  for (i = 0; i < n - 1; i += 2)
  {
    __m128d src_vec = _mm_loadu_pd(&s1[i]);
    src_vec = _mm_mul_pd(src_vec, volume_vec);
    __m128d dst_vec = _mm_loadu_pd(&d1[i]);
    dst_vec = _mm_add_pd(dst_vec, src_vec);
    _mm_storeu_pd(&d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] += s1[i] * p1;
  }
}
