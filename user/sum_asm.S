.global main

.section .text
main:
    // Сохраняем ra в стеке
    addi sp, sp, -16
    sd ra, 8(sp)

    // Выделяем буфер для строки
    addi sp, sp, -256
    mv a0, sp        // Буфер для gets
    call gets

    // Проверяем результат gets
    beqz a0, error   // Если NULL - ошибка

    // Первое число
    mv a0, sp
    call atoi
    mv s0, a0        // Сохраняем первое число

    // Ищем пробел
    mv t0, sp
find_space:
    lb t1, 0(t0)
    beqz t1, error    // Если конец строки - ошибка
    li t2, ' '
    beq t1, t2, found_space
    addi t0, t0, 1
    j find_space

found_space:
    // Второе число после пробела
    addi a0, t0, 1
    call atoi
    mv s1, a0        // Сохраняем второе число

    // Складываем числа
    add s0, s0, s1

    // Выводим результат
    la a0, fmt
    mv a1, s0
    call printf

    // Успешное завершение
    li a0, 0
    j exit

error:
    la a0, error_msg
    call printf
    li a0, 1

exit:
    // Восстанавливаем стек и возвращаемся
    addi sp, sp, 256
    ld ra, 8(sp)
    addi sp, sp, 16
    ret

.section .data
fmt:
    .string "Sum: %d\n"
error_msg:
    .string "Error: Invalid input\n"

