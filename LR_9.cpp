#include <iostream> // библиотека для ввода-вывода
#include <string> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

// Базовый класс Хобби
class Hobby {
    protected:
        string name;
        string type; // тип хобби (активное, творческое, научное)
        int hoursInWeek;
        
    public:
        // конструктор
        Hobby() {
            name = "Неизвестно";
            type = "Неизвестно";
            hoursInWeek = 0;
        }
        
        void input() {
            cout << "Введите название: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите тип хобби (активное/творческое/научное): ";
            getline(cin, type);
            cout << "Введите количество часов в неделю: ";
            cin >> hoursInWeek;
        }
        
        void display() {
            cout << "Название: " << name << endl;
            cout << "Тип: " << type << endl;
            cout << "Часов в неделю: " << hoursInWeek << endl;
        }
        
        void edit() {
            cout << "Редактирование:" << endl;
            input();
        }
        
        string getName() {
            return name;
        }
};

// класс Спорт (производный от Хобби)
class Sport : public Hobby {
    protected:
        string category; // вид спорта (командный/индивидуальный)
    public:
        Sport() : Hobby() {
            category = "Неизвестно";
        }
        
        void input() {
            Hobby::input();
            cout << "Введите категорию спорта (командный/индивидуальный): ";
            cin.ignore();
            getline(cin, category);
        }
        
        void display() {
            cout << "Хобби: Спорт " << endl;
            Hobby::display();
            cout << "Категория: " << category << endl;
        }
        
        void edit() {
            cout << "Редактирование спортивной секции:" << endl;
            input();
        }
};

// класс Футбол (наследует от Спорта)
class Football : public Sport {
    private:
        int numberOfTeams;
        string bestPlayer;
    public:
        Football() : Sport() {
            numberOfTeams = 0;
            bestPlayer = "Неизвестно";
        }
        
        void input() {
            Sport::input();
            cout << "Введите количество команд: ";
            cin >> numberOfTeams;
            cout << "Введите имя лучшего игрока: ";
            cin.ignore();
            getline(cin, bestPlayer);
        }
        
        void display() {
            cout << "Хобби: Спорт: Футбол " << endl;
            Sport::display();
            cout << "Количество команд: " << numberOfTeams << endl;
            cout << "Лучший игрок: " << bestPlayer << endl;
        }
        
        void edit() {
            cout << "Редактирование футбольной команды:" << endl;
            input();
        }
};

// класс Музыка (производный от Хобби)
class Music : public Hobby {
private:
    string genre;
    string favoriteInstrument;
public:
    Music() : Hobby() {
        genre = "Неизвестно";
        favoriteInstrument = "Неизвестно";
    }
    
    void input() {
        Hobby::input();
        cout << "Введите жанр музыки: ";
        cin.ignore();
        getline(cin, genre);
        cout << "Введите любимый инструмент: ";
        getline(cin, favoriteInstrument);
    }
    
    void display() {
        cout << "Хобби: Музыка" << endl;
        Hobby::display();
        cout << "Жанр: " << genre << endl;
        cout << "Любимый инструмент: " << favoriteInstrument << endl;
    }
    
    void edit() {
        cout << "Редактирование музыкальных предпочтений:" << endl;
        input();
    }
};

int main() {
    Hobby hobbyArr[10];
    Football footballArr[10];
    Sport sportArr[10];
    Music musicArr[10];
    
    int hobbyCount = 0;
    int footballCount = 0;
    int sportCount = 0;
    int musicCount = 0;
    
    int choice;
    int classChoice;
    int index;
    
    do {
        cout << "\n           ГЛАВНОЕ МЕНЮ          " << endl;
        cout << "1. Класс Хобби" << endl;
        cout << "2. Класс Спорт" << endl;
        cout << "3. Класс Футбол" << endl;
        cout << "4. Класс Музыка" << endl;
        cout << "5. Показать все записи" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        if (choice == 1) {
            // Меню для работы с хобби
            do {
                cout << "\n          ХОББИ         " << endl;
                cout << "1. Добавить запись" << endl;
                cout << "2. Просмотреть все записи" << endl;
                cout << "3. Редактировать запись" << endl;
                cout << "4. Удалить запись" << endl;
                cout << "0. Вернуться в главное меню" << endl;
                cout << "Выбор: ";
                cin >> classChoice;
                
                if (classChoice == 1) {
                    if (hobbyCount < 10) {
                        cout << "\n    Добавление хобби    " << endl;
                        hobbyArr[hobbyCount].input();
                        hobbyCount++;
                        cout << "Запись добавлена!" << endl;
                    } else {
                        cout << "Достигнут лимит записей (10)!" << endl;
                    }
                }
                else if (classChoice == 2) {
                    cout << "\n Хобби (" << hobbyCount << " записей) " << endl;
                    if (hobbyCount == 0) {
                        cout << "Нет записей!" << endl;
                    }
                    for (int i = 0; i < hobbyCount; i++) {
                        cout << "\nЗапись №" << i + 1 << ":" << endl;
                        hobbyArr[i].display();
                    }
                }
                else if (classChoice == 3) {
                    if (hobbyCount > 0) {
                        cout << "Введите номер записи для редактирования (1-" << hobbyCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= hobbyCount) {
                            hobbyArr[index - 1].edit();
                            cout << "Запись отредактирована!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для редактирования!" << endl;
                    }
                }
                else if (classChoice == 4) {
                    if (hobbyCount > 0) {
                        cout << "Введите номер записи для удаления (1-" << hobbyCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= hobbyCount) {
                            for (int i = index - 1; i < hobbyCount - 1; i++) {
                                hobbyArr[i] = hobbyArr[i + 1];
                            }
                            hobbyCount--;
                            cout << "Запись удалена!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для удаления!" << endl;
                    }
                }
                else if (classChoice != 0) {
                    cout << "Неверный выбор!" << endl;
                }
                
            } while (classChoice != 0);
        }
        
        else if (choice == 2) {
            // Меню для работы со спортом
            do {
                cout << "\n         СПОРТ         " << endl;
                cout << "1. Добавить запись" << endl;
                cout << "2. Просмотреть все записи" << endl;
                cout << "3. Редактировать запись" << endl;
                cout << "4. Удалить запись" << endl;
                cout << "0. Вернуться в главное меню" << endl;
                cout << "Выбор: ";
                cin >> classChoice;
                
                if (classChoice == 1) {
                    if (sportCount < 10) {
                        cout << "\n    Добавление спортивной секции    " << endl;
                        sportArr[sportCount].input();
                        sportCount++;
                        cout << "Запись добавлена!" << endl;
                    } else {
                        cout << "Достигнут лимит записей (10)!" << endl;
                    }
                }
                else if (classChoice == 2) {
                    cout << "\n Спорт (" << sportCount << " записей) " << endl;
                    if (sportCount == 0) {
                        cout << "Нет записей!" << endl;
                    }
                    for (int i = 0; i < sportCount; i++) {
                        cout << "\nЗапись №" << i + 1 << ":" << endl;
                        sportArr[i].display();
                    }
                }
                else if (classChoice == 3) {
                    if (sportCount > 0) {
                        cout << "Введите номер записи для редактирования (1-" << sportCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= sportCount) {
                            sportArr[index - 1].edit();
                            cout << "Запись отредактирована!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для редактирования!" << endl;
                    }
                }
                else if (classChoice == 4) {
                    if (sportCount > 0) {
                        cout << "Введите номер записи для удаления (1-" << sportCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= sportCount) {
                            for (int i = index - 1; i < sportCount - 1; i++) {
                                sportArr[i] = sportArr[i + 1];
                            }
                            sportCount--;
                            cout << "Запись удалена!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для удаления!" << endl;
                    }
                }
                else if (classChoice != 0) {
                    cout << "Неверный выбор!" << endl;
                }
                
            } while (classChoice != 0);
        }
        
        else if (choice == 3) {
            // Меню для работы с футболом
            do {
                cout << "\n         ФУТБОЛ        " << endl;
                cout << "1. Добавить запись" << endl;
                cout << "2. Просмотреть все записи" << endl;
                cout << "3. Редактировать запись" << endl;
                cout << "4. Удалить запись" << endl;
                cout << "0. Вернуться в главное меню" << endl;
                cout << "Выбор: ";
                cin >> classChoice;
                
                if (classChoice == 1) {
                    if (footballCount < 10) {
                        cout << "\n Добавление футбольной команды " << endl;
                        footballArr[footballCount].input();
                        footballCount++;
                        cout << "Запись добавлена!" << endl;
                    } else {
                        cout << "Достигнут лимит записей (10)!" << endl;
                    }
                }
                else if (classChoice == 2) {
                    cout << "\n Футбол (" << footballCount << " записей) " << endl;
                    if (footballCount == 0) {
                        cout << "Нет записей!" << endl;
                    }
                    for (int i = 0; i < footballCount; i++) {
                        cout << "\nЗапись №" << i + 1 << ":" << endl;
                        footballArr[i].display();
                    }
                }
                else if (classChoice == 3) {
                    if (footballCount > 0) {
                        cout << "Введите номер записи для редактирования (1-" << footballCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= footballCount) {
                            footballArr[index - 1].edit();
                            cout << "Запись отредактирована!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для редактирования!" << endl;
                    }
                }
                else if (classChoice == 4) {
                    if (footballCount > 0) {
                        cout << "Введите номер записи для удаления (1-" << footballCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= footballCount) {
                            for (int i = index - 1; i < footballCount - 1; i++) {
                                footballArr[i] = footballArr[i + 1];
                            }
                            footballCount--;
                            cout << "Запись удалена!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для удаления!" << endl;
                    }
                }
                else if (classChoice != 0) {
                    cout << "Неверный выбор!" << endl;
                }
                
            } while (classChoice != 0);
        }
        
        else if (choice == 4) {
            // Меню для работы с музыкой
            do {
                cout << "\n          МУЗЫКА        " << endl;
                cout << "1. Добавить запись" << endl;
                cout << "2. Просмотреть все записи" << endl;
                cout << "3. Редактировать запись" << endl;
                cout << "4. Удалить запись" << endl;
                cout << "0. Вернуться в главное меню" << endl;
                cout << "Выбор: ";
                cin >> classChoice;
                
                if (classChoice == 1) {
                    if (musicCount < 10) {
                        cout << "\n Добавление музыкальных предпочтений " << endl;
                        musicArr[musicCount].input();
                        musicCount++;
                        cout << "Запись добавлена!" << endl;
                    } else {
                        cout << "Достигнут лимит записей (10)!" << endl;
                    }
                }
                else if (classChoice == 2) {
                    cout << "\n Музыка (" << musicCount << " записей) " << endl;
                    if (musicCount == 0) {
                        cout << "Нет записей!" << endl;
                    }
                    for (int i = 0; i < musicCount; i++) {
                        cout << "\nЗапись №" << i + 1 << ":" << endl;
                        musicArr[i].display();
                    }
                }
                else if (classChoice == 3) {
                    if (musicCount > 0) {
                        cout << "Введите номер записи для редактирования (1-" << musicCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= musicCount) {
                            musicArr[index - 1].edit();
                            cout << "Запись отредактирована!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для редактирования!" << endl;
                    }
                }
                else if (classChoice == 4) {
                    if (musicCount > 0) {
                        cout << "Введите номер записи для удаления (1-" << musicCount << "): ";
                        cin >> index;
                        if (index >= 1 && index <= musicCount) {
                            for (int i = index - 1; i < musicCount - 1; i++) {
                                musicArr[i] = musicArr[i + 1];
                            }
                            musicCount--;
                            cout << "Запись удалена!" << endl;
                        } else {
                            cout << "Неверный номер!" << endl;
                        }
                    } else {
                        cout << "Нет записей для удаления!" << endl;
                    }
                }
                else if (classChoice != 0) {
                    cout << "Неверный выбор!" << endl;
                }
                
            } while (classChoice != 0);
        }
        
        else if (choice == 5) {
            cout << "\n         ВСЕ ЗАПИСИ        " << endl;
            
            cout << "\n Хобби (" << hobbyCount << " записей) " << endl;
            if (hobbyCount == 0) {
                cout << "Нет записей" << endl;
            }
            for (int i = 0; i < hobbyCount; i++) {
                cout << "\nЗапись №" << i + 1 << ":" << endl;
                hobbyArr[i].display();
            }
            
            cout << "\n Спорт (" << sportCount << " записей) " << endl;
            if (sportCount == 0) {
                cout << "Нет записей" << endl;
            }
            for (int i = 0; i < sportCount; i++) {
                cout << "\nЗапись №" << i + 1 << ":" << endl;
                sportArr[i].display();
            }
            
            cout << "\n Футбол (" << footballCount << " записей) " << endl;
            if (footballCount == 0) {
                cout << "Нет записей" << endl;
            }
            for (int i = 0; i < footballCount; i++) {
                cout << "\nЗапись №" << i + 1 << ":" << endl;
                footballArr[i].display();
            }
            
            cout << "\n Музыка (" << musicCount << " записей) " << endl;
            if (musicCount == 0) {
                cout << "Нет записей" << endl;
            }
            for (int i = 0; i < musicCount; i++) {
                cout << "\nЗапись №" << i + 1 << ":" << endl;
                musicArr[i].display();
            }
        }
        else if (choice != 0) {
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
        
    } while (choice != 0);
    
    cout << "Программа завершена!" << endl;
    
    return 0; // программа завершена успешно
}
