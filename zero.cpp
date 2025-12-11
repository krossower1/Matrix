#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::zero() {
    if (data_) {
        std::fill_n(data_.get(), n_ * n_, 0);
    }
    return *this;
}