#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// Перечисление для статуса заказа
enum class orderStatus {inStock, shipped, delivered, cancelled};

// Структура для представления заказа
struct order
{
	string name;
	int id;
	float weight;
	float price;
	orderStatus status;
	string notes;
}; //order

// Ф-ия statusToString преобразовывает статус в строку
string statusToString(orderStatus status)
{
	switch (status)
	{
	case orderStatus::inStock:
		return "На складе";
	case orderStatus::shipped:
		return "Отправлен";
	case orderStatus::delivered:
		return "Доставлен";
	case orderStatus::cancelled:
		return "Отменен";
	default:
		return "???";
	}
}//statusToString

int main()
{
	int statusInput;
	setlocale(LC_ALL, "ru");
	order order;

	// Ввод данных
	cout << "Введите название товара: ";
	getline(cin, order.name);

	cout << "Введите ID товара: ";
	cin >> order.id;

	cout << "Введите вес товара в граммах: ";
	cin >> order.weight;

	cout << "Введите стоимость товара: ";
	cin >> order.price;

	cout << "Введите статус заказа (0 - На складе, 1 - Отправлен, 2 - Доставлен, 3 - Отменен): ";
	cin >> statusInput;
	order.status = static_cast<orderStatus>(statusInput);

	// Вывод данных
	cout << "Товар: " << order.name << endl;
	cout << "ID товара: " << order.id << endl;
	cout << "Вес товара: " << order.weight << endl;
	cout << "Стоимость товара: " << order.price << endl;
	cout << "Итоговая стоимость заказа (наценка доставки 0.3 р. за 1 грамм): " << order.price + order.weight * 0.3 << endl;
	cout << "Статус заказа: " << statusToString(order.status) << endl;

	return 0;
}