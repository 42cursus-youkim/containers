#include "base.hpp"
#include "mutantstack.hpp"

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer {
  int  idx;
  char buff[BUFFER_SIZE];
};

// #define COUNT (MAX_RAM / (int)sizeof(Buffer))
#define COUNT 1000

int main(int argc, char** argv) {
  const unsigned int seed =
      (argc != 2) ? 0 : (unsigned int)atoi(argv[1]);
  srand(seed);

  ft::vector<std::string>                vector_str;
  ft::vector<int>                        vector_int;
  ft::stack<int>                         stack_int;
  ft::vector<Buffer>                     vector_buffer;
  ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
  ft::map<int, int>                      map_int;

  std::cout << "count: " << COUNT << std::endl;

  for (int i = 0; i < COUNT; i++) {
    vector_buffer.push_back(Buffer());
  }

  for (int i = 0; i < COUNT; i++) {
    const unsigned int idx =
        static_cast<unsigned int>(rand() % COUNT);
    vector_buffer[idx].idx = 5;
  }
  ft::vector<Buffer>().swap(vector_buffer);

  try {
    for (int i = 0; i < COUNT; i++) {
      const unsigned int idx =
          static_cast<unsigned int>(rand() % COUNT);
      vector_buffer.at(idx);
      std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!"
                << std::endl;
    }
  } catch (const std::exception& e) {
    // NORMAL ! :P
  }

  for (int i = 0; i < COUNT; ++i) {
    map_int.insert(ft::make_pair(rand(), rand()));
  }

  int sum = 0;
  for (int i = 0; i < 10000; i++) {
    int access = rand();
    sum += map_int[access];
  }
  std::cout << "should be constant with the same seed: " << sum
            << std::endl;

  { ft::map<int, int> copy = map_int; }
  MutantStack<char> iterable_stack;
  for (char letter = 'a'; letter <= 'z'; letter++)
    iterable_stack.push(letter);
  for (MutantStack<char>::iterator it = iterable_stack.begin();
       it != iterable_stack.end(); it++) {
    std::cout << *it;
  }
  std::cout << std::endl;
  return (0);
}
