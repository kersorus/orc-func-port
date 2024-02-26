#include <emmintrin.h>
#include "../dest_files/gstaudiopack-dist.h"

void audio_orc_pack_f64_sse(gdouble *ORC_RESTRICT d1, const gdouble *ORC_RESTRICT s1, int n) 
{
    int i;

    for (i = 0; i < n - 1; i += 2)
    {
        __m128d val_vec = _mm_loadu_pd(&s1[i]);
        _mm_storeu_pd(&d1[i], val_vec);
    }

    for (; i < n; i++)
        d1[i] = s1[i];
}
