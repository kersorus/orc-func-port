.function audio_orc_pack_f32_swap
.dest 4 d1 gfloat
.source 8 s1 gdouble
.temp 4 t1

convdf t1, s1
swapl d1, t1
