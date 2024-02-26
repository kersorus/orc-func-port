.function audiomixer_orc_add_volume_f32
.dest 4 d1 float
.source 4 s1 float
.floatparam 4 p1
.temp 4 t1

mulf t1, s1, p1
addf d1, d1, t1
