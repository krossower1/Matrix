#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

matrix& matrix::operator()(double a) {
    int ca = static_cast<int>(a);  // czêœæ ca³kowita liczby
    for (int i = 0; i < n_ * n_; ++i) {
        data_[i] += ca;            // zwiêkszamy ka¿dy element
    }
    return *this;                 // zwracamy referencjê do aktualnego obiektu
}