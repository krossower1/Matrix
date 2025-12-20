#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

/**
* @brief Operator overloading for multiplying with intigers
*
**/

matrix matrix::operator*(int a) const {
    matrix res(n_);
    for (int i = 0; i < n_ * n_; ++i) {
        res.data_[i] = data_[i] * a;
    }
    return res;
}