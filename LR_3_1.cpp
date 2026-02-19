#include <stdio.h> // библиотека ввода-вывода (printf, scanf, fopen, fclose и т.д.)

int main() // главный метод программы
{
    // создание файла F1 с 10 строками
    
    FILE *f1 = fopen("F1.txt", "w");  // открываем файл для записи 
    
    if (f1 == NULL)  // если не удалось открыть файл
    {
        printf("File creation error F1.txt\n");
        return 1;
    }
    
    // Записываем 10 строк
    for (int i = 1; i <= 10; i++)
    {
        fprintf(f1, "This is line number %d in the F1 file\n", i);
    }
    
    fclose(f1);  // закрываем файл
    printf("The F1.txt file is created and filled with 10 lines\n");
    
    // копирование строк с K по K+5 в файл F2
    
    FILE *f1_read = fopen("F1.txt", "r");  // открываем F1 для чтения 
    FILE *f2 = fopen("F2.txt", "w");        // открываем F2 для записи
    
    if (f1_read == NULL)
    {
        printf("Error opening F1.txt file for reading\n");
        return 1;
    }
    
    if (f2 == NULL)
    {
        printf("File creation error F2.txt\n");
        fclose(f1_read);
        return 1;
    }
    
    int k;
    printf("Enter the line number K (from 1 to 6):");
    scanf("%d", &k);
    
    // Проверяем корректность ввода
    if (k < 1 || k > 6)
    {
        printf("K must be between 1 and 6 to copy K to K+5 (6 rows total)\n");
        fclose(f1_read);
        fclose(f2);
        return 1;
    }
    
    char s[256];  // массив для хранения строки (максимум 255 символов)
    int num = 1;     // счетчик строк
    
    // Читаем файл построчно до конца
    while (fgets(s, sizeof(s), f1_read) != NULL)
    {
        // Если текущая строка попадает в диапазон от K до K+5
        if (num >= k && num <= k + 5)
        {
            fputs(s, f2);  // записываем строку в F2
        }
        num++;
    }
    
    fclose(f1_read);
    fclose(f2);
    
    printf("Lines from %d to %d have been copied to the F2.txt file.\n", k, k + 5);
    
    return 0; // программа завершилась успешно
}
