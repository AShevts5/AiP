// ПРИМЕР С ИСПОЛЬЗОВАНИЕМ УКАЗАТЕЛЕЙ
/*
#include <iostream>
#include <random>

using namespace std;

int main() {
    const int size = 6;          
    double* matrix[size];         
    
   
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }

    // Настройка генератора случайных чисел
    random_device rd;
    mt19937 engine(rd());
    uniform_real_distribution<double> dist(0, 100);

    // Заполнение матрицы случайными числами
    cout << "Матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = dist(engine);   // Генератор случайных чисел
            cout << matrix[i][j] << "\t";  // Вывод элемента
        }
        cout << endl;
    }

    // Вычисляем произведение элементов главной диагонали
    double product = 1.0;
    const double C = 2.5; // Произвольная константа
    for (int i = 0; i < size; i++) {
        product *= matrix[i][i];     // Перемножаем элементы главной диагонали
    }
    product *= C;                   // Умножаем результат на константу C

    // Вывод результата
    cout << "Произведение элементов главной диагонали, умноженное на C (" << C << ") равно: " << product << endl;

    // Очистка памяти
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];          // Освобождаем память
    }

    return 0;
}
*/

// ПРИМЕР БЕЗ ИСПОЛЬЗОВАНИЯ УКАЗАТЕЛЕЙ
#include <iostream>
#include <random>

using namespace std;

int main() {
    const int SIZE = 6; // размер матрицы
    const double C = 2.5; // константа

    double matrix[SIZE][SIZE];

    // настройка генератора случайных чисел
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0, 100); // диапазон случайных чисел от 0 до 100

    // заполняем матрицу случайными числами
    cout << "Исходная матрица:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = distribution(generator); // присваиваем каждому элементу случайное значение
            cout << matrix[i][j] << '\t'; // выводим элемент
        }
        cout << endl; // новая строка после заполнения строки матрицы
    }

    // находим произведение элементов главной диагонали
    double diagonal_product = 1.0; // начальное значение произведения
    for (int k = 0; k < SIZE; k++) {
        diagonal_product *= matrix[k][k]; // перемножаем элементы главной диагонали
    }

    // умножаем произведение на константу C
    diagonal_product *= C;

    // выводим результат
    cout << "Произведение элементов главной диагонали, умноженное на C(" << C << "), равно: " << diagonal_product << endl;

    return 0;
}
