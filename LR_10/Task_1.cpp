#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

// Структура узла 
struct Node {
    int data;        // значение элемента
    Node* next;      // указатель на следующий узел
};

// Функция добавления элемента в конец списка
void addLast(Node*& head, int value) {
    // создаем новый узел
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    
    // если список пуст, новый узел становится головой
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // иначе идем в конец списка
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // прикрепляем новый узел в конец
    current->next = newNode;
}

// Функция вывода списка на экран
void printList(Node* head) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция поиска первого четного элемента
Node* find(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {
            return current;  
        }
        current = current->next;
    }
    
    return NULL; 
}

// Функция очистки списка (освобождение памяти)
void clearList(Node*& head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
}

int main() { // главный метод программы
    Node* head = NULL;  // указатель на первый элемент списка
    int value;
    char choice;
    
    cout << "Введите элементы списка: " << endl;
    
    // Ввод элементов и занесение их в список
    do {
        cout << "Введите число: ";
        cin >> value;
        
        addLast(head, value);
        
        cout << "Продолжить ввод? (да/нет): ";
        cin >> choice;
        
    } while (choice == 'да' || choice == 'нет');
    
    // Вывод состояния списка после завершения ввода
    cout << "\nСписок после ввода: ";
    printList(head);
    
    // Обработка списка по варианту
    Node* evenNode = findFirstEven(head);
    
    // Вывод состояния списка после обработки
    if (evenNode != NULL) {
        cout << "Первый четный элемент списка: " << evenNode->data << endl;
    } else {
        cout << "В списке нет четных элементов" << endl;
    }
    
    // Очистка списка перед выходом из программы
    clearList(head);
    cout << "\nПамять очищена. Программа завершена." << endl;
    
    return 0; // программа завершена успешно
}
