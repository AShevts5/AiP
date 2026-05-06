#include <iostream> // библиотека для ввода-вывода
#include <string> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

// Базовый класс Средство передвижения
class Vehicle {
    protected:
        string number;  // Номер средства передвижения
        string color;   // Цвет средства передвижения
    
    public:
        // Конструктор с параметрами
        Vehicle(const string& num = "", const string& col = "") 
            : number(num), color(col) {}
    
        virtual void showInfo() const {
            cout << "Неизвестное средство передвижения" 
                 << " (Номер: " << (number.empty() ? "не указан" : number) 
                 << ", Цвет: " << (color.empty() ? "не указан" : color) << ")";
        }
    
        // Геттеры для доступа к атрибутам
        string getNumber() const { return number; }
        string getColor() const { return color; }
    
        // Виртуальный деструктор
        virtual ~Vehicle() {}
};

// Производный класс "Велосипед"
class Bicycle : public Vehicle {
public:
    Bicycle(const string& num = "", const string& col = "") 
        : Vehicle(num, col) {}

    void showInfo() const override {
        cout << "Велосипед" 
             << " (Номер: " << (number.empty() ? "не указан" : number) 
             << ", Цвет: " << (color.empty() ? "не указан" : color) << ")";
    }
};

// Производный класс "Автомобиль"
class Car : public Vehicle {
public:
    Car(const string& num = "", const string& col = "") 
        : Vehicle(num, col) {}

    void showInfo() const override {
        cout << "Автомобиль" 
             << " (Номер: " << (number.empty() ? "не указан" : number) 
             << ", Цвет: " << (color.empty() ? "не указан" : color) << ")";
    }
};

// Производный класс "Грузовик"
class Truck : public Vehicle {
public:
    Truck(const string& num = "", const string& col = "") 
        : Vehicle(num, col) {}

    void showInfo() const override {
        cout << "Грузовик" 
             << " (Номер: " << (number.empty() ? "не указан" : number) 
             << ", Цвет: " << (color.empty() ? "не указан" : color) << ")";
    }
};

// Шаблонный класс для массива указателей
template <typename T>
class PtrArray {
private:
    T** data;      
    int size;      
    int capacity;  

    void resizeBuffer(int newCapacity) {
        if (newCapacity <= 0) {
            throw "Ошибка: размер массива должен быть положительным.";
        }

        T** newData = new T*[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;  
        data = newData;
        capacity = newCapacity;
    }

public:
    // конструктор
    PtrArray() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }
    // деструктор
    ~PtrArray() {
        clear();
        delete[] data;
    }
    // добавление в конец
    void addBack(T* obj) {
        if (size >= capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            resizeBuffer(newCap);
        }
        data[size] = obj;
        size++;
    }
    // вставка по индексу
    void insertAt(int index, T* obj) {
        if (index < 0 || index > size) {
            throw "Ошибка: неверный индекс для вставки.";
        }

        if (size >= capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            resizeBuffer(newCap);
        }

        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = obj;
        size++;
    }
    // удаление по индексу
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw "Ошибка: неверный индекс для удаления.";
        }

        delete data[index];

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
    // усечение массива
    void truncate(int newSize) {
        if (newSize < 0 || newSize > size) {
            throw "Ошибка: некорректный размер для усечения.";
        }

        for (int i = newSize; i < size; ++i) {
            delete data[i];
        }
        size = newSize;
    }
    // очистка всего массива
    void clear() {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        size = 0;
    }
    // перегрузка оператора
    T*& operator[](int index) {
        if (index < 0 || index >= size) {
            throw "Ошибка: обращение к несуществующему индексу.";
        }
        return data[index];
    }

    const T* operator[](int index) const {
        if (index < 0 || index >= size) {
            throw "Ошибка: обращение к несуществующему индексу.";
        }
        return data[index];
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

// Вспомогательная функция для ввода номера и цвета
void getVehicleData(string& number, string& color) {
    cin.ignore(); // Очистка буфера ввода
    cout << "Введите номер средства передвижения: ";
    getline(cin, number);
    cout << "Введите цвет средства передвижения: ";
    getline(cin, color);
}

void printMenu() {
    cout << "\n     МЕНЮ    " << endl;
    cout << "1. Добавить велосипед" << endl;
    cout << "2. Добавить автомобиль" << endl;
    cout << "3. Добавить грузовик" << endl;
    cout << "4. Вставить элемент по индексу" << endl;
    cout << "5. Удалить элемент по индексу" << endl;
    cout << "6. Усечь массив (оставить N первых)" << endl;
    cout << "7. Показать все элементы" << endl;
    cout << "8. Очистить массив" << endl;
    cout << "9. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() { // главный метод программы
    PtrArray<Vehicle> vehicles;

    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    string number, color;
                    getVehicleData(number, color);
                    vehicles.addBack(new Bicycle(number, color));
                    cout << "Добавлен: Велосипед." << endl;
                    break;
                }
                case 2: {
                    string number, color;
                    getVehicleData(number, color);
                    vehicles.addBack(new Car(number, color));
                    cout << "Добавлен: Автомобиль." << endl;
                    break;
                }
                case 3: {
                    string number, color;
                    getVehicleData(number, color);
                    vehicles.addBack(new Truck(number, color));
                    cout << "Добавлен: Грузовик." << endl;
                    break;
                }
                case 4: {
                    int index;
                    cout << "Введите индекс для вставки (от 0 до " << vehicles.getSize() << "): ";
                    cin >> index;

                    int type;
                    cout << "Какой объект вставить? (1-Велосипед, 2-Авто, 3-Грузовик): ";
                    cin >> type;

                    string number, color;
                    getVehicleData(number, color);

                    Vehicle* newObj = nullptr;
                    if (type == 1) newObj = new Bicycle(number, color);
                    else if (type == 2) newObj = new Car(number, color);
                    else if (type == 3) newObj = new Truck(number, color);
                    else {
                        throw "Ошибка: неизвестный тип объекта.";
                    }

                    vehicles.insertAt(index, newObj);
                    cout << "Элемент успешно вставлен." << endl;
                    break;
                }
                case 5: {
                    int index;
                    cout << "Введите индекс для удаления (от 0 до " << (vehicles.getSize() - 1) << "): ";
                    cin >> index;
                    vehicles.removeAt(index);
                    cout << "Элемент удален." << endl;
                    break;
                }
                case 6: {
                    int newSize;
                    cout << "До какого размера усечь массив? (текущий: " << vehicles.getSize() << "): ";
                    cin >> newSize;
                    vehicles.truncate(newSize);
                    cout << "Массив усечен." << endl;
                    break;
                }
                case 7:
                    if (vehicles.isEmpty()) {
                        cout << "Список пуст." << endl;
                    } else {
                        cout << "Содержимое массива:" << endl;
                        for (int i = 0; i < vehicles.getSize(); ++i) {
                            cout << "[" << i << "] ";
                            vehicles[i]->showInfo();
                            cout << endl;
                        }
                    }
                    break;
                case 8:
                    vehicles.clear();
                    cout << "Массив очищен." << endl;
                    break;
                case 9:
                    cout << "Завершение работы..." << endl;
                    running = false;
                    break;
                default:
                    cout << "Неверный выбор. Попробуйте снова." << endl;
                    break;
            }
        } catch (const char* errorMsg) {
            cerr << "\nОШИБКА: " << errorMsg << endl;
        } catch (...) {
            cerr << "\nНЕИЗВЕСТНАЯ ОШИБКА!" << endl;
        }
    }

    return 0; // программа завершена успешно
}
