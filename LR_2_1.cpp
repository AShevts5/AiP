#include <iostream>
using namespace std;

int S(int H, int a) {
	int V = H*a*a;
	return V;

}

int main() {
    
    int H, a, V;
    cout << "Вычисляем объём 1 призмы: " << endl;
    cout << "Введите высоту (H): " << endl;
    cin >> H;
    cout << "Введите сторону основания (a): " << endl;
    cin >> a;
    V = S(H, a);
    printf("Объём 1 призмы = %d\n", V);
    
    cout << "Вычисляем объём 2 призмы: " << endl;
    cout << "Введите высоту (H): " << endl;
    cin >> H;
    cout << "Введите сторону основания (a): " << endl;
    cin >> a;
    V = S(H, a);
    printf("Объём 2 призмы = %d", V);
    
    return 0;
}
