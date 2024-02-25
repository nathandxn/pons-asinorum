#ifndef PONSASINORUM_H
#define PONSASINORUM_H

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace ponsas {

const double PI = 3.141592653589793;

typedef double (*svfunc)(double);

template <typename T> T sign(T x);
template <typename T> T abs(T x);
int factorial(int n);
double newton_sqroot(double a, double x, double tolerance = 1.0E-10);
void quadroots(double a, double b, double c, double &x1, double &x2);

// function implementations

// templated absolute value function or |x|
template <typename T>
T sign(T x) {
    return x < 0 ? -1 : 1;
}

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

void quadroots(double a, double b, double c, double &x1, double &x2) {

    double d = b*b - 4.0*a*c;
    if (d < 0) throw std::logic_error("std::logic_error: discriminant negative in ponsas::quadroots not accepted.");

    double s = -(b + sqrt(d) * sign(b)) / 2;

    x1 = s/a;
    x2 = c/s;
}

}

#endif // PONSASINORUM_H
