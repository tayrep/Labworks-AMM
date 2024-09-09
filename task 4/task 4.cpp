#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl; //std каждый раз нельзя((


int main()
{
    setlocale(LC_ALL, "ru"); // после функции мейн 

    int a1, a2, v1, v2, s, sumOfSpd, sumOfAcl;
    float t;

    cout << "Введите скорость первого автомобиля: ";
    cin >> v1;
    v1 = abs(v1);

    cout << "Введите скорость второго автомобиля: ";
    cin >> v2;
    v2 = abs(v2);

    cout << "Введите ускорение первого автомобиля: ";
    cin >> a1;
    a1 = abs(a1);

    cout << "Введите ускорение второго автомобиля: ";
    cin >> a2;
    a2 = abs(a2);

    cout << "Введите начальное расстояние между автомобилями: ";
    cin >> s;
    s = abs(s);

    sumOfSpd = v1 + v2;
    sumOfAcl = a1 + a2;
    t = abs(-sumOfSpd + sqrt(pow(sumOfSpd, 2) + sumOfAcl * 2 * s) / sumOfAcl); //были лишние скобки

    cout << "Время встречи автомобилей: " << t << endl;
    return 0;
}