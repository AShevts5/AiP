#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов n: ";
    cin >> n;

    // Генерация случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100); // Диапазон случайных чисел от -100 до 100

    vector<int> array(n);

    // Заполнение массива случайными числами
    for (int i = 0; i < n; ++i) {
        array[i] = dis(gen);
    }

    // Поиск минимального элемента
    int min_element = array[0];
    for (int i = 1; i < n; ++i) {
        if (array[i] < min_element) {
            min_element = array[i];
        }
    }

    // Поиск последнего минимального элемента
    int last_min_index = -1;
    for (int i = 0; i < n; ++i) {
        if (array[i] == min_element) {
            last_min_index = i;
        }
    }

    // Вывод результатов
    cout << "Последовательность: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    if (last_min_index != -1) {
        cout << "Последний минимальный элемент: " << array[last_min_index] << endl;
    } else {
        cout << "Минимальный элемент не найден." << endl;
    }

    return 0;
}
