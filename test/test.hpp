#include "base.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void mandatory(unsigned int seed);

struct Buffer {
  int  idx;
  char buff[BUFFER_SIZE];
};
