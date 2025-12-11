#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::odwroc() {
    if (!data_) return *this;
    for (int i = 0; i < n_; ++i) {
        for (int j = i + 1; j < n_; ++j) {
            std::swap(data_[idx(i, j)], data_[idx(j, i)]);
        }
    }
    return *this;
}