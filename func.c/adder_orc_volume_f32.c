#include <immintrin.h>
#include <xmmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_volume_f32_sse(float *ORC_RESTRICT d1, float p1, int n)
{
  int i;

  __m128 volume_vec = _mm_set1_ps(p1);

  for (i = 0; i < n - 3; i += 4)
  {
    __m128 dst_vec = _mm_loadu_ps(&d1[i]);
    dst_vec = _mm_mul_ps(dst_vec, volume_vec);
    _mm_storeu_ps(&d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] *= p1;
  }
}
