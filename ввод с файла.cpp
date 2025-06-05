// Задача: найти произведение указанного жанра (например, Комедия), которое понравилось больше всего. Вывести отзыв пользователя с самой высокой оценкой. 

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//структура userData: id, имя, количество и список просмотренных, количество и список избранных
struct userData
{
    int id;
    string name;
    size_t sWatched;
    string* watched;
    size_t sFav;
    string* fav;
};

//перечисление ageRating показывает возрастное ограчниение
enum class ageRating{r0, r6, r13, r18};

//перечисление genres показывает жанр
enum class genres{action, fantasy, horror, comedy, drama, adventure};

//структура userRate: пользователь, просмотрено ли?, в избранном ли?, оценка, отзыв
struct userRate
{
    userData* user;
    bool watched;
    bool liked;
    int rate;
    string review;
};

//структура work (основная): id работы, название, год выпуска, возрастное огр., жанр и оценки пользователей
struct work
{
    int id;
    string name;
    int releaseYear;
    ageRating ageRate;
    genres genre;
    size_t sReviews;
    userRate* userReviews;
};

//inArray проверяет, находится ли строка в массиве (не учитывая регистр)
bool inArray(string str, size_t size, string* array)
{
    size_t i = 0;
    bool found = false;
    while (!found && i < size)
    {
        if (str.size() == array[i].size())
        {
            found = true;
            size_t j = 0;
            while (found && j < str.length())
            {
                if (tolower(str[j]) != tolower(array[i][j]))
                    found = false;
                j++;
            }
        }
        i++;
    }

    return found;
}

//getRidOfSpacesL убирает пробелы слева строки
string getRidOfSpacesL(string str)
{
    if (!str.empty()) {
        string substr = "";
        int left = 0;
        while (isspace(str[left]))
            left++;

        for (int i = left; i <= str.size() - 1; i++)
            substr += str[i];

        return substr;
    }
    else {
        return str;
    }
}

//getRidOfSpacesR убирает пробелы справа строки
string getRidOfSpacesR(string str)
{
    if (!str.empty()) {
        string substr = "";
        int right = str.size() - 1;
        while (isspace(str[right]))
            ight--;

        for (int i = 0; i <= right; i++)
            substr += str[i];

        return substr;
    }
    else {
        return str;
    }
}

//getRidOfSpaces убирает пробелы справа и слева строки
string getRidOfSpaces(string str)
{
    string result = getRidOfSpacesR(getRidOfSpacesL(str));
    return result;
}

//enterString вводит непустую строку, убирая пробелы справа и слева
string enterString()
{
    string str;
    do
    {
        cin >> str;
        cout << endl;
        str = getRidOfSpaces(str);
        if (str.empty())
            cout << "Строка пустая" << endl;
    } while (str.empty());

    return str;
}

//getAgeRating возвращает возрастное огранич. (0 - 0+, 1 - 6+, 2 - 13+, 3 - 18+)
string getAgeRating(ageRating ageRate)
{
    string res;
    switch (ageRate) {
        case ageRating::r0:
            res = "Нет возрастных ограничений";
            break;
        case ageRating::r6:
            res = "Разрешен просмотр с 6 лет";
            break;
        case ageRating::r13:
            res = "Разрешен просмотр с 13 лет";
            break;
        case ageRating::r18:
            res = "Разрешен просмотр с 18 лет";
            break;
        default:
            res = "Данные введены неверно.";
    }

    return res;
}

//getGenre возвращает жанр (0 - Экшн, 1 - Фэнтези, 2 - Хоррор, 3 - Комедия, 4 - Драма, 5 - Приключения)
string getGenre(genres genre)
{
    string res;
    switch (genre) {
        case genres::action:
            res = "Экшн";
            break;
        case genres::fantasy:
            res = "Фэнтези";
            break;
        case genres::horror:
            res = "Хоррор";
            break;
        case genres::comedy:
            res = "Комедия";
            break;
        case genres::drama:
            res = "Драма";
            break;
        case genres::adventure:
            res = "Приключения";
            break;
        default:
            res = "Данные введены неверно.";
    }

    return res;
}

int readData(const string& filename, work* works, userData* users)
{
    int rating, genre, cUsers, cWorks;
    size_t watchedCount, favCount, reviewsCount, userId;
    userData u;
    work w;
    userRate uR;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return -1;
    }

    //Первые две строки содержат количество пользователей и работ
    file >> cUsers;
    file >> cWorks;

    // Данные пользователей
    for (int i = 0; i < usersSize; i++) {
        u.id = i;

        file.ignore();
        getline(file, u.name);

        // Чтение просмотренных
        file >> watchedCount;
        for (size_t j = 0; j < watchedCount; j++) {
            file.ignore();
            getline(file, u.watched[j]);
        }

        // Чтение избранного
        file >> favCount;
        for (size_t j = 0; j < favCount; j++) {
            file.ignore();
            getline(file, u.fav[j]);
        }

        users[i] = u;
    }

    //Данные произведений
    for (int i = 0; i < worksSize; i++) {
        w.id = i;

        file.ignore();
        getline(file, w.name);

        file >> w.releaseYear;

        file >> rating;
        w.ageRate = static_cast<ageRating>(rating);

        file >> genre;
        w.genre = static_cast<genres>(genre);

        // Чтение отзывов
        file >> w.sReviews;
        for (int j = 0; j < w.sReviews; j++) {
            file >> userId;
            uR.user = &users[userId];

            file >> uR.watched;
            file >> uR.liked;
            file >> uR.rate;

            file.ignore();
            getline(file, uR.review);

            w.userReviews[j] = uR;
        }

        works[i] = w;
    }
}

//solution возвращает отзыв пользователя с самой высокой оценкой самого популярного произведения выбранного жанра (условие задачи)
string solution(userData* users, size_t workDataSize, work* works, string lGenre)
{
    int counter, maxCount = -1, maxID, maxRate = 0;
    string reviewOfMax;
    //поиск id произведения самого популярного произведения
    for (int i = 0; i < workDataSize; i++) {
        counter = 0;
        if (getGenre(works[i].genre) == lGenre) {
            for (int j = 0; j < works[i].sReviews; j++) {
                if (works[i].userReviews[j].liked)
                    counter++;
            }
        }
        if (counter > maxCount) {
            maxCount = counter;
            maxID = works[i].id;
        }
    }

    //поиск пользователя с самой высокой оценкой найденного произведения
    for (int i = 0; i < works[maxID].sReviews; i++) {
        if (works[maxID].userReviews[i].rate > maxRate) {
            reviewOfMax = works[maxID].userReviews[i].review;
            maxRate = works[maxID].userReviews[i].rate;
        }
    }

    return reviewOfMax;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int cWorks, cUsers;
    userData user;
    work wk;

    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return -1;
    }

    file >> cUsers;
    userData* users{ new userData[cUsers] };

    file >> cWorks;
    work* works{ new work[cWorks] };

    if(readData("data.txt", works, users) == 0)
        solution(users, cWorks, works, "Комедия"); //решение задачи

    delete[] users;
    delete[] works;

    return 0;
}