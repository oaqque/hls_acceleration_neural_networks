open_project dense.proj -reset
add_files dense.c
add_files dense.h
set_top dense_layer
open_solution "solution1" -reset
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10
csynth_design
exit
