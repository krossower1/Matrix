#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

matrix matrix::operator*(matrix& m) {
    assert(n_ == m.n_);  // mno¿enie mo¿liwe tylko dla macierzy tego samego rozmiaru
    matrix res(n_);
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            int suma = 0;
            for (int k = 0; k < n_; ++k) {
                suma += this->pokaz(i, k) * m.pokaz(k, j);
            }
            res.wstaw(i, j, suma);
        }
    }
    return res;
}