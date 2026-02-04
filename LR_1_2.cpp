#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Способ 1: с использованием цикла for
    /*
    double p = 1.0;
    for (int k = 1; k <= 8; k++) {
        p *= (k + pow(2, k)); 
    }
    
    double sum = 0.0;  
    for (int j = 3; j <= 9; j++) {
        sum += sin(2 * j); 
    }
    
    double y = p + sum;
    cout << "y = " << y << endl;
    */
    
    // Способ 2: с использованием цикла do..while
    
    /*
    double p = 1.0;
    int k = 1; 
    do {
        p *= (k + pow(2, k)); 
        k++;
    } while (k <= 8); 
    

    double sum = 0.0;
    int j = 3; 
    do {
        sum += sin(2 * j); 
        j++;
    } while (j <= 9); 
    
    double y = p + sum;
    cout << "y = " << y << endl;
    */
    
    // Способ 3: с использованием цикла while
    
    double p = 1.0;
    int k = 1; 
    while (k <= 8) {
        p *= (k + pow(2, k)); 
        k++;
    }
    
    double sum = 0.0;
    int j = 3;
    while (j <= 9) {
        sum += sin(2 * j);
        j++;
    }
    
    double y = p + sum;
    cout << "y = " << y << endl;
    
    return 0;
}
