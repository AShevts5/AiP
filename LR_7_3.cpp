#include <iostream> // библиотека для ввода-вывода
#include <cstring> // библиотека для работы со строками
#include <cstdio>  // для работы с файлами
using namespace std; // чтобы не писать std::

// Структура сотрудника
struct Employee {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    int num_dep;  // номер отдела
    char position[50];
    int Day;
    int Month;
    int Year;
};

// Функция для сравнения двух дат
// Возвращает true, если дата сотрудника a <= даты сотрудника b
bool dateCompare(const Employee& a, const Employee& b) {
    if (a.Year != b.Year) {
        return a.Year <= b.Year;
    }
    if (a.Month != b.Month) {
        return a.Month <= b.Month;
    }
    return a.Day <= b.Day;
}

// Функция для разделения массива (для QuickSort)
int partition(Employee arr[], int low, int high) {
    Employee pivot = arr[high]; // опорный элемент
    int i = (low - 1); // индекс меньшего элемента
    
    for (int j = low; j <= high - 1; j++) {
        // Если текущая дата меньше или равна опорной
        if (dateCompare(arr[j], pivot)) {
            i++; // увеличиваем индекс меньшего элемента
            // меняем местами
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // ставим опорный элемент на место
    Employee temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Функция QuickSort
void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        // разделяем массив и получаем индекс опорного элемента
        int pi = partition(arr, low, high);
        
        // рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для информации о сотруднике
void prEmployee(const Employee& emp, int number) {
    cout << "\nСотрудник №" << number << ":\n";
    cout << "ФИО: " << emp.lastName << " " << emp.firstName << " " << emp.middleName << endl;
    cout << "Отдел: " << emp.num_dep << endl;
    cout << "Должность: " << emp.position << endl;
    cout << "Дата начала: " << emp.Day << "." << emp.Month << "." << emp.Year << endl;
}

int main() { // главный метод программы
    
    const int max_employees = 100;
    Employee employees[max_employees];
    int employeeCount = 0;
    int choice;
    
    do {
        // Выводим меню
        cout << "\n     МЕНЮ     \n";
        cout << "1) Ввод массива структур\n";
        cout << "2) Сортировка массива структур (QuickSort по дате)\n";
        cout << "3) Поиск в массиве структур по заданному параметру\n";
        cout << "4) Изменение заданной структуры\n";
        cout << "5) Удаление структуры из массива\n";
        cout << "6) Вывод на экран массива структур\n";
        cout << "7) Сохранить данные в файл\n";
        cout << "8) Загрузить данные из файла\n";
        cout << "9) Список сотрудников заданного отдела со стажем > 20 лет\n";
        cout << "10) Найти сотрудника, работающего с 1975 года\n";
        cout << "11) Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        
        if (choice == 1) {
            // Ввод массива структур
            cout << "Сколько сотрудников добавить? ";
            cin >> employeeCount;
            
            if (employeeCount > max_employees) {
                cout << "Слишком много сотрудников! Максимум " << max_employees << endl;
                employeeCount = max_employees;
            }
            
            for (int i = 0; i < employeeCount; i++) {
                cout << "\nСотрудник №" << i + 1 << ":\n";
                
                cout << "Фамилия: ";
                cin >> employees[i].lastName;
                
                cout << "Имя: ";
                cin >> employees[i].firstName;
                
                cout << "Отчество: ";
                cin >> employees[i].middleName;
                
                cout << "Номер отдела: ";
                cin >> employees[i].num_dep;
                
                cout << "Должность: ";
                cin.ignore(); // чтобы использовать getline()
                cin.getline(employees[i].position, 50);
                
                cout << "Дата начала работы (через пробел день месяц год): ";
                cin >> employees[i].Day >> employees[i].Month >> employees[i].Year;
            }
            cout << "Данные сохранены в памяти!\n";
        }
        else if (choice == 2) {
            // Сортировка по дате начала работы (QuickSort)
            if (employeeCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                quickSort(employees, 0, employeeCount - 1);
                cout << "Массив отсортирован по дате начала работы (неубывание) методом QuickSort\n";
                
                cout << "\nРезультат сортировки:\n";
                for (int i = 0; i < employeeCount; i++) {
                    cout << i + 1 << ". " << employees[i].lastName << " " 
                         << employees[i].firstName << " - " 
                         << employees[i].Day << "." << employees[i].Month << "." << employees[i].Year << endl;
                }
            }
        }
        else if (choice == 3) {
            // Поиск по параметру
            if (employeeCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                int searchChoice;
                cout << "Искать по:\n";
                cout << "1 - Фамилия\n";
                cout << "2 - Отдел\n";
                cout << "3 - Должность\n";
                cout << "Выберите: ";
                cin >> searchChoice;
                
                if (searchChoice == 1) {
                    // Поиск по фамилии
                    char searchLastN[50];
                    cout << "Введите фамилию для поиска: ";
                    cin >> searchLastN;
                    bool found = false;
                    for (int i = 0; i < employeeCount; i++) {
                        if (strcmp(employees[i].lastName, searchLastN) == 0) {
                            prEmployee(employees[i], i + 1);
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Сотрудник с фамилией " << searchLastN << " не найден.\n";
                    }
                }
                else if (searchChoice == 2) {
                    // Поиск по отделу
                    int searchDept;
                    cout << "Введите номер отдела: ";
                    cin >> searchDept;
                    
                    bool found = false;
                    for (int i = 0; i < employeeCount; i++) {
                        if (employees[i].num_dep == searchDept) {
                            cout << "\nСотрудник №" << i + 1 << ": " 
                                 << employees[i].lastName << " " << employees[i].firstName << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Сотрудники отдела " << searchDept << " не найдены.\n";
                    }
                }
                else if (searchChoice == 3) {
                    // Поиск по должности
                    char searchPosition[50];
                    cout << "Введите должность: ";
                    cin.ignore();
                    cin.getline(searchPosition, 50);
                    
                    bool found = false;
                    for (int i = 0; i < employeeCount; i++) {
                        if (strcmp(employees[i].position, searchPosition) == 0) {
                            cout << "\nСотрудник №" << i + 1 << ": " 
                                 << employees[i].lastName << " " << employees[i].firstName << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "Сотрудники с должностью '" << searchPosition << "' не найдены.\n";
                    }
                }
            }
        }
        else if (choice == 4) {
            // Изменение заданной структуры
            if (employeeCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                int index;
                cout << "Введите номер сотрудника для изменения (1-" << employeeCount << "): ";
                cin >> index;
                
                if (index >= 1 && index <= employeeCount) {
                    int pos = index - 1;
                    
                    cout << "Введите новые данные для сотрудника №" << index << ":\n";
                    
                    cout << "Фамилия (" << employees[pos].lastName << "): ";
                    cin >> employees[pos].lastName;
                    
                    cout << "Имя (" << employees[pos].firstName << "): ";
                    cin >> employees[pos].firstName;
                    
                    cout << "Отчество (" << employees[pos].middleName << "): ";
                    cin >> employees[pos].middleName;
                    
                    cout << "Номер отдела ("<< employees[pos].num_dep << "): ";
                    cin >> employees[pos].num_dep;
                    
                    cout << "Должность (" << employees[pos].position << "): ";
                    cin.ignore();
                    cin.getline(employees[pos].position, 50);
                    
                    cout << "Дата начала работы (было: " << employees[pos].Day << "." 
                         << employees[pos].Month << "." << employees[pos].Year << ")\n";
                    cout << "Введите новую дату (день месяц год): ";
                    cin >> employees[pos].Day >> employees[pos].Month >> employees[pos].Year;
                    
                    cout << "Данные обновлены!\n";
                } else {
                    cout << "Неверный номер!\n";
                }
            }
        }
        else if (choice == 5) {
            // Удаление структуры
            if (employeeCount == 0) {
                cout << "Массив пуст!\n";
            } else {
                int index;
                cout << "Введите номер сотрудника для удаления (1-" << employeeCount << "): ";
                cin >> index;
                
                if (index >= 1 && index <= employeeCount) {
                    int pos = index - 1;
                    
                    for (int i = pos; i < employeeCount - 1; i++) {
                        employees[i] = employees[i + 1];
                    }
                    
                    employeeCount--;
                    cout << "Сотрудник удален!\n";
                } else {
                    cout << "Неверный номер!\n";
                }
            }
        }
        else if (choice == 6) {
            // Вывод массива на экран
            if (employeeCount == 0) {
                cout << "Массив пуст!\n";
            } else {
                cout << "\n   СПИСОК СОТРУДНИКОВ     \n";
                for (int i = 0; i < employeeCount; i++) {
                    prEmployee(employees[i], i + 1); 
                }
            }
        }
        else if (choice == 7) {
            // Сохранение в файл 
            if (employeeCount == 0) {
                cout << "Нет данных для сохранения!\n";
            } else {
                char filename[50];
                cout << "Введите имя файла для сохранения: ";
                cin >> filename;
                
                FILE* File = fopen(filename, "w");
                if (File != NULL) {
                    // Сначала сохраняем количество записей
                    fprintf(File, "%d\n", employeeCount);
                    
                    // Сохраняем все данные
                    for (int i = 0; i < employeeCount; i++) {
                        fprintf(File, "%s\n", employees[i].lastName);
                        fprintf(File, "%s\n", employees[i].firstName);
                        fprintf(File, "%s\n", employees[i].middleName);
                        fprintf(File, "%d\n", employees[i].num_dep);
                        fprintf(File, "%s\n", employees[i].position);
                        fprintf(File, "%d %d %d\n", employees[i].Day, employees[i].Month, employees[i].Year);
                    }
                    
                    fclose(File); 
                    cout << "Данные сохранены в файл " << filename << endl;
                } else {
                    cout << "Ошибка открытия файла для записи!\n";
                }
            }
        }
        else if (choice == 8) {
            // Загрузка из файла 
            char filename[50];
            cout << "Введите имя файла для загрузки: ";
            cin >> filename;
            
            FILE* inFile = fopen(filename, "r");
            if (inFile != NULL) {
                // Читаем количество записей
                fscanf(inFile, "%d\n", &employeeCount);
                
                if (employeeCount > max_employees) {
                    cout << "В файле слишком много записей! Максимум " << max_employees << endl;
                    employeeCount = max_employees;
                }
                
                // Читаем все данные
                for (int i = 0; i < employeeCount; i++) {
                    fscanf(inFile, "%s\n", employees[i].lastName);
                    fscanf(inFile, "%s\n", employees[i].firstName);
                    fscanf(inFile, "%s\n", employees[i].middleName);
                    fscanf(inFile, "%d\n", &employees[i].num_dep);
                    fscanf(inFile, "%s\n", employees[i].position);
                    fscanf(inFile, "%d %d %d\n", &employees[i].Day, &employees[i].Month, &employees[i].Year);
                }
                
                fclose(inFile);
                cout << "Данные загружены из файла " << filename << endl;
                cout << "Загружено сотрудников: " << employeeCount << endl;
            } else {
                cout << "Ошибка открытия файла для чтения!\n";
            }
        }
        else if (choice == 9) {
            // Список сотрудников заданного отдела со стажем > 20 лет
            if (employeeCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                int deptNumber;
                cout << "Введите номер отдела для поиска: ";
                cin >> deptNumber;
                
                // Получаем текущую дату для расчета стажа
                int currentDay, currentMonth, currentYear;
                cout << "Введите текущий год: ";
                cin >> currentYear;
                
                cout << "\n Сотрудники отдела " << deptNumber << " со стажем > 20 лет \n";
                
                // Объявляем имя файла
                char filename[50];
                cout << "Введите имя файла для сохранения результатов: ";
                cin >> filename;
                
                // Открываем файл для сохранения результатов
                FILE* File = fopen(filename, "w");
                if (File != NULL) {
                    fprintf(File, "Сотрудники отдела %d со стажем > 20 лет\n", deptNumber);
                }
                
                bool found = false;
                int count = 0;
                
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].num_dep == deptNumber) {
                        int experience = currentYear - employees[i].Year;
                        
                        if (experience > 20) {
                            count++;
                            found = true;
                            cout << "Сотрудник №" << i + 1 << ":\n";
                            cout << "Фамилия: " << employees[i].lastName << endl;
                            cout << "Имя: " << employees[i].firstName << endl;
                            cout << "Отчество: " << employees[i].middleName << endl;
                            cout << "Должность: " << employees[i].position << endl;
                            cout << "Дата начала работы: " << employees[i].Day << "." 
                                 << employees[i].Month << "." << employees[i].Year << endl;
                            cout << "Стаж: " << experience << " лет\n";
                            
                            if (File != NULL) {
                                fprintf(File, "Сотрудник №%d:\n", i + 1);
                                fprintf(File, "Фамилия: %s\n", employees[i].lastName);
                                fprintf(File, "Имя: %s\n", employees[i].firstName);
                                fprintf(File, "Отчество: %s\n", employees[i].middleName);
                                fprintf(File, "Должность: %s\n", employees[i].position);
                                fprintf(File, "Дата начала работы: %d.%d.%d\n", 
                                        employees[i].Day, employees[i].Month, employees[i].Year);
                                fprintf(File, "Стаж: %d лет\n", experience);
                            }
                        }
                    }
                }
                
                if (!found) {
                    cout << "\nВ отделе " << deptNumber << " нет сотрудников со стажем более 20 лет.\n";
                    if (File != NULL) {
                        fprintf(File, "\nВ отделе %d нет сотрудников со стажем более 20 лет.\n", deptNumber);
                    }
                } else {
                    cout << "\nНайдено сотрудников: " << count << endl;
                    
                    if (File != NULL) {
                        fprintf(File, "\nНайдено сотрудников: %d\n", count);
                    }
                }
                
                // Закрываем файл
                if (File != NULL) {
                    fclose(File);
                    cout << "\nРезультаты сохранены в файл '" << filename << "'\n";
                }
            }
        }
        else if (choice == 10) {
            // Поиск сотрудника, работающего с 1975 года 
            if (employeeCount == 0) {
                cout << "Массив пуст! Сначала введите данные.\n";
            } else {
                cout << "\nПоиск сотрудника, работающего с 1975 года\n";
                
                bool found = false;
                int count = 0;
                
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].Year == 1975) {
                        if (!found) {
                            cout << "Найденные сотрудники:\n";
                        }
                        prEmployee(employees[i], i + 1);
                        found = true;
                        count++;
                    }
                }
                
                if (!found) {
                    cout << "Сотрудники, работающие с 1975 года, не найдены.\n";
                } else {
                    cout << "Всего найдено сотрудников: " << count << "\n";
                }
            }
        }
        else if (choice == 11) {
            cout << "Программа завершена.\n";
        }
        else {
            cout << "Неверный пункт меню! Попробуйте снова.\n";
        }
        
    } while (choice != 11); 
    
    return 0; // программа завершена успешно
}
