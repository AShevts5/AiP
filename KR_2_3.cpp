#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    // ВВОД РАЗМЕРОВ МАТРИЦ
    int n, m, l;
    
    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов в первой матрице (m): ";
    cin >> m;
    cout << "Введите количество столбцов во второй матрице (l): ";
    cin >> l;
    
    // Проверка корректности ввода
    if (n <= 0 || m <= 0 || l <= 0) {
        cout << "Ошибка: размеры должны быть положительными числами!" << endl;
        return 1;
    }
    
    //ВВОД ПЕРВОЙ МАТРИЦЫ A(n, m)
    cout << "\n=== ВВОД ПЕРВОЙ МАТРИЦЫ A(" << n << "x" << m << ") ===" << endl;
    vector<vector<int>> A(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        cout << "Введите " << m << " элементов для строки " << (i + 1) << ": ";
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    // ВВОД ВТОРОЙ МАТРИЦЫ B(n, l)
    cout << "\n=== ВВОД ВТОРОЙ МАТРИЦЫ B(" << n << "x" << l << ") ===" << endl;
    vector<vector<int>> B(n, vector<int>(l));
    
    for (int i = 0; i < n; i++) {
        cout << "Введите " << l << " элементов для строки " << (i + 1) << ": ";
        for (int j = 0; j < l; j++) {
            cin >> B[i][j];
        }
    }
    
    //ВЫВОД ИСХОДНЫХ МАТРИЦ
    cout << "\n=== ИСХОДНЫЕ МАТРИЦЫ ===" << endl;
    
    cout << "\nМатрица A:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < m; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    
    cout << "\nМатрица B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < l; j++) {
            cout << setw(4) << B[i][j];
        }
        cout << endl;
    }
    
    //ОБЪЕДИНЕНИЕ МАТРИЦ ПО СТОЛБЦАМ
    int totalCols = m + l;
    vector<vector<int>> C(n, vector<int>(totalCols));
    
    // Копируем столбцы из матрицы A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j];
        }
    }
    
    // Копируем столбцы из матрицы B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            C[i][m + j] = B[i][j];
        }
    }
    
    cout << "\n=== МАТРИЦА ПОСЛЕ ОБЪЕДИНЕНИЯ (ДО СОРТИРОВКИ) ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < totalCols; j++) {
            cout << setw(4) << C[i][j];
        }
        cout << endl;
    }
    
    //СОРТИРОВКА СТОЛБЦОВ ПО ПЕРВОЙ СТРОКЕ
    // Создаем вектор пар: (значение из первой строки, индекс столбца)
    vector<pair<int, int>> columnInfo;
    
    for (int j = 0; j < totalCols; j++) {
        columnInfo.push_back({C[0][j], j});
    }
    
    // Сортируем пары по возрастанию значения (первого элемента пары)
    sort(columnInfo.begin(), columnInfo.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    
    // Создаем отсортированную матрицу
    vector<vector<int>> sortedC(n, vector<int>(totalCols));
    
    // Заполняем отсортированную матрицу
    for (int newCol = 0; newCol < totalCols; newCol++) {
        int oldCol = columnInfo[newCol].second;  // Получаем исходный индекс столбца
        
        // Копируем весь столбец
        for (int i = 0; i < n; i++) {
            sortedC[i][newCol] = C[i][oldCol];
        }
    }
    
    //ВЫВОД РЕЗУЛЬТАТА
    cout << "\n=== РЕЗУЛЬТАТ - ОБЪЕДИНЕННАЯ МАТРИЦА ===" << endl;
    cout << "Первая строка отсортирована по возрастанию:" << endl;
    
    // Выводим отсортированную первую строку
    cout << "Первая строка: ";
    for (int j = 0; j < totalCols; j++) {
        cout << setw(4) << sortedC[0][j];
    }
    cout << endl;
    
    // Выводим всю отсортированную матрицу
    cout << "\nВся матрица C (столбцы отсортированы по первой строке):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < totalCols; j++) {
            cout << setw(4) << sortedC[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
