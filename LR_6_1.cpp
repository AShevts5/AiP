#include <iostream> // библиотека для ввода-вывода
#include <string> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

int main() { // главный метод программы

    // Определяем структуру для анкеты ребенка
    struct Child {
        string name;
        char gender;   // 'm' - мальчик, 'g' - девочка
        int height;    // рост в сантиметрах
    };
    
    const int N = 5;
    Child children[N];
    
    cout << "Введите информацию о 20 детях" << endl;
    cout << "Для каждого ребенка нужно ввести: имя пол(m/g) рост(в см)" << endl;
    cout << "Пример ввода: Мария f 145" << endl;
    cout << endl;
    
    // Ввод информации по 20 детям
    for (int i = 0; i < N; i++) {
        cout << "Ребенок " << i + 1 << ": ";
        cin >> children[i].name >> children[i].gender >> children[i].height;
    }
    
    // Найдем максимальный рост среди девочек
    int maxHeight = -1;
    bool hasGirls = false;
    
    for (int i = 0; i < N; i++) {
        if (children[i].gender == 'g' || children[i].gender == 'G') {
            hasGirls = true;
            if (children[i].height > maxHeight) {
                maxHeight = children[i].height;
            }
        }
    }
    
    // Вывод результата
    cout << endl;
    
    if (!hasGirls) {
        cout << "Среди 20 детей нет ни одной девочки" << endl;
    } else {
        cout << "Самый высокий рост среди девочек: " << maxHeight << " см" << endl;
        cout << "Девочки с таким ростом: " << endl;
        
        // Проходим по массиву и выводим всех девочек с максимальным ростом
        for (int i = 0; i < N; i++) {
            if ((children[i].gender == 'g' || children[i].gender == 'G') && children[i].height == maxHeight) {
                cout << "  - " << children[i].name << endl;
            }
        }
    }
    
    return 0; // программа завершена успешно
}
