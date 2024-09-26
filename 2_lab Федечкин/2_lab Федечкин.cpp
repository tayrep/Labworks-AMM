/*23. Составьте программу для определения вида треугольника
(равносторонний, равнобедренный, разносторонний, прямоугольный,
тупоугольный, остроугольный), если по данным трем отрезкам
его можно построить*/

#include <iostream>
#include <cmath> 

using std::cout;
using std::cin;
using std::endl;

int main() {
    setlocale(LC_ALL, "ru");
    const double EPS = 1e-12;
    float sideA, sideB, sideC, sqMaxSide, sqSumOfMins;

    cout << "Введите первую сторону треугольника: ";
    cin >> sideA;

    if (sideA == 0) {
        cout << "Введена неверная величина" << endl;
    }
    else {
        cout << "Введите вторую сторону треугольника: ";
        cin >> sideB;

        if (sideB == 0) {
            cout << "Введена неверная величина" << endl;
        }
        else {
            cout << "Введите третью сторону треугольника: ";
            cin >> sideC;

            if (sideC == 0) {
                cout << "Введена неверная величина" << endl;
            }
            else {
                sideA = abs(sideA);
                sideB = abs(sideB);
                sideC = abs(sideC);

                // Проверка существования треугольника
                if (sideB + sideC - sideA < EPS || sideB + sideA - sideC < EPS || sideA + sideC - sideB < EPS) {
                    cout << "Треугольник не существует" << endl;
                }
                else {
                    // Определение типа треугольника по сторонам
                    if (abs(sideA - sideB) < EPS && abs(sideB - sideC) < EPS) {
                        cout << "Треугольник равносторонний" << endl;
                    }
                    else if (abs(sideA - sideB) < EPS || abs(sideB - sideC) < EPS || abs(sideA - sideC) < EPS) {
                        cout << "Треугольник равнобедренный" << endl;
                    }
                    else {
                        cout << "Треугольник разносторонний" << endl;
                    }

                    // Определение квадрата максимальной стороны и суммы квадратов минимальных 
                    if (sideA > sideB && sideA > sideC) {
                        sqMaxSide = sideA * sideA;
                        sqSumOfMins = sideB * sideB + sideC * sideC;
                    }
                    else if (sideB > sideA && sideB > sideC) {
                        sqMaxSide = sideB * sideB;
                        sqSumOfMins = sideA * sideA + sideC * sideC;
                    }
                    else {
                        sqMaxSide = sideC * sideC;
                        sqSumOfMins = sideA * sideA + sideB * sideB;
                    }

                    // Определение вида треугольника по углам
                    if (abs(sqMaxSide - sqSumOfMins) < EPS) {
                        cout << "Треугольник прямоугольный" << endl;
                    }
                    else if (sqMaxSide - sqSumOfMins > EPS) {
                        cout << "Треугольник тупоугольный" << endl;
                    }
                    else {
                        cout << "Треугольник остроугольный" << endl;
                    }
                }
            }
        }
    }

    return 0;
}