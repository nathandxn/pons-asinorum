#ifndef PONSASINORUM_H
#define PONSASINORUM_H

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace ponsas {

const double PI = 3.141592653589793;

template <typename T>
T abs(T x);

// function implementations

// templated absolute value function or |x|
template <typename T>
T abs(T x) {
    if (x < 0) return -x;
    return x;
}

}

#endif // PONSASINORUM_H
