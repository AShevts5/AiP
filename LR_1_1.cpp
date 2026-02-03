#include <iostream>
#include <climits>
using namespace std;

int main() {
    int i = -20;
    long long p = 1;
    bool overflow = false;
    
    cout << "Натуральные числа в диапазоне от -20 до 100:" << endl;
    
    do {
        if (i > 0) {
            // Проверка на переполнение перед умножением
            if (p > LLONG_MAX / i) {
                overflow = true;
                break; // Прерываем цикл при переполнении
            }
            p *= i;
            
            if (i != 100)
                cout << i << ", ";
            else
                cout << i;
        }
        i++;
    } while (i <= 100);
    
    cout << endl;
    
    if (overflow) {
        cout << "Произведение слишком велико для типа long long!" << endl;
        cout << "Частичное произведение до переполнения: " << p << endl;
    } else {
        cout << "Произведение всех натуральных чисел в интервале = " << p << endl;
    }
    
    return 0;
}
