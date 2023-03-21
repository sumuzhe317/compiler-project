#!/bin/bash
clang -cc1 -ast-dump=json $1 2>&1|tee read.json read1.json
echo -------------------------------------------------------------------------------------------------------|tee -a read.json
rm -rf read2.json
clang -E $1 | clang -cc1 -dump-tokens 2>&1| /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-parser 2>&1|tee -a read.json read2.json
echo -------------------------------------------------------------------------------------------------------|tee -a read.json
diff read1.json read2.json |tee -a read.json