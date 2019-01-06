#ifndef MATRIX_H
#define MATRIX_H

#include "../problem-1/array.h"

template<class T>
class matrix : public array<T> {
private:
    T **a;
protected:
    int n, m;

public:
    matrix(int n, int m);

    matrix(const matrix<T> &);

    matrix(int **, int n, int m);

    virtual ~matrix();

    T &get(int i, int j) const;

    matrix<T> &add(int i, int j, const T &x);

    matrix<T> &set(int i, int j, const T &x);

    matrix<T> &transpose();

    matrix<T> inverse();

    virtual void print();

    matrix<T> &operator~();

    matrix<T> operator^(int p);

    matrix<T> operator+(const matrix<T> &rhs);

    matrix<T> operator-(const matrix<T> &rhs);

    matrix<T> operator*(const matrix<T> &rhs);

    matrix<T> operator/(matrix<T> &rhs);

    matrix<T> &operator+=(const matrix<T> &rhs);

    matrix<T> &operator-=(const matrix<T> &rhs);

    matrix<T> &operator*=(const matrix<T> &rhs);

    matrix<T> &operator/=(matrix<T> &rhs);

    matrix<T> operator+(T **rhs);

    matrix<T> operator-(T **rhs);

    matrix<T> operator*(T **rhs);

    matrix<T> operator/(T **rhs);

    matrix<T> &operator+=(T **rhs);

    matrix<T> &operator-=(T **rhs);

    matrix<T> &operator*=(T **rhs);

    matrix<T> &operator/=(T **rhs);

    friend T **operator+(T **lhs, const matrix<T> &rhs) {
        matrix<T> result(rhs);
        result += lhs;
        return result.a;
    }

    friend T **operator-(T **lhs, const matrix<T> &rhs) {
        matrix<T> result(rhs);
        result -= lhs;
        return result.a;
    }

    friend T **operator*(T **lhs, const matrix<T> &rhs) {
        matrix<T> result(rhs);
        result *= lhs;
        return result.a;
    }

    friend std::ostream &operator<<(std::ostream &out, const matrix<T> &rhs) {
        for (int i = 0; i < rhs.n; i++) {
            for (int j = 0; j < rhs.m; j++) {
                out << rhs.a[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, matrix<T> &rhs) {
        for (int i = 0; i < rhs.n; i++) {
            for (int j = 0; j < rhs.m; j++) {
                in >> rhs.a[i][j];
            }
        }
        return in;
    }
};

#endif
