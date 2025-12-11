#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::ustal(int* t) {
    if (!t || n_ <= 0) return *this;
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            data_[idx(i, j)] = t[j];
        }
    }
    return *this;
}