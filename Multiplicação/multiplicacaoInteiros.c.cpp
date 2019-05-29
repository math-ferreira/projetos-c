#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int func(){
	//  Utiliza UTF-8 prompt-comando
	setlocale(LC_ALL, "Portuguese");
	
	printf("- Digite duas variaveis inteiras:\n");
	int x,y;
	scanf("%d %d", &x ,&y);
	printf("O resultado da multiplicação é: %d\n\n-----\n\n", x*y);
}
int main(){
	func();
	
	char valida[3];
	
	printf("Deseja realizar outra multiplicação ?\n");
	scanf("%s",&valida);
	
	//  A strcmp compara uma string com outra string:
	//  strcmp(primeirastring,segundastring), ela te retorna 0 se ambas forem iguais, 1 se a primeira string for "maior" que a segunda e -1 se a primeira for "menor" que a segunda
	if ((strcmp(valida,"sim") == 0) || (strcmp(valida,"s") == 0) || (strcmp(valida,"Sim") == 0)){
		main();
	} 
}
