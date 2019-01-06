#include <iostream>
#include "problem-1/array.h"
#include "problem-1/array.cpp"
#include "problem-2/matrix.h"
#include "problem-2/matrix.cpp"


int main() {
    int **x = new int *[3];
    for (int i = 0; i < 3; i++) x[i] = new int[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x[i][j] = (i + 1) * (j + 1);
        }
    }

    matrix<int> a(x, 3, 3);
    matrix<int> b(a);
    array<int> c(x[0], 3);

    std::cout << "\na=\n" << a << std::endl;
    std::cout << "\nc=\n" << c << std::endl;

    std::cout << "\nc+x[0]=\n" << c + x[0] << std::endl;
    std::cout << "\nc-x[0]=\n" << c - x[0] << std::endl;
    std::cout << "\nc*x[0]=\n" << c * x[0] << std::endl;
    std::cout << "\nc/x[0]=\n" << c / x[0] << std::endl;

    std::cout << "\n~a=\n" << ~a << std::endl;

    std::cout << "\na^2=\n" << (a ^ 2) << std::endl;

    std::cout << "\na+b=\n" << a + b << std::endl;
    std::cout << "\na+x=\n" << a + x << std::endl;

    std::cout << "\na-b=\n" << a - b << std::endl;
    std::cout << "\na-x=\n" << a - x << std::endl;

    std::cout << "\na*b=\n" << a * b << std::endl;
    std::cout << "\na*x=\n" << a * x << std::endl;

    std::cout << "\na/b=\n" << a / b << std::endl;
    std::cout << "\na/x=\n" << a / x << std::endl;

    a += b;
    std::cout << "\na+=b\n" << a << std::endl;
    a += x;
    std::cout << "\na+=x\n" << a << std::endl;

    a -= b;
    std::cout << "\na-=b\n" << a << std::endl;
    a -= x;
    std::cout << "\na-=x\n" << a << std::endl;

    a *= b;
    std::cout << "\na*=b\n" << a << std::endl;
    a *= x;
    std::cout << "\na*=x\n" << a << std::endl;

    a /= b;
    std::cout << "\na/=b\n" << a << std::endl;
    a /= x;
    std::cout << "\na/=x\n" << a << std::endl;
}