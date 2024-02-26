.function adder_orc_add_volume_s32
.dest 4 d1 gint32
.source 4 s1 gint32
.param 4 p1
.temp 8 t1
.temp 4 t2

mulslq t1, s1, p1
shrsq t1, t1, 27
convsssql t2, t1
addssl d1, d1, t2
