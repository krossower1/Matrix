#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

/**
* @brief Operator overloading for derementation
*
**/

matrix matrix::operator--(int) {
    matrix temp(*this);
    for (int i = 0; i < n_ * n_; ++i) {
        data_[i] -= 1;
    }
    return temp;
}