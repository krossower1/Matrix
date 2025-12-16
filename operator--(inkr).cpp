#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

matrix matrix::operator--(int) {
    matrix temp(*this);  // kopia przed zmniejszeniem
    for (int i = 0; i < n_ * n_; ++i) {
        data_[i] -= 1;    // zmniejszamy orygina³
    }
    return temp;          // zwracamy kopiê sprzed zmiany
}