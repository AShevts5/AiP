#ifndef MONEY_H // защита от повторного включения файла
#define MONEY_H // защита от повторного включения файла
#include <iostream> // библиотека для ввода-вывода 
#include <list> // контейнер list
#include "Money.h"
using namespace std; // чтобы не писать std::

class Money
{
    private:
        long rub;    // рубли
        int kop;     // копейки (0-99)
        
    public:
        // Конструкторы
        Money()
        {
            rub = 0;
            kop = 0;
        }
        
        Money(long r, int k)
        {
            rub = r;
            kop = k;
            // Нормализация копеек
            if(kop >= 100)
            {
                rub += kop / 100;
                kop = kop % 100;
            }
            if(kop < 0)
            {
                rub -= 1;
                kop += 100;
            }
        }
        
        Money(const Money &m)
        {
            rub = m.rub;
            kop = m.kop;
        }
        
        // Методы доступа
        long get_rub() const { return rub; }
        int get_kop() const { return kop; }
        
        void set_rub(long r) { rub = r; }
        void set_kop(int k) 
        { 
            kop = k;
            if(kop >= 100)
            {
                rub += kop / 100;
                kop = kop % 100;
            }
        }
        
        // Преобразование в копейки для удобства
        long to_kop() const
        {
            return rub * 100 + kop;
        }
        
        // Оператор присваивания
        Money& operator=(const Money &m)
        {
            if(this != &m)
            {
                rub = m.rub;
                kop = m.kop;
            }
            return *this;
        }
        
        // Оператор сложения
        Money operator+(const Money &m) const
        {
            long total = to_kop() + m.to_kop();
            return Money(total / 100, total % 100);
        }
        
        // Оператор вычитания
        Money operator-(const Money &m) const
        {
            long total = to_kop() - m.to_kop();
            return Money(total / 100, total % 100);
        }
        
        // Оператор сравнения "равно"
        bool operator==(const Money &m) const
        {
            return (rub == m.rub && kop == m.kop);
        }
        
        // Оператор сравнения "больше"
        bool operator>(const Money &m) const
        {
            return to_kop() > m.to_kop();
        }
        
        // Оператор сравнения "меньше"
        bool operator<(const Money &m) const
        {
            return to_kop() < m.to_kop();
        }
        
        // Оператор деления на целое число
        Money operator/(int divisor) const
        {
            long total = to_kop() / divisor;
            return Money(total / 100, total % 100);
        }
        
        // Оператор умножения на число
        Money operator*(int mult) const
        {
            long total = to_kop() * mult;
            return Money(total / 100, total % 100);
        }
        
        // Дружественные функции ввода/вывода
        friend istream& operator>>(istream &in, Money &m);
        friend ostream& operator<<(ostream &out, const Money &m);
};

// Глобальная функция ввода
istream& operator>>(istream &in, Money &m)
{
    cout << "Введите рубли: ";
    in >> m.rub;
    cout << "Введите копейки: ";
    in >> m.kop;
    
    // Нормализация
    if(m.kop >= 100)
    {
        m.rub += m.kop / 100;
        m.kop = m.kop % 100;
    }
    
    return in;
}

// Глобальная функция вывода
ostream& operator<<(ostream &out, const Money &m)
{
    out << m.rub << " руб. " << m.kop << " коп.";
    return out;
}

#endif

typedef list<Money> ListMoney;

// Функция создания списка Money
ListMoney make_money_list(int n)
{
    ListMoney l;
    Money m;
    
    for(int i = 0; i < n; i++)
    {
        cout << "Элемент " << i+1 << ":" << endl;
        cin >> m;
        l.push_back(m);
    }
    
    return l;
}

// Функция печати списка Money
void print_money_list(ListMoney l)
{
    list<Money>::iterator it;
    int i = 0;
    for(it = l.begin(); it != l.end(); it++)
    {
        cout << "Элемент " << i++ << ": " << *it << endl;
    }
    cout << endl;
}

// Поиск элемента по ключу (возвращает итератор)
list<Money>::iterator find_money_element(ListMoney &l, Money key)
{
    list<Money>::iterator it;
    for(it = l.begin(); it != l.end(); it++)
    {
        if(*it == key)
        {
            return it;
        }
    }
    return l.end();
}

// Добавление на позицию
void add_at_position(ListMoney &l, Money el, int pos)
{
    list<Money>::iterator it = l.begin();
    for(int i = 0; i < pos && it != l.end(); i++)
    {
        it++;
    }
    l.insert(it, el);
}

int main() // главный метод программы
{
    int n;
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    
    ListMoney mylist = make_money_list(n);
    cout << "\nИсходный список:" << endl;
    print_money_list(mylist);
    
    // Задание 3: найти элемент с заданным ключом и добавить на позицию
    Money key;
    cout << "Введите ключ (сумму) для поиска:" << endl;
    cin >> key;
    
    list<Money>::iterator found = find_money_element(mylist, key);
    
    if(found != mylist.end())
    {
        cout << "Элемент " << key << " найден!" << endl;
        
        int pos;
        cout << "Введите позицию для вставки (от 0 до " << mylist.size() << "): ";
        cin >> pos;
        
        add_at_position(mylist, key, pos);
        cout << "\nСписок после добавления:" << endl;
        print_money_list(mylist);
        
        // Задание 4: удалить этот элемент
        found = find_money_element(mylist, key);
        if(found != mylist.end())
        {
            mylist.erase(found);
            cout << "Список после удаления элемента:" << endl;
            print_money_list(mylist);
        }
        
        // Задание 5: найти max-min и вычесть из каждого элемента
        if(!mylist.empty())
        {
            Money max_val = mylist.front();
            Money min_val = mylist.front();
            
            list<Money>::iterator it;
            for(it = mylist.begin(); it != mylist.end(); it++)
            {
                if(*it > max_val) max_val = *it;
                if(*it < min_val) min_val = *it;
            }
            
            Money diff = max_val - min_val;
            cout << "\nМаксимальный: " << max_val << endl;
            cout << "Минимальный: " << min_val << endl;
            cout << "Разница: " << diff << endl;
            
            // Вычитаем разницу из каждого элемента
            for(it = mylist.begin(); it != mylist.end(); it++)
            {
                *it = *it - diff;
            }
            
            cout << "\nСписок после вычитания разницы:" << endl;
            print_money_list(mylist);
        }
    }
    else
    {
        cout << "Элемент " << key << " не найден!" << endl;
    }
    
    return 0; // программа завершена успешно
}
