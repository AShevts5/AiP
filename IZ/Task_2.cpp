#include <iostream> // библиотека для ввода-вывода
#include <string> // библиотека для работы со строками
#include <iomanip> // для функций fixed и setprecision

using namespace std; // чтобы не писать std::

struct Child {
    string name;    
    string gender;  
    double height;  
};

bool isGirl(const string& g) {
    if (g.empty()) return false;

    char c = g[0];
    if (c == 'f' || c == 'F') return true;
    if (g == "ж" || g == "Ж" || g == "д" || g == "Д" || g == "девочка" || g == "Девочка") return true;

    return false;
}

int main() { // главный метод программы
    const int N = 20;
    Child kids[N];

    cout << "Введите данные по 20 детям.\n";
    cout << "Формат: имя пол рост\n";
    cout << "Пример: Anna ж 165\n\n";

    for (int i = 0; i < N; ++i) {
        cout << "Ребенок №" << i + 1 << ": ";
        cin >> kids[i].name >> kids[i].gender >> kids[i].height;
    }

    // Средний рост девочек
    double sumGirls = 0.0;
    int countGirls = 0;

    for (int i = 0; i < N; ++i) {
        if (isGirl(kids[i].gender)) {
            sumGirls += kids[i].height;
            countGirls++;
        }
    }

    if (countGirls > 0) {
        double avg = sumGirls / countGirls;
        cout << "\nСредний рост девочек: " << fixed << setprecision(2) << avg << "\n";
    } else {
        cout << "\nДевочки не найдены, средний рост вычислить нельзя.\n";
    }

    // Сортировка по имени 
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (kids[j].name > kids[j + 1].name) {
                Child temp = kids[j];
                kids[j] = kids[j + 1];
                kids[j + 1] = temp;
            }
        }
    }

    cout << "\nСписок детей по алфавиту:\n";
    cout << "Имя: \tПол: \tРост: \n";
    for (int i = 0; i < N; ++i) {
        cout << kids[i].name << "\t" << kids[i].gender << "\t" << kids[i].height << "\n";
    }

    return 0;
}
