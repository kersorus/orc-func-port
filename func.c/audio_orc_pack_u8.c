#include <emmintrin.h>
#include "../dest_files/gstaudiopack-dist.h"

void audio_orc_pack_u8_sse(guint8 *ORC_RESTRICT d1, const gint32 *ORC_RESTRICT s1, int n) 
{
    int i;

    for (i = 0; i < n - 127; i += 128)
    {
        __m128i val_vec = _mm_loadu_si128((__m128i *) &s1[i]);
        _mm_storeu_si128((__m128i *) &d1[i], val_vec);
    }

    for (; i < n; i++)
        d1[i] = (gint8) s1[i];
}
