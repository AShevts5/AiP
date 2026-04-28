#include <iostream> // библиотека для ввода-вывода
#include <queue> // очередь
#include <vector> // контейнер вектор
using namespace std; // чтобы не писать std::

typedef priority_queue<double> PQueue;
typedef vector<double> Vec;

// копирование очереди в вектор
Vec copy_pqueue_to_vector(PQueue pq)
{
    Vec v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

// копирование вектора в очередь
PQueue copy_vector_to_pqueue(Vec v)
{
    PQueue pq;
    for (int i = 0; i < (int)v.size(); i++)
    {
        pq.push(v[i]);
    }
    return pq;
}

// создание очереди
PQueue make_pqueue(int n)
{
    PQueue pq;
    double a;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> a;
        pq.push(a);
    }
    return pq;
}

// печать очереди
void print_pqueue(PQueue pq)
{
    if (pq.empty())
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    
    Vec v = copy_pqueue_to_vector(pq);
    cout << "Содержимое очереди: ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// поиск элемента
bool find_in_pqueue(PQueue pq, double key)
{
    Vec v = copy_pqueue_to_vector(pq);
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
}

// ЗАДАНИЕ 3: добавить элемент на позицию
void add_to_pqueue(PQueue& pq, double el, int pos)
{
    Vec v = copy_pqueue_to_vector(pq);
    
    if (pos < 0) pos = 0;
    if (pos > (int)v.size()) pos = v.size();
    
    v.insert(v.begin() + pos, el);
    pq = copy_vector_to_pqueue(v);
}

// ЗАДАНИЕ 4: удалить элемент по ключу
void delete_from_pqueue(PQueue& pq, double key)
{
    Vec v = copy_pqueue_to_vector(pq);
    Vec res;
    
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] != key)
        {
            res.push_back(v[i]);
        }
    }
    
    pq = copy_vector_to_pqueue(res);
}

// ЗАДАНИЕ 5: максимальный элемент
double max_in_pqueue(PQueue pq)
{
    Vec v = copy_pqueue_to_vector(pq);
    double m = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] > m)
        {
            m = v[i];
        }
    }
    return m;
}

// минимальный элемент
double min_in_pqueue(PQueue pq)
{
    Vec v = copy_pqueue_to_vector(pq);
    double m = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    return m;
}

// вычитание из всех элементов
void vychest_from_pqueue(PQueue& pq, double val)
{
    Vec v = copy_pqueue_to_vector(pq);
    Vec res;
    
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
        
        PQueue pq = make_pqueue(n);
        
        cout << "\nИсходная очередь:" << endl;
        print_pqueue(pq);
        
        // ЗАДАНИЕ 3
        double key;
        cout << "Введите элемент для поиска и добавления: ";
        cin >> key;
        
        if (find_in_pqueue(pq, key))
        {
            cout << "Элемент " << key << " найден" << endl;
            
            int pos;
            cout << "Введите позицию для добавления: ";
            cin >> pos;
            
            add_to_pqueue(pq, key, pos);
            cout << "После добавления:" << endl;
            print_pqueue(pq);
        }
        else
        {
            cout << "Элемент " << key << " не найден!" << endl;
        }
        
        // ЗАДАНИЕ 4
        cout << "Введите элемент для удаления: ";
        cin >> key;
        
        if (find_in_pqueue(pq, key))
        {
            cout << "Элемент " << key << " найден" << endl;
            delete_from_pqueue(pq, key);
            cout << "После удаления:" << endl;
            print_pqueue(pq);
        }
        else
        {
            cout << "Элемент " << key << " не найден!" << endl;
        }
        
        // ЗАДАНИЕ 5
        
        if (!pq.empty())
        {
            double max_val = max_in_pqueue(pq);
            double min_val = min_in_pqueue(pq);
            double razn = max_val - min_val;
            
            cout << "Максимальный элемент: " << max_val << endl;
            cout << "Минимальный элемент: " << min_val << endl;
            cout << "Разница (max - min): " << razn << endl;
            
            vychest_from_pqueue(pq, razn);
            cout << "После вычитания разницы:" << endl;
            print_pqueue(pq);
        }
        else
        {
            cout << "Очередь пуста!" << endl;
        }
    }
    catch(int)
    {
        cout << "Ошибка!" << endl;
    }
    
    return 0; // программа завершена успешно
}
