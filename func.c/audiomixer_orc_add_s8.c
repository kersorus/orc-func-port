#include <emmintrin.h>
#include "../dest_files/gstaudiomixerorc-dist.h"

void audiomixer_orc_add_s8_sse(gint8 *ORC_RESTRICT d1, const gint8 *ORC_RESTRICT s1, int n)
{
  int i;

  for (i = 0; i < n - 15; i += 16)
  {
      __m128i src_vec = _mm_loadu_si128((__m128i *) &s1[i]);
      __m128i dst_vec = _mm_loadu_si128((__m128i *) &d1[i]);
      dst_vec = _mm_adds_epi8(dst_vec, src_vec);
      _mm_storeu_si128((__m128i *) &d1[i], dst_vec);
  }

  for (; i < n; i++)
  {
      d1[i] += s1[i];
  }
}
