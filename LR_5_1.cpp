#define _CRT_SECURE_NO_WARNINGS // чтобы безопасно использовать fopen()

#include <iostream>  // библиотека для ввода-вывода
#include <cstdlib>   // библиотека для rand() и srand()
#include <ctime>     // библиотека для time()
#include <cstdio>    // библиотека для работы с файлами

using namespace std; // чтобы не писать std::

int main() { // главный метод программы
    /*
    
    // Подключаем генератор случайных чисел
    srand(time(0));
    
    // Часть 1: (задание на одномерный массив)

    int n;
    cout << "Vvedite razmer massiva n: ";
    cin >> n;

    // Создаем массив и заполняем случайными вещественными числами от -10 до 10
    double* arr = new double[n];
    cout << "Ishodniy massiv:" << endl;
    for (int i = 0; i < n; i++) {
        // Генерируем число от -100 до 100, затем делим на 10, чтобы получить -10.0 ... 10.0
        arr[i] = (rand() % 201 - 100) / 10.0;
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ищем максимальный отрицательный элемент
    double maxN = -100000000000000; 

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (arr[i] > maxN) {
                maxN = arr[i];
            }
        }
    }

    // Выводим результат
    if (maxN != -100000000000000) {
        cout << "Max otriz element: " << maxN << endl;
    }
    else {
        cout << "Otriz elementov net" << endl;
    }

    // Сортировка пузырьком по возрастанию
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Otsortirovanniy massiv:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Применение бинарного поиска 
    double key;
    cout << "Введите число для поиска в отсортированном массиве: ";
    cin >> key;
    
    int left = 0;
    int right = n - 1;
    int index = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            index = mid;
            break;
        }
        
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (index != -1) {
        cout << "Число " << key << " найдено на позиции " << index << endl;
    } else {
        cout << "Число " << key << " не найдено в массиве" << endl;
    }
        
    // Сохраняем результаты первой части в файл
    FILE* file1 = fopen("array1_results.txt", "w");
    if (file1 != nullptr) {
        fprintf(file1, "Ishodniy massiv:\n");
        for (int i = 0; i < n; i++) {
            fprintf(file1, "%.2f ", arr[i]);
        }

        fprintf(file1, "Max otriz element: ");
        if (maxN != -100000000000000) {
            fprintf(file1, "%.2f\n", maxN);
        }
        else {
            fprintf(file1, "net otriz elementov\n");
        }

        fprintf(file1, "Otsortirovanniy massiv:\n");
        for (int i = 0; i < n; i++) {
            fprintf(file1, "%.2f ", arr[i]);
        }
        fprintf(file1, "\n");

        fclose(file1);
        cout << "Rezultati chasti 1 sohraneni v fail array_results.txt" << endl;
    }
    else {
        cout << "Oshibka sozdaniya faila dlya chasti 1" << endl;
    }
    
    
    // сохранение данных, полученных в процессе бинарного поиска, в тот же файл
    
    file1 = fopen("array1_results.txt", "a"); 
    if (file1 != nullptr) {
        fprintf(file1, "\nБинарный поиск\n");
        fprintf(file1, "Искомое число: %.2f\n", key);
        if (index != -1) {
            fprintf(file1, "Число найдено на позиции %d\n", index);
        } else {
            fprintf(file1, "Число не найдено\n");
        }
        fclose(file1);
    }

    delete[] arr; // освобождаем память

    return 0;

    */
    
    // Часть 2: матрица

    int size;
    cout << "Введите размер квадратной матрицы: ";
    cin >> size;

    // Создаем матрицу
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    // Заполняем матрицу случайными целыми числами от -5 до 10
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 16 - 5; // числа от -5 до 10
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Произведение элементов в строках с отрицательными элементами
    cout << "\nПроизведения элементов в строках, содержащих отрицательные элементы:" << endl;
    FILE* file2 = fopen("matrix_results.txt", "w");

    if (file2 != nullptr) {
        fprintf(file2, "Исходная матрица:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fprintf(file2, "%d\t", matrix[i][j]);
            }
            fprintf(file2, "\n");
        }
        fprintf(file2, "\n");

        bool has_negative_rows = false;
        for (int i = 0; i < size; i++) {
            // Проверяем, есть ли в строке отрицательные элементы
            bool has_negative = false;
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] < 0) {
                    has_negative = true;
                    break;
                }
            }

            if (has_negative) {
                // Вычисляем произведение элементов строки
                long long product = 1; // используем long long, чтобы избежать переполнения
                for (int j = 0; j < size; j++) {
                    product *= matrix[i][j];
                }

                cout << "Строка " << i << ": " << product << endl;
                fprintf(file2, "Строка %d: произведение = %lld\n", i, product);
                has_negative_rows = true;
            }
        }

        if (!has_negative_rows) {
            cout << "Нет строк с отрицательными элементами" << endl;
            fprintf(file2, "Нет строк с отрицательными элементами\n");
        }

        // Поиск максимума на главной диагонали
        int max_diag = matrix[0][0];
        int max_row = 0;

        for (int i = 1; i < size; i++) {
            if (matrix[i][i] > max_diag) {
                max_diag = matrix[i][i];
                max_row = i;
            }
        }

        cout << "\nМаксимальный элемент на главной диагонали: " << max_diag << endl;
        cout << "Он находится в строке " << max_row << endl;

        fprintf(file2, "\nМаксимальный элемент на главной диагонали: %d\n", max_diag);
        fprintf(file2, "Строка с этим элементом: %d\n", max_row);

        // Заменяем нулями строку, где найден максимальный элемент
        for (int j = 0; j < size; j++) {
            matrix[max_row][j] = 0;
        }

        cout << "\nМатрица после замены " << max_row << "-й строки нулями:" << endl;
        fprintf(file2, "\nМатрица после замены %d-й строки нулями:\n", max_row);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << "\t";
                fprintf(file2, "%d\t", matrix[i][j]);
            }
            cout << endl;
            fprintf(file2, "\n");
        }

        fclose(file2);
    }
    else {
        cout << "Ошибка создания файла для части 2" << endl;
    }

    // Освобождаем память матрицы
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0; // программа завершена успешно
}
