#include <omp.h>

#include <stdio.h>

#include <stdbool.h>

int primes(int id);
int even(int id);
int odd(int id);

int main() {
  omp_set_num_threads(3);
  int id;
  #pragma omp parallel 
  {
    id = omp_get_thread_num();
    (even(id) ? id == 1 : false);
    (odd(id) ? id == 2 : false);
    (primes(id) ? id == 3 : false);
  }

  return 0;
}

int primes(int id) {
  int i, j, flag;
  printf("Eu sou o id %d \n", id);
  i = 10;
  j = 10;
  while (i < j) {
    flag = 0;
    if (i <= 1) {
      ++i;
      continue;
    }
    for (i = 2; i <= i / 2; ++i) {

      if (i % i == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("%d ", i);
  }
  return 1;
}

int even(int id) {
  int i;
  printf("Eu sou o id %d \n", id);
  for (i = 0; i <= 10; i++) {
    (printf("%d ", i) ? (i % 2 == 0) : false);
  }
  return 1;
}

int odd(int id) {
  int i;
  printf("Eu sou o id %d \n", id);
  for (i = 0; i <= 10; i++) {
    (printf("%d\n", i) ? (i % 2 != 0) : false);
  }
  return 1;
}
