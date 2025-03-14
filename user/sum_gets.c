#include "kernel/types.h"
#include "user/user.h"

#define MAXLEN 100

int main(void) {
    char buf[MAXLEN];
    char *s;
    int num1, num2;
    
    // Получаем строку
    s = gets(buf, MAXLEN);
    if (s == 0) {
        fprintf(2, "Error: Failed to read input\n");
        exit(1);
    }

    // Убираем символ новой строки, если есть
    int len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') {
        buf[len-1] = '\0';
    }

    // Находим пробел
    char *space = strchr(buf, ' ');
    if (space == 0) {
        fprintf(2, "Error: Invalid format (need two numbers separated by space)\n");
        exit(1);
    }

    // Разделяем строку
    *space = '\0';
    
    // Конвертируем числа
    num1 = atoi(buf);
    num2 = atoi(space + 1);

    // Выводим сумму
    printf("Sum: %d\n", num1 + num2);
    
    exit(0);
}

