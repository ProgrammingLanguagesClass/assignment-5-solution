#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class array {
protected:
    T *a;
    int n;

public:
    explicit array(int n);

    array(const array<T> &other);

    array(const int a[], int n);

    virtual ~array();

    int size() const;

    T *&get() const;

    array<T> &setSize(int n);

    T &get(int i) const;

    void add(int i, const T &element);

    void set(int i, const T &element);

    T average();

    virtual void print() const;

    array<T> operator-();

    array<T> operator+(const array<T> &rhs);

    array<T> operator-(const array<T> &rhs);

    virtual array<T> operator*(const array<T> &rhs);

    array<T> operator/(const array<T> &rhs);

    array<T> operator+(const T rhs[]);

    array<T> operator-(const T rhs[]);

    array<T> operator*(const T rhs[]);

    array<T> operator/(const T rhs[]);

    array<T> &operator=(const array<T> &rhs);

    array<T> &operator+=(const array<T> &rhs);

    array<T> &operator-=(const array<T> &rhs);

    virtual array<T> &operator*=(const array<T> &rhs);

    array<T> &operator/=(const array<T> &rhs);

    array<T> &operator+=(const T rhs[]);

    array<T> &operator-=(const T rhs[]);

    array<T> &operator*=(const T rhs[]);

    array<T> &operator/=(const T rhs[]);

    T &operator[](int index) const;

    friend array<T> &operator+(const T lhs[], const array<T> &rhs);

    friend array<T> &operator-(const T lhs[], const array<T> &rhs);

    friend array<T> &operator*(const T lhs[], const array<T> &rhs);

    friend array<T> &operator/(const T lhs[], const array<T> &rhs);

    friend std::ostream &operator<<(std::ostream &out, const array<T> &rhs) {
        for (int i = 0; i < rhs.n; i++) {
            out << rhs.a[i] << " ";
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, array<T> &rhs) {
        for (int i = 0; i < rhs.n; i++) {
            in >> rhs.a[i];
        }
        return in;
    }
};

#endif
