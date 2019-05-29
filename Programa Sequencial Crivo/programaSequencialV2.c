/*Programação Paralela, prof Emilio
Projeto 1 - Programa Sequencial - Projeto Time M&M
https://github.com/ufabc-bcc/2019_Q1_PP_MPI-projetotimem-m
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Digite seu limite superior dos numeros primos: ");
    long n;
    scanf("%ld", &n);
    long arrayP[n];

    for(long i=0; i < n; i++){
        arrayP[i] = i+2;
    }
    char valida = 'T';
    long primo = 0;
    long contador = 0;
    long aux;
     while(valida == 'T'){
         if (aux != 0){
             for (long j=0; j < n; j++){
                 if (arrayP[j]%primo == 0){
                     arrayP[j] = 1;
                     contador++;
                     aux = arrayP[j];
                 }
            }
         }
         primo++;
         if (primo > n){
             valida = 'F';
         }
     }
    printf("Quantidade de numeros Primos: %ld", n-contador);

}
