#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");
    float x, y;

    cout << "Введите координату (x) точки на плоскости: ";
    cin >> x;
    cout << "Введите координату (y) той же точки: ";
    cin >> y;

    if (x * x + y * y <= 4 && (x <= 0 || y >= 2 * x)) {
        cout << "Принадлежит" << endl;
    }
    else {
        cout << "Не принадлежит" << endl;
    }
}