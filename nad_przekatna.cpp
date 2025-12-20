#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Fills the matrix with ones above the diagonal
*
**/

matrix& matrix::nad_przekatna() {
    if (!data_) return *this;
    zero();
    for (int i = 0; i < n_; ++i) {
        for (int j = i + 1; j < n_; ++j) {
            data_[idx(i, j)] = 1;
        }
    }
    return *this;
}