#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
    
	void apresentacao(){	
		//Imprime cabecalho do nosso jogo
		printf("\n");
		printf("            P  /_\\  P     							  \n");                           
		printf("          /_\\_|_|_/_\\                               \n");                           
		printf("       n_n | ||. .|| | n_n         Bem vindo ao       \n");   
		printf("       |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!   \n");   
		printf("      |'" "' |  |_|  |'""'|                           \n");   
		printf("      |_____| ' _ ' |_____|                           \n");   
		printf("           \\__|_|__/                                 \n");   
		printf("Escolha um nível de dificuldade:           \n");
    	printf("\n(1) - Fácil\n(2) - Média\n(3) - Difícil\n");
	}
    
    int escolheNivel(double pontuacao, int nivelDificuldade) {
	  int numeroTentativas;
      switch (nivelDificuldade) {
      case (1):
        numeroTentativas = 20;
        printf("Nivel escolhido: Fácil. Você têm %d tentativas!\n\n", numeroTentativas);
        break;
      case (2):
        numeroTentativas = 15;
        printf("Nivel escolhido: Médio. Você têm %d tentativas!\n\n", numeroTentativas);
        break;
      case (3):
        numeroTentativas = 6;
        printf("Nivel escolhido: Difícil. Você têm %d tentativas!\n\n", numeroTentativas);
        break;
      default:
        printf("Nivel escolhido invalido. Digite Novamente:\n");
        iniciaJogo(numeroTentativas,pontuacao);
      }
      return numeroTentativas;
    }

    double dica(int nivelDificuldade) {
      printf("Deseja obter uma dica? Caso sim, você começara com uma pontuação menor!\nResponda com 'S' ou 'N': ");
      double pontuacaoComDica = 1000;
      char dica[1];
      scanf("%s", &dica);
      if((strcmp(dica,"s") == 0) || (strcmp(dica,"S") == 0)) {
		switch (nivelDificuldade){
			case (1):
				pontuacaoComDica-= 500;
				break;
			case (2):
				pontuacaoComDica-= 300;
				break;
			case (3):
				pontuacaoComDica-= 150;
				break;							
			default:
				pontuacaoComDica = 1000;
				break;				
		}
      }
      return pontuacaoComDica;
    }

    void iniciaJogo(int numeroTentativas, double pontuacaoPadrao) {
	  int segundos = time(0);
      srand(segundos);
      
      int numeroSecreto = rand() % 100;
      int i, acertou = 0, tentativas = 1, chute = 0, nivelDificuldade;
      scanf("%d", &nivelDificuldade);
      numeroTentativas = escolheNivel(pontuacaoPadrao, nivelDificuldade);
      pontuacaoPadrao = dica(nivelDificuldade);
      printf("Você esta iniciando o jogo com: %.f pontos!\n", pontuacaoPadrao);
      for (i = 0; i < numeroTentativas; i++) {
        printf("Tentativa %d\n", tentativas);
        
        printf("Qual é o seu chute?\n");
        scanf("%d", &chute);

        int invalido = (chute < 0);

        int menor = (chute < numeroSecreto);
        acertou = (chute == numeroSecreto);

        if (invalido) {
          printf("Número inválido. Você não pode chutar um valor negativo!\n\n");
          continue;
        }
        if (acertou) {
          break;
        } else if (menor) {
          pontuacaoPadrao = (double)abs(pontuacaoPadrao - (numeroSecreto - chute)) / 2;
          printf("Seu chute foi menor que o numero secreto! Sua pontuação parcial é de: %.2f pontos!! Vamos la...\n\n", pontuacaoPadrao);
        } else {
          pontuacaoPadrao = (double) abs(pontuacaoPadrao - (chute - numeroSecreto)) / 2;
          printf("Seu chute foi maior que o numero secreto!  Sua pontuação parcial é de: %.2f pontos!! Vamos la...\n\n", pontuacaoPadrao);
        }
        tentativas++;
      }
	  printf("\n-------------\n\n");	
      if (acertou) {
        printf("Parabéns, você acertou na %dª tentativa! e sua pontuacao foi de %.2f pontos!!\n\nO numero a ser encontrado era: %d\n", tentativas, pontuacaoPadrao, numeroSecreto);
      } else {
        printf("Você errou, tente novamente!\n\nO numero a ser encontrado era: %d\n", numeroSecreto);
      }

    }
    
    void repeteJogo(){
    	char reinicia[3];
    	printf("Deseja Reiniciar o jogo?\n ");
    	scanf("%s", &reinicia);
    	if((strcmp(reinicia,"sim") == 0) || (strcmp(reinicia,"Sim") == 0)) {
    		main();
    	} else {
      printf("\n                  *******************\n");
      printf("                  * Jogo Finalizado!* \n");
      printf("                  *******************\n\n");
    		system("PAUSE");
		}
	}

    int main() {
      // Utiliza UTF-8 prompt-comando
      setlocale(LC_ALL, "Portuguese");
	  apresentacao();
      double pontuacaoPadrao = 1000;
      int numeroTentativas = 0;
      iniciaJogo(numeroTentativas, pontuacaoPadrao);
      repeteJogo();
      
    }

