#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::wiersz(int y, int* t) {
    if (!data_) return *this;
    assert(y >= 0 && y < n_);
    for (int j = 0; j < n_; ++j) {
        data_[idx(y, j)] = t ? t[j] : 0;
    }
    return *this;
}