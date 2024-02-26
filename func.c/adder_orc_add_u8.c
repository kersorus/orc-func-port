#include <emmintrin.h>
#include "../dest_files/gstadderorc-dist.h"

void adder_orc_add_u8_sse(guint8 *ORC_RESTRICT d1, const guint8 *ORC_RESTRICT s1, int n)
{
  int i;

  for (i = 0; i < n - 15; i += 16)
  {
      __m128i src_vec = _mm_loadu_si128((__m128i *) &s1[i]);
      __m128i dst_vec = _mm_loadu_si128((__m128i *) &d1[i]);
      dst_vec = _mm_adds_epu8(dst_vec, src_vec);
      _mm_storeu_si128((__m128i *) &d1[i], dst_vec);
  }

  for (; i < n; i++)
  {
      d1[i] += s1[i];
  }
}
