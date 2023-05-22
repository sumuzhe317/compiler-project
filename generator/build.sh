#!/bin/bash
PRO_DIR=/mnt/sda/2022-0526/home/scc/zty/compiler
source $PRO_DIR/compiler-project/run/build.sh
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/function_test2020/*.sysu.c" 2>&1 |tee function_test2020.txt
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/function_test2021/*.sysu.c" 2>&1 |tee function_test2021.txt
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/function_test2022/*.sysu.c" 2>&1 |tee function_test2022.txt
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/functional/*.sysu.c" 2>&1 |tee functional.txt
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/h_functional/*.sysu.c" 2>&1 |tee h_functional.txt
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/mizuno_ai/*.sysu.c" 2>&1 |tee mizuno_ai.txt