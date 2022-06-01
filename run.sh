#!/bin/bash

section () {
  echo
  echo $@
  echo
}

compile () {
  section STD mode
  make CXXFLAGS='-D DO_STD=1' TARGET=test_std.out re
  section FT mode
  make TARGET=test_ft.out re
}

timeit () {
  section 'time for STD'
  time ./test_std.out > std.log
  section 'time for FT'
  time ./test_ft.out > ft.log
}

output () {
  section output diff
  diff std.log ft.log
}

leak () {
  section check leak
  make CXXFLAGS='-D COUNT=4096 -D LOOP=1 -g3' TARGET=test_ft.out re
  # valgrind ./test_ft.out
  ./test_ft.out &
  pid=$!
  leaks test_ft.out
  kill $pid
}

compile
timeit
output
leak
