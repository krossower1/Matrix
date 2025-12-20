#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Operator overloading for the lesser comparison
*
**/

bool matrix::operator<(const matrix& m) const {
    if (n_ != m.n_) return false;
    for (int i = 0; i < n_ * n_; ++i) if (!(data_[i] < m.data_[i])) return false;
    return true;
}