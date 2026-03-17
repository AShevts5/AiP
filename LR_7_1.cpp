#include <iostream> // библиотека для ввода-вывода
#include <cstring>  // библиотека для работы со строками
using namespace std;  // чтобы не писать std::

int main() { // главный метод программы

    // Структура для студента
    struct Student {
        char lastName[50]; 
        char firstName[50]; 
        char middleName[50]; 
        char address[100];
        char group[20];
        int rating;
    };
    const int max_students = 100;
    Student students[max_students];
    int studentCount = 0;
    int choice;
    
    do {
        // Выводим меню
        cout << "\n      МЕНЮ      \n";
        cout << "1) Ввод массива структур\n";
        cout << "2) Сортировка массива структур\n";
        cout << "3) Поиск в массиве структур по заданному параметру\n";
        cout << "4) Изменение заданной структуры\n";
        cout << "5) Удаление структуры из массива\n";
        cout << "6) Вывод на экран массива структур\n";
        cout << "7) Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        
        if (choice == 1) {
            // Ввод массива структур
            cout << "Сколько студентов добавить? ";
            cin >> studentCount;
            
            if (studentCount > max_students) {
                cout << "Слишком много студентов! Максимум 100." <<  endl;
                studentCount = max_students;
            }
            
            for (int i = 0; i < studentCount; i++) {
                cout << "\nСтудент №" << i + 1 << ":\n";
                
                cout << "Фамилия: ";
                cin >> students[i].lastName;
                
                cout << "Имя: ";
                cin >> students[i].firstName;
                
                cout << "Отчество: ";
                cin >> students[i].middleName;
                
                cout << "Домашний адрес: ";
                cin.ignore(); // чтобы использовать getline после cin
                cin.getline(students[i].address, 100);
                
                cout << "Группа: ";
                cin >> students[i].group;
                
                cout << "Рейтинг: ";
                cin >> students[i].rating;
            }
            cout << "Данные сохранены!\n";
        }
        else if (choice == 2) {
            // Сортировка по фамилии (первое поле)
            if (studentCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                // Сортировка пузырьком 
                for (int i = 0; i < studentCount - 1; i++) {
                    for (int j = 0; j < studentCount - i - 1; j++) {
                        if (strcmp(students[j].lastName, students[j + 1].lastName) > 0) {
                            // Меняем местами
                            Student temp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = temp;
                        }
                    }
                }
                cout << "Массив отсортирован по фамилии!\n";
            }
        }
        else if (choice == 3) {
            // Поиск по параметру
            if (studentCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                int searchChoice;
                cout << "Искать по:\n";
                cout << "1 - Фамилия\n";
                cout << "2 - Группа\n";
                cout << "3 - Рейтинг\n";
                cout << "Выберите: ";
                cin >> searchChoice;
                
                if (searchChoice == 1) {
                    // Поиск по фамилии
                    char searchLastN[50];
                    cout << "Введите фамилию для поиска: ";
                    cin >> searchLastN;
                    
                    bool found = false;
                    for (int i = 0; i < studentCount; i++) {
                        if (strcmp(students[i].lastName, searchLastN) == 0) {
                            cout << "\nНайден студент №" << i + 1 << ":\n";
                            cout << "Фамилия: " << students[i].lastName << endl;
                            cout << "Имя: " << students[i].firstName << endl;
                            cout << "Отчество: " << students[i].middleName << endl;
                            cout << "Адрес: " << students[i].address << endl;
                            cout << "Группа: " << students[i].group << endl;
                            cout << "Рейтинг: " << students[i].rating << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Студент с фамилией " << searchLastN << " не найден.\n";
                    }
                }
                else if (searchChoice == 2) {
                    // Поиск по группе
                    char searchGroup[20];
                    cout << "Введите группу для поиска: ";
                    cin >> searchGroup;
                    
                    bool found = false;
                    for (int i = 0; i < studentCount; i++) {
                        if (strcmp(students[i].group, searchGroup) == 0) {
                            cout << "\nСтудент №" << i + 1 << ": " << students[i].lastName 
                                 << " " << students[i].firstName << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Студенты группы " << searchGroup << " не найдены.\n";
                    }
                }
                else if (searchChoice == 3) {
                    // Поиск по рейтингу
                    int minR, maxR;
                    cout << "Введите минимальный рейтинг: ";
                    cin >> minR;
                    cout << "Введите максимальный рейтинг: ";
                    cin >> maxR;
                    
                    bool found = false;
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].rating >= minR && students[i].rating <= maxR) {
                            cout << "\nСтудент №" << i + 1 << ": " << students[i].lastName 
                                 << " " << students[i].firstName << ", рейтинг: " 
                                 << students[i].rating << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Студенты с рейтингом от " << minR << " до " 
                             << maxR << " не найдены.\n";
                    }
                }
            }
        }
        else if (choice == 4) {
            // Изменение заданной структуры
            if (studentCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                int index;
                cout << "Введите номер студента для изменения (1-" << studentCount << "): ";
                cin >> index;
                
                if (index >= 1 && index <= studentCount) {
                    int pos = index - 1; // переводим в индекс массива
                    
                    cout << "Введите новые данные для студента №" << index << ":\n";
                    
                    cout << "Фамилия (" << students[pos].lastName << "): ";
                    cin >> students[pos].lastName;
                    
                    cout << "Имя (" << students[pos].firstName << "): ";
                    cin >> students[pos].firstName;
                    
                    cout << "Отчество (" << students[pos].middleName << "): ";
                    cin >> students[pos].middleName;
                    
                    cout << "Адрес (" << students[pos].address << "): ";
                    cin.ignore();
                    cin.getline(students[pos].address, 100);
                    
                    cout << "Группа (" << students[pos].group << "): ";
                    cin >> students[pos].group;
                    
                    cout << "Рейтинг (" << students[pos].rating << "): ";
                    cin >> students[pos].rating;
                    
                    cout << "Данные обновлены!\n";
                } else {
                    cout << "Неверный номер!\n";
                }
            }
        }
        else if (choice == 5) {
            // Удаление структуры
            if (studentCount == 0) {
                cout << "Массив пуст!\n";
            } else {
                int index;
                cout << "Введите номер студента для удаления (1-" << studentCount << "): ";
                cin >> index;
                
                if (index >= 1 && index <= studentCount) {
                    int pos = index - 1;
                    
                    // Сдвигаем все элементы после удаляемого на одну позицию влево
                    for (int i = pos; i < studentCount - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    
                    studentCount--; // уменьшаем количество студентов
                    cout << "Студент удален!\n";
                } else {
                    cout << "Неверный номер!\n";
                }
            }
        }
        else if (choice == 6) {
            // Вывод массива на экран
            if (studentCount == 0) {
                cout << "Массив пуст!\n";
            } else {
                cout << "\n      СПИСОК СТУДЕНТОВ      \n";
                for (int i = 0; i < studentCount; i++) {
                    cout << "\nСтудент №" << i + 1 << ":\n";
                    cout << "Фамилия: " << students[i].lastName << endl;
                    cout << "Имя: " << students[i].firstName << endl;
                    cout << "Отчество: " << students[i].middleName << endl;
                    cout << "Адрес: " << students[i].address << endl;
                    cout << "Группа: " << students[i].group << endl;
                    cout << "Рейтинг: " << students[i].rating << endl;
                    cout << "_____________________\n";
                }
            }
        }
        else if (choice == 7) {
            cout << "Программа завершена.\n";
        }
        else {
            cout << "Неверный пункт меню! Попробуйте снова.\n";
        }
        
    } while (choice != 7);
    
    return 0; // программа завершена успешно
}
