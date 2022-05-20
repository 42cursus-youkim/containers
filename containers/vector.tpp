#ifndef VECTOR_VECTOR_TPP
#define VECTOR_VECTOR_TPP

#include <utils/general/lexicographical_compare.hpp>
#include <utils/general/nullptr.hpp>
#include <utils/tmp/enable_if.hpp>
#include <utils/tmp/is_integral.hpp>
#include "utils/util/util.hpp"
#include "vector.hpp"

#define VEC vector<T, Allocator>

namespace ft {

/// default constructor (empty)
template <typename T, typename Allocator>
VEC::vector(const Allocator& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {}

/// fill constructor (container with n val)
template <typename T, typename Allocator>
VEC::vector(size_type n, const T& val, const Allocator& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {
  insert(begin(), n, val);
}

/// fill constructor, has ambiguity with integer, therefore using
/// dispatch
template <typename T, typename Allocator>
template <typename InputIterator>
VEC::vector(InputIterator                       first,
            InputIterator                       last,
            const typename VEC::allocator_type& alloc)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(alloc) {
  typedef typename is_integral<InputIterator>::type is_integral;
  initialize_dispatch(first, last, is_integral());
}

/// resolve ambiguity
template <typename T, typename Allocator>
template <class Integer>
void VEC::initialize_dispatch(Integer n, Integer val, true_type) {
  reserve(FT_VECTOR_INITIAL_SIZE);
  data_end_ =
      UninitializedFillN(begin(), static_cast<size_type>(n), val);
}

template <typename T, typename Allocator>
template <typename InputIterator>
void VEC::initialize_dispatch(InputIterator first,
                              InputIterator last,
                              false_type) {
  insert(end(), first, last);
}

/// copy constructor
template <typename T, typename Allocator>
VEC::vector(const vector& other)
    : data_start_(u_nullptr),
      data_end_(u_nullptr),
      capacity_ptr_(u_nullptr),
      allocator_(other.get_allocator()) {
  insert(begin(), other.begin(), other.end());
}

/// copy assignment operator
template <typename T, typename Allocator>
VEC& VEC::operator=(const vector& other) {
  if (this != &other) {
    clear();
    insert(end(), other.begin(), other.end());
  }
  return *this;
}

/// destructor
template <typename T, typename Allocator>
VEC::~vector() {
  clear();
  allocator_.deallocate(data_start_, capacity());
}

}  // namespace ft

#endif  // VECTOR_VECTOR_TPP
