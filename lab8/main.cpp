#include <iostream>

using namespace std;

int inputInt(int mx) {
    int n;
    cin >> n;

    if (n > mx) return mx;
    return n;
}

int** inputArray(int n, int m) {
    int** arr = new int*[n];

    cout << "Введите элементы массива (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++) {
        int* row = new int[m];
        for (int j = 0; j < m; j++) {
            cout << "arr[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> row[j];
        }
        arr[i] = row;
    }

    return arr;
}

int* formResArray(int** matrix, int n, int m, int a) {
    int* res = new int[m];
    for (int i = 0; i < m; i++) {
        int resNum = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] > a) resNum = resNum + matrix[j][i];
        }
        res[i] = resNum;
    }

    return res;
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int* arr, int length) {
    for (int i = 0; i < length; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, m, a;
    cout << "Введите количество строк: ";
    n = inputInt(5);
    cout << "Введите количество столбцов: ";
    m = inputInt(5);
    cout << "Введите произвольное число a: ";
    cin >> a;

    int** arr = inputArray(n, m);
    int* res = formResArray(arr, n, m, a);

    cout << "Матрица:" << endl;
    printMatrix(arr, n, m);
    cout << "Результат выполнения программы: ";
    printArray(res, m);

    return 0;
}