/*Programação Paralela, prof Emilio
Projeto 1 - Programa Sequencial - Projeto Time M&M
https://github.com/ufabc-bcc/2019_Q1_PP_MPI-projetotimem-m
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock(); //Inicia a contagem do tempo para o Programa

    // Apresenta mensagem inicial para usuario entrar com valor N
    // para limite superior até qual todos os números primos deverão ser gerados
    printf("Digite seu limite superior dos numeros primos: ");

    //O tipo de dado short requer 16 bits para ser implementado (10^6 até 10^11).
    long n, aux=1, soma=0;
    scanf("%ld", &n);

    srand(time(NULL));
    long arrayP[n]; // Declara 'arrayPrimo', que sera o Array dos numeros PRIMOS de p a n, tal que [2p, 3p, 4p... n]
    for (long i=0; i < n; i++){
        arrayP[i] = i+2;
    }
    while (aux < n){ //Percorre um laço até o valor limite n definido pelo usuario
        aux++; //Variavel auxiliar para servir de parametro para verificar o numero primo ou não (resto da divisão)
        for(long i=0; i < n; i++){
            if (arrayP[i]%aux == 0 && arrayP[i] > aux && arrayP[i] != -1){ // Caso condição seja True, signifca que não é primo
                arrayP[i] = -1;
            } 
        }
    }
    for(long i=0; i < n; i++){
        if (arrayP[i] != -1 && arrayP[i] <= n){
            soma++;
        }
    }
    printf("%ld\n", soma);
    double tempoTotal = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf ("Tempo total do programa: %lf\n", tempoTotal);
}