#!/bin/bash

cd ..

debug="True";

if [[ -z $1 ]]; then
    debug="False";
fi

if [[ $1 == "no-debug" ]]; then
    echo "Debug is set to off";
    debug="False";
elif [[ $1 == "debug" ]]; then
    echo "Debug is set to true";
    debug="True";
fi

if [[ $debug == "True" ]]; then
    echo "Current directory:" $(pwd)
    echo "Building CMakeLists.txt"
fi

cmake -B ./build
cd ./build
make

echo "Building is finished";

exit 0;