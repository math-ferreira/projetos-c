#include <stdio.h>
#include <math.h>

#define MAX 1000000 //Assumindo que nosso vetor tera no minimo 1000000 (10 ^ 6) elementos. Só alterar aqui!!
char primos[MAX];

int main (void) {
   int i, j, n, contador=0;
   n = (int)sqrt(MAX);
   primos[2] = 1; //COmeçamos assumindo que o nuemro 2 é primo

   // Assumimos também que todos os ímpares além de 1 são primos
   for (i = 3; i < MAX; i += 2) {
       primos[i] = 1;
   }

   /* Começando no 3 (2 ja é primo) e saltando de ímpar em ímpar, o projeto diz que podemos começar a marcar os múltiplos a partir de i². */
   for (i = 3; i < n; i += 2) {
       if (primos[i]) {
           for (j = i * i; j < MAX; j += i) {
               primos[j] = 0;
           }
       }
   }

   for (i = 0; i < MAX; ++i) {
       if (primos[i]) {
           contador++;
           //Contador imprime a quantidade de primos do vetor
        //        printf("teste");
        //        printf("%d/n", primos[i]);
        //    }
       }
   }

   return printf("Quantidade de Primos: %d\n", contador);
}