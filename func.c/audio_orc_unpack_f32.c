#include <emmintrin.h>
#include "../dest_files/gstaudiopack-dist.h"

void audio_orc_unpack_f32_sse(gdouble *ORC_RESTRICT d1, const gfloat *ORC_RESTRICT s1, int n) 
{
    int i;

    for (i = 0; i < n - 1; i += 2)
    {
        __m128 val_vec_f = _mm_loadu_ps(&s1[i]);
        __m128d val_vec_d = _mm_cvtps_pd(val_vec_f);
        _mm_storeu_pd(&d1[i], val_vec_d);
    }

    for (; i < n; i++)
        d1[i] = (gdouble) s1[i];
}
