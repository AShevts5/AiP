#include <iostream> // библиотека для ввода-вывода
#include <cstring> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

// Структура для хранения номеров страниц (максимум 10)
struct PageNumbers {
    int pages[10];  
    int count;     
};

// Структура узла предметного указателя
struct Node {
    char word[50];          // слово
    PageNumbers pages;      // номера страниц
    Node* next;             // указатель на следующий узел
};

// голова списка
Node* head = NULL;

// Функция для ввода номеров страниц
void inputPageNumbers(PageNumbers& pages) {
    cout << "Введите количество страниц (от 1 до 10): ";
    cin >> pages.count;
    
    while (pages.count < 1 || pages.count > 10) {
        cout << "Ошибка! Количество страниц должно быть от 1 до 10. Повторите: ";
        cin >> pages.count;
    }
    
    cout << "Введите номера страниц: ";
    for (int i = 0; i < pages.count; i++) {
        cin >> pages.pages[i];
        while (pages.pages[i] < 1) {
            cout << "Номер страницы должен быть положительным. Повторите: ";
            cin >> pages.pages[i];
        }
    }
}

// Функция вывода номеров страниц
void printPageNumbers(PageNumbers pages) {
    for (int i = 0; i < pages.count; i++) {
        cout << pages.pages[i];
        if (i < pages.count - 1) {
            cout << ", ";
        }
    }
}

// Функция поиска узла по слову 
Node* findWord(const char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Функция поиска предыдущего узла для заданного слова
Node* findPrevious(const char* word) {
    if (head == NULL) return NULL;
    
    Node* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


// Начальное формирование предметного указателя
void createIndex() {
    int numWords;
    cout << "Сколько слов вы хотите добавить в указатель? ";
    cin >> numWords;
    
    for (int i = 0; i < numWords; i++) {
        Node* newNode = new Node;
        
        cout << "\nСлово " << i + 1 << endl;
        cout << "Введите слово: ";
        cin >> newNode->word;
        
        inputPageNumbers(newNode->pages);
        newNode->next = NULL;
        
        // Добавляем в конец списка
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

//  Вывод предметного указателя
void printIndex() {
    if (head == NULL) {
        cout << "Предметный указатель пуст!" << endl;
        return;
    }
    
    cout << "\nПредметный указатель" << endl;
    Node* current = head;
    int counter = 1;
    
    while (current != NULL) {
        cout << counter << ". " << current->word << " -> страницы: ";
        printPageNumbers(current->pages);
        cout << endl;
        current = current->next;
        counter++;
    }
}

// Вывод номеров страниц для заданного слова
void findAndPrintPages() {
    if (head == NULL) {
        cout << "Указатель пуст. Сначала создайте указатель!" << endl;
        return;
    }
    
    char searchWord[50];
    cout << "Введите слово для поиска: ";
    cin >> searchWord;
    
    Node* found = findWord(searchWord);
    
    if (found != NULL) {
        cout << "Слово \"" << found->word << "\" встречается на страницах: ";
        printPageNumbers(found->pages);
        cout << endl;
    } else {
        cout << "Слово \"" << searchWord << "\" не найдено в указателе!" << endl;
    }
}

// Поиск слова с максимальным количеством номеров страниц
void findMaxPagesWord() {
    if (head == NULL) {
        cout << "Указатель пуст!" << endl;
        return;
    }
    
    Node* current = head;
    Node* maxNode = head;
    int maxCount = head->pages.count;
    
    while (current != NULL) {
        if (current->pages.count > maxCount) {
            maxCount = current->pages.count;
            maxNode = current;
        }
        current = current->next;
    }
    
    cout << "Слово с максимальным количеством страниц (" << maxCount << "): ";
    cout << maxNode->word << " -> страницы: ";
    printPageNumbers(maxNode->pages);
    cout << endl;
}

// Добавление нового слова в начало списка
void addToBeginning() {
    Node* newNode = new Node;
    
    cout << "Введите слово: ";
    cin >> newNode->word;
    inputPageNumbers(newNode->pages);
    
    newNode->next = head;
    head = newNode;
    
    cout << "Слово \"" << newNode->word << "\" добавлено в начало указателя!" << endl;
}

// Добавление нового слова в конец списка
void addToEnd() {
    Node* newNode = new Node;
    
    cout << "Введите слово: ";
    cin >> newNode->word;
    inputPageNumbers(newNode->pages);
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    cout << "Слово \"" << newNode->word << "\" добавлено в конец указателя!" << endl;
}

// Добавление нового слова в отсортированном по алфавиту порядке
void addSorted() {
    Node* newNode = new Node;
    
    cout << "Введите слово: ";
    cin >> newNode->word;
    inputPageNumbers(newNode->pages);
    
    if (head == NULL || strcmp(newNode->word, head->word) < 0) {
        newNode->next = head;
        head = newNode;
        cout << "Слово \"" << newNode->word << "\" добавлено в указатель (сортировка)!" << endl;
        return;
    }
    
    Node* current = head;
    while (current->next != NULL && strcmp(newNode->word, current->next->word) > 0) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    cout << "Слово \"" << newNode->word << "\" добавлено в указатель (сортировка)!" << endl;
}

// Добавление нового слова перед указанным словом
void addBeforeWord() {
    if (head == NULL) {
        cout << "Указатель пуст. Сначала создайте указатель!" << endl;
        return;
    }
    
    char targetWord[50];
    cout << "Введите слово, перед которым нужно добавить: ";
    cin >> targetWord;
    
    // Проверяем, существует ли целевое слово
    if (findWord(targetWord) == NULL) {
        cout << "Слово \"" << targetWord << "\" не найдено в указателе!" << endl;
        return;
    }
    
    Node* newNode = new Node;
    cout << "Введите новое слово: ";
    cin >> newNode->word;
    inputPageNumbers(newNode->pages);
    
    // Если добавляем перед первым элементом
    if (strcmp(head->word, targetWord) == 0) {
        newNode->next = head;
        head = newNode;
        cout << "Слово \"" << newNode->word << "\" добавлено перед \"" << targetWord << "\"!" << endl;
        return;
    }
    
    // Ищем предыдущий узел
    Node* prev = findPrevious(targetWord);
    if (prev != NULL) {
        newNode->next = prev->next;
        prev->next = newNode;
        cout << "Слово \"" << newNode->word << "\" добавлено перед \"" << targetWord << "\"!" << endl;
    }
}

// Добавление нового слова после указанного слова
void addAfterWord() {
    if (head == NULL) {
        cout << "Указатель пуст. Сначала создайте указатель!" << endl;
        return;
    }
    
    char targetWord[50];
    cout << "Введите слово, после которого нужно добавить: ";
    cin >> targetWord;
    
    Node* target = findWord(targetWord);
    if (target == NULL) {
        cout << "Слово \"" << targetWord << "\" не найдено в указателе!" << endl;
        return;
    }
    
    Node* newNode = new Node;
    cout << "Введите новое слово: ";
    cin >> newNode->word;
    inputPageNumbers(newNode->pages);
    
    newNode->next = target->next;
    target->next = newNode;
    
    cout << "Слово \"" << newNode->word << "\" добавлено после \"" << targetWord << "\"!" << endl;
}

// Удаление указанного слова
void deleteWord() {
    if (head == NULL) {
        cout << "Указатель пуст!" << endl;
        return;
    }
    
    char targetWord[50];
    cout << "Введите слово для удаления: ";
    cin >> targetWord;
    
    if (findWord(targetWord) == NULL) {
        cout << "Слово \"" << targetWord << "\" не найдено в указателе!" << endl;
        return;
    }
    
    if (strcmp(head->word, targetWord) == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Слово \"" << targetWord << "\" удалено из указателя!" << endl;
        return;
    }
    
    Node* prev = findPrevious(targetWord);
    if (prev != NULL && prev->next != NULL) {
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        cout << "Слово \"" << targetWord << "\" удалено из указателя!" << endl;
    }
}

// Функция очистки всего списка
void clearAll() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    cout << "Вся память очищена!" << endl;
}

// ГЛАВНОЕ МЕНЮ 

int main() {
    int choice;
    
    do {
        cout << "ПРЕДМЕТНЫЙ УКАЗАТЕЛЬ" << endl;
        cout << "1. Начальное формирование указателя" << endl;
        cout << "2. Вывод указателя" << endl;
        cout << "3. Найти страницы для слова" << endl;
        cout << "4. Слово с максимальным количеством страниц" << endl;
        cout << "5. Добавить слово в НАЧАЛО" << endl;
        cout << "6. Добавить слово в КОНЕЦ" << endl;
        cout << "7. Добавить слово с СОРТИРОВКОЙ по алфавиту" << endl;
        cout << "8. Добавить слово ПЕРЕД указанным" << endl;
        cout << "9. Добавить слово ПОСЛЕ указанного" << endl;
        cout << "10. Удалить указанное слово" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                createIndex();
                break;
            case 2:
                printIndex();
                break;
            case 3:
                findAndPrintPages();
                break;
            case 4:
                findMaxPagesWord();
                break;
            case 5:
                addToBeginning();
                break;
            case 6:
                addToEnd();
                break;
            case 7:
                addSorted();
                break;
            case 8:
                addBeforeWord();
                break;
            case 9:
                addAfterWord();
                break;
            case 10:
                deleteWord();
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Ошибка! Введите число от 0 до 10!" << endl;
        }
    } while (choice != 0);
    
    // Очистка памяти перед выходом
    clearAll();
    
    return 0; // программа завершена успешно
}
