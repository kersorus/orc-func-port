#include <immintrin.h>
#include <xmmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_add_volume_u32_sse(guint32 *ORC_RESTRICT d1, const guint32 *ORC_RESTRICT s1, int p1, int n)
{
  int i;

  __m128i volume_vec = _mm_set1_epi32((gint32) p1);
 
  for (i = 0; i < n - 3; i += 4)
  {
    __m128i src_vec = _mm_loadu_si128((__m128i *) &s1[i]);
    src_vec = _mm_mullo_epi32(src_vec, volume_vec);
    __m128i dst_vec = _mm_loadu_si128((__m128i *) &d1[i]);
    dst_vec = _mm_add_epi32(dst_vec, src_vec);
    _mm_storeu_si128((__m128i *) &d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] += s1[i] * p1;
  }
}
