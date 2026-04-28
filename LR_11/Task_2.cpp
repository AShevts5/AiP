#include <iostream> // библиотека для ввода-вывода
#include <cstring> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

const int max_words = 100; // максимальное количество слов в очереди
const int max_word_len = 50; // максимальная длина слова
const int max_pages = 10; // максимум страниц на слово

// Структура одного элемента очереди
struct QueueItem {
    char word[max_word_len];
    int pages[max_pages];
    int pageCount;
};

int main() {
    QueueItem queue[max_words]; 
    int front = 0;  // индекс первого элемента
    int rear = -1;  // индекс последнего элемента
    int size = 0;   // текущее количество элементов
    
    int choice;
    char tempWord[max_word_len];
    char targetWord[max_word_len];
    int tempPages[max_pages];
    int tempPageCount;
    bool found;
    
    cout << "Начальное формирование очереди" << endl;
    cout << "Сколько слов добавить? (не более " << max_words << "): ";
    cin >> choice;
    if (choice > max_words) choice = max_words;
    
    for (int i = 0; i < choice; i++) {
        if (size >= max_words) {
            cout << "Очередь заполнена!" << endl;
            break;
        }
        
        cout << "\nСлово " << i+1 << ": ";
        cin >> tempWord;
        
        cout << "Сколько страниц (1-" << max_pages << "): ";
        cin >> tempPageCount;
        if (tempPageCount < 1) tempPageCount = 1;
        if (tempPageCount > max_pages) tempPageCount = max_pages;
        
        cout << "Введите номера страниц: ";
        for (int j = 0; j < tempPageCount; j++) {
            cin >> tempPages[j];
        }
        
        // Добавляем в конец очереди
        rear++;
        int k = 0;
        while (tempWord[k] != '\0' && k < max_word_len-1) {
            queue[rear].word[k] = tempWord[k];
            k++;
        }
        queue[rear].word[k] = '\0';
        queue[rear].pageCount = tempPageCount;
        for (int j = 0; j < tempPageCount; j++) {
            queue[rear].pages[j] = tempPages[j];
        }
        size++;
    }
    
    do {
        cout << "\n    МЕНЮ    " << endl;
        cout << "1. Вывод очереди" << endl;
        cout << "2. Найти слово и вывести его страницы" << endl;
        cout << "3. Найти слово с максимальным количеством страниц" << endl;
        cout << "4. Добавить слово в конец очереди" << endl;
        cout << "5. Удалить слово из начала очереди" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        // 2. Вывод очереди
        if (choice == 1) {
            if (size == 0) {
                cout << "Очередь пуста." << endl;
            } else {
                cout << "\n ОЧЕРЕДЬ:" << endl;
                for (int i = front; i <= rear; i++) {
                    cout << "Слово: " << queue[i].word << " | Страницы: ";
                    for (int j = 0; j < queue[i].pageCount; j++) {
                        cout << queue[i].pages[j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        
        // 3. Вывод страниц для заданного слова
        else if (choice == 2) {
            if (size == 0) {
                cout << "Очередь пуста." << endl;
                continue;
            }
            cout << "Введите слово для поиска: ";
            cin >> targetWord;
            found = false;
            for (int i = front; i <= rear; i++) {
                bool same = true;
                int idx = 0;
                while (targetWord[idx] != '\0' || queue[i].word[idx] != '\0') {
                    if (targetWord[idx] != queue[i].word[idx]) {
                        same = false;
                        break;
                    }
                    idx++;
                }
                if (same) {
                    cout << "Слово \"" << queue[i].word << "\" встречается на страницах: ";
                    for (int j = 0; j < queue[i].pageCount; j++) {
                        cout << queue[i].pages[j] << " ";
                    }
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Слово не найдено." << endl;
            }
        }
        
        // 4. Поиск слова с максимальным количеством страниц
        else if (choice == 3) {
            if (size == 0) {
                cout << "Очередь пуста." << endl;
                continue;
            }
            int maxPages = -1;
            int maxIndex = front;
            for (int i = front; i <= rear; i++) {
                if (queue[i].pageCount > maxPages) {
                    maxPages = queue[i].pageCount;
                    maxIndex = i;
                }
            }
            cout << "Слово с максимальным количеством страниц (" << maxPages << "): ";
            cout << queue[maxIndex].word << endl;
        }
        
        // 5. Добавление в конец очереди
        else if (choice == 4) {
            if (size >= max_words) {
                cout << "Очередь переполнена!" << endl;
                continue;
            }
            cout << "Введите новое слово: ";
            cin >> tempWord;
            cout << "Сколько страниц (1-" << max_pages << "): ";
            cin >> tempPageCount;
            if (tempPageCount < 1) tempPageCount = 1;
            if (tempPageCount > max_pages) tempPageCount = max_pages;
            cout << "Введите номера страниц: ";
            for (int j = 0; j < tempPageCount; j++) {
                cin >> tempPages[j];
            }
            
            rear++;
            int k = 0;
            while (tempWord[k] != '\0' && k < max_word_len-1) {
                queue[rear].word[k] = tempWord[k];
                k++;
            }
            queue[rear].word[k] = '\0';
            queue[rear].pageCount = tempPageCount;
            for (int j = 0; j < tempPageCount; j++) {
                queue[rear].pages[j] = tempPages[j];
            }
            size++;
            cout << "Слово добавлено в конец очереди." << endl;
        }
        
        // 6. Удаление из начала очереди
        else if (choice == 5) {
            if (size == 0) {
                cout << "Очередь пуста, нечего удалять." << endl;
                continue;
            }
            cout << "Удалено слово: " << queue[front].word << endl;
            front++;
            size--;
            if (size == 0) {
                front = 0;
                rear = -1;
            }
            cout << "Удаление выполнено." << endl;
        }
        
        else if (choice != 0) {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
        
    } while (choice != 0);
    
    cout << "Программа завершена." << endl;
    
    return 0; // программа завершена успешно
}
