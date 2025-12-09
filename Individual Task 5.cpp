#include <iostream>   
#include <random>     // Для генерации случайных чисел
#include <iomanip>    // Для форматирования вывода

using namespace std;  

int main() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100;

    //ВВОД РАЗМЕРОВ МАТРИЦ ОТ ПОЛЬЗОВАТЕЛЯ
    int rows1, cols1;  // Размеры первой матрицы
    int rows2, cols2;  // Размеры второй матрицы
    
    cout << "Введите размеры первой матрицы (строки, столбцы): ";
    cin >> rows1 >> cols1;
    
    cout << "Введите размеры второй матрицы (строки, столбцы): ";
    cin >> rows2 >> cols2;
    
    // Проверка: матрицы должны быть разного размера
    if (rows1 == rows2 && cols1 == cols2) {
        cout << "Ошибка: матрицы должны быть разного размера!" << endl;
        return 1;  // Завершаем программу с кодом ошибки
    }

    //СОЗДАНИЕ И ЗАПОЛНЕНИЕ ПЕРВОЙ МАТРИЦЫ
    // Создаем первую матрицу как двумерный динамический массив
    int** matrix1 = new int*[rows1];  // Создаем массив указателей на строки
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = new int[cols1];  // Для каждой строки создаем массив столбцов
    }
    
    cout << "\nМатрица 1 (" << rows1 << "x" << cols1 << "):" << endl;
    cout << string(cols1 * 5, '-') << endl;
    
    // Заполняем первую матрицу случайными числами
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = dis(gen);  
            cout << setw(4) << matrix1[i][j];  // Выводим с форматированием
        }
        cout << endl;  
    }
    cout << string(cols1 * 5, '-') << endl;

    //СОЗДАНИЕ И ЗАПОЛНЕНИЕ ВТОРОЙ МАТРИЦЫ
    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = new int[cols2];
    }
    
    cout << "\nМатрица 2 (" << rows2 << "x" << cols2 << "):" << endl;
    cout << string(cols2 * 5, '-') << endl;
    
    // Заполняем вторую матрицу случайными числами
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = dis(gen);
            cout << setw(4) << matrix2[i][j];
        }
        cout << endl;
    }
    cout << string(cols2 * 5, '-') << endl;

    //ВЫЧИСЛЕНИЕ ПРОИЗВЕДЕНИЯ НЕНУЛЕВЫХ ЭЛЕМЕНТОВ ДЛЯ МАТРИЦЫ 1
    long long product1 = 1;  // Используем long long для больших произведений
    bool hasNonZero1 = false;  // Флаг: были ли ненулевые элементы
    
    cout << "\nВычисляем произведение ненулевых элементов матрицы 1:" << endl;
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            if (matrix1[i][j] != 0) {  // Если элемент не равен нулю
                product1 *= matrix1[i][j];  // Умножаем произведение на элемент
                hasNonZero1 = true;  // Устанавливаем флаг
                cout << "Умножаем на " << matrix1[i][j] 
                     << ", текущее произведение: " << product1 << endl;
            }
        }
    }
    
    // Если не было ни одного ненулевого элемента, произведение = 0
    if (!hasNonZero1) {
        product1 = 0;
    }
    cout << "Итоговое произведение для матрицы 1: " << product1 << endl;

    //ВЫЧИСЛЕНИЕ ПРОИЗВЕДЕНИЯ НЕНУЛЕВЫХ ЭЛЕМЕНТОВ ДЛЯ МАТРИЦЫ 2
    long long product2 = 1;
    bool hasNonZero2 = false;
    
    cout << "\nВычисляем произведение ненулевых элементов матрицы 2:" << endl;
    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            if (matrix2[i][j] != 0) {
                product2 *= matrix2[i][j];
                hasNonZero2 = true;
                cout << "Умножаем на " << matrix2[i][j] 
                     << ", текущее произведение: " << product2 << endl;
            }
        }
    }
    
    if (!hasNonZero2) {
        product2 = 0;
    }
    cout << "Итоговое произведение для матрицы 2: " << product2 << endl;

    //СРАВНЕНИЕ ПРОИЗВЕДЕНИЙ И ВЫБОР МАТРИЦЫ
    cout << "\nСравниваем произведения:" << endl;
    cout << "Матрица 1: " << product1 << endl;
    cout << "Матрица 2: " << product2 << endl;
    
    int** selectedMatrix;  // Указатель на выбранную матрицу
    int selectedRows, selectedCols;
    string selectedName;
    
    if (product1 > product2) {
        cout << "Выбираем матрицу 1 (произведение больше)" << endl;
        selectedMatrix = matrix1;
        selectedRows = rows1;
        selectedCols = cols1;
        selectedName = "1";
    } else if (product2 > product1) {
        cout << "Выбираем матрицу 2 (произведение больше)" << endl;
        selectedMatrix = matrix2;
        selectedRows = rows2;
        selectedCols = cols2;
        selectedName = "2";
    } else {
        cout << "Произведения равны. Выбираем матрицу 1 по умолчанию." << endl;
        selectedMatrix = matrix1;
        selectedRows = rows1;
        selectedCols = cols1;
        selectedName = "1";
    }

    //ПОДСЧЕТ КОЛИЧЕСТВА ПОЛОЖИТЕЛЬНЫХ ЭЛЕМЕНТОВ В КАЖДОЙ СТРОКЕ ВЫБРАННОЙ МАТРИЦЫ
    cout << "\nАнализ выбранной матрицы " << selectedName << ":" << endl;
    cout << "Количество положительных элементов по строкам:" << endl;
    
    // Создаем массив для хранения количества положительных элементов в каждой строке
    int* positiveCount = new int[selectedRows];
    
    for (int i = 0; i < selectedRows; i++) {
        positiveCount[i] = 0;
    }
    
    // Подсчитываем положительные элементы для каждой строки
    for (int i = 0; i < selectedRows; i++) {
        cout << "Строка " << (i + 1) << ": [";
        
        for (int j = 0; j < selectedCols; j++) {
            cout << setw(4) << selectedMatrix[i][j];
            
            if (selectedMatrix[i][j] > 0) {
                positiveCount[i]++;
            }
        }
        cout << "] -> " << positiveCount[i] << " положительных элементов" << endl;
    }


    //ОСВОБОЖДЕНИЕ ПАМЯТИ 
    //Освобождаем память, выделенную для первой матрицы
    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    
    // Освобождаем память, выделенную для второй матрицы
    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    
    // Освобождаем память, выделенную для массива positiveCount
    delete[] positiveCount;
    
    return 0;
}
