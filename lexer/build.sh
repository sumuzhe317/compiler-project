#!/bin/bash
PRO_DIR=/mnt/sda/2022-0526/home/scc/zty/compiler
source $PRO_DIR/compiler-project/run/build.sh
sysu-compiler --unittest=lexer-3 "../tester/**/*.sysu.c" 