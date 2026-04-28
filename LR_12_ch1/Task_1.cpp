#include <iostream> // библиотека для ввода-вывода
#include <list> // контейнер list
#include <cstdlib> // библиотека для использования рандомной функции
#include <ctime> // библиотека для функции time()

using namespace std; // чтобы не писать std::

typedef list<double> ListDouble;

ListDouble make_list(int n)
{
    ListDouble l;
    
    for(int i = 0; i < n; i++)
    {
        double a = (rand() % 1000) / 10.0;
        l.push_back(a);
    }
    
    return l;
}

void print_list(ListDouble l)
{
    // Используем итератор для прохода по списку
    list<double>::iterator it;
    for(it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// Функция поиска элемента по ключу (возвращает итератор)
list<double>::iterator find_element(ListDouble &l, double key)
{
    list<double>::iterator it;
    for(it = l.begin(); it != l.end(); it++)
    {
        if(*it == key)
        {
            return it;  // вернули позицию найденного элемента
        }
    }
    return l.end();  // не найден
}

// Функция добавления элемента на заданную позицию
void add_at_position(ListDouble &l, double el, int pos)
{
    list<double>::iterator it = l.begin();
    
    // Перемещаем итератор на нужную позицию
    for(int i = 0; i < pos && it != l.end(); i++)
    {
        it++;
    }
    
    l.insert(it, el);
}

int main()
{
    srand(time(0));
    
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    
    ListDouble mylist = make_list(n);
    cout << "Исходный список: ";
    print_list(mylist);
    
    double key;
    cout << "Введите ключ (элемент) для поиска: ";
    cin >> key;
    
    // 3: найти элемент с заданным ключом и добавить его на заданную позицию
    list<double>::iterator found = find_element(mylist, key);
    
    if(found != mylist.end())
    {
        cout << "Элемент " << key << " найден!" << endl;
        
        int pos;
        cout << "Введите позицию для вставки: ";
        cin >> pos;
        
        add_at_position(mylist, key, pos);
        cout << "Список после добавления: ";
        print_list(mylist);
    }
    else
    {
        cout << "Элемент " << key << " не найден!" << endl;
    }
    
    // 4: удалить найденный элемент
    if(found != mylist.end())
    {
        mylist.erase(found);
        cout << "Список после удаления элемента: ";
        print_list(mylist);
    }
    
    // 5: найти разницу между max и min и вычесть её из каждого элемента
    
    // Находим максимальный и минимальный элементы
    double max_val = mylist.front();
    double min_val = mylist.front();
    
    list<double>::iterator it;
    for(it = mylist.begin(); it != mylist.end(); it++)
    {
        if(*it > max_val) max_val = *it;
        if(*it < min_val) min_val = *it;
    }
    
    double diff = max_val - min_val;
    cout << "Максимальный: " << max_val << ", Минимальный: " << min_val << endl;
    cout << "Разница: " << diff << endl;
    
    // Вычитаем разницу из каждого элемента
    for(it = mylist.begin(); it != mylist.end(); it++)
    {
        *it = *it - diff;
    }
    
    cout << "Список после вычитания разницы: ";
    print_list(mylist);
    
    return 0; // программа завершена успешно
}
