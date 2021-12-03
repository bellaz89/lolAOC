#include <cstdio>
#include <type_traits>

constexpr size_t cpow(size_t base, size_t exp) {
    return (exp == 0) ? 1 : (base * cpow(base, exp -1));
}

template<size_t values, size_t z0, size_t z1, size_t z2, size_t z3, 
                        size_t z4, size_t z5, size_t z6, size_t z7, 
                        size_t z8, size_t z9, size_t z10, size_t z11>
constexpr size_t power() {
 return ((z0 > values/2) * cpow(2, 11) + (z1 > values/2) * cpow(2, 10) + 
        (z2 > values/2) * cpow(2, 9)   + (z3 > values/2) * cpow(2, 8) +
        (z4 > values/2) * cpow(2, 7)   + (z5 > values/2) * cpow(2, 6) + 
        (z6 > values/2) * cpow(2, 5)   + (z7 > values/2) * cpow(2, 4) +
        (z8 > values/2) * cpow(2, 3)   + (z9 > values/2) * cpow(2, 2) + 
        (z10> values/2) * cpow(2, 1)   + (z11> values/2) * cpow(2, 0)) *
        ((z0 < values/2) * cpow(2, 11) + (z1 < values/2) * cpow(2, 10) + 
        (z2 < values/2) * cpow(2, 9)   + (z3 < values/2) * cpow(2, 8) +
        (z4 < values/2) * cpow(2, 7)   + (z5 < values/2) * cpow(2, 6) + 
        (z6 < values/2) * cpow(2, 5)   + (z7 < values/2) * cpow(2, 4) +
        (z8 < values/2) * cpow(2, 3)   + (z9 < values/2) * cpow(2, 2) + 
        (z10< values/2) * cpow(2, 1)   + (z11< values/2) * cpow(2, 0));
}


template<size_t values, size_t z0, size_t z1, size_t z2, size_t z3, 
                        size_t z4, size_t z5, size_t z6, size_t z7, 
                        size_t z8, size_t z9, size_t z10, size_t z11,
                        size_t b0, size_t b1, size_t b2, size_t b3, 
                        size_t b4, size_t b5, size_t b6, size_t b7, 
                        size_t b8, size_t b9, size_t b10, size_t b11,
                        size_t ...args> 
constexpr size_t power() {
  return power<values + 1, z0+b0, z1+b1, z2+b2, z3+b3, z4+b4, z5+b5, 
                           z6+b6, z7+b7, z8+b8, z9+b9, z10+b10, z11+b11, 
                           args...>();
};

int main() {
  printf("%zu\n", power<0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#include "input"
      >());
  return 0;
}
