#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Product {
    string name;
    int day, month, year;
    double price;
};

Product* inputProducts(int n) {
    Product* products = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "Товар #" << i+1 << ":\n";
        cout << "Наименование: ";
        cin.ignore();
        getline(cin, products[i].name);

        cout << "Дата поступления (день месяц год): ";
        cin >> products[i].day >> products[i].month >> products[i].year;

        cout << "Цена: ";
        cin >> products[i].price;
    }

    return products;
}

// Функция вычисления количества месяцев между двумя датами
int monthsPassed(int day, int month, int year) {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int totalMonthsNow = now->tm_year*12 + now->tm_mon;
    int totalMonthsThen = (year - 1900)*12 + (month - 1); // tm_year с 1900, tm_mon 0-11

    return totalMonthsNow - totalMonthsThen;
}

// Функция обработки массива: снижение цены для старых товаров
void processProducts(Product* products, int n, int k, double m) {
    for (int i = 0; i < n; i++) {
        int months = monthsPassed(products[i].day, products[i].month, products[i].year);
        if (months > k) {
            products[i].price *= (1 - m/100.0);
        }
    }
}

// Функция вывода массива структур
void outputProducts(Product* products, int n) {
    cout << "\nСписок товаров:\n";
    for (int i = 0; i < n; i++) {
        cout << "Товар #" << i+1 << ":\n";
        cout << "Наименование: " << products[i].name << endl;
        cout << "Дата поступления: " << products[i].day << "/" 
             << products[i].month << "/" << products[i].year << endl;
        cout << "Цена: " << products[i].price << endl << endl;
    }
}

int main() {
    int n;
    cout << "Введите количество товаров: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: количество товаров должно быть больше 0.\n";
        return 1;
    }

    Product* products = inputProducts(n);

    int k;
    double m;
    cout << "Введите срок хранения в месяцах (k): ";
    cin >> k;
    cout << "Введите процент снижения цены (m%): ";
    cin >> m;

    processProducts(products, n, k, m);

    outputProducts(products, n);

    return 0;
}