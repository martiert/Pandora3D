#!/bin/bash
mkdir _build_/test-reports -p
cd _build_
cmake ..
make -j8
./bin/mathtests --gtest_output=xml:test-reports/mathreport.xml
./bin/physicstests --gtest_output=xml:test-reports/physicsreport.xml
