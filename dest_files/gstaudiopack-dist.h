
/* autogenerated from gstaudiopack.orc */

#ifndef _GSTAUDIOPACK_H_
#define _GSTAUDIOPACK_H_

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif



#ifndef _ORC_INTEGER_TYPEDEFS_
#define _ORC_INTEGER_TYPEDEFS_
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
typedef int8_t orc_int8;
typedef int16_t orc_int16;
typedef int32_t orc_int32;
typedef int64_t orc_int64;
typedef uint8_t orc_uint8;
typedef uint16_t orc_uint16;
typedef uint32_t orc_uint32;
typedef uint64_t orc_uint64;
#define ORC_UINT64_C(x) UINT64_C(x)
#elif defined(_MSC_VER)
typedef signed __int8 orc_int8;
typedef signed __int16 orc_int16;
typedef signed __int32 orc_int32;
typedef signed __int64 orc_int64;
typedef unsigned __int8 orc_uint8;
typedef unsigned __int16 orc_uint16;
typedef unsigned __int32 orc_uint32;
typedef unsigned __int64 orc_uint64;
#define ORC_UINT64_C(x) (x##Ui64)
#define inline __inline
#else
#include <limits.h>
typedef signed char orc_int8;
typedef short orc_int16;
typedef int orc_int32;
typedef unsigned char orc_uint8;
typedef unsigned short orc_uint16;
typedef unsigned int orc_uint32;
#if INT_MAX == LONG_MAX
typedef long long orc_int64;
typedef unsigned long long orc_uint64;
#define ORC_UINT64_C(x) (x##ULL)
#else
typedef long orc_int64;
typedef unsigned long orc_uint64;
#define ORC_UINT64_C(x) (x##UL)
#endif
#endif
typedef union { orc_int16 i; orc_int8 x2[2]; } orc_union16;
typedef union { orc_int32 i; float f; orc_int16 x2[2]; orc_int8 x4[4]; } orc_union32;
typedef union { orc_int64 i; double f; orc_int32 x2[2]; float x2f[2]; orc_int16 x4[4]; } orc_union64;
#endif
#ifndef ORC_RESTRICT
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define ORC_RESTRICT restrict
#elif defined(__GNUC__) && __GNUC__ >= 4
#define ORC_RESTRICT __restrict__
#else
#define ORC_RESTRICT
#endif
#endif

#ifndef ORC_INTERNAL
#if defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define ORC_INTERNAL __attribute__((visibility("hidden")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)
#define ORC_INTERNAL __hidden
#elif defined (__GNUC__)
#define ORC_INTERNAL __attribute__((visibility("hidden")))
#else
#define ORC_INTERNAL
#endif
#endif

void audio_orc_unpack_u8 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u8_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s8 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s8_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_swap_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_swap_trunc (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u24_32 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s24_32 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u24_32_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s24_32_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u32 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u32_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s32 (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s32_swap (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f32 (gdouble * ORC_RESTRICT d1, const gfloat * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f32_swap (gdouble * ORC_RESTRICT d1, const gfloat * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f64 (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f64_swap (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_u8 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s8 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u16 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s16 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u16_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s16_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u24_32 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s24_32 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u24_32_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s24_32_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u32 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s32 (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u32_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s32_swap (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_f32 (gfloat * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f32_swap (gfloat * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f64 (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f64_swap (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_splat_u16 (guint16 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_splat_u32 (guint32 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_splat_u64 (guint64 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_int_bias (gint32 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int p1, int p2, int n);
void audio_orc_int_dither (gint32 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, const gint32 * ORC_RESTRICT s2, int p1, int n);
void audio_orc_update_rand (guint32 * ORC_RESTRICT d1, int n);
void audio_orc_s32_to_double (gdouble * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_double_to_s32 (gint32 * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);

void audio_orc_unpack_u8_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u8_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s8_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s8_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u16_swap_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s16_swap_trunc_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u24_32_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s24_32_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u24_32_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s24_32_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u32_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_u32_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s32_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_s32_swap_sse (gint32 * ORC_RESTRICT d1, const guint8 * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f32_sse (gdouble * ORC_RESTRICT d1, const gfloat * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f32_swap_sse (gdouble * ORC_RESTRICT d1, const gfloat * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f64_sse (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_unpack_f64_swap_sse (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_u8_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s8_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u16_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s16_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u16_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s16_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u24_32_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s24_32_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u24_32_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s24_32_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u32_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s32_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_u32_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_s32_swap_sse (guint8 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_pack_f32_sse (gfloat * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f32_swap_sse (gfloat * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f64_sse (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_pack_f64_swap_sse (gdouble * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);
void audio_orc_splat_u16_sse (guint16 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_splat_u32_sse (guint32 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_splat_u64_sse (guint64 * ORC_RESTRICT d1, int p1, int n);
void audio_orc_int_bias_sse (gint32 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int p1, int p2, int n);
void audio_orc_int_dither_sse (gint32 * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, const gint32 * ORC_RESTRICT s2, int p1, int n);
void audio_orc_update_rand_sse (guint32 * ORC_RESTRICT d1, int n);
void audio_orc_s32_to_double_sse (gdouble * ORC_RESTRICT d1, const gint32 * ORC_RESTRICT s1, int n);
void audio_orc_double_to_s32_sse (gint32 * ORC_RESTRICT d1, const gdouble * ORC_RESTRICT s1, int n);

#ifdef __cplusplus
}
#endif

#endif

