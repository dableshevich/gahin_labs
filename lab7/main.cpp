#include <iostream>
#include <algorithm>

using namespace std;

double* inputArray(int length, char name) {
    double* arr = new double[length];
    cout << "Введите элементы массива " << name << ":" << endl;
    for (int i = 0; i < length; ++i) {
        cout << name << "[" << i + 1 << "] = ";
        cin >> arr[i]; 
    }

    return arr;
}

double* formArray(double* arr1, double* arr2, double d, int length) {
    double* resArr = new double[length];
    for (int i = 0; i < length; i++) {
        resArr[i] = max({arr1[i], arr2[i], d}) / 2;
    }

    return resArr;
}

void printArray(char name, double* arr, int length) {
    cout << "Массив " << name << ": ";
    for (int i = 0; i < length; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    double d;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите произвольное число d: ";
    cin >> d;

    double* a = inputArray(n, 'A');
    double* b = inputArray(n, 'B');
    double* c = inputArray(n, 'C');
    double* x = formArray(a, b, d, n);
    double* y = formArray(b, c, d, n);
    

    printArray('A', a, n);
    printArray('B', b, n);
    printArray('C', c, n);
    cout << "-----------------" << endl;
    printArray('X', x, n);
    printArray('Y', y, n);

    return 0;
}