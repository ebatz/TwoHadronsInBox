#!/bin/bash

echo "cp Makefile.awl.mac Makefile"
cp Makefile.mac.clang.accelerate Makefile

echo "make lib"
make lib
