#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Fill the diagonal with the values from the array
* @param The array to draw from
*
**/

matrix& matrix::diagonalna(int* t) {
    if (!data_) return *this;
    zero();
    for (int i = 0; i < n_; ++i) {
        data_[idx(i, i)] = t ? t[i] : 0;
    }
    return *this;
}