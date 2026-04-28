#include <iostream> // библиотека для ввода-вывода
#include <queue> // очередь
#include <vector> // контейнер вектор
using namespace std; // чтобы не писать std::

template <class T>
vector<T> copy_pqueue_to_vector(priority_queue<T> pq)
{
    vector<T> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

template <class T>
priority_queue<T> copy_vector_to_pqueue(vector<T> v)
{
    priority_queue<T> pq;
    for (int i = 0; i < (int)v.size(); i++)
    {
        pq.push(v[i]);
    }
    return pq;
}

// параметризированный класс
template <class T>
class Vector
{
    priority_queue<T> pq;
    
public:
    Vector();
    Vector(int n);
    ~Vector() {};
    
    void Print();
    bool Find(T key);
    void Add(T el, int pos);
    void Del(T key);
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
        pq.push(a);
    }
}

// печать
template <class T>
void Vector<T>::Print()
{
    if (pq.empty())
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    
    vector<T> v = copy_pqueue_to_vector(pq);
    cout << "Содержимое очереди: ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// поиск
template <class T>
bool Vector<T>::Find(T key)
{
    vector<T> v = copy_pqueue_to_vector(pq);
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
}

// ЗАДАНИЕ 3: добавить на позицию
template <class T>
void Vector<T>::Add(T el, int pos)
{
    vector<T> v = copy_pqueue_to_vector(pq);
    
    if (pos < 0) pos = 0;
    if (pos > (int)v.size()) pos = v.size();
    
    v.insert(v.begin() + pos, el);
    pq = copy_vector_to_pqueue(v);
}

// ЗАДАНИЕ 4: удалить по ключу
template <class T>
void Vector<T>::Del(T key)
{
    vector<T> v = copy_pqueue_to_vector(pq);
    vector<T> res;
    
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] != key)
        {
            res.push_back(v[i]);
        }
    }
    
    pq = copy_vector_to_pqueue(res);
}

// максимальный
template <class T>
T Vector<T>::Max()
{
    vector<T> v = copy_pqueue_to_vector(pq);
    T m = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] > m)
        {
            m = v[i];
        }
    }
    return m;
}

// минимальный
template <class T>
T Vector<T>::Min()
{
    vector<T> v = copy_pqueue_to_vector(pq);
    T m = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    return m;
}

// ЗАДАНИЕ 5: max-min
template <class T>
T Vector<T>::Raznost()
{
    return Max() - Min();
}

// вычитание из всех элементов
template <class T>
void Vector<T>::Vychest(T val)
{
    vector<T> v = copy_pqueue_to_vector(pq);
    vector<T> res;
    
    for (int i = 0; i < (int)v.size(); i++)
    {
        res.push_back(v[i] - val);
    }
    
    pq = copy_vector_to_pqueue(res);
}

int main()
{
    try
    {
        int n;
        cout << "Введите количество элементов очереди: ";
        cin >> n;
        
        Vector<double> vec(n);
        
        cout << "\nИсходная очередь:" << endl;
        vec.Print();
        
        // ЗАДАНИЕ 3
        double key;
        cout << "Введите элемент для поиска и добавления: ";
        cin >> key;
        
        if (vec.Find(key))
        {
            cout << "Элемент " << key << " найден" << endl;
            
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
        
        // ЗАДАНИЕ 4
        cout << "Введите элемент для удаления: ";
        cin >> key;
        
        if (vec.Find(key))
        {
            cout << "Элемент " << key << " найден" << endl;
            vec.Del(key);
            cout << "После удаления:" << endl;
            vec.Print();
        }
        else
        {
            cout << "Элемент " << key << " не найден!" << endl;
        }
        
        // ЗАДАНИЕ 5
        
        double max_val = vec.Max();
        double min_val = vec.Min();
        double razn = vec.Raznost();
        
        cout << "Максимальный элемент: " << max_val << endl;
        cout << "Минимальный элемент: " << min_val << endl;
        cout << "Разница (max - min): " << razn << endl;
        
        vec.Vychest(razn);
        cout << "После вычитания разницы:" << endl;
        vec.Print();
    }
    catch(int)
    {
        cout << "Ошибка!" << endl;
    }
    
    return 0;
}
