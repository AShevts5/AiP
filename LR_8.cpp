#include <iostream> // библиотека для ввода-вывода
#include <cmath> // библиотека для математических операций
using namespace std; // чтобы не писать std::

class Triangle
{
    protected:
        double x1, y1; // координаты первой точки
        double x2, y2; // координаты второй точки
        double x3, y3; // координаты третьей точки
    
    public:
        Triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
        {
            x1 = x1_;
            y1 = y1_;
            x2 = x2_;
            y2 = y2_;
            x3 = x3_;
            y3 = y3_;
        }
    
        // Проверка существования треугольника
        bool exists()
        {
            // Вычисляем длины сторон
            double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            double b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
            double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    
            // Проверка неравенства треугольника
            if (a + b > c && a + c > b && b + c > a)
                return true;
            else
                return false;
        }
    
        // Вычисление длины стороны AB
        double sideAB()
        {
            return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
    
        // Вычисление длины стороны BC
        double sideBC()
        {
            return sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        }
    
        // Вычисление длины стороны CA
        double sideCA()
        {
            return sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        }
    
        // Вычисление угла при вершине A 
        double angleA()
        {
            double a = sideBC();
            double b = sideCA();
            double c = sideAB();
            // Теорема косинусов: cos A = (b^2 + c^2 - a^2) / (2*b*c)
            double cosA = (b * b + c * c - a * a) / (2 * b * c);
            return acos(cosA) * 180 / 3.14;
        }
    
        // Вычисление угла при вершине B 
        double angleB()
        {
            double a = sideBC();
            double b = sideCA();
            double c = sideAB();
            double cosB = (a * a + c * c - b * b) / (2 * a * c);
            return acos(cosB) * 180 / 3.14;
        }
    
        // Вычисление угла при вершине C 
        double angleC()
        {
            double a = sideBC();
            double b = sideCA();
            double c = sideAB();
            double cosC = (a * a + b * b - c * c) / (2 * a * b);
            return acos(cosC) * 180 / 3.14;
        }
    
        // Вычисление периметра
        double perimeter()
        {
            return sideAB() + sideBC() + sideCA();
        }
    
        // Вычисление площади по формуле Герона
        double area()
        {
            double a = sideAB();
            double b = sideBC();
            double c = sideCA();
            double p = (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
    
        // Вывод сведений о фигуре
        void printInfo()
        {
            cout << "Длины сторон: " << sideAB() << ", " << sideBC() << ", " << sideCA() << endl;
            cout << "Углы: " << angleA() << ", " << angleB() << ", " << angleC() << endl;
            cout << "Периметр: " << perimeter() << endl;
            cout << "Площадь: " << area() << endl;
        }
};

// Производный класс: прямоугольный треугольник
class RightTriangle : public Triangle
{
    public:
        RightTriangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
            : Triangle(x1_, y1_, x2_, y2_, x3_, y3_)
        {
        }
    
        // Проверка, является ли треугольник прямоугольным
        bool isRight()
        {
            double a = sideAB();
            double b = sideBC();
            double c = sideCA();
    
            // Находим наибольшую сторону
            double maxSide = a;
            double side1 = b;
            double side2 = c;
    
            if (b > maxSide)
            {
                maxSide = b;
                side1 = a;
                side2 = c;
            }
            if (c > maxSide)
            {
                maxSide = c;
                side1 = a;
                side2 = b;
            }
    
            // Проверка теоремы Пифагора с учетом погрешности вычислений
            if (abs(maxSide * maxSide - (side1 * side1 + side2 * side2)) < 0.0001)
                return true;
            else
                return false;
        }
    
        // Вычисление гипотенузы 
        double hypotenuse()
        {
            double a = sideAB();
            double b = sideBC();
            double c = sideCA();
            
            if (a >= b && a >= c)
                return a;
            else if (b >= a && b >= c)
                return b;
            else
                return c;
        }
};

int main()
{
    int N, M;

    cout << "Введите количество треугольников N: ";
    cin >> N;
    cout << "Введите количество прямоугольных треугольников M: ";
    cin >> M;

    // Массивы для хранения треугольников
    Triangle** triangles = new Triangle*[N];
    RightTriangle** rightTriangles = new RightTriangle*[M];

    // Ввод данных для N треугольников
    for (int i = 0; i < N; i++)
    {
        double x1, y1, x2, y2, x3, y3;

        cout << "\nТреугольник " << i + 1 << ":" << endl;
        cout << "Введите координаты первой точки (x y): ";
        cin >> x1 >> y1;
        cout << "Введите координаты второй точки (x y): ";
        cin >> x2 >> y2;
        cout << "Введите координаты третьей точки (x y): ";
        cin >> x3 >> y3;

        triangles[i] = new Triangle(x1, y1, x2, y2, x3, y3);

        // Проверка существования треугольника
        if (!triangles[i]->exists())
        {
            cout << "Треугольник не существует!" << endl;
        }
    }

    // Ввод данных для M прямоугольных треугольников
    cout << endl;
    cout << "Ввод данных для " << M << " прямоугольных треугольников " << endl;
    for (int i = 0; i < M; i++)
    {
        double x1, y1, x2, y2, x3, y3;

        cout << "\nПрямоугольный треугольник " << i + 1 << ":" << endl;
        cout << "Введите координаты первой точки (x y): ";
        cin >> x1 >> y1;
        cout << "Введите координаты второй точки (x y): ";
        cin >> x2 >> y2;
        cout << "Введите координаты третьей точки (x y): ";
        cin >> x3 >> y3;

        rightTriangles[i] = new RightTriangle(x1, y1, x2, y2, x3, y3);

        // Проверка существования треугольника
        if (!rightTriangles[i]->exists())
        {
            cout << "Треугольник не существует!" << endl;
        }
    }

    // Обработка N треугольников: средняя площадь и минимальный периметр
    double sumArea = 0;
    double minPerimeter = -1;
    int TrianglesCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (triangles[i]->exists())
        {
            double area = triangles[i]->area();
            double perim = triangles[i]->perimeter();

            sumArea += area;
            TrianglesCount++;

            if (minPerimeter < 0 || perim < minPerimeter)
            {
                minPerimeter = perim;
            }
        }
    }

    // Вывод результатов для N треугольников
    if (TrianglesCount > 0)
    {
        double avgArea = sumArea / TrianglesCount;
        cout << endl;
        cout << "Средняя площадь: " << avgArea << endl;
        cout << "Минимальный периметр: " << minPerimeter << endl;
    }
    else
    {
        cout << "Нет существующих треугольников!" << endl;
    }

    // Обработка M прямоугольных треугольников: найти прямоугольный треугольник с наибольшей гипотенузой
    int maxIndex = -1;
    double maxHypotenuse = -1;

    for (int i = 0; i < M; i++)
    {
        if (rightTriangles[i]->exists())
        {
            // Проверяем, является ли треугольник прямоугольным
            if (rightTriangles[i]->isRight())
            {
                double hyp = rightTriangles[i]->hypotenuse();
                if (maxHypotenuse < 0 || hyp > maxHypotenuse)
                {
                    maxHypotenuse = hyp;
                    maxIndex = i;
                }
            }
        }
    }

    // Вывод результата для прямоугольных треугольников
    if (maxIndex != -1)
    {
        cout << "Прямоугольный треугольник с наибольшей гипотенузой: " << maxIndex + 1 << endl;
        cout << "Гипотенуза: " << maxHypotenuse << endl;
        cout << "\nИнформация о треугольнике:" << endl;
        rightTriangles[maxIndex]->printInfo();
    }
    else
    {
        cout << "Нет существующих прямоугольных треугольников!" << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++)
    {
        delete triangles[i];
    }
    delete[] triangles;

    for (int i = 0; i < M; i++)
    {
        delete rightTriangles[i];
    }
    delete[] rightTriangles;

    return 0; // программа завершена успешно
}
