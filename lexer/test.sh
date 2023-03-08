#!/bin/bash
/mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor $1 | clang -cc1 -dump-tokens 2>&1|tee read.txt read1.txt
echo -------------------------------------------------------------------------------------------------------|tee -a read.txt
rm -rf read2.txt
/mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-preprocessor $1 | /mnt/sda/2022-0526/home/scc/zty/compiler/sysu/bin/sysu-lexer 2>&1|tee -a read.txt read2.txt
echo -------------------------------------------------------------------------------------------------------|tee -a read.txt
diff read1.txt read2.txt |tee -a read.txt