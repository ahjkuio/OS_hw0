#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

// Системный вызов add, получает два целых числа и возвращает их сумму
uint64
sys_add(void)
{
  int n1, n2;
  
  // Получаем аргументы из стека
  if(argint(0, &n1) < 0 || argint(1, &n2) < 0)
    return -1;
  
  // Возвращаем сумму
  return n1 + n2;
}
