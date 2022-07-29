#ifndef PONSASINORUM_H
#define PONSASINORUM_H

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace ponsas {

const double PI = 3.141592653589793;

template <typename T>
T abs(T x);
int factorial(int n);

// function implementations

// templated absolute value function or |x|
template <typename T>
T abs(T x) {
    if (x < 0) return -x;
    return x;
}

// factorial function
int factorial(int n) {
    if (n < 0) throw std::invalid_argument("std::invalid_argument: ponsas::factorial only takes non-negative integer values.");
    return n == 0 ? 1 : n * factorial(n - 1);
}

}

#endif // PONSASINORUM_H
