#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

int main() { // главный метод программы
    int N;
    cout << "Введите размерность пространства N: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "Размерность должна быть больше 0" << endl;
        return 0;
    }
    
    // Создание массивов для хранения координат
    double V1[100]; 
    double V2[100];
    
    cout << "Введите координаты первой точки (V1):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "V1[" << i << "] = ";
        cin >> V1[i];
    }
    
    cout << "Введите координаты второй точки (V2):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "V2[" << i << "] = ";
        cin >> V2[i];
    }
    
    // Вычисление метрики r(x, y) = max |x_i - y_i|
    double max_r = 0;
    
    for (int i = 0; i < N; i++) {
        double r = V1[i] - V2[i];
        
        if (r < 0) {
            r = -r;
        }
        
        // Находим максимум
        if (r > max_r) {
            max_r = r;
        }
    }
    
    cout << "\nМетрика r(V1, V2) = max|V1[i] - V2[i]| = " << max_r << endl;
    
    return 0; // программа завершена успешно
}
