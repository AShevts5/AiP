#include <iostream>
#include <cstdlib>  // для функции rand()

using namespace std;

int find(int arr[], int size) {
    int lastIndex = -1;  
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            lastIndex = i;  
        }
    }
    
    return lastIndex;
}

int main() {
    const int SIZE = 15;
    int a[SIZE], b[SIZE];
    
    cout << "Заполнение массивов случайными числами: " << endl;
    
    cout << "Массив A: ";
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "Массив B: ";
    for (int i = 0; i < SIZE; i++) {
        b[i] = rand() % 101 - 50;
        cout << b[i] << " ";
    }
    cout << endl;
    
    int indexA = find(a, SIZE);
    int indexB = find(b, SIZE);
    
    cout << "Индекс последнего положительного элемента в массиве A: ";
    if (indexA != -1) {
        cout << indexA << endl;
    } else {
        cout << "не найден (нет положительных элементов)" << endl;
    }
    
    cout << "Индекс последнего положительного элемента в массиве B: ";
    if (indexB != -1) {
        cout << indexB << endl;
    } else {
        cout << "не найден (нет положительных элементов)" << endl;
    }
    
    if (indexA != -1 && indexB != -1) {
        int p = indexA * indexB;
        cout << "Произведение индексов: " << p << endl;
    } else {
        cout << "Не удалось вычислить произведение индексов, так как в одном из массивов нет положительных элементов" << endl;
    }
    
    return 0;
}
