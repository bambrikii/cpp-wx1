#!/bin/bash

while inotifywait -e close_write ../CMakeLists.txt; do cmake .. && make VERBOSE=1; done

