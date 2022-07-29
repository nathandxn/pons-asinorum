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
double newton_sqroot(double a, double x, double tolerance = 1.0E-10);

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

// newton square root algorithm
double newton_sqroot(double a, double x, double tolerance) {
    // algorithm fails if initial guess is set to 0 so adding small value
    if (x == 0) {
        x = x + 1.0E-5;
    }

    while (abs<double>(x * x - a) > tolerance) {
        x = (x + a/x)/2;
    }
    return x;
    
}

}

#endif // PONSASINORUM_H
