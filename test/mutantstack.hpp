#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include "base.hpp"

template <typename T>
class MutantStack : public ft::stack<T> {
 public:
  MutantStack() {}
  MutantStack(const MutantStack<T>& src) { *this = src; }
  MutantStack<T>& operator=(const MutantStack<T>& rhs) {
    this->c = rhs.c;
    return *this;
  }
  ~MutantStack() {}

  typedef typename ft::stack<T>::container_type::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

#endif // __MUTANTSTACK_H__
