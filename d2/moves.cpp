#include <cstdio>
#include <cstdint>

template<int64_t result> 
int64_t moves() {
  return result;
}

#ifdef FIRST
template<int64_t x, int64_t y> 
#else
template<int64_t x, int64_t y, int64_t aim> 
#endif
size_t moves() {
  return moves<x*y>();
}

#ifdef FIRST
template<int64_t x, int64_t y, int64_t move, int64_t qty, int64_t ...args> 
#else
template<int64_t x, int64_t y, int64_t aim, int64_t move, int64_t qty, int64_t ...args> 
#endif
int64_t moves() {
#ifdef FIRST
  return moves<x + (move == 0 ? qty : 0), 
               y + (move == 0 ? 0 : qty * move), args...>();
#else
  return moves<x + (move == 0 ? qty : 0), 
               y + (move == 0 ? aim * qty : 0), 
               aim + (move == 0 ? 0 : move * qty), args...>();
#endif
};

#define forward ,0,
#define up ,-1,
#define down ,1,

int main() {
  printf("%zu\n", moves<0, 0
#ifndef FIRST
  , 0
#endif
#include "input"
      >());
  return 0;
}
