#include <iostream> // библиотека для ввода-вывода
#include <string> // библиотека для рабрты со строками
using namespace std; // чтобы не писать std::

int main() { // главный метод программы
    const int N = 6; // количество студентов
    
    // Структура для хранения даты рождения
    struct Date {
        int day;
        int month;
        int year;
    };
    
    // Структура для хранения информации о студенте
    struct Student {
        string surname;
        Date birthday;
        int grade1;   // оценка по первому предмету
        int grade2;   // оценка по второму предмету
        int grade3;   // оценка по третьему предмету
    };
    
    Student students[N];
    
    cout << "Введите информацию о " << N << " студентах" << endl;
    cout << "Для каждого студента введите:" << endl;
    cout << "Фамилию, день рождения(число месяц год), оценки по трем предметам" << endl;
    cout << "Пример: Иванов 15 5 2003 4 5 3" << endl;
    cout << endl;
    
    // Ввод информации о студентах
    for (int i = 0; i < N; i++) {
        cout << "Студент " << i + 1 << ": ";
        cin >> students[i].surname 
            >> students[i].birthday.day 
            >> students[i].birthday.month 
            >> students[i].birthday.year
            >> students[i].grade1 
            >> students[i].grade2 
            >> students[i].grade3;
    }
    
    // Сортировка студентов по дате рождения (сначала по году, потом по месяцу, потом по дню)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            // Сравниваем годы рождения
            if (students[j].birthday.year > students[j + 1].birthday.year) {
                // Меняем студентов местами
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
            // Если годы равны, сравниваем месяцы
            else if (students[j].birthday.year == students[j + 1].birthday.year) {
                if (students[j].birthday.month > students[j + 1].birthday.month) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
                // Если годы и месяцы равны, сравниваем дни
                else if (students[j].birthday.month == students[j + 1].birthday.month) {
                    if (students[j].birthday.day > students[j + 1].birthday.day) {
                        Student temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
        }
    }
    
    // Вывод отсортированного списка
    cout << endl;
    cout << "Список студентов, отсортированный по дате рождения:" << endl;

    for (int i = 0; i < N; i++) {
        cout << students[i].surname << ": " << students[i].birthday.day << "." 
             << students[i].birthday.month << "." 
             << students[i].birthday.year
             << ", оценки: " << students[i].grade1 << " " 
             << students[i].grade2 << " " << students[i].grade3 << endl;
    }
    
    // Поиск студентов, чьи фамилии начинаются с буквы А
    cout << endl;
    cout << "Студенты, фамилии которых начинаются с буквы А:" << endl;
    
    bool found = false;
    
    for (int i = 0; i < N; i++) {
        if (students[i].surname[0] == 'A' || students[i].surname[0] == 'a') {
            cout << students[i].surname << ": "
                 << students[i].birthday.day << "." 
                 << students[i].birthday.month << "." 
                 << students[i].birthday.year
                 << ", оценки: " << students[i].grade1 << " " 
                 << students[i].grade2 << " " << students[i].grade3 << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Нет студентов с фамилией на букву А" << endl;
    }
    
    return 0; // программа завершена успешно
}
