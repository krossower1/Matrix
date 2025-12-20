#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

/**
* @brief Operator overloading for brackets, in this case adding the whole part of the double
*
**/

matrix& matrix::operator()(double a) {
    int ca = static_cast<int>(a);
    for (int i = 0; i < n_ * n_; ++i) {
        data_[i] += ca;
    }
    return *this;
}