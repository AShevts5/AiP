#include <iostream> // библиотека для ввода-вывода
#include <fstream> // библиотека для работы с файлами
#include <deque> // очередь
#include <list> // список
#include <stack> // стек
#include <vector> // вектор
#include <string> // библиотека для работы со строками
#include <limits> // предельные значения типов данных
#include <algorithm> // алгоритмы для работы с данными
using namespace std; // чтобы не писать std::

// Базовый класс ошибки
class Error {
public:
    string message;
    int code;
    
    Error() {
        message = "";
        code = 0;
    }
    
    virtual void input() {
        cout << "Введите код ошибки: ";
        cin >> code;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите сообщение: ";
        getline(cin, message);
    }
    
    virtual void print() const {
        cout << "Код: " << code << ", Сообщение: " << message;
    }
    
    virtual int getSortKey() const {
        return code;
    }
};

// 1 подкласс - для очереди
class NotEnoughPrivilegesError : public Error {
private:
    string requiredPrivilege;
    int currentLevel;
    
public:
    NotEnoughPrivilegesError() : Error() {
        requiredPrivilege = "";
        currentLevel = 0;
    }
    
    void input() {
        Error::input();
        cout << "Введите требуемую привилегию: ";
        getline(cin, requiredPrivilege);
        cout << "Введите текущий уровень: ";
        cin >> currentLevel;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    void print() const override {
        Error::print();
        cout << " [Privileges: " << requiredPrivilege << ", Level: " << currentLevel << "]";
    }
    
    int getSortKey() const override {
        return currentLevel;
    }
};

// 2 подкласс - для списка
class ConversionError : public Error {
private:
    string fromType;
    string toType;
    
public:
    ConversionError() : Error() {
        fromType = "";
        toType = "";
    }
    
    void input() {
        Error::input();
        cout << "Введите исходный тип: ";
        getline(cin, fromType);
        cout << "Введите целевой тип: ";
        getline(cin, toType);
    }
    
    void print() const override {
        Error::print();
        cout << " [Conversion: " << fromType << " -> " << toType << "]";
    }
};

// 3 подкласс - для стека
class CannotConvertValueError : public Error {
private:
    string badValue;
    string expectedFormat;
    
public:
    CannotConvertValueError() : Error() {
        badValue = "";
        expectedFormat = "";
    }
    
    void input() {
        Error::input();
        cout << "Введите ошибочное значение: ";
        getline(cin, badValue);
        cout << "Введите ожидаемый формат: ";
        getline(cin, expectedFormat);
    }
    
    void print() const override {
        Error::print();
        cout << " [Value: " << badValue << ", Format: " << expectedFormat << "]";
    }
};

// 4 подкласс - для вектора
class CannotCastToInterfaceError : public Error {
private:
    string objectType;
    string interfaceName;
    
public:
    CannotCastToInterfaceError() : Error() {
        objectType = "";
        interfaceName = "";
    }
    
    void input() {
        Error::input();
        cout << "Введите тип объекта: ";
        getline(cin, objectType);
        cout << "Введите имя интерфейса: ";
        getline(cin, interfaceName);
    }
    
    void print() const override {
        Error::print();
        cout << " [Object: " << objectType << ", Interface: " << interfaceName << "]";
    }
};

// ФУНКЦИИ СОРТИРОВКИ ВЫБОРОМ ПО УБЫВАНИЮ 

// Для вектора
void selectionSortDesc(vector<CannotCastToInterfaceError>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j].getSortKey() > vec[maxIdx].getSortKey()) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
        }
    }
}

// Для очереди
void selectionSortDesc(deque<NotEnoughPrivilegesError>& dq) {
    int n = dq.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (dq[j].getSortKey() > dq[maxIdx].getSortKey()) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(dq[i], dq[maxIdx]);
        }
    }
}

// Для списка 
bool compareConversionErrors(const ConversionError& a, const ConversionError& b) {
    return a.getSortKey() > b.getSortKey();
}

void sortListDesc(list<ConversionError>& lst) {
    lst.sort(compareConversionErrors);
}

// Для стека 
void selectionSortDesc(stack<CannotConvertValueError>& st) {
    if (st.empty()) return;
    
    vector<CannotConvertValueError> tempVec;
    while (!st.empty()) {
        tempVec.push_back(st.top());
        st.pop();
    }
    
    int n = tempVec.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (tempVec[j].getSortKey() > tempVec[maxIdx].getSortKey()) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(tempVec[i], tempVec[maxIdx]);
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        st.push(tempVec[i]);
    }
}

void showMenu() {
    cout << "\n           МЕНЮ          \n";
    cout << "1. Добавить в очередь (Privileges)\n";
    cout << "2. Добавить в список (Conversion)\n";
    cout << "3. Добавить в стек (CannotConvert)\n";
    cout << "4. Добавить в вектор (CannotCast)\n";
    cout << "5. Удалить из очереди\n";
    cout << "6. Удалить из списка\n";
    cout << "7. Удалить из стека\n";
    cout << "8. Удалить из вектора\n";
    cout << "9. Показать все структуры\n";
    cout << "10. Сохранить всё в файл и отсортировать\n";
    cout << "0. Выход\n";
    cout << "Выбор: ";
}

int main() {
    deque<NotEnoughPrivilegesError> dequeErrors;
    list<ConversionError> listErrors;
    stack<CannotConvertValueError> stackErrors;
    vector<CannotCastToInterfaceError> vectorErrors;
    
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: {
                NotEnoughPrivilegesError err;
                err.input();
                dequeErrors.push_back(err);
                cout << "Добавлено в очередь!\n";
                break;
            }
            case 2: {
                ConversionError err;
                err.input();
                listErrors.push_back(err);
                cout << "Добавлено в список!\n";
                break;
            }
            case 3: {
                CannotConvertValueError err;
                err.input();
                stackErrors.push(err);
                cout << "Добавлено в стек!\n";
                break;
            }
            case 4: {
                CannotCastToInterfaceError err;
                err.input();
                vectorErrors.push_back(err);
                cout << "Добавлено в вектор!\n";
                break;
            }
            case 5: {
                if (!dequeErrors.empty()) {
                    dequeErrors.pop_front();
                    cout << "Удалено из очереди!\n";
                } else {
                    cout << "Очередь пустая!\n";
                }
                break;
            }
            case 6: {
                if (!listErrors.empty()) {
                    listErrors.pop_front();
                    cout << "Удалено из списка!\n";
                } else {
                    cout << "Список пуст!\n";
                }
                break;
            }
            case 7: {
                if (!stackErrors.empty()) {
                    stackErrors.pop();
                    cout << "Удалено из стека!\n";
                } else {
                    cout << "Стек пуст!\n";
                }
                break;
            }
            case 8: {
                if (!vectorErrors.empty()) {
                    vectorErrors.pop_back();
                    cout << "Удалено из вектора!\n";
                } else {
                    cout << "Вектор пуст!\n";
                }
                break;
            }
            case 9: {
                cout << "\n    ОЧЕРЕДЬ (Privileges)    \n";
                for (int i = 0; i < dequeErrors.size(); i++) {
                    cout << i + 1 << ": ";
                    dequeErrors[i].print();
                    cout << "\n";
                }
                
                cout << "\n   СПИСОК (Conversion)    \n";
                int idx = 1;
                for (auto it = listErrors.begin(); it != listErrors.end(); ++it) {
                    cout << idx++ << ": ";
                    (*it).print();
                    cout << "\n";
                }
                
                cout << "\n   СТЕК (CannotConvert)    \n";
                stack<CannotConvertValueError> tempStack = stackErrors;
                idx = 1;
                while (!tempStack.empty()) {
                    cout << idx++ << ": ";
                    tempStack.top().print();
                    cout << "\n";
                    tempStack.pop();
                }
                
                cout << "\n   ВЕКТОР (CannotCast)    \n";
                for (int i = 0; i < vectorErrors.size(); i++) {
                    cout << i + 1 << ": ";
                    vectorErrors[i].print();
                    cout << "\n";
                }
                break;
            }
            case 10: {
                ofstream outFile("errors.txt");
                if (!outFile.is_open()) {
                    cout << "Ошибка открытия файла!\n";
                    break;
                }
                
                int idx = 1;
                
                cout << "\n    ДО СОРТИРОВКИ    \n";
                outFile << "    ДО СОРТИРОВКИ    \n\n";
                
                // ОЧЕРЕДЬ 
                cout << "\nОЧЕРЕДЬ до сортировки:\n";
                outFile << "ОЧЕРЕДЬ до сортировки:\n";
                for (int i = 0; i < dequeErrors.size(); i++) {
                    dequeErrors[i].print();
                    cout << "\n";
                    outFile << i+1 << ": ";
                    dequeErrors[i].print();
                    outFile << "\n";
                }
                
                // СПИСОК 
                cout << "\nСПИСОК до сортировки:\n";
                outFile << "\nСПИСОК до сортировки:\n";
                idx = 1;
                for (auto it = listErrors.begin(); it != listErrors.end(); ++it) {
                    (*it).print();
                    cout << "\n";
                    outFile << idx++ << ": ";
                    (*it).print();
                    outFile << "\n";
                }
                
                // СТЕК 
                cout << "\nСТЕК до сортировки:\n";
                outFile << "\nСТЕК до сортировки:\n";
                stack<CannotConvertValueError> tempStk = stackErrors;
                idx = 1;
                while (!tempStk.empty()) {
                    tempStk.top().print();
                    cout << "\n";
                    outFile << idx++ << ": ";
                    tempStk.top().print();
                    outFile << "\n";
                    tempStk.pop();
                }
                
                // ВЕКТОР 
                cout << "\nВЕКТОР до сортировки:\n";
                outFile << "\nВЕКТОР до сортировки:\n";
                for (int i = 0; i < vectorErrors.size(); i++) {
                    vectorErrors[i].print();
                    cout << "\n";
                    outFile << i+1 << ": ";
                    vectorErrors[i].print();
                    outFile << "\n";
                }
                
                // СОРТИРУЕМ ВСЁ
                selectionSortDesc(dequeErrors);
                sortListDesc(listErrors);
                selectionSortDesc(stackErrors);
                selectionSortDesc(vectorErrors);
                
                cout << "\n    ПОСЛЕ СОРТИРОВКИ    \n";
                outFile << "\n    ПОСЛЕ СОРТИРОВКИ    \n\n";
                
                // ОЧЕРЕДЬ 
                cout << "\nОЧЕРЕДЬ после сортировки (по уровню, убывание):\n";
                outFile << "\nОЧЕРЕДЬ после сортировки (по уровню, убывание):\n";
                for (int i = 0; i < dequeErrors.size(); i++) {
                    dequeErrors[i].print();
                    cout << "\n";
                    outFile << i+1 << ": ";
                    dequeErrors[i].print();
                    outFile << "\n";
                }
                
                // СПИСОК 
                cout << "\nСПИСОК после сортировки (по коду, убывание):\n";
                outFile << "\nСПИСОК после сортировки (по коду, убывание):\n";
                idx = 1;
                for (auto it = listErrors.begin(); it != listErrors.end(); ++it) {
                    (*it).print();
                    cout << "\n";
                    outFile << idx++ << ": ";
                    (*it).print();
                    outFile << "\n";
                }
                
                // СТЕК 
                cout << "\nСТЕК после сортировки (по коду, убывание):\n";
                outFile << "\nСТЕК после сортировки (по коду, убывание):\n";
                tempStk = stackErrors;
                idx = 1;
                while (!tempStk.empty()) {
                    tempStk.top().print();
                    cout << "\n";
                    outFile << idx++ << ": ";
                    tempStk.top().print();
                    outFile << "\n";
                    tempStk.pop();
                }
                
                // ВЕКТОР 
                cout << "\nВЕКТОР после сортировки (по коду, убывание):\n";
                outFile << "\nВЕКТОР после сортировки (по коду, убывание):\n";
                for (int i = 0; i < vectorErrors.size(); i++) {
                    vectorErrors[i].print();
                    cout << "\n";
                    outFile << i+1 << ": ";
                    vectorErrors[i].print();
                    outFile << "\n";
                }
                
                outFile.close();
                cout << "\nВсе данные сохранены в файл 'errors.txt'\n";
                break;
            }
            default:
                cout << "Неверный выбор!\n";
        }
    }
    
    cout << "Программа завершена.\n";
    return 0; // программа завершена успешно
}
