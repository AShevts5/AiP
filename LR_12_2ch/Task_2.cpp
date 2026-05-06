#include <iostream> // библиотека для ввода-вывода

//чтобы не писать std:: 
using namespace std;

// Базовый класс Средство передвижения
class Vehicle {
public:
    virtual void showInfo() const {
        cout << "Неизвестное средство передвижения";
    }

    // Виртуальный деструктор
    virtual ~Vehicle() {}
};

// Производный класс "Велосипед"
class Bicycle : public Vehicle {
public:
    void showInfo() const override {
        cout << "Велосипед";
    }
};

// Производный класс "Автомобиль"
class Car : public Vehicle {
public:
    void showInfo() const override {
        cout << "Автомобиль";
    }
};

// Производный класс "Грузовик"
class Truck : public Vehicle {
public:
    void showInfo() const override {
        cout << "Грузовик";
    }
};


// шаблонный класс для массива указателей

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
    // Конструктор
    PtrArray() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    // Деструктор
    ~PtrArray() {
        clear();
        delete[] data;
    }

    // Добавление в конец
    void addBack(T* obj) {
        if (size >= capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            resizeBuffer(newCap);
        }
        data[size] = obj;
        size++;
    }

    // Вставка по индексу
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

    // Удаление по индексу
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

    // Усечение массива
    void truncate(int newSize) {
        if (newSize < 0 || newSize > size) {
            throw "Ошибка: некорректный размер для усечения.";
        }

        for (int i = newSize; i < size; ++i) {
            delete data[i];
        }
        size = newSize;
    }

    // Очистка всего массива
    void clear() {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }
        size = 0;
    }

    // Перегрузка оператора []
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

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

void printMenu() {
    cout << "\n    МЕНЮ    " << endl;
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
                case 1:
                    vehicles.addBack(new Bicycle());
                    cout << "Добавлен: Велосипед." << endl;
                    break;
                case 2:
                    vehicles.addBack(new Car());
                    cout << "Добавлен: Автомобиль." << endl;
                    break;
                case 3:
                    vehicles.addBack(new Truck());
                    cout << "Добавлен: Грузовик." << endl;
                    break;
                case 4: {
                    int index;
                    cout << "Введите индекс для вставки (от 0 до " << vehicles.getSize() << "): ";
                    cin >> index;

                    int type;
                    cout << "Какой объект вставить? (1-Велосипед, 2-Авто, 3-Грузовик): ";
                    cin >> type;

                    Vehicle* newObj = nullptr;
                    if (type == 1) newObj = new Bicycle();
                    else if (type == 2) newObj = new Car();
                    else if (type == 3) newObj = new Truck();
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
