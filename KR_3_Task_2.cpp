#include <iostream> // библиотека для ввода-вывода
#include <cmath> // библиотека для мат функций
#include <string> // библиотека для работы со строками

using namespace std; // чтобы не писать std::

// Базовый класс Треугольник
class Triangle {
public:
    double a, b, c;

    // Конструктор для инициализации сторон
    Triangle(double side_a, double side_b, double side_c) {
        a = side_a;
        b = side_b;
        c = side_c;
    }

    // Метод вычисления периметра
    double Perimeter() {
        return a + b + c;
    }

    // Метод вычисления площади (формула Герона)
    double Area() {
        double p = Perimeter() / 2.0; 
        // Формула Герона: S = sqrt(p * (p-a) * (p-b) * (p-c))
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }

    // Метод возврата информации о фигуре 
    string Info() {
        string res = "Треугольник со сторонами: " 
                   + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + "\n"
                   + "Периметр: " + to_string(Perimeter()) + "\n"
                   + "Площадь: " + to_string(Area());
        return res;
    }
};

// Класс-наследник Четырехугольник
class Quadrilateral : public Triangle {
public:
    double d; // Четвертая сторона
    double e, f; // Диагонали

    // Конструктор
    Quadrilateral(double side_a, double side_b, double side_c, double side_d, double diag_e, double diag_f) 
        : Triangle(side_a, side_b, side_c) {
        d = side_d;
        e = diag_e;
        f = diag_f;
    }

    // Переопределение периметра (сумма 4 сторон)
    double Perimeter() {
        return a + b + c + d;
    }

    // Переопределение площади по заданной формуле
    double Area() {
        // S = sqrt(((4*e^2)*(f^2)-(b^2+d^2-a^2-c^2)^2)/16)
        double term1 = 4 * e * e * f * f;
        double term2 = (b * b + d * d - a * a - c * c);
        term2 = term2 * term2; 
        
        double s = sqrt((term1 - term2) / 16.0);
        return s;
    }

    // Переопределение метода Info
    string Info() {
        string res = "Четырехугольник со сторонами: " 
                   + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ", " + to_string(d) + "\n"
                   + "Диагонали: " + to_string(e) + ", " + to_string(f) + "\n"
                   + "Периметр: " + to_string(Perimeter()) + "\n"
                   + "Площадь: " + to_string(Area());
        return res;
    }
};

int main() { // главный метод программы
    Triangle tr(3.0, 4.0, 5.0);

    cout << "Информация о треугольнике " << endl;
    cout << tr.Info() << endl;
    cout << endl;
    double side = 10.0;
    double diagonal = side * sqrt(2.0);

    Quadrilateral quad(side, side, side, side, diagonal, diagonal);

    cout << "Информация о четырехугольнике (квадрат) " << endl;
    cout << quad.Info() << endl;

    return 0;
}
