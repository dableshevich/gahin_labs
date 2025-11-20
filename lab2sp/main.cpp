#include <iostream>
#include <string>
using namespace std;

class BankCard {
private:
    string cardNumber;
    string ownerSurname;
    int expiryYear;
    double balance;

public:
    BankCard() {
        cardNumber = "0000 0000 0000 0000";
        ownerSurname = "Unknown";
        expiryYear = 0;
        balance = 0.0;
    }

    BankCard(string number, string surname, int year, double bal) {
        cardNumber = number;
        ownerSurname = surname;
        expiryYear = year;
        balance = bal;
    }

    void setCardNumber(const string &num) { cardNumber = num; }
    void setOwnerSurname(const string &surname) { ownerSurname = surname; }
    void setExpiryYear(int year) { expiryYear = year; }
    void setBalance(double bal) { balance = bal; }

    string getCardNumber() const { return cardNumber; }
    string getOwnerSurname() const { return ownerSurname; }
    int getExpiryYear() const { return expiryYear; }
    double getBalance() const { return balance; }

    void print() const {
        cout << "Номер карты: " << cardNumber << endl;
        cout << "Фамилия владельца: " << ownerSurname << endl;
        cout << "Год окончания действия: " << expiryYear << endl;
        cout << "Остаток: " << balance << endl;
        cout << "------------------------------\n";
    }
};

// === Функция ввода одной карты ===
BankCard inputCard() {
    string num, surname;
    int year;
    double bal;

    cout << "Номер карты: ";
    getline(cin, num);
    if (num.empty()) getline(cin, num); // фикс пустой строки после cin

    cout << "Фамилия владельца: ";
    getline(cin, surname);

    cout << "Год окончания действия: ";
    cin >> year;

    cout << "Остаток: ";
    cin >> bal;
    cin.ignore();

    return BankCard(num, surname, year, bal);
}

// === Вывод массива карт ===
void printCards(BankCard cards[], int n) {
    cout << "\n=== Введённые карты ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Карта #" << i + 1 << ":\n";
        cards[i].print();
    }
}

// === Поиск индекса карты с минимальным остатком ===
int findMinBalanceIndex(BankCard cards[], int n) {
    int minIndex = 0;
    double minBalance = cards[0].getBalance();

    for (int i = 1; i < n; i++) {
        if (cards[i].getBalance() < minBalance) {
            minBalance = cards[i].getBalance();
            minIndex = i;
        }
    }
    return minIndex;
}

// === Основная программа ===
int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== Объект по умолчанию ===\n";
    BankCard defaultCard;
    defaultCard.print();

    cout << "=== Объект с параметрами ===\n";
    BankCard customCard("1111 2222 3333 4444", "Иванов", 2027, 15000.50);
    customCard.print();

    const int n = 4;
    BankCard cards[n];

    cout << "\nВведите данные для 4-х банковских карт:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nКарта " << i + 1 << ":\n";
        cards[i] = inputCard();
    }

    printCards(cards, n);

    int minIndex = findMinBalanceIndex(cards, n);

    cout << "\n=== Владелец с минимальным остатком ===\n";
    cards[minIndex].print();

    return 0;
}
