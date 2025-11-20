#include "crane.h"

Crane::Crane(int h) {
    height = h;
    rotationAngle = 0;
    loadWeight = 0;
    isWorking = false;
}

void Crane::turnOn() {
    isWorking = true;
    cout << "Кран включен.\n";
    
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

void Crane::turnOff() {
    if (loadWeight > 0) {
        cout << "Нельзя выключить кран с грузом!\n";
        return;
    }
    isWorking = false;
    cout << "Кран выключен.\n";

    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

void Crane::rotate(int angle) {
    if (!isWorking) {
        cout << "Кран выключен — поворот невозможен.\n";
        return;
    }
    rotationAngle = (rotationAngle + angle) % 360;
    cout << "Кран повернут. Новый угол: " << rotationAngle << "°\n";
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

void Crane::raiseLoad(int weight) {
    if (!isWorking) {
        cout << "Кран выключен — поднять груз нельзя.\n";
        return;
    }
    if (weight < 0 || weight > 5000) {
        cout << "Недопустимый вес!\n";
        return;
    }
    loadWeight = weight;
    cout << "Груз поднят (" << weight << " кг).\n";
    
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

void Crane::dropLoad() {
    if (loadWeight == 0) {
        cout << "Груз не поднят.\n";
        return;
    }
    cout << "Груз опущен (" << loadWeight << " кг).\n";
    loadWeight = 0;
    
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

void Crane::status() const {
    cout << "\n===== Состояние крана =====\n";
    cout << "Высота: " << height << " м\n";
    cout << "Угол поворота: " << rotationAngle << "°\n";
    cout << "Груз: " << loadWeight << " кг\n";
    cout << "Состояние: " << (isWorking ? "Работает" : "Выключен") << "\n";
    cout << "============================\n\n";
    
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}
