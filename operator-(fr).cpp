#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

/**
* @brief Operator overloading for subtraction with intigers
*
**/

matrix operator-(int a, const matrix& m) {
    matrix res(m.n_);
    for (int i = 0; i < m.n_ * m.n_; ++i) {
        res.data_[i] = a - m.data_[i];
    }
    return res;
}