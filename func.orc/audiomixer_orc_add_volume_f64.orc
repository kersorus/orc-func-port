.function audiomixer_orc_add_volume_f64
.dest 8 d1 double
.source 8 s1 double
.doubleparam 8 p1
.temp 8 t1

muld t1, s1, p1
addd d1, d1, t1
