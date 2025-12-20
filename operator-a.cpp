#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

/**
* @brief Operator overloading for subtractive asigning
*
**/

matrix& matrix::operator-=(int a) {
    for (int i = 0; i < n_ * n_; ++i) {
        data_[i] -= a;
    }
    return *this;
}
