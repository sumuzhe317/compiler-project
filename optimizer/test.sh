#!/bin/bash
rm -rf read1.ll
rm -rf read2.ll
rm -rf read.ll
clang -E $1  | 
  clang -cc1 -O0 -S -emit-llvm  | 
  opt -S --enable-new-pm -load-pass-plugin=libsysuOptimizer.so -passes="sysu-optimizer-pass"  |
  tee read.ll read1.ll
echo -------------------------------------------------------------------------------------------------------|tee -a read.ll
clang -E $1  |
  clang -cc1 -O0 -S -emit-llvm  |
  sysu-optimizer  |
  tee -a read.ll read2.ll
echo -------------------------------------------------------------------------------------------------------|tee -a read.ll
# diff read1.json read2.json |tee -a read.json

# /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor ../tester/function_test2020/12_getint.sysu.c | clang -cc1 -ast-dump=json
# /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor ../tester/function_test2020/12_getint.sysu.c | clang -cc1 -dump-tokens  | /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-parser

# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2020/02_arr_defn4.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2020/05_const_array_defn.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2021/006_arr_defn3.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2021/007_arr_defn4.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2021/042_arr_expr_len.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2021/078_big_int_mul.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/04_arr_defn3.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/05_arr_defn4.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/34_arr_expr_len.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/54_hidden_var.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/63_big_int_mul.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/69_expr_eval.sysu.c
# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/93_nested_calls.sysu.c
#?

# /mnt/sda/2022-0526/home/scc/zty/compiler/compiler-project/tester/function_test2022/86_long_code2.sysu.c