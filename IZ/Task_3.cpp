#include <stdio.h> // для форматированного ввода-вывода
#include <stdlib.h> // для рандомной функции
#include <time.h> // для time()

class IntStack {
    private:
        static const int kCapacity = 100;
        int data[kCapacity]; // массив стека 
        int *top;           
    
    public:
        IntStack() : top(data - 1) {}
    
        // Запись в вершину стека 
        bool push(int value) {
            if (top >= data + kCapacity - 1)
                return 0; 
            *++top = value;
            return 1;
        }
    
        // Чтение вершины стека 
        bool read(int *out) const {
            if (top < data)
                return 0; 
            if (out)
                *out = *top;
            return 1;
        }
    
        int empty() const { return top < data; }
};

int main(void) {
    IntStack s;

    srand((unsigned int)time(NULL));

    int i;
    for (i = 0; i < 3; i++) {
        int r = rand() % 100;
        s.push(r);
        printf("Записано в стек: %d\n", r);
    }

    int x;
    if (s.read(&x))
        printf("Вершина после трёх записей: %d\n", x);

    s.read(&x);
    printf("Повторное чтение: %d\n", x);

    return 0;
}
