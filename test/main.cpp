#include "test.hpp"
#include <stdlib.h>

int main(int argc, char** argv) {
  const unsigned int seed =
      (argc != 2) ? 0 : (unsigned int)atoi(argv[1]);
  mandatory(seed);
  return (0);
}
