#include <assert.h>
#include <iostream>
#include <string>
#include "test.hpp"

typedef NS::vector<std::string> vecStr;
using std::string;

void print_vector(vecStr v) {
  for (vecStr::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << ", ";
  }
  std::cout << "\n";
}

void print_map(NS::map<string, int> m) {
  for (NS::map<string, int>::iterator it = m.begin(); it != m.end();
       it++) {
    std::cout << it->first << " " << it->second << '\n';
  }
}

int main() {
#ifdef DO_STD
  std::cout << "This program is on DO_STD" << std::endl;
#else
  std::cout << "This program is on FT" << std::endl;
#endif

  {
    vecStr vec(1, "4");

    vec.push_back("abababab");
    vec.push_back("bye");
    vec.push_back("elllo");
    std::cout << vec.begin()->c_str() << '\n';
    vecStr::iterator       iter = vec.end();
    vecStr::const_iterator cit  = vec.end();
    cit--;
    vecStr::const_reverse_iterator crit = vec.rbegin();

    std::cout << (cit == iter) << '\n';
    std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
    std::cout << (cit->get_allocator() == (*crit).get_allocator())
              << '\n';
    std::cout << *cit << " " << *crit << '\n';

    print_vector(vec);
    vecStr copiedVec(vec);
    print_vector(copiedVec);

    vecStr           otherVec;

    vecStr::iterator it_prev  = vec.begin();
    string&          str_prev = vec.front();
    string*          ptr_prev = &vec[0];

    vec.swap(otherVec);
    vecStr::iterator it_after  = otherVec.begin();
    string&          str_after = otherVec.front();
    string*          ptr_after = &otherVec[0];

    assert(it_prev == it_after);
    assert(str_prev == str_after);
    assert(ptr_prev == ptr_after);
    print_vector(otherVec);
  }
  {
    typedef NS::pair<string, int> key;
    key                           k1 = NS::make_pair("hello", 1);
    key                           k2 = NS::make_pair("world", 2);
    key                           k3("bye", 3);
    key                           k_new("bye", 123);
    NS::map<string, int>          m;
    m.insert(k1);
    m.insert(k2);
    m.insert(k3);
    print_map(m);
    m.erase(m.find("world"));
    print_map(m);
    m.erase(m.find("hello"));
    print_map(m);
    std::cout << "find bye: " << m.find("bye")->second << '\n';
    m.insert(k_new);
    print_map(m);
  }
  {
    NS::set<string> s;
    s.insert("hello");
    s.insert("world");
    s.insert("bye");
    for (int i = 0; i < 10; i++)
      s.insert("yay");

    for (NS::set<string>::iterator it = s.begin(); it != s.end();
         it++) {
      std::cout << *it << '\n';
    }
  }

  mandatory(0);
  return (0);
}
