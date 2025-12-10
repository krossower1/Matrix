#include "matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    int n = 15;
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    matrix A(n);
    matrix B;
    matrix C(n, arr);
    matrix D(C);
    B.alokuj(n);

    cout << "Tworzenie i wype³nianie macierzy losowymi cyframi (0-9), wstawienie 11 na [0,0]\n";
    A.losuj();
    B.losuj();
    A.wstaw(0, 0, 11);

    cout << "Macierz A (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << A.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz B (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << B.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz C (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << C.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz D (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << D.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Transpozycja A (pierwsze 4x4):\n";
    A.dowroc();
    for (int i = 0; i < std::min(4, n); ++i) {
        for (int j = 0; j < std::min(4, n); ++j) cout << std::setw(4) << A.pokaz(i, j);
        cout << '\n';
    }
    return 0;
}