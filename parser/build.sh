#!/bin/bash
PRO_DIR=/mnt/sda/2022-0526/home/scc/zty/compiler
source $PRO_DIR/compiler-project/run/build.sh
sysu-compiler --unittest=benchmark_generator_and_optimizer_1 "../tester/**/*.sysu.c" 