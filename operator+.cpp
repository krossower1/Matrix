#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix matrix::operator+(const matrix& m) const {
    assert(n_ == m.n_);
    matrix res(n_);
    for (int i = 0; i < n_ * n_; ++i) res.data_[i] = data_[i] + m.data_[i];
    return res;
}