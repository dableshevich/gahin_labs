#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Функция для удаления ведущих и завершающих пробелов
wstring trim(const wstring& str) {
    size_t start = 0;
    while (start < str.length() && iswspace(str[start])) start++;

    size_t end = str.length();
    while (end > start && iswspace(str[end - 1])) end--;

    return str.substr(start, end - start);
}

// Функция подсчета гласных букв в строке
int countVowels(const wstring& str) {
    int count = 0;
    wstring vowels = L"аоуэеиюяёАУОЭЕИЮЯЁ"; // русские гласные
    for (wchar_t c : str) {
        if (vowels.find(c) != wstring::npos)
            count++;
    }
    return count;
}

// Функция ввода n строк текста
wstring* inputText(int n) {
    wstring* text = new wstring[n];
    wstring line;
    wcout << L"Введите текст (" << n << L" строк):\n";
    for (int i = 0; i < n; i++) {
        getline(wcin, line);
        text[i] = line;
    }
    return text;
}

int main() {
    // Устанавливаем локаль для корректного ввода/вывода русских символов
    setlocale(LC_ALL, "");

    int n;
    wcout << L"Введите количество строк (n <= 20): ";
    wcin >> n;
    wcin.ignore(); // очищаем символ переноса строки после числа

    if (n < 1 || n > 20) {
        wcout << L"Ошибка: n должно быть от 1 до 20.\n";
        return 1;
    }

    wstring* text = inputText(n);

    wcout << L"\nКоличество гласных в каждой строке:\n";
    for (int i = 0; i < n; ++i) {
        wstring trimmedLine = trim(text[i]);
        int vowelsCount = countVowels(trimmedLine);
        wcout << L"Строка " << (i+1) << L": " << vowelsCount << L" гласных\n";
    }

    delete[] text;
    return 0;
}
