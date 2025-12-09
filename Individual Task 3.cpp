#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    int m;
    cout << "Введите количество чисел m: ";
    cin >> m;

    // Генерация случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-2.0, 2.0); 

    vector<double> numbers(m);

    // Заполнение массива случайными числами
    for (int i = 0; i < m; ++i) {
        numbers[i] = dis(gen);
    }

    int count_zeros = 0;
    for (int i = 0; i < m; ++i) {
        if (numbers[i] == 0) {
            count_zeros++;
        } else if (numbers[i] >= -1 && numbers[i] <= 1) {
            numbers[i] = pow(numbers[i], 3);
        }
    }

    // Вывод результатов
    cout << "Количество чисел, равных 0: " << count_zeros << endl;
    cout << "Обработанный массив: ";
    for (int i = 0; i < m; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
