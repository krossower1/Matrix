#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

// constructors
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
        set_from_array(t);
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

// allocation
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

// access / modify
matrix& matrix::wstaw(int x, int y, int wartosc) {
    assert(x >= 0 && x < n_ && y >= 0 && y < n_);
    data_[idx(x, y)] = wartosc;
    return *this;
}

int matrix::pokaz(int x, int y) const {
    assert(x >= 0 && x < n_ && y >= 0 && y < n_);
    return data_[idx(x, y)];
}

matrix& matrix::set_from_array(int* t) {
    if (!t || n_ <= 0) return *this;
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            data_[idx(i, j)] = t [j];
        }
    }
    return *this;
}

matrix& matrix::zero() {
    if (data_) {
        std::fill_n(data_.get(), n_ * n_, 0);
    }
    return *this;
}

// transpose
matrix& matrix::dowroc() {
    if (!data_) return *this;
    for (int i = 0; i < n_; ++i) {
        for (int j = i + 1; j < n_; ++j) {
            std::swap(data_[idx(i, j)], data_[idx(j, i)]);
        }
    }
    return *this;
}

// random
matrix& matrix::losuj() {
    if (!data_) return *this;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < n_ * n_; ++i) data_[i] = dist(gen);
    return *this;
}