﻿// номер 23
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");
    const double E1 = 1e-5, E2 = 1e-6;
    double x, f1, f2 = 0, f3 = 0, f4 = 0, term = 1;
    int n, n1 = 0, n2 = 0, fact = 1;

    cout << "Введите значение x: ";
    cin >> x;

    cout << "Введите количество слагаемых n: ";
    cin >> n;

    // Значение функции 
    f1 = exp(x);
    
    // Сумма f2 n слагаемых
    for (int i = 1; i <= n; i++) {
        f2 += pow(x, i - 1) / fact;
        fact *= i;
    }

    // Суммы f3 и f4 тех слагаемых, которые по модулю больше E1 и E2 соответственно и количество этих слагаемых n1 и n2
    while (abs(term) > E2) {
        if (abs(term) > E1) {
            f3 += term;
            n1++;
        }

        f4 += term;
        n2++;
        term *= x / n2;
    }

    /*
    Получившиеся n1 и n2 на 1 меньше, чем должны быть,
    т.к.первая итерация, при которой term = 1, умышленно пропущена
    (чтобы в цикле while не рассматривать случай n = 0)
    */ 
    n1++;
    n2++;


    cout << "Значение функции: " << f1 << endl;
    cout << "Сумма n слагаемых: " << f2 << endl;
    cout << "Сумма n слагаемых, по модулю больших E1 = 1e-5: " << f3 << endl;
    cout << "Количество слагаемых, по модулю больших E1 = 1e-5: " << n1 << endl;
    cout << "Сумма n слагаемых, по модулю больших E2 = 1e-6: " << f4 << endl;
    cout << "Количество слагаемых, по модулю больших E2 = 1e-6: " << n2 << endl;

    return 0;
}
