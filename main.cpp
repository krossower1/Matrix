#include "matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    int n = 35;
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    matrix A(n);
    matrix B;
    matrix C(n, arr);
    matrix D(C);
    matrix E(n);
    B.alokuj(n);

    cout << "Tworzenie i wypelnianie macierzy losowymi cyframi (0-9), wstawienie 11 na [0,0]\n";
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

    cout << "Transpozycja A (fragment):\n";
    A.odwroc();
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) cout << std::setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    C.losuj(30);

    cout << "Macierz C po losowaniu (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << C.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    D.diagonalna(arr);

    cout << "Macierz D po diag (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << D.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    D.diagonalna_k(-2, arr);

    cout << "Macierz D po diag z przesunieciem (fragment):\n";
    for (int i = 0; i < std::min(8, n); ++i) {
        for (int j = 0; j < std::min(8, n); ++j) {
            cout << std::setw(3) << D.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    std::vector<int> col(n, 7);
    D.kolumna(2, col.data());
    std::vector<int> row(n, 9);
    D.wiersz(0, row.data());
    cout << "D po wstawieniu kolumny i wiersza (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << D.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    D.przekatna();
    cout << "D po przekatna (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << D.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    D.pod_przekatna();
    cout << "D po pod_przekatna (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << D.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    D.nad_przekatna();
    cout << "D po nad_przekatna (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << D.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    D.szachownica();
    cout << "D po scachownica (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << D.pokaz(i, j);
        cout << '\n';
    }

    cout << "Suma A i B (fragment):\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cout << std::setw(3) << (A + B).pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Mnozenie A i B (fragment):\n";
    matrix F = A * B;
    for (int i = 0; i < std::min(8, F.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, F.rozmiar()); ++j) {
            cout << setw(4) << F.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A po dodaniu 5 (fragment):\n";
    matrix G = A;     
    G + 5;             
    for (int i = 0; i < std::min(8, G.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, G.rozmiar()); ++j) {
            cout << setw(3) << G.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A po mnozeniu przez 3 (fragment):\n";
    matrix H = A * 3; 
    for (int i = 0; i < std::min(8, H.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, H.rozmiar()); ++j) {
            cout << setw(3) << H.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A po odjêciu 2 (fragment):\n";
    matrix I = A - 2;
    for (int i = 0; i < std::min(8, I.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, I.rozmiar()); ++j) {
            cout << setw(3) << I.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "5 + Macierz A (fragment):\n";
    matrix J = 5 + A; 
    for (int i = 0; i < std::min(8, J.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, J.rozmiar()); ++j) {
            cout << setw(3) << J.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "3 * Macierz A (fragment):\n";
    matrix K = 3 * A; 
    for (int i = 0; i < std::min(8, K.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, K.rozmiar()); ++j) {
            cout << setw(3) << K.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "10 - Macierz A (fragment):\n";
    matrix L = 10 - A; 
    for (int i = 0; i < std::min(8, L.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, L.rozmiar()); ++j) {
            cout << setw(3) << L.pokaz(i, j);
        }
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A++ (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    matrix M = A++; 
    cout << "Macierz A po A++ (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A-- (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    A--; 
    cout << "Macierz A po A-- (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A += 3 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    A += 3; 

    cout << "Macierz A po A += 3 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A -= 2 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    A -= 2;

    cout << "Macierz A po A -= 2 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A *= 3 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    A *= 3;

    cout << "Macierz A po A *= 3 (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    cout << "Macierz A przed A(2.7) (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";

    A(2.7);

    cout << "Macierz A po A(2.7) (fragment):\n";
    for (int i = 0; i < std::min(8, A.rozmiar()); ++i) {
        for (int j = 0; j < std::min(8, A.rozmiar()); ++j)
            cout << setw(3) << A.pokaz(i, j);
        cout << '\n';
    }
    cout << "...\n";
    cout << "Czy A == A ? - " << (A == B ? "tak" : "nie") << '\n';
    cout << "Czy A == A ? - " << (A == A ? "tak" : "nie") << '\n';
    cout << "Czy A > B ? - " << (A > B ? "tak" : "nie") << '\n';
    cout << "Czy A < B ? - " << (A < B ? "tak" : "nie") << '\n';
    cout << "...\n";
    matrix X(15);
    X.losuj();
    cout << "Automatyczne wypisanie calego X - " << '\n' << X;
}