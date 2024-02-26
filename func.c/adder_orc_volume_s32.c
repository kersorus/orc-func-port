#include <emmintrin.h>
#include <smmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_volume_s32_sse(gint32 *ORC_RESTRICT d1, int p1, int n)
{
  int i;

  __m128i volume_vec = _mm_set1_epi32((gint32) p1);

  for (i = 0; i < n - 3; i += 4)
  {
    __m128i dst_vec = _mm_loadu_si128((__m128i *) &d1[i]);
    dst_vec = _mm_mullo_epi32(dst_vec, volume_vec);
    _mm_storeu_si128((__m128i *) &d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] *= p1;
  }
}
