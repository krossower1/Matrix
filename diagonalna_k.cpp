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
    // k=0 -> g³ówna przek¹tna
    // k>0 -> przesuniêcie "w górê" o k (tj. diagonal zaczyna siê w kolumnie k, w wierszu 0)
    // k<0 -> przesuniêcie "w dó³" o |k|
    if (k == 0) {
        return diagonalna(t);
    }
    else if (k > 0) {
        // i from 0..n-1, column = i+k < n
        for (int i = 0; i < n_; ++i) {
            int col = i + k;
            if (col >= 0 && col < n_) {
                data_[idx(i, col)] = t ? t[i] : 0;
            }
        }
    }
    else {
        // k < 0, rows shifted down: row = i - k? Let's interpret: negative przesuwa w dó³ o |k|
        // interpretacja: diagonal starts at row = |k|, col = 0. So element t[i] goes to (i+|k|, i)
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