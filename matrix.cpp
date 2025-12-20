#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief The constructor of the class without parameters
*
**/

matrix::matrix() : n_(0), data_(nullptr) { data_.reset(new int[n_ * n_]); zero(); }

/**
* @brief The constructor of the class
* @param The desired size
*
**/

matrix::matrix(int n) : n_(0), data_(nullptr) {
    if (n > 0) {
        data_.reset(new int[n * n]);
        n_ = n;
        zero();
    }
}

/**
* @brief The constructor of the class
* @param The desired size
* @param The array to draw from
*
**/

matrix::matrix(int n, int* t) : n_(0), data_(nullptr) {
    if (n > 0) {
        data_.reset(new int[n * n]);
        n_ = n;
        ustal(t);
    }
}

/**
* @brief The constructor of the class
* @param The matrix to copy from
*
**/

matrix::matrix(const matrix& m) : n_(0), data_(nullptr) {
    if (m.n_ > 0) {
        data_.reset(new int[m.n_ * m.n_]);
        n_ = m.n_;
        std::memcpy(data_.get(), m.data_.get(), sizeof(int) * n_ * n_);
    }
}

matrix::~matrix() {
    // auto
}