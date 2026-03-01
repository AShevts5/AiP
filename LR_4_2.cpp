#include <iostream> // библиотека для ввода-вывода
#include <cstdlib>  // библиотека для rand() и srand()
#include <ctime>    // для time()

using namespace std; //чтобы не писать std::

int main() { // главный метод программы
    // Настраиваем генератор случайных чисел
    srand(time(0));
    
    const int N = 15; // размер массива
    int X[N];       
    
    // Заполняем массив случайными числами от -20 до 20
    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        X[i] = rand() % 41 - 20;   // числа от -20 до 20
        cout << X[i] << " ";
    }
    cout << endl;
    
    
    // Сортируем массив по возрастанию (пузырьковая сортировка)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (X[j] > X[j + 1]) {
                int temp = X[j];
                X[j] = X[j + 1];
                X[j + 1] = temp;
            }
        }
    }
    
    // Выводим отсортированный массив
    cout << "Отсортированный массив по возрастанию: ";
    for (int i = 0; i < N; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
    
    // Считаем сумму положительных элементов и количество нулей
    int sumP = 0;   // сумма положительных
    int countZero = 0;     // количество нулей
    
    for (int i = 0; i < N; i++) {
        if (X[i] > 0) {
            sumP += X[i];    
        }
        if (X[i] == 0) {
            countZero++;         
        }
    }
    
    cout << "Сумма положительных элементов: " << sumP << endl;
    cout << "Количество элементов, равных 0: " << countZero << endl;
    
    // бинарный поиск
    // есть ли в массиве 0 
    cout << "Бинарный поиск (проверка наличия нуля):" << endl;
    
    int left = 0;
    int right = N - 1;
    int found = -1;  // индекс найденного нуля
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (X[mid] == 0) {
            found = mid;   // нашли ноль
            break;              // выходим из цикла
        }
        else if (X[mid] < 0) {
            left = mid + 1;     // ищем в правой половине
        }
        else {  // X[mid] > 0
            right = mid - 1;    // ищем в левой половине
        }
    }
    
    if (found != -1) {
        cout << "Индекс найденного 0:  " << found << endl;
        
        // Найдем все нули 
        // Сдвигаемся влево до первого нуля
        int firstZero = found;
        while (firstZero > 0 && X[firstZero - 1] == 0) {
            firstZero--;
        }
        
        // Сдвигаемся вправо до последнего нуля
        int lastZero = found;
        while (lastZero < N - 1 && X[lastZero + 1] == 0) {
            lastZero++;
        }
        
        cout << "Всего нулей в массиве: " << (lastZero - firstZero + 1) << endl;
        cout << "Их позиции (индексы): ";
        for (int i = firstZero; i <= lastZero; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ноль не найден в массиве" << endl;
    }
    
    return 0; // программа завершена успешно
}
