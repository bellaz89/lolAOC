#include <cstdio>

#ifdef FIRST
template<size_t acc, size_t a> 
#else
template<size_t acc, size_t a, size_t b, size_t c> 
#endif
size_t depth() {
  return acc;
}

#ifdef FIRST
template<size_t acc, size_t a, size_t b, size_t ... args>
#else
template<size_t acc, size_t a, size_t b, size_t c, size_t d, size_t ... args>
#endif
size_t depth() {
#ifdef FIRST
  return depth<acc + (b > a), b, args...>();
#else
  return depth<acc + (d > a), b, c, d, args...>();
#endif
};

int main() {
  printf("%zu\n", depth<0,
#include "input"
      >());
  return 0;
}
