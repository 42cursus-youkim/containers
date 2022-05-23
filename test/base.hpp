#ifndef __BASE_H__
#define __BASE_H__

#include <deque>
#include <iostream>
#include <string>
#ifdef DO_STD  // CREATE A REAL STL EXAMPLE
#include <map>
#include <set>
#include <stack>
#include <vector>
namespace NS = std;
#else
#include <map.hpp>
#include <set.hpp>
#include <stack.hpp>
#include <vector.hpp>
namespace NS = ft;
#endif

#endif  // __BASE_H__
