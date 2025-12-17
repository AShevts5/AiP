#include <iostream>
#include <string>
#include <sstream>
#include <cctype> //для приведения к нижнему регистру

using namespace std;

// Функция для проверки, является ли символ гласной буквой
bool isVowel(char c) {
    c = tolower(c); // Приводим к нижнему регистру для проверки
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'y' || c == 'а' || c == 'е' || c == 'и' || c == 'о' || 
            c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
}

int main() {
    string new_Str;
    
    cout << "Введите строку: ";
    getline(cin, new_Str); 
    
    stringstream ss(new_Str);
    string word;
    string result;
    bool firstWord = true; // Флаг для правильной расстановки пробелов
    
    while (ss >> word) {
        // Проверяем, начинается ли слово на гласную
        if (!isVowel(word[0])) {
            // Если это не первое слово, добавляем пробел перед ним
            if (!firstWord) {
                result += " ";
            }
            result += word;
            firstWord = false;
        }
    }
    
    cout << "Результат: " << result << endl;
    
    return 0;
}
