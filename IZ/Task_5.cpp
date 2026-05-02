#include <iostream> // библиотека для ввода-вывода
using namespace std; // чтобы не писать std::

// Структура для узла списка
struct Node {
    int data;
    Node* next;
};

int main() { // главный метод программы
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Количество элементов должно быть больше 0" << endl;
        return 0;
    }
    
    // Создание циклического списка
    Node* head = NULL;
    Node* tail = NULL;
    
    cout << "Введите " << n << " элементов:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Элемент " << i + 1 << ": ";
        cin >> value;
        
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Замыкаем список в кольцо
    if (tail != NULL) {
        tail->next = head;
    }
    
    // Распределение по двум линейным спискам
    Node* list1_head = NULL;
    Node* list1_tail = NULL;
    Node* list2_head = NULL;
    Node* list2_tail = NULL;
    
    int mid = n / 2;
    int firstHalfCount = mid;
    
    // Проходим по циклическому списку и распределяем
    Node* current = head;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->next = NULL;
        
        // Первая половина - в первый список
        if (i < firstHalfCount) {
            if (list1_head == NULL) {
                list1_head = newNode;
                list1_tail = newNode;
            } else {
                list1_tail->next = newNode;
                list1_tail = newNode;
            }
        } 
        // Вторая половина - во второй список
        else {
            if (list2_head == NULL) {
                list2_head = newNode;
                list2_tail = newNode;
            } else {
                list2_tail->next = newNode;
                list2_tail = newNode;
            }
        }
        
        current = current->next;
    }
    
    cout << "\nПервый список (с начала циклического):" << endl;
    Node* temp = list1_head;
    int count1 = 0;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
        count1++;
    }
    if (count1 == 0) {
        cout << "пуст";
    }
    cout << endl;
    
    cout << "Второй список (с конца циклического):" << endl;
    Node* temp2 = list2_head;
    int count2 = 0;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
        count2++;
    }
    if (count2 == 0) {
        cout << "пуст";
    }
    cout << endl;
    
    // Освобождение памяти
    if (head != NULL) {
        Node* current2 = head;
        Node* nextNode = NULL;
        tail->next = NULL;
        while (current2 != NULL) {
            nextNode = current2->next;
            delete current2;
            current2 = nextNode;
        }
    }
    
    Node* toDelete = list1_head;
    while (toDelete != NULL) {
        Node* nextNode = toDelete->next;
        delete toDelete;
        toDelete = nextNode;
    }
    
    toDelete = list2_head;
    while (toDelete != NULL) {
        Node* nextNode = toDelete->next;
        delete toDelete;
        toDelete = nextNode;
    }
    
    return 0; // программа завершена успешно
}
