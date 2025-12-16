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
    int rozmiar() const { return n_; }
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
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& przekatna();
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();
    matrix& ustal(int* t);
    matrix& zero();
    matrix operator+(const matrix& m) const;
    matrix operator*(matrix& m);
    matrix operator+(int a) const;
    matrix operator*(int a) const;
    matrix operator-(int a) const;
    friend matrix operator+(int a, const matrix& m);
    friend matrix operator*(int a, const matrix& m);
    friend matrix operator-(int a, const matrix& m);
    matrix operator++(int); // postinkrementacja
    matrix operator--(int); // postdekrementacja
    matrix& operator+=(int a);
    matrix& operator-=(int a);
    matrix& operator*=(int a);
    matrix& operator()(double a);

};

#endif