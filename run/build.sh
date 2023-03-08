#!/bin/bash
PRO_DIR=/mnt/sda/2022-0526/home/scc/zty/compiler
pushd $PRO_DIR/compiler-project
BUILD_TOP_FOLDER=$PRO_DIR/sysu
rm -rf $BUILD_TOP_FOLDER
cmake -G Ninja \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_INSTALL_PREFIX=$BUILD_TOP_FOLDER \
  -DCMAKE_MODULE_PATH=$(llvm-config --cmakedir) \
  -DCPACK_SOURCE_IGNORE_FILES=".git/;tester/third_party/" \
  -B $BUILD_TOP_FOLDER/build
cmake --build $BUILD_TOP_FOLDER/build
cmake --build $BUILD_TOP_FOLDER/build -t install
popd