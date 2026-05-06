#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

// узел двусвязного списка
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
class DoubleList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // конструктор
    DoubleList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // деструктор
    ~DoubleList() {
        clear();
    }

    // добавление элемента в конец
    void add(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // удаление из списка заданных элементов 
    void removeAll(T value) {
        Node<T>* current = head;
        
        while (current != NULL) {
            if (current->data == value) {
                Node<T>* toDelete = current;
                
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                
                current = current->next;
                delete toDelete;
                size--;
            } else {
                current = current->next;
            }
        }
    }

    // определение количества различных элементов списка
    int countDistinct() {
        if (head == NULL) {
            return 0;
        }
        
        T* unique = new T[size];
        int uniqueCount = 0;
        
        Node<T>* current = head;
        
        while (current != NULL) {
            bool alreadyExists = false;
            
            for (int i = 0; i < uniqueCount; i++) {
                if (unique[i] == current->data) {
                    alreadyExists = true;
                    break;
                }
            }
            
            if (!alreadyExists) {
                unique[uniqueCount] = current->data;
                uniqueCount++;
            }
            
            current = current->next;
        }
        
        delete[] unique;
        return uniqueCount;
    }

    // вывод списка на консоль
    void print() {
        if (head == NULL) {
            cout << "Список пуст" << endl;
            return;
        }
        
        Node<T>* current = head;
        cout << "Список: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // очистка списка
    void clear() {
        Node<T>* current = head;
        while (current != NULL) {
            Node<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // получение размера
    int getSize() {
        return size;
    }
};

// функция тестирования для целых чисел
void testInt() {
    
    DoubleList<int> list;
    
    cout << "Добавляем элементы: 5, 2, 5, 8, 2, 5, 3" << endl;
    list.add(5);
    list.add(2);
    list.add(5);
    list.add(8);
    list.add(2);
    list.add(5);
    list.add(3);
    
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
    
    cout << "\nУдаляем все элементы со значением 5" << endl;
    list.removeAll(5);
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
    
    cout << "\nУдаляем все элементы со значением 2" << endl;
    list.removeAll(2);
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
}

// функция тестирования для вещественных чисел
void testDouble() {
    
    DoubleList<double> list;
    
    cout << "Добавляем элементы: 1.5, 2.7, 1.5, 3.9, 2.7, 1.5" << endl;
    list.add(1.5);
    list.add(2.7);
    list.add(1.5);
    list.add(3.9);
    list.add(2.7);
    list.add(1.5);
    
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
    
    cout << "\nУдаляем все элементы со значением 1.5" << endl;
    list.removeAll(1.5);
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
}

// функция тестирования для символов
void testChar() {
    
    DoubleList<char> list;
    
    cout << "Добавляем элементы: A, B, A, C, B, A, D" << endl;
    list.add('A');
    list.add('B');
    list.add('A');
    list.add('C');
    list.add('B');
    list.add('A');
    list.add('D');
    
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
    
    cout << "\nУдаляем все элементы со значением A" << endl;
    list.removeAll('A');
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
    
    cout << "\nУдаляем все элементы со значением B" << endl;
    list.removeAll('B');
    list.print();
    cout << "Количество различных элементов: " << list.countDistinct() << endl;
}

int main() { // главный метод программы
    
    // тестируем на разных типах данных
    testInt();
    testDouble();
    testChar();
    
    cout << "Программа завершена." << endl;
    
    return 0; // программа завершена успешно
}
