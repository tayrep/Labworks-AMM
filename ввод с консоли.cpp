// Задача: найти произведение указанного жанра (например, Комедия), которое понравилось больше всего. Вывести отзыв пользователя с самой высокой оценкой. 

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

//enterUserData вводит данные о пользователе
void enterUserData(userData& user, int id) {
    user.id = id;

    //name
    cout << "Введите имя пользователя: ";
    user.name = enterString();

    //sWatched
    do {
        cout << "Введите количество просмотренных произведений: ";
        cin >> user.sWatched;
    } while (user.sWatched < 0);

    //watched
    if (user.sWatched > 0) {
        user.watched = new string[user.sWatched];
        cout << "Введите названия просмотренных работ:" << endl;;
        for (int i = 0; i < user.sWatched; ++i) {
            user.watched[i] = enterString();
        }
    }

    //sFav
    do {
        cout << "Введите количество избранных произведений: ";
        cin >> user.sFav;
    } while (user.sFav < 0);

    //fav
    if (user.sFav > 0) {
        user.fav = new string[user.sFav];
        cout << "Введите названия избранных работ:" << endl;
        for (int i = 0; i < user.sFav; ++i) {
            user.fav[i] = enterString();
        }
    }
}

//enterUserReview вводит данные об отзыве пользователя на конкретную работу
void enterUserReview(work& lWork, userData* users, size_t userCount, size_t currentReview) {
    userRate newReview;
    size_t userId;

    cout << "Отзыв " << currentReview << endl;

    do {
        cout << "Введите ID пользователя (0-" << userCount - 1 << "): ";
        cin >> userId;
    } while (userId >= userCount);

    //user
    newReview.user = &users[userId];
    //watched
    newReview.watched = inArray(lWork.name, users[userId].sWatched, users[userId].watched);
    //liked
    newReview.liked = inArray(lWork.name, users[userId].sFav, users[userId].fav);

    //rate
    do {
        cout << "Введите оценку (1-10): ";
        cin >> newReview.rate;
    } while (newReview.rate < 1 || newReview.rate > 10);

    //review
    cout << "Введите отзыв: ";
    cin.ignore();
    getline(cin, newReview.review);
    newReview.review = getRidOfSpaces(newReview.review);
    cout << endl;

    //заполнение массива из оценок для произведения (lWork)
    lWork.userReviews[currentReview] = newReview;
}

//enterWorkData вводит данные о произведении
void enterWorkData(work& wk, userData* users, size_t userCount, int id) {
    int tRate, tGenre;

    //id
    wk.id = id;

    //name
    cout << "Введите название произведения: ";
    wk.name = enterString();

    //releaseYear
    do { 
        cout << "Введите год выпуска (>= 1900): ";
        cin >> wk.releaseYear;
    } while (wk.releaseYear < 1900);

    //ageRate
    do {
        cout << "Возрастной рейтинг (0 - 0+, 1 - 6+, 2 - 13+, 3 - 18+): ";
        cin >> tRate;
    } while (tRate < 0 || tRate > 3);
    wk.ageRate = static_cast<ageRating>(tRate);

    //genre
    do {
        cout << "Жанр (0 - Экшн, 1 - Фэнтези, 2 - Хоррор, 3 - Комедия, 4 - Драма, 5 - Приключения): ";
        cin >> tGenre;
    } while (tGenre < 0 || tGenre > 5);
    wk.genre = static_cast<genres>(tGenre);

    //sReviews
    cout << "Введите количество отзывов: ";
    do {
        cin >> wk.sReviews;
    } while (wk.sReviews < 0);

    //userReviews
    if (wk.sReviews != 0) {
        for (int i = 0; i < wk.sReviews; i++)
            enterUserReview(wk, users, userCount, i);
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

    //ввод массива пользователей
    cout << "Введите количество пользователей:" << endl;
    do {
        cin >> cUsers;
        cout << endl;
    } while (cUsers < 1);

    userData* users{ new userData[cUsers] };

    for (int i = 0; i < cUsers; i++)
    {
        cout << "Пользователь с id = " << i << endl;
        enterUserData(user, i);
        users[i] = user;
    }
    //ввод массива пользователей

    //ввод массива произведений
    cout << "Введите количество произведений:" << endl;
    do {
        cin >> cWorks;
        cout << endl;
    } while (cWorks < 1);

    work* works{ new work[cWorks] };

    for (int i = 0; i < cWorks; i++)
    {
        cout << "Произведение с id = i " << i << endl;
        enterWorkData(wk, users, cUsers, i);
        works[i] = wk;
    }
    //ввод массива произведений

    solution(users, cWorks, works, "Комедия"); //решение задачи

    delete[] users;
    delete[] works;

    return 0;
}