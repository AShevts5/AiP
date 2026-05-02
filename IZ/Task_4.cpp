#include <iostream> // библиотека для ввода-вывода
#include <limits> // чтобы корректно вызвать ignore()
#include <string> // библиотека для работы со строками
using namespace std; // чтобы не писать std::

class Error {
public:
    virtual ~Error() = default;

    virtual void Print() const = 0;
    virtual void Read() = 0;
};

static void flush_line_rest(istream &in) {
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Недостаточно привилегий
class NotEnoughPrivilegesError : public Error {
    private:
        string required_privilege_; 
        int current_level_{0};           
    
    public:
        NotEnoughPrivilegesError()
            : required_privilege_("неизвестно"), current_level_(0) {}
    
        void Read() override {
            cout << "Введите требуемый уровень привилегий: ";
            getline(cin, required_privilege_);
            cout << "Введите текущий уровень пользователя (целое число): ";
            if (!(cin >> current_level_)) {
                current_level_ = 0;
                cin.clear();
            }
            flush_line_rest(std::cin);
        }
    
        void Print() const override {
            cout << "\nОШИБКА: НЕДОСТАТОЧНО ПРИВИЛЕГИЙ\n";
            cout << "Требуется: " << required_privilege_ << '\n';
            cout << "Текущий уровень: " << current_level_ << '\n';
            cout << "Операция отклонена.\n";
        }
};

// Ошибка преобразования 
class ConversionError : public Error {
    private:
        string from_type_;
        string to_type_;
    
    public:
        ConversionError() : from_type_("неизвестно"), to_type_("неизвестно") {}
    
        void Read() override {
            cout << "Введите исходный тип данных: ";
            getline(cin, from_type_);
            cout << "Введите целевой тип данных: ";
            getline(cin, to_type_);
        }
    
        void Print() const override {
            cout << "\nОШИБКА ПРЕОБРАЗОВАНИЯ\n";
            cout << "Невозможно преобразовать из " << from_type_ << " в " << to_type_
                      << '\n';
            cout << "Проверьте совместимость типов.\n";
        }
};

// Невозможно преобразовать значение
class CannotConvertValueError : public Error {
private:
    string bad_value_;
    string expected_format_;

public:
    CannotConvertValueError()
        : bad_value_("неизвестно"), expected_format_("неизвестно") {}

    void Read() override {
        cout << "Введите значение, которое не удалось преобразовать: ";
        getline(cin, bad_value_);
        cout << "Введите ожидаемый формат: ";
        getline(cin, expected_format_);
    }

    void Print() const override {
        cout << "\nОШИБКА: НЕВОЗМОЖНО ПРЕОБРАЗОВАТЬ ЗНАЧЕНИЕ\n";
        cout << "Значение: " << bad_value_ << '\n';
        cout << "Ожидаемый формат: " << expected_format_ << '\n';
        cout << "Значение не соответствует формату.\n";
    }
};

// Невозможно привести к интерфейсу 
class CannotCastToInterfaceError : public Error {
private:
    string object_type_;
    string interface_name_;

public:
    CannotCastToInterfaceError()
        : object_type_("неизвестно"), interface_name_("неизвестно") {}

    void Read() override {
        cout << "Введите тип объекта: ";
        getline(cin, object_type_);
        cout << "Введите имя интерфейса: ";
        getline(cin, interface_name_);
    }

    void Print() const override {
        cout << "\nОШИБКА: НЕВОЗМОЖНО ПРИВЕСТИ К ИНТЕРФЕЙСУ\n";
        cout << "Объект типа: " << object_type_ << '\n';
        cout << "Требуемый интерфейс: " << interface_name_ << '\n';
        cout << "Объект не реализует данный интерфейс.\n";
    }
};

int main() { // главный метод программы
    Error *ptr = nullptr;
    int choice;

    cout << "Выберите тип ошибки:\n";
    cout << "1 - Недостаточно привилегий\n";
    cout << "2 - Ошибка преобразования\n";
    cout << "3 - Невозможно преобразовать значение\n";
    cout << "4 - Невозможно привести к интерфейсу\n";
    cout << "Ваш выбор: ";

    if (!(cin >> choice)) {
        cout << "Ошибка ввода.\n";
        return 1;
    }
    flush_line_rest(cin);

    switch (choice) {
    case 1:
        ptr = new NotEnoughPrivilegesError();
        break;
    case 2:
        ptr = new ConversionError();
        break;
    case 3:
        ptr = new CannotConvertValueError();
        break;
    case 4:
        ptr = new CannotCastToInterfaceError();
        break;
    default:
        cout << "Неверный выбор. Программа завершена.\n";
        return 1;
    }

    cout << "\nВвод данных об ошибке\n";
    ptr->Read();

    cout << "\nИНФОРМАЦИЯ ОБ ОШИБКЕ\n";
    ptr->Print();

    delete ptr;
    ptr = nullptr;

    cout << "\nПамять освобождена. Программа завершена.\n";
    return 0; // программа завершена успешно
}
