#include "matrix.h"
#include <random>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
* @brief Operator overloading for printing a whole matrix
*
**/

std::ostream& operator<<(std::ostream& o, const matrix& m) {
    if (m.n_ == 0) {
        o << "(empty matrix)";
        return o;
    }
    for (int i = 0; i < m.n_; ++i) {
        for (int j = 0; j < m.n_; ++j) {
            o << std::setw(3) << m.data_[m.idx(i, j)];
        }
        o << '\n';
    }
    return o;
}