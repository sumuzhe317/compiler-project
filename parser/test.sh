#!/bin/bash
/mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor $1 2>&1|clang -cc1 -ast-dump=json 2>&1|tee read.json read1.json
echo -------------------------------------------------------------------------------------------------------|tee -a read.json
/mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor $1 2>&1|clang -cc1 -ast-dump 2>&1|tee -a read.json read1.json
echo -------------------------------------------------------------------------------------------------------|tee -a read.json
rm -rf read2.json
/mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor $1 2>&1|clang -cc1 -dump-tokens 2>&1| /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-parser 2>&1|tee -a read.json read2.json
echo -------------------------------------------------------------------------------------------------------|tee -a read.json
# diff read1.json read2.json |tee -a read.json

# /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor ../tester/function_test2020/12_getint.sysu.c | clang -cc1 -ast-dump=json
# /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor ../tester/function_test2020/12_getint.sysu.c | clang -cc1 -dump-tokens 2>&1 | /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-parser

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