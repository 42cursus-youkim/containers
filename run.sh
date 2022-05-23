#!/bin/bash

echo STD mode
make CXXFLAGS='-D DO_STD=1' TARGET=test_std.out re
echo FT mode
make TARGET=test_ft.out re

echo 'time for STD'
time ./test_std.out > std.log
echo 'time for FT'
time ./test_ft.out > ft.log

echo output diff
diff std.log ft.log
