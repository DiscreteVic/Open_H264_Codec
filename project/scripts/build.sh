#!/bin/bash

cd  ../cmake

if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake -DPRJ_NAME=open_h264_codec .. && make