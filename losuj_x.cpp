#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

matrix& matrix::losuj(int x) {
    if (!data_ || x <= 0) return *this;
    int total = n_ * n_;
    if (x >= total) {
        return losuj();
    }
    std::vector<int> idxs(total);
    for (int i = 0;i < total;++i) idxs[i] = i;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(idxs.begin(), idxs.end(), gen);
    std::uniform_int_distribution<int> dist(0, 9);
    std::fill_n(data_.get(), total, 0);
    for (int k = 0;k < x;++k) {
        int pos = idxs[k];
        data_[pos] = dist(gen);
    }
    return *this;
}