#include "kernel/types.h"
#include "user/user.h"

#define MAXLEN 100
#define CHUNK_SIZE 16

int safe_read(char *buf, int maxlen) {
    int n = 0;
    int r;
    char *p = buf;
    
    while (n < maxlen - 1) {
        r = read(0, p, 1);
        if (r <= 0) {
            break;
        }
        if (*p == '\n') {
            *p = '\0';
            return n;
        }
        p++;
        n++;
    }
    
    if (n == maxlen - 1) {
        buf[n] = '\0';
        printf("Warning: Input truncated\n");
    }
    
    return n;
}

int main(void) {
    char buf[MAXLEN];
    int len;
    
    // Читаем строку
    printf("Enter two numbers separated by space: ");
    len = safe_read(buf, MAXLEN);
    
    if (len <= 0) {
        printf("Error: Failed to read input\n");
        exit(1);
    }

    // Выводим полученную строку в ограничителях
    printf("|%s|\n", buf);
    
    // Находим пробел
    char *space = strchr(buf, ' ');
    if (space == 0) {
        printf("Error: Invalid format (need two numbers separated by space)\n");
        exit(1);
    }

    // Разделяем строку
    *space = '\0';
    
    // Конвертируем и проверяем числа
    int num1 = atoi(buf);
    int num2 = atoi(space + 1);
    
    // Проверяем, что строки действительно содержат числа
    if (strlen(buf) == 0 || strlen(space + 1) == 0) {
        printf("Error: Empty number\n");
        exit(1);
    }
    
    // Выводим результат
    printf("Sum: %d\n", num1 + num2);
    
    exit(0);
}

