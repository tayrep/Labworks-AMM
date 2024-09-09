#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "ru");
    int a1, a2, V1, V2, S, sumOfSpd, sumOfAcl;
    float t;

    std::cout << "Введите скорость первого автомобиля: ";
    std::cin >> V1;
    V1 = abs(V1);

    std::cout << "Введите скорость второго автомобиля: ";
    std::cin >> V2;
    V2 = abs(V2);

    std::cout << "Введите ускорение первого автомобиля: ";
    std::cin >> a1;
    a1 = abs(a1);

    std::cout << "Введите ускорение второго автомобиля: ";
    std::cin >> a2;
    a2 = abs(a2);

    std::cout << "Введите начальное расстояние между автомобилями: ";
    std::cin >> S;
    S = abs(S);

    sumOfSpd = V1 + V2;
    sumOfAcl = a1 + a2;
    t = abs((-sumOfSpd) + sqrt(pow(sumOfSpd, 2) + sumOfAcl * 2 * S) / sumOfAcl);

    std::cout << "Время встречи автомобилей: " << t << std::endl;
    return 0;
}