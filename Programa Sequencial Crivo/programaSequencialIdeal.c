/*Programação Paralela, prof Emilio
Projeto 1 - Programa Sequencial - Projeto Time M&M
https://github.com/ufabc-bcc/2019_Q1_PP_MPI-projetotimem-m
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned int num1 = 0, num2 = 0;
    int i, j, isprime = 0, count = 0, test = 0;

    printf("\nEnter a range of numbers(e.g. '100 200')(MAX RANGE = 10000): ");

    do
    {
        test = scanf("%4u %5u", &num1, &num2);
        fflush(stdin);
    }while((num2 - num1) > 10000 || test != 2);

    printf("The prime numbers of the range %u - %u are...\n\n", num1, num2);

    for(j = num1; j <= num2; ++j)
    {
        for(i = j; i > 0; --i)
        {
            if((j % i)== 0) isprime++;
        }

        if(isprime == 2){ printf("%4u ", j); count++; }
        isprime = 0;
    }
    printf("\n\nPrime numbers count: %d\n", count);

  getchar();
  return 0;
}