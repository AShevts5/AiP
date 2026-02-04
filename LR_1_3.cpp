#include <iostream>
using namespace std;

int main() {
    int n, m; 
    
    cout << "Введите количество строк матрицы (n): ";
    cin >> n;
    cout << "\nВведите количество столбцов матрицы (m): ";
    cin >> m;
    
    double** A = new double*[n];
    
    for (int i = 0; i < n; i++) {
        A[i] = new double[m];
    }
    
    cout << "\nВведите элементы матрицы " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    
    double* averages = new double[m];
    
    for (int j = 0; j < m; j++) {
        double sum = 0.0;   
        int count = 0;    
        
        for (int i = 0; i < n; i++) {
            if (A[i][j] > 0) { 
                sum += A[i][j];
                count++;
            }
        }
        
        if (count > 0) {
            averages[j] = sum / count; 
        } else {
            averages[j] = 0.0; 
        }
    }
    
    cout << "\nИсходная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nОдномерный массив средних значений: ";
    cout << "[ ";
    for (int j = 0; j < m; j++) {
        cout << averages[j];
        if (j < m - 1) cout << ", ";
    }
    cout << " ]" << endl;
    
    return 0;
}
