#!/bin/bash -x

g++ app1.cpp -o build/app1 `~/Software/wxWidgets-3.2.1/wx-config --cxxflags --libs`
build/app1

