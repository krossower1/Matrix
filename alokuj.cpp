#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Allocate a matrix for the given size
* @param The desired size
*
**/

matrix& matrix::alokuj(int n) {
    if (n <= 0) return *this;
    if (!data_) {
        data_.reset(new int[n * n]);
        n_ = n;
        zero();
    }
    else {
        if (n == n_) {
        }
        else if (n > n_) {
            data_.reset(new int[n * n]);
            n_ = n;
            zero();
        }
        else {
            n_ = n;
        }
    }
    return *this;
}