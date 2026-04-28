#include <iostream> // библиотека для ввода-вывода
#include <vector> // контейнер вектор
using namespace std; // чтобы не писать std::

// параметризированный класс Vector
template <class T>
class Vector
{
        vector<T> v;
        
    public:
        Vector();
        Vector(int n);
        ~Vector() {};
        
        void Print();
        int Find(T key);
        void Add(T el, int pos);
        void Del(int pos);
        T Max();
        T Min();
        T Raznost();
        void Vychest(T val);
};

template <class T>
Vector<T>::Vector()
{}

template <class T>
Vector<T>::Vector(int n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> a;
        v.push_back(a);
    }
}

// вывод вектора
template <class T>
void Vector<T>::Print()
{
    if (v.empty())
    {
        cout << "Вектор пуст!" << endl;
        return;
    }
    
    cout << "Содержимое вектора: ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// поиск элемента по ключу
template <class T>
int Vector<T>::Find(T key)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// добавление элемента на позицию pos
template <class T>
void Vector<T>::Add(T el, int pos)
{
    if (pos < 0) pos = 0;
    if (pos > (int)v.size()) pos = v.size();
    v.insert(v.begin() + pos, el);
}

// удаление элемента с позиции pos
template <class T>
void Vector<T>::Del(int pos)
{
    if (pos >= 0 && pos < (int)v.size())
    {
        v.erase(v.begin() + pos);
    }
}

// поиск максимального элемента
template <class T>
T Vector<T>::Max()
{
    T max = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

// поиск минимального элемента
template <class T>
T Vector<T>::Min()
{
    T min = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    return min;
}

// разница между максимальным и минимальным
template <class T>
T Vector<T>::Raznost()
{
    return Max() - Min();
}

// вычесть значение из каждого элемента
template <class T>
void Vector<T>::Vychest(T val)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        v[i] = v[i] - val;
    }
}

// главный метод программы
int main()
{
    try
    {
        int n;
        cout << "Введите количество элементов вектора: ";
        cin >> n;
        
        Vector<double> vec(n);
        
        cout << "\nИсходный вектор:" << endl;
        vec.Print();
        
        // ЗАДАНИЕ 3: найти элемент и добавить его на заданную позицию
        double key;
        cout << "Введите элемент для поиска: ";
        cin >> key;
        
        int index = vec.Find(key);
        
        if (index != -1)
        {
            cout << "Элемент " << key << " найден на позиции " << index << endl;
            
            int pos;
            cout << "Введите позицию для добавления: ";
            cin >> pos;
            
            vec.Add(key, pos);
            cout << "После добавления:" << endl;
            vec.Print();
        }
        else
        {
            cout << "Элемент " << key << " не найден!" << endl;
        }
        
        // ЗАДАНИЕ 4: найти элемент и удалить его
        cout << "Введите элемент для удаления: ";
        cin >> key;
        
        index = vec.Find(key);
        
        if (index != -1)
        {
            cout << "Элемент " << key << " найден" << endl;
            vec.Del(index);
            cout << "После удаления:" << endl;
            vec.Print();
        }
        else
        {
            cout << "Элемент " << key << " не найден!" << endl;
        }
        
        // ЗАДАНИЕ 5: max-min и вычитание из каждого элемента
        
        double max_val = vec.Max();
        double min_val = vec.Min();
        double razn = vec.Raznost();
        
        cout << "Максимальный элемент: " << max_val << endl;
        cout << "Минимальный элемент: " << min_val << endl;
        cout << "Разница (max - min): " << razn << endl;
        
        vec.Vychest(razn);
        cout << "После вычитания разницы из каждого элемента:" << endl;
        vec.Print();
    }
    catch(int)
    {
        cout << "Ошибка!" << endl;
    }
    
    return 0; // программа завершена успешно
}
