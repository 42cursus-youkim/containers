#!/bin/bash

section () {
  echo
  echo $@
  echo
}

section STD mode
make CXXFLAGS='-D DO_STD=1' TARGET=test_std.out re
section FT mode
make TARGET=test_ft.out re

section 'time for STD'
time ./test_std.out > std.log
section 'time for FT'
time ./test_ft.out > ft.log

section output diff
diff std.log ft.log
