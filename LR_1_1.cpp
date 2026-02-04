#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "Натуральные числа в диапазоне от -20 до 100:" << endl;
    
    int j = -20; 
    
    do {
        if (j > 0) {
            if (j != 100)
                cout << j << ", ";
            else
                cout << j;
        }
        j++;
    } while (j <= 100);
    
    cout << endl;
    
    long long p = 1;
    bool overflow = false;
    
    int i = -20; 
    
    do {
        if (i > 0) {
            if (p > LLONG_MAX / i) {
                overflow = true;
                break;
            }
            p *= i;
        }
        i++;
    } while (i <= 100);
    
    if (overflow) {
        cout << "Произведение слишком велико для типа long long!" << endl;
        cout << "Частичное произведение до переполнения: " << p << endl;
    } else {
        cout << "Произведение всех натуральных чисел в интервале = " << p << endl;
    }
    
    return 0;
}
