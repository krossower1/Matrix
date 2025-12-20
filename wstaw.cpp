#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Inserts a value into the matrix at the designated coordinates
*
**/

matrix& matrix::wstaw(int x, int y, int wartosc) {
    assert(x >= 0 && x < n_ && y >= 0 && y < n_);
    data_[idx(x, y)] = wartosc;
    return *this;
}