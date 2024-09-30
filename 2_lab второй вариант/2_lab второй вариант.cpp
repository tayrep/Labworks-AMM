#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {
/* 23. Составьте программу для определения вида треугольника
(равносторонний, равнобедренный, разносторонний, прямоугольный,
тупоугольный, остроугольный), если по данным трем отрезкам
его можно построить */;

    setlocale(LC_ALL, "ru");
    const double EPS = 1e-12;
    float sideA, sideB, sideC, maxSide, minSide, midSide;

    cout << "Введите первую сторону треугольника: ";
    cin >> sideA;
    if (sideA == 0) {
        cout << "Введено неверное значение";
        return 0;
    }

    cout << "Введите вторую сторону треугольника: ";
    cin >> sideB;
    if (sideB == 0) {
        cout << "Введено неверное значение";
        return 0;
    }

    cout << "Введите третью сторону треугольника: ";
    cin >> sideC;
    if (sideC == 0) {
        cout << "Введено неверное значение";
        return 0;
    }

    sideA = abs(sideA);
    sideB = abs(sideB);
    sideC = abs(sideC);
    
    // Сортировка
    if (sideA > sideB + EPS) {
        maxSide = sideA;
        minSide = sideB;
    }
    else {
        minSide = sideA;
        maxSide = sideB;
    }
    if (minSide > sideC + EPS) {
        midSide = minSide;
        minSide = sideC;
    }
    else if (sideC > maxSide + EPS) {
        midSide = maxSide;
        maxSide = sideC;
    }
    else {
        midSide = sideC;
    }

    // Проверка на существование треугольника
    if (maxSide - midSide - minSide > EPS) {
        cout << "Треугольник не существует";
        return 0;
    }

    // Определение вида треугольника по равным сторонам
    if (abs(sideA - sideB) < EPS && abs(sideB - sideC) < EPS) {
        cout << "Треугольник равносторонний" << endl;
    }
    else if (abs(sideA - sideB) < EPS || abs(sideB - sideC) < EPS || abs(sideA - sideC) < EPS) {
        cout << "Треугольник равнобедренный" << endl;
    }
    else {
        cout << "Треугольник разносторонний" << endl;
    }

    // Определение вида треугольника по углам
    if (abs(maxSide*maxSide - midSide*midSide - minSide*minSide) < EPS) {
        cout << "Треугольник прямоугольный" << endl;
    }
    else if (maxSide * maxSide - midSide * midSide - minSide * minSide > EPS) {
        cout << "Треугольник тупоугольный" << endl;
    }
    else {
        cout << "Треугольник остроугольный" << endl;
    }

    return 0;
}