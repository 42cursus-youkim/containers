#include <stdlib.h>
// #include <map>
#include "map.hpp"
// #include "test.hpp"

int main(int argc, char** argv) {
  const unsigned int seed =
      (argc != 2) ? 0 : (unsigned int)atoi(argv[1]);
  // mandatory(seed);
  (void)seed;

  typedef ft::map<int, int> MAP;
  MAP                        m;
  MAP::iterator              it  = m.begin();
  MAP::const_iterator        cit = m.begin();

  if (cit == it)
    return 0;

  return (0);
}
