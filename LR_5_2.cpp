#define _CRT_SECURE_NO_WARNINGS  // убираем предупреждение про fopen (для Visual Studio)

#include <iostream>  // для cin, cout
#include <cstdlib>   // для rand, srand
#include <ctime>     // для time
#include <cstdio>    // для работы с файлами (fopen, fprintf, fclose)

using namespace std; // чтобы не писать std::

int main() {  // главный метод программы
    srand(time(0));
    
    // создание первого файла
    int size1;
    cout << "Vvedite kolichestvo chisel v pervom file: ";
    cin >> size1;
    
    // создаём массив для хранения чисел первого файла
    double* arr1 = new double[size1];
    
    // заполняем массив случайными числами от -10 до 10
    cout << "Pervyj fajl (S1.txt) do sortirovki: ";
    for (int i = 0; i < size1; i++) {
        arr1[i] = (rand() % 201 - 100) / 10.0;  // числа от -10.0 до 10.0
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // сортируем первый массив методом пузырька
    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size1 - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                double temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
    
    // записываем отсортированный массив в файл
    FILE* file1 = fopen("S1.txt", "w");
    if (file1 == nullptr) {
        cout << "Oshibka sozdanija pervogo fajla!" << endl;
        delete[] arr1;
        return 1;
    }
    
    cout << "Otsortirovannyj pervyj fajl (S1.txt): ";
    for (int i = 0; i < size1; i++) {
        fprintf(file1, "%.2f ", arr1[i]);
        cout << arr1[i] << " ";
    }
    fclose(file1);
    
    // создание второго файла
    int size2;
    cout << "Vvedite kolichestvo chisel vo vtorom file: ";
    cin >> size2;
    
    // создаём массив для хранения чисел второго файла
    double* arr2 = new double[size2];
    
    // заполняем массив случайными числами от -10 до 10
    cout << "Vtoroj fajl (S2.txt) do sortirovki: ";
    for (int i = 0; i < size2; i++) {
        arr2[i] = (rand() % 201 - 100) / 10.0;
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // сортируем второй массив методом пузырька
    for (int i = 0; i < size2 - 1; i++) {
        for (int j = 0; j < size2 - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                double temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }
    
    // записываем отсортированный массив в файл
    FILE* file2 = fopen("S2.txt", "w");
    if (file2 == nullptr) {
        cout << "Oshibka sozdanija vtorogo fajla!" << endl;
        delete[] arr1;
        delete[] arr2;
        return 1;
    }
    
    cout << "Otsortirovannyj vtoroj fajl (S2.txt): ";
    for (int i = 0; i < size2; i++) {
        fprintf(file2, "%.2f ", arr2[i]);
        cout << arr2[i] << " ";
    }
    fclose(file2);
    
    file1 = fopen("S1.txt", "r");
    file2 = fopen("S2.txt", "r");
    
    if (file1 == nullptr || file2 == nullptr) {
        cout << "Oshibka otkrytija fajlov dlya chtenija" << endl;
        delete[] arr1;
        delete[] arr2;
        return 1;
    }
    
    // создаём третий файл для записи результата
    FILE* file3 = fopen("S3.txt", "w");
    if (file3 == nullptr) {
        cout << "Oshibka sozdanija tretego fajla!" << endl;
        fclose(file1);
        fclose(file2);
        delete[] arr1;
        delete[] arr2;
        return 1;
    }
    
    cout << "\nSlivaem fails" << endl;
    
    double a, b;
    bool hasA = (fscanf(file1, "%lf", &a) == 1);
    bool hasB = (fscanf(file2, "%lf", &b) == 1);
    
    // пока есть числа в обоих файлах, сравниваем и пишем меньшее
    while (hasA && hasB) {
        if (a < b) {
            fprintf(file3, "%.2f ", a);
            hasA = (fscanf(file1, "%lf", &a) == 1);
        } else {
            fprintf(file3, "%.2f ", b);
            hasB = (fscanf(file2, "%lf", &b) == 1);
        }
    }
    
    // если остались числа в первом файле
    while (hasA) {
        fprintf(file3, "%.2f ", a);
        hasA = (fscanf(file1, "%lf", &a) == 1);
    }
    
    // если остались числа во втором файле
    while (hasB) {
        fprintf(file3, "%.2f ", b);
        hasB = (fscanf(file2, "%lf", &b) == 1);
    }
    
    // закрываем все файлы
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    cout << "\nRezultat slitija (fail S3.txt)" << endl;
    
    file3 = fopen("S3.txt", "r");
    if (file3 == nullptr) {
        cout << "Oshibka otkrytija rezultirujushchego fajla!" << endl;
        delete[] arr1;
        delete[] arr2;
        return 1;
    }
    
    double x;
    int count = 0;
    while (fscanf(file3, "%lf", &x) == 1) {
        cout << x << " ";
    }
    fclose(file3);
    
    cout << "Fajl S3.txt sozdan!" << endl;
    
    // освобождаем память
    delete[] arr1;
    delete[] arr2;
    
    return 0; // программа завершена успешно
}
