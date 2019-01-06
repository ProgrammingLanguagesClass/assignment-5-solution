#include <iostream>
#include "matrix.h"

template<class T>
matrix<T>::matrix(int n, int m): array<T>(n), n(n), m(m), a(new T *[n]) {
    for (int i = 0; i < n; i++) {
        a[i] = new T[m];
    }
}

template<class T>
matrix<T>::matrix(const matrix<T> &other): array<T>(other.n), n(other.n), m(other.m) {
    a = new T *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new T[m];
        for (int j = 0; j < m; j++) {
            a[i][j] = other.a[i][j];
        }
    }
}

template<class T>
matrix<T>::matrix(int **other, int n, int m): array<T>(n), n(n), m(m), a(new T *[n]) {
    for (int i = 0; i < n; i++) {
        a[i] = new T[m];
        for (int j = 0; j < m; j++) {
            a[i][j] = other[i][j];
        }
    }
}

template<class T>
matrix<T>::~matrix() {
    for (int i = 0; i < n; i++) {
        delete a[i];
    }
    delete [] a;
}

template<class T>
T &matrix<T>::get(int i, int j) const {
    return a[i][j];
}

template<class T>
matrix<T> &matrix<T>::add(int i, int j, const T &x) {
    a[i][j] = x;
    return *this;
}

template<class T>
matrix<T> &matrix<T>::set(int i, int j, const T &x) {
    return add(i, j, x);
}

template<class T>
matrix<T> &matrix<T>::transpose() {
    if (n != m) {
        std::cout << "Error";
        exit(-1);
    }
    int **t = new T *[n];
    for (int i = 0; i < n; i++) {
        t[i] = new int[m];
        for (int j = 0; j < m; j++) {
            t[i][j] = a[j][i];
        }
    }
    a = t;
    return *this;
}

template<class T>
matrix<T> matrix<T>::inverse() {
    matrix<T> result(*this);
    // Todo: implement this (bonus 10 points for complete implementation)
    return result;
}

template<class T>
void matrix<T>::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<class T>
matrix<T> &matrix<T>::operator~() {
    return transpose();
}

template<class T>
matrix<T> matrix<T>::operator^(int p) {
    if (p == -1) return inverse();
    matrix<T> result(*this);
    for (int i = 1; i < p; i++) {
        result *= (*this);
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator+(const matrix<T> &rhs) {
    if (n != rhs.n || m != rhs.m) {
        // different size
        std::cout << "Error";
        exit(-1);
    }
    matrix<T> result(rhs.n, rhs.m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.a[i][j] = a[i][j] + rhs.a[i][j];
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator-(const matrix<T> &rhs) {
    if (n != rhs.n || m != rhs.m) {
        // different size
        std::cout << "Error";
        exit(-1);
    }
    matrix<T> result(rhs.n, rhs.m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.a[i][j] = a[i][j] - rhs.a[i][j];
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator*(const matrix<T> &rhs) {
    if (m != rhs.n) {
        // Inner dimensions don't agree
        std::cout << "Error";
        exit(-1);
    }
    matrix<T> result(n, rhs.m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rhs.m; j++) {
            result.a[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result.a[i][j] += a[i][k] * rhs.a[k][j];
            }
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator/(matrix<T> &rhs) {
    matrix<T> result(*this);
    return result * rhs.inverse();
}

template<class T>
matrix<T> &matrix<T>::operator+=(const matrix<T> &rhs) {
    if (n != rhs.n || m != rhs.m) {
        std::cout << "Error";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] += rhs.a[i][j];
        }
    }
    return *this;

}

template<class T>
matrix<T> &matrix<T>::operator-=(const matrix<T> &rhs) {
    if (n != rhs.n || m != rhs.m) {
        std::cout << "Error";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] -= rhs.a[i][j];
        }
    }
    return *this;
}

template<class T>
matrix<T> &matrix<T>::operator*=(const matrix<T> &rhs) {
    if (m != rhs.n) {
        // Inner dimensions don't agree
        std::cout << "Error";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rhs.m; j++) {
            a[i][j] = 0;
            for (int k = 0; k < m; k++) {
                a[i][j] += a[i][k] * rhs.a[k][j];
            }
        }
    }
    return *this;
}

template<class T>
matrix<T> &matrix<T>::operator/=(matrix<T> &rhs) {
    return (*this) *= rhs.inverse();
}

template<class T>
matrix<T> matrix<T>::operator+(T *rhs[]) {
    // Assume same size for simplicity
    matrix<T> result(*this);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.a[i][j] += rhs[i][j];
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator-(T *rhs[]) {
    // Assume same size for simplicity
    matrix<T> result(*this);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.a[i][j] -= rhs[i][j];
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator*(T **rhs) {
    // Assume inner dimensions are the same for simplicity
    matrix<T> result(*this);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.a[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result.a[i][j] += rhs[i][j];
            }
        }
    }
    return result;
}

template<class T>
matrix<T> matrix<T>::operator/(T **rhs) {
    // Assume same size for simplicity
    matrix<T> t(rhs, n, m);
    matrix<T> result(*this);
    return result / t;

}

template<class T>
matrix<T> &matrix<T>::operator+=(T **rhs) {
    // Assume same size for simplicity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] += rhs[i][j];
        }
    }
    return *this;
}

template<class T>
matrix<T> &matrix<T>::operator-=(T **rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] -= rhs[i][j];
        }
    }
    return *this;
}

template<class T>
matrix<T> &matrix<T>::operator*=(T **rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
            for (int k = 0; k < m; k++) {
                a[i][j] += rhs[i][j];
            }
        }
    }
    return *this;
}

template<class T>
matrix<T> &matrix<T>::operator/=(T **rhs) {
    matrix<T> t(rhs, n, m);
    (*this) *= t.inverse();
    return *this;
}


