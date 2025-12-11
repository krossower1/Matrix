#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

int matrix::pokaz(int x, int y) const {
    assert(x >= 0 && x < n_ && y >= 0 && y < n_);
    return data_[idx(x, y)];
}