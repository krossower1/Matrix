#ifndef MATRIX_H
#define MATRIX_H
#include <memory>
#include <iostream>

class matrix {
private:
    int n_;
    std::unique_ptr<int[]> data_;
    inline int idx(int x, int y) const { return x * n_ + y; }
public:
    matrix();
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m);
    ~matrix();
    matrix& alokuj(int n);
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y) const;
    matrix& odwroc();
    matrix& losuj();
    matrix& ustal(int* t);
    matrix& zero();
};

#endif