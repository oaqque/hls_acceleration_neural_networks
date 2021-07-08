open_project conv.proj -reset
add_files conv.c
add_files conv.h
set_top conv_layer
open_solution "solution1" -reset
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10
csynth_design
exit
