#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

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
    userData user;
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
    userRate userSection;
};

//inArray проверяет, находится ли строка в массиве (не учитывая регистр)
bool inArray(string name, size_t size, string* array)
{
    int i = 0;
    bool res = false;
    while (!res && i < size)
    {
        if (name.size() == array[i].size())
        {
            res = true;
            for (int j = 0; j < name.size(); j++)
            {
                if (tolower(name[j]) != tolower(array[i][j]))
                    res = false;
            }
        }

        i++;
    }

    return res;
}

//getRidOfSpacesL убирает пробелы слева строки
string getRidOfSpacesL(string str)
{
    string substr = "";
    int left = 0;
    while (isspace(str[left]))
        left++;

    for (int i = left; i <= str.size() - 1; i++)
        substr += str[i];

    return substr;
}

//getRidOfSpacesL убирает пробелы справа строки
string getRidOfSpacesR(string str)
{
    string substr = "";
    int right = str.size() - 1;
    while (isspace(str[right]))
        right--;

    for (int i = 0; i <= right; i++)
        substr += str[i];

    return substr;
}

//getAgeRating возвращает возрастное огранич.
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

//getGenre возвращает жанр
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

//printUserReview выводит произведение, отзыв и оценку пользователя
void printUserReview(work lWork)
{
    string lwatched, lgenre, lageRate;
    lgenre = getGenre(lWork.genre);
    lageRate = getAgeRating(lWork.ageRate);
    if (lWork.userSection.watched)
        lwatched = "Просмотрено";
    else
        lwatched = "Не просмотрено";

    cout << "Произведение: " << lWork.name << endl
        << "Вышло в: " << lWork.releaseYear << " году" << endl
        << "Жанр: " << lgenre << endl
        << lageRate << endl
        << "---Отзыв пользователя---" << endl
        << "Имя: " << lWork.userSection.user.name << endl
        << "Просмотрено?: " << lwatched << endl
        << "Оценка: " << lWork.userSection.rate << endl
        << "Отзыв: " << lWork.userSection.review << endl;
}

//printUserData выводит данные пользователя
void printUserData(userData lUser)
{
    cout << "Имя: " << lUser.name << endl;
    cout << "Просмотрено: ";
    for (int i = 0; i < lUser.sWatched; i++)
        cout << lUser.watched[i] << " ";
    cout << "В избранном: ";
    for (int i = 0; i < lUser.sFav; i++)
        cout << lUser.fav[i] << " ";
}

//enterWorkData вводит данные о произведении
void enterWorkData(string &workName, int &releaseYear, int &nAgeRate, int &nGenre, ageRating &lageRate, genres &lgenre)
{
    cout << "Введите название произведения: ";
    getline(cin, workName);
    workName = getRidOfSpacesR(getRidOfSpacesL(workName));
    cout << endl;

    do {
        cout << "Введите год выпуска: ";
        cin >> releaseYear;
        cout << endl;
    } while (releaseYear < 1900);

    do {
        cout << "Введите возрастной рейтинг (0 - 0+, 1 - 6+, 2 - 13+, 3 - 18+): ";
        cin >> nAgeRate;
        cout << endl;
    } while (nAgeRate < 0 || nAgeRate > 3);
    ageRating lageRate = static_cast<ageRating>(nAgeRate);

    do {
        cout << "Введите жанр (0 - Экшн, 1 - Фэнтези, 2 - Хоррор, 3 - Комедия, 4 - Драма, 5 - Приключения): ";
        cin >> nGenre;
    } while (nGenre < 0 || nGenre > 5);
    genres lgenre = static_cast<genres>(nGenre);
}

//enterUserData вводит данные о пользователе
void enterUserData(string& userName, int& sWatched, string* &watchedAr, int &sFav, string* &favAr)
{
    cout << "Введите имя пользователя: ";
    getline(cin, userName);
    userName = getRidOfSpacesR(getRidOfSpacesL(userName));
    cout << endl;

    do {
        cout << "Введите количество просмотренных произведений: ";
        cin >> sWatched;
        cout << endl;
    } while (sWatched < 0);

    if (sWatched > 0) {
        cout << "Введите просмотренные произведения через Enter: ";
        for (int i = 0; i < sWatched; i++) {
            getline(cin, watchedAr[i]);
            watchedAr[i] = getRidOfSpacesR(getRidOfSpacesL(watchedAr[i]));
        }
    }

    do {
        cout << "Введите количество понравившихся произведений: ";
        cin >> sFav;
        cout << endl;
    } while (sFav < 0);

    if (sFav > 0) {
        cout << "Введите понравившиеся произведения через Enter: ";
        for (int i = 0; i < sFav; i++) {
            getline(cin, favAr[i]);
            favAr[i] = getRidOfSpacesR(getRidOfSpacesL(favAr[i]));
        }
    }
}

//enterUSerReview вводит данные об оценке пользователя
void enterUserReview(string &workName, int &sWatched, string* &watchedAr, int &sFav, string* &favAr, bool& watched, bool& fav, int &rate, string &review)
{
    watched = inArray(workName, sWatched, watchedAr);
    fav = inArray(workName, sFav, favAr);

    do {
        cout << "Введите оценку (1-10): ";
        cin >> rate;
        cout << endl;
    } while (rate < 0 || rate > 10);

    cout << "Введите отзыв: ";
    getline(cin, review);
    review = getRidOfSpacesR(getRidOfSpacesL(review));
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    string workName, userName, review;
    int releaseYear, nAgeRate, nGenre, sWatched, sFav, rate, idUser = 0, idWork = 0;
    bool watched, fav;
    ageRating lageRate;
    genres lgenre;
    string* watchedAr{ new string[sWatched] };
    string* favAr{ new string[sFav] };

    enterWorkData(workName, releaseYear, nAgeRate, nGenre, lageRate, lgenre);
    enterUserData(userName, sWatched, watchedAr, sFav, favAr);
    enterUserReview(workName, sWatched, watchedAr, sFav, favAr, watched, fav, rate, review);

    idUser++;
    idWork++;

    userData user1 = { idUser, userName, sWatched, watchedAr, sFav, favAr };
    userRate userRate1 = { user1, watched, fav, rate, review };
    work work1 = { idWork, workName, releaseYear, lageRate, lgenre, userRate1 };

    delete[] watchedAr;
    delete[] favAr;

    return 0;
}