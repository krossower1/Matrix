#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::diagonalna_k(int k, int* t) {
    if (!data_) return *this;
    zero();
    if (k == 0) {
        return diagonalna(t);
    }
    else if (k > 0) {
        for (int i = 0; i < n_; ++i) {
            int col = i + k;
            if (col >= 0 && col < n_) {
                data_[idx(i, col)] = t ? t[i] : 0;
            }
        }
    }
    else {
        int kk = -k;
        for (int i = 0; i < n_; ++i) {
            int row = i + kk;
            int col = i;
            if (row >= 0 && row < n_ && col < n_) {
                data_[idx(row, col)] = t ? t[i] : 0;
            }
        }
    }
    return *this;
}