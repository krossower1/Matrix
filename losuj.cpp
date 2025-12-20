#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Fill the matrix with random numbers
*
**/

matrix& matrix::losuj() {
    if (!data_) return *this;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < n_ * n_; ++i) data_[i] = dist(gen);
    return *this;
}