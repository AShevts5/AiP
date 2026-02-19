#include <stdio.h> // библиотека для ввода-вывода (printf, scanf, fopen, fclose)
#include <stdlib.h> // для функции remove

int main() // главный метод программы
{
    int choice; // хранит выбор команды
    char filename[100] = "materials.txt";
    
    while (1)  // бесконечный цикл для меню
    {
        // Выводим меню
        printf("\n--- МЕНЮ ---\n");
        printf("1 - создание файла\n");
        printf("2 - просмотр содержимого файла\n");
        printf("3 - удаление файла\n");
        printf("4 - выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        
        if (choice == 1)
        {
            // Создание файла
            FILE *f = fopen(filename, "w");
            
            if (f == NULL)
            {
                printf("Ошибка создания файла!\n");
                continue;
            }
            
            int n;
            printf("Сколько записей добавить? ");
            scanf("%d", &n);
            
            char name[50];
            float price;
            int quantity;
            
            for (int i = 0; i < n; i++)
            {
                printf("\nЗапись %d:\n", i + 1);
                
                printf("Наименование материала: ");
                scanf("%s", name);  
                
                printf("Цена за единицу (руб): ");
                scanf("%f", &price);
                
                printf("Количество (шт): ");
                scanf("%d", &quantity);
                
                // Записываем в файл
                fprintf(f, "%s %.2f %d\n", name, price, quantity);
            }
            
            fclose(f);
            printf("\nФайл успешно создан!\n");
        }
        else if (choice == 2)
        {
            // Просмотр файла
            FILE *f = fopen(filename, "r");
            
            if (f == NULL)
            {
                printf("Файл не существует или не может быть открыт!\n");
                continue;
            }
            
            // Выводим названия столбцов таблицы
            printf("\n");
            printf(" Наименование  Цена за ед.  Количество    Сумма   \n");
            
            char name[50];
            float price;
            int quantity;
            float summa;
            float total_sum = 0;
            
            // Читаем и выводим записи
            while (fscanf(f, "%s %f %d", name, &price, &quantity) == 3)
            {
                summa = price * quantity;
                total_sum = total_sum + summa;
                // форматирование для более аккуратного представления данных в таблице
                printf(" %-12s  %11.2f  %10d  %9.2f \n", name, price, quantity, summa);
            }
            
            printf(" Итого: %52.2f \n", total_sum);
            
            fclose(f);
        }
        else if (choice == 3)
        {
            // Удаление файла
            if (remove(filename) == 0)
            {
                printf("Файл удален!\n");
            }
            else
            {
                printf("Ошибка удаления файла (возможно, файл не существует)\n");
            }
        }
        else if (choice == 4)
        {
            // Выход
            printf("Программа завершена.\n");
            break;
        }
        else
        {
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    }
    
    return 0; // программа успешно завершена
}
