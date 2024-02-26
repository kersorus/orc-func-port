#include <emmintrin.h>
#include "../dest_files/gstaudiomixerorc-dist.h"

void audiomixer_orc_add_s32_sse(gint32 *ORC_RESTRICT d1, const gint32 *ORC_RESTRICT s1, int n)
{
  int i;
  for (i = 0; i < n - 3; i += 4)
  {
    __m128i src_vec = _mm_loadu_si128((__m128i *) &s1[i]);
    __m128i dst_vec = _mm_loadu_si128((__m128i *) &d1[i]);
    dst_vec = _mm_add_epi32(dst_vec, src_vec);
    _mm_storeu_si128((__m128i *) &d1[i], dst_vec);
  }

  for (; i < n; ++i)
  {
    d1[i] += s1[i];
  }
}
