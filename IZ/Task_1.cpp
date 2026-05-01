#include <iostream> // библиотека для ввода-вывода
#include <vector> // вектор
#include <string> // библиотека для работы со строками
#include <algorithm> // для функции sort

using namespace std; // чтобы не писать std::

bool endsWith(const string& s, const string& suffix) {
    if (s.size() < suffix.size()) return false;

    for (size_t i = 0; i < suffix.size(); ++i) {
        if (s[s.size() - suffix.size() + i] != suffix[i]) {
            return false;
        }
    }
    return true;
}

int main() { // главный метод программы
    vector<string> peaks = {
        "Алатау", "KhanTau", "Belukha", "Karatau", "Aksu",
        "Ортау", "Muztau", "Shymbulak", "Koktau", "Everest",
        "Жетысутау", "Tau", "тау", "Baitau", "K2",
        "Aktau", "Sarytau", "Пик Победы", "Qaratau", "Ulutau"
    };

    vector<string> filtered;

    for (const string& name : peaks) {
        if (endsWith(name, "тау") || endsWith(name, "tau")) {
            filtered.push_back(name);
        }
    }

    sort(filtered.begin(), filtered.end());

    cout << "Подходящие вершины (" << filtered.size() << "):\n";
    for (const string& name : filtered) {
        cout << name << '\n';
    }

    return 0; // программа завершена успешно
}
