#include "array.h"

template<class T>
array<T>::array(int n) : n(n) {
    a = new T[n];
}

template<class T>
array<T>::array(const array<T> &other) : n(other.n) {
    a = new T[n];
    for (int i = 0; i < n; i++) {
        a[i] = other.a[i];
    }
}

template<class T>
array<T>::array(const int a[], int n) : n(n), a(new T[n]) {
    for (int i = 0; i < n; i++) {
        this->a[i] = a[i];
    }
}

template<class T>
array<T>::~array() {
    delete[] a;
}

template<class T>
int array<T>::size() const {
    return n;
}

template<class T>
T *&array<T>::get() const {
    return a;
}

template<class T>
array<T> &array<T>::setSize(int n) {
    this->n = n;
    return *this;
}

template<class T>
T &array<T>::get(int i) const {
    return a[i];
}

template<class T>
void array<T>::add(int i, const T &element) {
    a[i] = element;
}

template<class T>
void array<T>::set(int i, const T &element) {
    a[i] = element;
}

template<class T>
T array<T>::average() {
    T avg = 0;
    for (auto t : a) {
        avg += t;
    }
    avg /= n;
}

template<class T>
void array<T>::print() const {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}

template<class T>
array<T> array<T>::operator-() {
    array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] = -result.a[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator+(const array<T> &rhs) {
    const array<T> result(*this);
    result += rhs;
    return result;
}

template<class T>
array<T> array<T>::operator-(const array<T> &rhs) {
    const array<T> result(*this);
    result -= rhs;
    return result;
}

template<class T>
array<T> array<T>::operator*(const array<T> &rhs) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] *= rhs.a[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator/(const array<T> &rhs) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] /= rhs.a[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator+(const T rhs[]) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] += rhs[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator-(const T rhs[]) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] -= rhs[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator*(const T rhs[]) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] *= rhs[i];
    }
    return result;
}

template<class T>
array<T> array<T>::operator/(const T rhs[]) {
    const array<T> result(*this);
    for (int i = 0; i < n; i++) {
        result.a[i] /= rhs[i];
    }
    return result;
}

template<class T>
array<T> operator+(const T lhs[], const array<T> &rhs) {
    const array<T> result(lhs);
    result += rhs;
    return result;
}

template<class T>
array<T> operator-(const T lhs[], const array<T> &rhs) {
    const array<T> result(lhs);
    result -= rhs;
    return result;
}

template<class T>
array<T> operator*(const T lhs[], const array<T> &rhs) {
    const array<T> result(lhs);
    result *= rhs;
    return result;
}

template<class T>
array<T> operator/(const T lhs[], const array<T> &rhs) {
    const array<T> result(lhs);
    result /= rhs;
    return result;
}

template<class T>
array<T> &array<T>::operator=(const array<T> &rhs) {
    delete[] a;
    n = rhs.n;
    a = new T[rhs.n];
    for (int i = 0; i < n; i++) {
        a[i] = rhs.a[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator+=(const array<T> &rhs) {
    for (int i = 0; i < n; i++) {
        a[i] += rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator-=(const array<T> &rhs) {
    for (int i = 0; i < n; i++) {
        a[i] -= rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator*=(const array<T> &rhs) {
    for (int i = 0; i < n; i++) {
        a[i] *= rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator/=(const array<T> &rhs) {
    for (int i = 0; i < n; i++) {
        a[i] /= rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator+=(const T rhs[]) {
    for (int i = 0; i < n; i++) {
        a[i] += rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator-=(const T rhs[]) {
    for (int i = 0; i < n; i++) {
        a[i] -= rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator*=(const T rhs[]) {
    for (int i = 0; i < n; i++) {
        a[i] *= rhs[i];
    }
    return *this;
}

template<class T>
array<T> &array<T>::operator/=(const T rhs[]) {
    for (int i = 0; i < n; i++) {
        a[i] /= rhs[i];
    }
    return *this;
}

template<class T>
T &array<T>::operator[](int index) const {
    return a[index];
}