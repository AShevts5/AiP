#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

const int max_size = 100; // максимальный размер стека

int main() { // главный метод программы

    int stack[max_size]; // массив для хранения стека
    int top = -1;        // вершина стека 
    int value;
    char choice;

    cout << "Введите элементы стека (по одному). Для завершения введите 'n'." << endl;
    while (true) {
        if (top + 1 >= max_size) {
            cout << "Стек переполнен!" << endl;
            break;
        }
        cout << "Введите число: ";
        cin >> value;
        top++;
        stack[top] = value;
        
        cout << "Продолжить? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    
    cout << "\nСостояние стека: ";
    if (top == -1) {
        cout << "Стек пуст" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    
    // найти первый четный элемент 
    int firstEven = -1; 
    int evenIndex = -1;
    
    for (int i = top; i >= 0; i--) {
        if (stack[i] % 2 == 0) {
            firstEven = stack[i];
            evenIndex = i;
            break; // нашли первый чётный (ближайший к вершине)
        }
    }
    
    cout << "\nРезультат обработки:" << endl;
    if (firstEven != -1) {
        cout << "Первый чётный элемент (от вершины стека): " << firstEven << endl;
        cout << "Его позиция от вершины: " << (top - evenIndex) << endl;
    } else {
        cout << "Чётных элементов в стеке нет." << endl;
    }
    
    cout << "\nСостояние стека после обработки: ";
    if (top == -1) {
        cout << "Стек пуст" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    
    // Очистка стека 
    while (top >= 0) {
        top--;
    }
    
    cout << "\nСтек очищен. Программа завершена." << endl;
    
    return 0; // программа завершена успешно
}
