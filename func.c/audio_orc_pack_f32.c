#include <emmintrin.h>
#include "../dest_files/gstaudiopack-dist.h"

void audio_orc_pack_f32_sse(gfloat *ORC_RESTRICT d1, const gdouble *ORC_RESTRICT s1, int n) 
{
    int i;

    for (i = 0; i < n - 1; i += 2)
    {
        __m128d val_vec_d = _mm_loadu_pd(&s1[i]);
        __m128 val_vec_f = _mm_cvtpd_ps(val_vec_d);
        _mm_storeu_ps(&d1[i], val_vec_f);
    }

    for (; i < n; i++)
        d1[i] = (gfloat) s1[i];
}
