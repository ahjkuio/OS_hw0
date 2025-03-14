#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAXLEN 100

int main(void) {
    char buf[MAXLEN];
    char *s;
    int num1, num2, sum;
    
    // Запрашиваем ввод
    printf("Enter two numbers separated by space: ");
    
    // Получаем строку
    s = gets(buf, MAXLEN);
    if(s == 0) {
        fprintf(2, "Error: Failed to read input\n");
        exit(1);
    }

    // Убираем символ новой строки
    int len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
        buf[len-1] = '\0';

    // Находим пробел
    char *space = strchr(buf, ' ');
    if(space == 0) {
        fprintf(2, "Error: Invalid format (need two numbers separated by space)\n");
        exit(1);
    }

    // Разделяем строку
    *space = '\0';
    
    // Конвертируем числа
    num1 = atoi(buf);
    num2 = atoi(space + 1);

    // Вызываем системный вызов add
    sum = add(num1, num2);

    // Выводим результат
    printf("Sum from syscall: %d\n", sum);
    
    exit(0);
}

