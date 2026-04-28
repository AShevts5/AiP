#define _CRT_SECURE_NO_WARNINGS // чтобы безопасно использовать fopen()
#include <iostream> // библиотека для ввода-вывода
#include <cstdio>   // библиотека для FILE, fopen, fprintf, fclose
#include <cstring>  // библиотека для работы со строками
using namespace std; // чтобы не писать std::

int main() { // главный метод программы
    
    // Структура для хранения данных о футболисте
    struct Footballer {
        char surname[50];
        char position[20];
        int age;
        int games;
        int goals;
    };
    
    Footballer players[50];
    int n = 0;
    int choice;
    
    do {
        // Меню программы
        cout << "\n            МЕНЮ             " << endl;
        cout << "1. Ввод данных о футболистах" << endl;
        cout << "2. Сортировка по количеству голов" << endl;
        cout << "3. Вывод данных на экран" << endl;
        cout << "4. Вывод данных в файл" << endl;
        cout << "5. Найти лучшего форварда" << endl;
        cout << "6. Футболисты, сыгравшие менее 5 игр" << endl;
        cout << "7. Поиск футболистов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                // Ввод количества футболистов
                cout << "Введите количество футболистов (1-50): ";
                cin >> n;
                
                // Проверка корректности
                if (n < 1 || n > 50) {
                    cout << "Ошибка! Количество должно быть от 1 до 50." << endl;
                    n = 0;
                    break;
                }
                
                // Ввод данных
                for (int i = 0; i < n; i++) {
                    cout << "\nФутболист " << i + 1 << ":" << endl;
                    
                    cout << "Фамилия: ";
                    cin >> players[i].surname;
                    
                    cout << "Амплуа: ";
                    cin >> players[i].position;
                    
                    cout << "Возраст: ";
                    cin >> players[i].age;
                    
                    cout << "Количество игр: ";
                    cin >> players[i].games;
                    
                    cout << "Количество голов: ";
                    cin >> players[i].goals;
                }
                cout << "Данные сохранены!" << endl;
                break;
            }
            
            case 2: {
                // Проверка наличия данных
                if (n == 0) {
                    cout << "Сначала введите данные!" << endl;
                    break;
                }
                
                // Сортировка по количеству голов (последнее поле) по убыванию
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (players[j].goals < players[j + 1].goals) {
                            // Обмен местами
                            Footballer temp = players[j];
                            players[j] = players[j + 1];
                            players[j + 1] = temp;
                        }
                    }
                }
                cout << "Сортировка выполнена!" << endl;
                break;
            }
            
            case 3: {
                // Вывод на экран
                if (n == 0) {
                    cout << "Нет данных для вывода!" << endl;
                    break;
                }
                
                cout << "\n    ДАННЫЕ О ФУТБОЛИСТАХ    " << endl;
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << ". " << players[i].surname 
                         << " - " << players[i].position 
                         << " - Возраст: " << players[i].age 
                         << " - Игр: " << players[i].games 
                         << " - Голов: " << players[i].goals << endl;
                }
                break;
            }
            
            case 4: {
                if (n == 0) {
                    cout << "Нет данных для вывода!" << endl;
                    break;
                }
                
                FILE* file = fopen("footballers.txt", "w");
                
                if (file == NULL) {
                    cout << "Ошибка создания файла!" << endl;
                    break;
                }
                
                fprintf(file, "    ДАННЫЕ О ФУТБОЛИСТАХ    \n");
                for (int i = 0; i < n; i++) {
                    fprintf(file, "%d. %s - %s - Возраст: %d - Игр: %d - Голов: %d\n", 
                            i + 1, 
                            players[i].surname, 
                            players[i].position, 
                            players[i].age, 
                            players[i].games, 
                            players[i].goals);
                }
                
                fclose(file);
                cout << "Данные сохранены в файл footballers.txt" << endl;
                break;
            }
            
            case 5: {
                // Поиск лучшего форварда
                if (n == 0) {
                    cout << "Сначала введите данные" << endl;
                    break;
                }
                
                int maxGoals = -1;
                int bestIndex = -1;
                bool found = false;
                
                for (int i = 0; i < n; i++) {
                    // Проверяем, является ли игрок форвардом
                    if (strcmp(players[i].position, "форвард") == 0) {
                        found = true;
                        if (players[i].goals > maxGoals) {
                            maxGoals = players[i].goals;
                            bestIndex = i;
                        }
                    }
                }
                
                if (!found) {
                    cout << "Форварды не найдены!" << endl;
                } else {
                    cout << "\nЛУЧШИЙ ФОРВАРД:" << endl;
                    cout << "Фамилия: " << players[bestIndex].surname << endl;
                    cout << "Возраст: " << players[bestIndex].age << endl;
                    cout << "Сыграно игр: " << players[bestIndex].games << endl;
                    cout << "Забито голов: " << players[bestIndex].goals << endl;
                }
                break;
            }
            
            case 6: {
                // Поиск игроков с менее 5 играми
                if (n == 0) {
                    cout << "Сначала введите данные!" << endl;
                    break;
                }
                
                cout << "\nФУТБОЛИСТЫ, СЫГРАВШИЕ МЕНЕЕ 5 ИГР:" << endl;
                bool found = false;
                
                for (int i = 0; i < n; i++) {
                    if (players[i].games < 5) {
                        found = true;
                        cout << players[i].surname 
                             << " - сыграл " << players[i].games 
                             << " игр(ы), забил " << players[i].goals 
                             << " голов" << endl;
                    }
                }
                
                if (!found) {
                    cout << "Таких игроков нет." << endl;
                }
                break;
            }
            
            case 7: {
                // Поиск по полям
                if (n == 0) {
                    cout << "Сначала введите данные!" << endl;
                    break;
                }
                
                int searchType;
                cout << "\n    ПОИСК    " << endl;
                cout << "1. Поиск по фамилии" << endl;
                cout << "2. Поиск по амплуа" << endl;
                cout << "3. Поиск по возрасту" << endl;
                cout << "Выберите тип поиска: ";
                cin >> searchType;
                
                if (searchType == 1) {
                    // Поиск по фамилии
                    char searchSurname[50];
                    cout << "Введите фамилию: ";
                    cin >> searchSurname;
                    
                    cout << "\nРезультаты поиска:" << endl;
                    bool found = false;
                    
                    for (int i = 0; i < n; i++) {
                        if (strcmp(players[i].surname, searchSurname) == 0) {
                            found = true;
                            cout << players[i].surname << " - " 
                                 << players[i].position << ", возраст " 
                                 << players[i].age << ", игр " 
                                 << players[i].games << ", голов " 
                                 << players[i].goals << endl;
                        }
                    }
                    
                    if (!found) {
                        cout << "Игрок с такой фамилией не найден." << endl;
                    }
                }
                else if (searchType == 2) {
                    // Поиск по амплуа
                    char searchPosition[20];
                    cout << "Введите амплуа: ";
                    cin >> searchPosition;
                    
                    cout << "\nРезультаты поиска:" << endl;
                    bool found = false;
                    
                    for (int i = 0; i < n; i++) {
                        if (strcmp(players[i].position, searchPosition) == 0) {
                            found = true;
                            cout << players[i].surname << " - " 
                                 << players[i].position << ", возраст " 
                                 << players[i].age << ", игр " 
                                 << players[i].games << ", голов " 
                                 << players[i].goals << endl;
                        }
                    }
                    
                    if (!found) {
                        cout << "Игроки с таким амплуа не найдены." << endl;
                    }
                }
                else if (searchType == 3) {
                    // Поиск по возрасту
                    int searchAge;
                    cout << "Введите возраст: ";
                    cin >> searchAge;
                    
                    cout << "\nРезультаты поиска:" << endl;
                    bool found = false;
                    
                    for (int i = 0; i < n; i++) {
                        if (players[i].age == searchAge) {
                            found = true;
                            cout << players[i].surname << " - " 
                                 << players[i].position << ", возраст " 
                                 << players[i].age << ", игр " 
                                 << players[i].games << ", голов " 
                                 << players[i].goals << endl;
                        }
                    }
                    
                    if (!found) {
                        cout << "Игроки с таким возрастом не найдены." << endl;
                    }
                }
                break;
            }
            
            case 0:
                cout << "Программа завершена." << endl;
                break;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
        
    } while (choice != 0);
    
    return 0; // программа завершена успешно
}
