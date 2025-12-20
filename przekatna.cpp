#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Fills the matrix with ones on the diagonal
*
**/

matrix& matrix::przekatna() {
    if (!data_) return *this;
    zero();
    for (int i = 0; i < n_; ++i) data_[idx(i, i)] = 1;
    return *this;
}