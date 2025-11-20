#include <iostream>
#include "crane.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Crane crane;

    int choice;
    while (true) {
        system("clear");

        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Включить кран\n";
        cout << "2. Выключить кран\n";
        cout << "3. Повернуть стрелу\n";
        cout << "4. Поднять груз\n";
        cout << "5. Опустить груз\n";
        cout << "6. Показать состояние\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        system("clear");

        if (choice == 0) break;

        switch (choice) {
            case 1: 
                crane.turnOn();
                break;
            case 2: 
                crane.turnOff();
                break;
            case 3: {
                int angle;
                cout << "Введите угол: ";
                cin >> angle;
                crane.rotate(angle);
                break;
            }
            case 4: {
                int w;
                cout << "Введите вес груза: ";
                cin >> w;
                crane.raiseLoad(w);
                break;
            }
            case 5: 
                crane.dropLoad();
                break;
            case 6: 
                crane.status();
                break;
            default: 
                cout << "Ошибка ввода!\n";
        }
    }

    return 0;
}
