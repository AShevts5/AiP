#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x, y;
    cout << "Введите x и y:" << endl;
    cin >> x >> y;
    
    if (y == 0) 
    {
        cout << "Ошибка: y не может быть равен 0" << endl;
        return 1;  // Выход из программы с кодом ошибки
    }
    
    float r = x / y;
    
    if (r < 0) 
    {
        cout << pow((x*x + y), 3);
    }
    else if (r > 0) 
    {
        // Поскольку r > 0, вместо модуля можно записать r
        cout << log(r) + r;  
    }
    else  
    { 
        cout << cbrt(sin(y));
    }
    
    return 0;
}
