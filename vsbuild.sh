#!/bin/sh
#====================================
# @file   : vsbuild.sh
# @version: 2020-02-07
# @created: 2017-08-21
# @author : Anth0rx
# @author : pyramid
# @brief  : clean build VegaStrike
# @usage  : ./vsbuild.sh
# @param  : none
#====================================

#============ DESCRIPTION ===========
# This scipt is making a clean build of VegaStrike.
# After this, it copies the relevant files to the 'bin' directory.
# The steps for creating this script were taken from the projects wiki:
# https://github.com/Taose/Vegastrike-taose/wiki/How-to-Build
#====================================


echo "-------------------------------"
echo "--- vsbuild.sh | 2020-02-07 ---"
echo "-------------------------------"

#----------------------------------
# validate parameters
#----------------------------------

ROOT_DIR=$(pwd)
BUILD_DIR=$ROOT_DIR/engine/build
BIN_DIR=$ROOT_DIR/bin
COMMAND=""

if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
fi

cd $BUILD_DIR

# configure libraries
cmake -DCMAKE_BUILD_TYPE=Release $ROOT_DIR/engine

# for a clean build only
# mut we can do it manually
#make clean

# compile now using all cpus
make -j$(nproc)

cd $ROOT_DIR

if [ ! -d "$BIN_DIR" ]; then
    mkdir $BIN_DIR
fi

cp $BUILD_DIR/{vegastrike,vegaserver,setup/vssetup,objconv/mesh_tool} $BIN_DIR
