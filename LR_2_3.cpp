#include <iostream>
#include <string>  

using namespace std;

int count(string text) {
    int count = 0;  
    
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            count++; 
        }
    }
    
    return count; 
}

int main() {
    string S1, S2;
    
    cout << "Введите первую строку (S1): ";
    getline(cin, S1);  
    cout << "Введите вторую строку (S2): ";
    getline(cin, S2);  
    
    int digits_S1 = count(S1);
    int digits_S2 = count(S2);
    
    cout << "Количество цифр в S1: " << digits_S1 << endl;
    cout << "Количество цифр в S2: " << digits_S2 << endl;
    
    if (digits_S1 == digits_S2) {
        cout << "Количество цифр в текстах совпадает." << endl;
    } else {
        cout << "Количество цифр в текстах не совпадает." << endl;
    }
    
    return 0;
}
