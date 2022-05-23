#include <stdlib.h>
#include "mutantstack.hpp"
#include "test.hpp"

void mandatory(unsigned int seed) {
  srand(seed);

  NS::vector<std::string>                vector_str;
  NS::vector<int>                        vector_int;
  NS::stack<int>                         stack_int;
  NS::vector<Buffer>                     vector_buffer;
  NS::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
  NS::map<int, int>                      map_int;

  std::cout << "count: " << COUNT << std::endl;

  for (int i = 0; i < COUNT; i++) {
    vector_buffer.push_back(Buffer());
  }

  for (int i = 0; i < COUNT; i++) {
    const unsigned int idx =
        static_cast<unsigned int>(rand() % COUNT);
    vector_buffer[idx].idx = 5;
  }
  NS::vector<Buffer>().swap(vector_buffer);

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
    map_int.insert(NS::make_pair(rand(), rand()));
  }

  int sum = 0;
  for (int i = 0; i < 10000; i++) {
    int access = rand();
    sum += map_int[access];
  }
  std::cout << "should be constant with the same seed: " << sum
            << std::endl;

  { NS::map<int, int> copy = map_int; }
  MutantStack<char> iterable_stack;
  for (char letter = 'a'; letter <= 'z'; letter++)
    iterable_stack.push(letter);
  for (MutantStack<char>::iterator it = iterable_stack.begin();
       it != iterable_stack.end(); it++) {
    std::cout << *it;
  }
  std::cout << std::endl;
}
