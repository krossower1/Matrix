#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::szachownica() {
    if (!data_) return *this;
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            data_[idx(i, j)] = ((i + j) % 2 == 0) ? 0 : 1;
        }
    }
    return *this;
}