#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

// constr
matrix::matrix() : n_(0), data_(nullptr) { data_.reset(new int[n_ * n_]); zero(); }

matrix::matrix(int n) : n_(0), data_(nullptr) {
    if (n > 0) {
        data_.reset(new int[n * n]);
        n_ = n;
        zero();
    }
}

matrix::matrix(int n, int* t) : n_(0), data_(nullptr) {
    if (n > 0) {
        data_.reset(new int[n * n]);
        n_ = n;
        ustal(t);
    }
}

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