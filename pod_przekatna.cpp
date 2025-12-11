#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::pod_przekatna() {
    if (!data_) return *this;
    zero();
    for (int i = 1; i < n_; ++i) {
        for (int j = 0; j < i; ++j) {
            data_[idx(i, j)] = 1;
        }
    }
    return *this;
}