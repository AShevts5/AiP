#include <iostream>     // библиотека для ввода-вывода
#include <string>       // библиотека для работы со строками
using namespace std;    // чтобы не писать std::

// Базовый класс: Хобби
class Hobby {
protected:
    string name;        // название хобби 
    string description; // описание
    int hoursInWeek;    // часов в неделю
public:
    Hobby() {
        name = "Неизвестно";
        description = "Нет описания";
        hoursInWeek = 0;
    }

    virtual ~Hobby() {
        // виртуальный деструктор базового класса
    }

    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setHours(int h) { hoursInWeek = h; }

    string getName() { return name; }
    string getDescription() { return description; }
    int getHours() { return hoursInWeek; }

    virtual int getType() {
        return 1; 
    }

    virtual void show() {
        cout << "Название хобби: " << name << endl;
        cout << "Описание: " << description << endl;
        cout << "Часов в неделю: " << hoursInWeek << endl;
    }
    
    virtual void inputData() {
        cout << "Введите название хобби: ";
        cin.ignore();
        getline(cin, name);
        cout << "Введите описание: ";
        getline(cin, description);
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
    }

    virtual void edit() {
        cout << "Введите новое название: ";
        cin.ignore();
        getline(cin, name);
        cout << "Введите новое описание: ";
        getline(cin, description);
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
    }

    virtual void removeData() {
        name = "";
        description = "";
        hoursInWeek = 0;
        cout << "Данные удалены" << endl;
    }
};

// Спорт (наследует ВСЕ атрибуты от Hobby)
class Sport : public Hobby {
protected:
    int intensity;      // интенсивность (1-10)
    int injuryRisk;     // травмоопасность (1-10)
public:
    Sport() {
        intensity = 0;
        injuryRisk = 0;
    }

    ~Sport() {
    }

    void setIntensity(int i) { intensity = i; }
    void setInjuryRisk(int ir) { injuryRisk = ir; }
    int getIntensity() { return intensity; }
    int getInjuryRisk() { return injuryRisk; }

    int getType() override {
        return 2; 
    }

    void show() override {
        Hobby::show();
        cout << "Интенсивность (1-10): " << intensity << endl;
        cout << "Травмоопасность (1-10): " << injuryRisk << endl;
    }

    void edit() override {
        Hobby::edit();
        cout << "Введите интенсивность (1-10): ";
        cin >> intensity;
        cout << "Введите травмоопасность (1-10): ";
        cin >> injuryRisk;
    }

    void removeData() override {
        Hobby::removeData();
        intensity = 0;
        injuryRisk = 0;
    }
    
    void inputData() override {
        Hobby::inputData();
        cout << "Введите интенсивность (1-10): ";
        cin >> intensity;
        cout << "Введите травмоопасность (1-10): ";
        cin >> injuryRisk;
    }
};

// Футбол (наследует hoursInWeek от Hobby)
class Football : public Hobby {
private:
    string teamName;    // название команды 
    string position;    // позиция на поле
    int goals;          // количество голов за сезон
public:
    Football() {
        teamName = "Не указана";
        position = "Не указана";
        goals = 0;
        hoursInWeek = 0;  
    }

    ~Football() {
    }

    void setTeamName(string tn) { teamName = tn; }
    void setPosition(string p) { position = p; }
    void setGoals(int g) { goals = g; }
    
    string getTeamName() { return teamName; }
    string getPosition() { return position; }
    int getGoals() { return goals; }

    int getType() override {
        return 3; 
    }

    void show() override {
        cout << "Название команды: " << teamName << endl;
        cout << "Часов в неделю: " << hoursInWeek << endl;
        cout << "Позиция на поле: " << position << endl;
        cout << "Голов за сезон: " << goals << endl;
    }

    void edit() override {
        cout << "Введите название команды: ";
        cin.ignore();
        getline(cin, teamName);
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
        cout << "Введите позицию на поле: ";
        cin.ignore();
        getline(cin, position);
        cout << "Введите количество голов за сезон: ";
        cin >> goals;
    }

    void removeData() override {
        teamName = "";
        hoursInWeek = 0;
        position = "";
        goals = 0;
        cout << "Данные удалены" << endl;
    }
    
    void inputData() override {
        cout << "Введите название команды: ";
        cin.ignore();
        getline(cin, teamName);
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
        cout << "Введите позицию на поле: ";
        cin.ignore();
        getline(cin, position);
        cout << "Введите количество голов за сезон: ";
        cin >> goals;
    }
};

// Музыка 
class Music : public Hobby {
private:
    string instrument;  // инструмент
    string skill_Level; // уровень мастерства
public:
    Music() {
        instrument = "Не указан";
        skill_Level = "Не указан";
    }

    ~Music() {
    }

    void setInstrument(string i) { instrument = i; }
    void setSkillLevel(string sl) { skill_Level = sl; }
    
    string getInstrument() { return instrument; }
    string getSkillLevel() { return skill_Level; }

    int getType() override {
        return 4; 
    }

    void show() override {
        cout << "Часов в неделю: " << hoursInWeek << endl;
        cout << "Инструмент: " << instrument << endl;
        cout << "Уровень мастерства: " << skill_Level << endl;
    }

    void edit() override {
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
        cout << "Введите инструмент: ";
        cin.ignore();
        getline(cin, instrument);
        cout << "Введите уровень мастерства (начальный/средний/профи): ";
        getline(cin, skill_Level);
    }

    void removeData() override {
        hoursInWeek = 0;
        instrument = "";
        skill_Level = "";
        cout << "Данные удалены" << endl;
    }
    
    void inputData() override {
        cout << "Введите количество часов в неделю: ";
        cin >> hoursInWeek;
        cout << "Введите инструмент: ";
        cin.ignore();
        getline(cin, instrument);
        cout << "Введите уровень мастерства (начальный/средний/профи): ";
        getline(cin, skill_Level);
    }
};

int main() {
    const int MAX_HOBBIES = 20; 
    Hobby* hobbies[MAX_HOBBIES];
    int hobbyCount = 0;  
    
    for (int i = 0; i < MAX_HOBBIES; i++) {
        hobbies[i] = NULL;
    }

    int choice;
    int hobbyIndex;
    int addChoice;
    int viewChoice;

    do {
        cout << "\n    МЕНЮ    \n";
        cout << "1. Добавить новую запись\n";
        cout << "2. Просмотреть все записи\n";
        cout << "3. Изменить запись\n";
        cout << "4. Удалить запись\n";
        cout << "5. Просмотреть записи по классам\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;
        
        // Пункт 1: добавить новую запись
        if (choice == 1) {
            if (hobbyCount < MAX_HOBBIES) {
                cout << "\n    Добавление новой записи    \n";
                cout << "Выберите класс:\n";
                cout << "1. Хобби\n";
                cout << "2. Спорт\n";
                cout << "3. Футбол\n";
                cout << "4. Музыка\n";
                cout << "Ваш выбор: ";
                cin >> addChoice;
                
                if (addChoice == 1) {
                    hobbies[hobbyCount] = new Hobby();
                } else if (addChoice == 2) {
                    hobbies[hobbyCount] = new Sport();
                } else if (addChoice == 3) {
                    hobbies[hobbyCount] = new Football();
                } else if (addChoice == 4) {
                    hobbies[hobbyCount] = new Music();
                } else {
                    cout << "Неверный выбор\n";
                    continue;
                }
                
                hobbies[hobbyCount]->inputData();
                hobbyCount++;
                cout << "\nЗапись добавлена. Всего записей: " << hobbyCount << endl;
            } else {
                cout << "Достигнут максимум записей (" << MAX_HOBBIES << ")\n";
            }
            continue;
        }
        
        // Пункт 2: просмотреть все записи
        if (choice == 2) {
            cout << "\n    ВСЕ ЗАПИСИ    \n";
            if (hobbyCount == 0) {
                cout << "Нет добавленных записей\n";
            } else {
                for (int i = 0; i < hobbyCount; i++) {
                    cout << "\nЗапись " << i + 1 << endl;
                    hobbies[i]->show();
                }
            }
            continue;
        }
        
        // Пункт 3: изменить запись
        if (choice == 3) {
            if (hobbyCount == 0) {
                cout << "Нет записей для изменения\n";
                continue;
            }
            cout << "Введите номер записи (1-" << hobbyCount << "): ";
            cin >> hobbyIndex;
            if (hobbyIndex >= 1 && hobbyIndex <= hobbyCount) {
                cout << "\n    Изменение записи " << hobbyIndex << "\n";
                hobbies[hobbyIndex - 1]->edit();
                cout << "\nЗапись изменена\n";
            } else {
                cout << "Неверный номер\n";
            }
            continue;
        }
        
        // Пункт 4: удалить запись
        if (choice == 4) {
            if (hobbyCount == 0) {
                cout << "Нет записей для удаления\n";
                continue;
            }
            cout << "Введите номер записи (1-" << hobbyCount << "): ";
            cin >> hobbyIndex;
            if (hobbyIndex >= 1 && hobbyIndex <= hobbyCount) {
                delete hobbies[hobbyIndex - 1];
                for (int i = hobbyIndex - 1; i < hobbyCount - 1; i++) {
                    hobbies[i] = hobbies[i + 1];
                }
                hobbyCount--;
                cout << "\nЗапись удалена\n";
            } else {
                cout << "Неверный номер\n";
            }
            continue;
        }
        
        // Пункт 5: просмотреть записи по классам
        if (choice == 5) {
            cout << "\n    ПРОСМОТР ЗАПИСЕЙ ПО КЛАССАМ    \n";
            cout << "Выберите класс:\n";
            cout << "1. Хобби (все записи)\n";
            cout << "2. Только Спорт\n";
            cout << "3. Только Футбол\n";
            cout << "4. Только Музыка\n";
            cout << "Ваш выбор: ";
            cin >> viewChoice;
            
            int foundCount = 0;
            
            for (int i = 0; i < hobbyCount; i++) {
                if (viewChoice == 1) {
                    if (foundCount == 0) {
                        cout << "\n=ВСЕ ХОББИ (включая спорт, футбол, музыку) \n";
                    }
                    cout << "\nЗапись " << foundCount + 1 << endl;
                    hobbies[i]->show();
                    foundCount++;
                }
                else if (hobbies[i]->getType() == viewChoice) {
                    if (foundCount == 0) {
                        cout << "\nЗаписи класса ";
                        if (viewChoice == 2) cout << "Спорт";
                        else if (viewChoice == 3) cout << "Футбол";
                        else if (viewChoice == 4) cout << "Музыка";
                        cout << " \n";
                    }
                    cout << "\nЗапись " << foundCount + 1 << endl;
                    hobbies[i]->show();
                    foundCount++;
                }
            }
            
            if (foundCount == 0) {
                cout << "\nНет записей\n";
            } else {
                cout << "\nВсего записей: " << foundCount << endl;
            }
            continue;
        }

    } while (choice != 0);

    // Удаление всех записей
    for (int i = 0; i < hobbyCount; i++) {
        delete hobbies[i];
    }

    cout << "\nПрограмма завершена\n";
    return 0; // программа завершена успешно
}
