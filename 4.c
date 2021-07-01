#include <stdio.h>

#include <stdlib.h>

#include "omp.h"

int primo(int x);
int main() {
  int count_total = 0;
  int chamadas = 0;
  int i, n;
  double t1, t2;

  int inicio;
  int fim;
  omp_set_num_threads(4);

  t1 = omp_get_wtime();
  do {
    printf("\n Digite um numero N: ");
    scanf("%d", & n);

    if (n < 0)
      printf("\n numero invalido, digite novamente");
  } while (n < 0);
  while (count_total < n) {
    inicio = (chamadas * 10);
    fim = (chamadas * 10) + 10;

    #pragma omp parallel 
    {
      int count = 0;
      int vet[n];
      #pragma omp for schedule(dynamic,1)
      for (i = inicio; i < fim; i++) {
        if (primo(i)) {
          vet[count] = i;
          count++;
        }
      }
      #pragma omp critical 
      {
        count_total = count_total + count;
      }
    }
    chamadas++;
  }

  t2 = omp_get_wtime();
  printf("\ntotal: %d tempo gasto %lf", count_total, t2 - t1);

  return 0;
}

int primo(int x) {
  int i, j, z;

  for (i = 0; i < 10000; i++) {
    for (j = 0; j < 10000; j++) {
      z = 1;
    }
  }

  if ((x == 0) || (x == 1))
    return 0;
  int div;
  for (div = 2; div < x; div++) {
    if (x % div == 0) {
      return 0;
    }
  }
  return 1;
}
