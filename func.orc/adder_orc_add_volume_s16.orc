.function adder_orc_add_volume_s16
.dest 2 d1 gint16
.source 2 s1 gint16
.param 2 p1
.temp 4 t1
.temp 2 t2

mulswl t1, s1, p1
shrsl t1, t1, 11
convssslw t2, t1
addssw d1, d1, t2
