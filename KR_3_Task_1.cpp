#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

// Структура для элемента очереди
struct Node {
    char computer[50];   // название компьютера
    int memory;          // объем оперативки (в ГБ)
    Node* next;          // указатель на следующий элемент
};

int main() // главный метод программы
{
    Node* head = NULL;   // начало очереди (первый элемент)
    Node* tail = NULL;   // конец очереди (последний элемент)
    int choice;
    int totalMemory = 0;
    int count = 0;
    
    do {
        cout << "\n    Меню    " << endl;
        cout << "1. Добавить компьютер в очередь" << endl;
        cout << "2. Удалить первый компьютер из очереди" << endl;
        cout << "3. Просмотреть все компьютеры в очереди" << endl;
        cout << "4. Вычислить общий объем памяти" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        if (choice == 1) {
            // Добавление элемента в конец очереди
            Node* newNode = new Node;
            newNode->next = NULL;
            
            cout << "Введите название компьютера: ";
            cin >> newNode->computer;
            
            cout << "Введите объем оперативной памяти (ГБ): ";
            cin >> newNode->memory;
            
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            
            cout << "Компьютер добавлен в очередь!" << endl;
        }
        else if (choice == 2) {
            // Удаление первого элемента из очереди
            if (head == NULL) {
                cout << "Очередь пуста!" << endl;
            } else {
                Node* temp = head;
                head = head->next;
                
                cout << "Удален компьютер: " << temp->computer 
                     << " (память: " << temp->memory << " ГБ)" << endl;
                
                delete temp;
                
                if (head == NULL) {
                    tail = NULL;
                }
            }
        }
        else if (choice == 3) {
            // Просмотр всех элементов очереди
            if (head == NULL) {
                cout << "Очередь пуста!" << endl;
            } else {
                cout << "\nСодержимое очереди " << endl;
                Node* current = head;
                int num = 1;
                
                while (current != NULL) {
                    cout << num << ". Компьютер: " << current->computer 
                         << ", ОЗУ: " << current->memory << " ГБ" << endl;
                    current = current->next;
                    num++;
                }
                cout << endl;
            }
        }
        else if (choice == 4) {
            // Вычисление общего объема памяти
            if (head == NULL) {
                cout << "Очередь пуста! Общий объем памяти: 0 ГБ" << endl;
            } else {
                totalMemory = 0;
                Node* current = head;
                
                while (current != NULL) {
                    totalMemory = totalMemory + current->memory;
                    current = current->next;
                }
                
                cout << "Общий объем оперативной памяти всех компьютеров в очереди: " 
                     << totalMemory << " ГБ" << endl;
            }
        }
        else if (choice == 0) {
            cout << "Программа завершена." << endl;
        }
        else {
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
        
    } while (choice != 0);
    
    // Освобождение памяти перед завершением программы
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0; // программа завершена успешно
}
