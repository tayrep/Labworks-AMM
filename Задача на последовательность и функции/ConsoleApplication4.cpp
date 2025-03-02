/*
188) Элементы последовательности могут принимать целые значения от 1 до 10 000 включительно.
Определите количество пар последовательности, в которых только одно число не является трехзначным,
а элементы пары отличаются на значение, кратное минимальному трехзначному значению в последовательности,
оканчивающемуся на 11. В ответе запишите количество найденных пар, затем максимальную из сумм элементов
таких пар. В данной задаче под парой подразумевается два идущих подряд элемента последовательности.*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;

// Функция принимает на вход число и проверяет, является ли оно трехзначным
bool isThreeDigit(int pNum)
{
    bool res = pNum < 1000 && pNum > 99; 

    return res;
}

/*
Функция принимает на вход массив и его длину,
возвращает минимальное трехзначное число из массива, которое оканчивается на 11.
Если таких нет, функция вернет 10001.
*/
int findMinThreeDigitEnding11(int pA[], int pN)                                                
{
    int minThreeDigitEnding11 = 10001;

    for (int i = 0; i < pN; i++)
    {
        if (isThreeDigit(pA[i]) && pA[i] % 100 == 11 && pA[i] < minThreeDigitEnding11)
            minThreeDigitEnding11 = pA[i];
    }

    return minThreeDigitEnding11;
}

/*
Функция принимает на вход массив и его длину,
возвращает количество пар и максимальную сумму элементов пары из пар, удовлетворяющих условию задачи.
*/
int solution(int pA[], int pN, int &maxPair)
{
    int minThreeDigitEnding11 = findMinThreeDigitEnding11(pA, pN), count = 0;

    if (minThreeDigitEnding11 == 10001)
    {
        return count;
    }

    for (int i = 0; i < pN - 1; i++)
    {
        if (isThreeDigit(pA[i]) != isThreeDigit(pA[i + 1]) && abs(pA[i] - pA[i + 1]) % minThreeDigitEnding11 == 0)
        {
            count++;
            maxPair = max(maxPair, pA[i] + pA[i + 1]);
        }
    }

    return count;
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 10;
    int a[N], maxPair = 1, count;

    for (int i = 0; i < N; i++) {
        while (a[i] <= 0 || a[i] >= 10001) {
            cin >> a[i];
        }
    }

    count = solution(a, N, maxPair);

    if (count == 0)
        cout << "Таких пар не найдено";
    else
        cout << "Количество пар: " << count << endl << "Максимальная сумма элементов пары: " << maxPair << endl;

    return 0;
}
