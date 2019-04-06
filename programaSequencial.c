/*Programação Paralela, prof Emilio
Projeto 1 - Programa Sequencial
https://github.com/ufabc-bcc/2019_Q1_PP_MPI-projetotimem-m
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Apresenta mensagem inicial para usuario entrar com valor N
  // para limite superior até qual todos os números primos deverão ser gerados
  printf("Digite seu limite superior dos numeros primos:\n");

  //O tipo de dado short requer 16 bits para ser implementado (10^6 até 10^11).
  long n;
  scanf("%ld", &n);

  srand(time(NULL));
  int data[n];

  for (int i = 0; i < n; i++){
      data[i] = i+2;    
  }

  for (int j = 0; j < n; j++){
      printf("data[%d] = %d"), j, data[j];    
  }



  // clock_t start = clock();
  // long long sum = 0;
  // for (int i = 0; i < 100000; i++){
  //   for (int c = 0; c < arraySize; ++c) {
  //     if (data[c] >= 128)
  //       sum += data[c];
  //   }
  // }
  // double elapsedTime = (double)(clock() - start) / CLOCKS_PER_SEC;
  // printf ("Tempo total: %lf\n", elapsedTime);
  // printf ("Soma: %lld\n", sum);
}