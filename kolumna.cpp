#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Draw a column within the matrix
* @param The column number
* @param The array to draw from
*
**/

matrix& matrix::kolumna(int x, int* t) {
    if (!data_) return *this;
    assert(x >= 0 && x < n_);
    for (int i = 0; i < n_; ++i) {
        data_[idx(i, x)] = t ? t[i] : 0;
    }
    return *this;
}