#!/bin/bash
PRO_DIR=/mnt/sda/2022-0526/home/scc/zty/compiler
pushd $PRO_DIR/compiler-project/run
. $SCC_SETUP_ENV
spack load gcc@7.5.0
spack load cmake@3.24.3
spack load python@3.10.8
spack load llvm@15.0.4
spack load flex@2.6.3
spack load bison@3.8.2
spack load ninja@1.11.1
export PATH=$PRO_DIR/sysu/bin:$PATH \
  CPATH=$PRO_DIR/sysu/include:$CPATH \
  LIBRARY_PATH=$PRO_DIR/sysu/lib:$LIBRARY_PATH \
  LD_LIBRARY_PATH=$PRO_DIR/sysu/lib:$LD_LIBRARY_PATH
popd