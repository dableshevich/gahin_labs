#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Функция подсчета слов в строке
int countWords(const string& line) {
    istringstream iss(line);
    int count = 0;
    string word;
    while (iss >> word) {
        count++;
    }
    return count;
}

// Функция обработки файла
void processFile(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла " << inputFile << endl;
        return;
    }

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла " << outputFile << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        int wordsCount = countWords(line);
        fout << line << " (" << wordsCount << " слов)" << endl;
    }

    fin.close();
    fout.close();
}

int main() {
    string inputFile, outputFile;
    cout << "Введите имя исходного файла: ";
    cin >> inputFile;
    cout << "Введите имя нового файла: ";
    cin >> outputFile;

    processFile(inputFile, outputFile);

    cout << "Обработка завершена. Результат записан в файл " << outputFile << endl;

    return 0;
}