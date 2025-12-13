#include <iostream>   
#include <random>     
#include <iomanip>    

using namespace std;  

int main() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100);

    int rows1, cols1;
    int rows2, cols2;
    
    cout << "Введите размеры первой матрицы (строки, столбцы): ";
    cin >> rows1 >> cols1;
    
    cout << "Введите размеры второй матрицы (строки, столбцы): ";
    cin >> rows2 >> cols2;
    
    if (rows1 == rows2 && cols1 == cols2) {
        cout << "Ошибка: матрицы должны быть разного размера!" << endl;
        return 1;
    }

    int** matrix1 = new int*[rows1];
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = new int[cols1];
    }
    
    cout << "\nМатрица 1 (" << rows1 << "x" << cols1 << "):" << endl;
    cout << string(cols1 * 5, '-') << endl;
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = dis(gen);  
            cout << setw(4) << matrix1[i][j];
        }
        cout << endl;  
    }
    cout << string(cols1 * 5, '-') << endl;

    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = new int[cols2];
    }
    
    cout << "\nМатрица 2 (" << rows2 << "x" << cols2 << "):" << endl;
    cout << string(cols2 * 5, '-') << endl;
    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = dis(gen);
            cout << setw(4) << matrix2[i][j];
        }
        cout << endl;
    }
    cout << string(cols2 * 5, '-') << endl;

    long long product1 = 1;
    bool hasNonZero1 = false;
    
    cout << "\nВычисляем произведение ненулевых элементов матрицы 1:" << endl;
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            if (matrix1[i][j] != 0) {
                product1 *= matrix1[i][j];
                hasNonZero1 = true;
                cout << "Умножаем на " << matrix1[i][j] 
                     << ", текущее произведение: " << product1 << endl;
            }
        }
    }
    
    if (!hasNonZero1) {
        product1 = 0;
    }
    cout << "Итоговое произведение для матрицы 1: " << product1 << endl;

    long long product2 = 1;
    bool hasNonZero2 = false;
    
    cout << "\nВычисляем произведение ненулевых элементов матрицы 2:" << endl;
    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            if (matrix2[i][j] != 0) {
                product2 *= matrix2[i][j];
                hasNonZero2 = true;
                cout << "Умножаем на " << matrix2[i][j] 
                     << ", текущее произведение: " << product2 << endl;
            }
        }
    }
    
    if (!hasNonZero2) {
        product2 = 0;
    }
    cout << "Итоговое произведение для матрицы 2: " << product2 << endl;

    cout << "\nСравниваем произведения:" << endl;
    cout << "Матрица 1: " << product1 << endl;
    cout << "Матрица 2: " << product2 << endl;
    
    int** selectedMatrix;
    int selectedRows, selectedCols;
    string selectedName;
    
    if (product1 > product2) {
        cout << "Выбираем матрицу 1 (произведение больше)" << endl;
        selectedMatrix = matrix1;
        selectedRows = rows1;
        selectedCols = cols1;
        selectedName = "1";
    } else if (product2 > product1) {
        cout << "Выбираем матрицу 2 (произведение больше)" << endl;
        selectedMatrix = matrix2;
        selectedRows = rows2;
        selectedCols = cols2;
        selectedName = "2";
    } else {
        cout << "Произведения равны. Выбираем матрицу 1 по умолчанию." << endl;
        selectedMatrix = matrix1;
        selectedRows = rows1;
        selectedCols = cols1;
        selectedName = "1";
    }

    cout << "\nАнализ выбранной матрицы " << selectedName << ":" << endl;
    cout << "Количество положительных элементов по строкам:" << endl;
    
    int* positiveCount = new int[selectedRows];
    
    for (int i = 0; i < selectedRows; i++) {
        positiveCount[i] = 0;
    }
    
    for (int i = 0; i < selectedRows; i++) {
        cout << "Строка " << (i + 1) << ": [";
        
        for (int j = 0; j < selectedCols; j++) {
            cout << setw(4) << selectedMatrix[i][j];
            
            if (selectedMatrix[i][j] > 0) {
                positiveCount[i]++;
            }
        }
        cout << "] -> " << positiveCount[i] << " положительных элементов" << endl;
    }

    int** smallMatrix;
    int smallRows, smallCols;
    int** bigMatrix;
    int bigRows, bigCols;
    
    if (rows1 * cols1 < rows2 * cols2) {
        smallMatrix = matrix1;
        smallRows = rows1;
        smallCols = cols1;
        bigMatrix = matrix2;
        bigRows = rows2;
        bigCols = cols2;
        cout << "\nМатрица 1 меньшего размера" << endl;
    } else {
        smallMatrix = matrix2;
        smallRows = rows2;
        smallCols = cols2;
        bigMatrix = matrix1;
        bigRows = rows1;
        bigCols = cols1;
        cout << "\nМатрица 2 меньшего размера" << endl;
    }

    if (smallRows == smallCols) {
        bool* zeroRows = new bool[smallRows];
        bool* zeroCols = new bool[smallCols];
        
        for (int i = 0; i < smallRows; i++) {
            zeroRows[i] = false;
            zeroCols[i] = false;
        }
        
        for (int i = 0; i < smallRows; i++) {
            for (int j = 0; j < smallCols; j++) {
                if (smallMatrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        
        for (int i = 0; i < smallRows; i++) {
            if (zeroRows[i] || zeroCols[i]) {
                for (int k = 0; k < smallRows; k++) {
                    int temp = smallMatrix[i][k];
                    smallMatrix[i][k] = smallMatrix[k][i];
                    smallMatrix[k][i] = temp;
                }
            }
        }
        
        delete[] zeroRows;
        delete[] zeroCols;
        
        cout << "Меньшая матрица после обмена строк и столбцов с нулями:" << endl;
        for (int i = 0; i < smallRows; i++) {
            for (int j = 0; j < smallCols; j++) {
                cout << setw(4) << smallMatrix[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "Меньшая матрица не квадратная, операция не выполнена" << endl;
    }

    cout << "\nПреобразование большей матрицы:" << endl;
    
    int** newBigMatrix = new int*[bigRows];
    for (int i = 0; i < bigRows; i++) {
        newBigMatrix[i] = new int[bigCols];
        for (int j = 0; j < bigCols; j++) {
            newBigMatrix[i][j] = bigMatrix[i][j];
        }
    }
    
    for (int i = 0; i < bigRows; i += 2) {
        for (int j = 1; j < bigCols; j += 2) {
            if (i < bigCols && j < bigRows) {
                int temp = newBigMatrix[i][j];
                newBigMatrix[i][j] = newBigMatrix[j][i];
                newBigMatrix[j][i] = temp;
            } else {
                if (i < bigRows && j < bigCols) {
                    newBigMatrix[i][j] = 1;
                }
                if (j < bigRows && i < bigCols) {
                    newBigMatrix[j][i] = 1;
                }
            }
        }
    }
    
    cout << "Большая матрица после обмена:" << endl;
    for (int i = 0; i < bigRows; i++) {
        for (int j = 0; j < bigCols; j++) {
            cout << setw(4) << newBigMatrix[i][j];
        }
        cout << endl;
    }
    
    for (int i = 0; i < bigRows; i++) {
        delete[] newBigMatrix[i];
    }
    delete[] newBigMatrix;

    for (int i = 0; i < rows1; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    
    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    
    delete[] positiveCount;
    
    return 0;
}
