#include <iostream> // библиотека для ввода-вывода
#include <cstdlib>  // библиотека для rand() 
#include <ctime>    // библиотека для time()

using namespace std;

int main() { // главный метод программы
    // Настраиваем генератор случайных чисел
    srand(time(0));
    
    const int SIZE = 15; // размер массива
    int A[SIZE];                  
    int key = 30;  // ключ для сравнения          
    
    //Заполняем массив случайными числами от 0 до 99
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 100;       // случайные числа 0..99
        cout << A[i] << " ";
    }
    cout << endl;
    
    //Сортируем массив (пузырьковая сортировка)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "Линейный поиск:" << endl;
    cout << "Элементы больше " << key << ": ";
    
    bool found = false;
    
    for (int i = 0; i < SIZE; i++) {
        if (A[i] > key) {
            cout << A[i] << " ";
            found = true;
        }
    }
    
    if (!found) {
        cout << "Нет таких элементов";
    }
    cout << endl;
    
    cout << "Бинарный поиск:" << endl;
    
    int left = 0;
    int right = SIZE - 1;
    int firstIndex = -1;    // индекс первого элемента > key
    
    // Ищем первый элемент, который больше key
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (A[mid] > key) {
            firstIndex = mid;    // запоминаем этот индекс
            right = mid - 1;     // ищем ещё левее
        } else {
            left = mid + 1;      // ищем правее
        }
    }
    
    // Выводим результат
    cout << "Элементы больше " << key << ": ";
    
    if (firstIndex == -1) {
        cout << "нет таких элементов";
    } else {
        for (int i = firstIndex; i < SIZE; i++) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    
    return 0; // программа завершена успешно
}
