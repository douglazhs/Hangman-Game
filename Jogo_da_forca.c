/*****************************************************************************
*                               JOGO DA FORCA                                *
* - Roda no proprio terminal                                                 *
* - Uma pessoa escolhe uma palavra e o outro tenta adivinhar                 *
*                                                                            *
* - Douglas Henrique de Souza Pereira - maio/junho 2019                      *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void menu ();
void instrucoes ();
void multiPlayer ();
void singlePlayer ();
void boneco (int contadorErros);

int main () {
	setlocale (LC_ALL, "");

	menu ();

	return 0;
}


void menu () {
	int opcao;
	do {
		printf ("\n========================================================================================================================");
		printf ("\n");
		printf ("\n\t\t\t\t\t                 JOGO DA FORCA");
		printf ("\n\t\t\t\t\t\t________________");
		printf ("\n\t\t\t\t\t\t|             ***");
		printf ("\n\t\t\t\t\t\t|            *   *");
		printf ("\n\t\t\t\t\t\t|             ***");
		printf ("\n\t\t\t\t\t\t|             /|\\");
		printf ("\n\t\t\t\t\t\t|            / | \\");
		printf ("\n\t\t\t\t\t\t|             / \\");
		printf ("\n\t\t\t\t\t\t|            /   \\");
		printf ("\n========================================================================================================================");
		printf ("\n\t\t\t\t\t        [1] JOGAR MODO MULTIPLAYER");
		printf ("\n\t\t\t\t\t        [2] JOGAR MODO SINGLE PLAYER");
		printf ("\n\t\t\t\t\t        [3] INSTRUÇÕES");
		printf ("\n\t\t\t\t\t        [4] SAIR");
		printf ("\n\t\t\t\t\t");


		printf ("\n\n\t\t\t\t\t\tOPÇÃO -> ");
		scanf ("%d", &opcao);
		fflush (stdin);

		if (opcao == 1) {
			multiPlayer ();
		} else if (opcao == 3) {
			instrucoes ();
		} else if (opcao == 4) {
			break;
		}
		
		system ("cls");

	} while (opcao != 1);
}

void instrucoes () {
	
	char voltar;
	
	system ("cls");
	
	printf ("\n\t\t\t-> Existem dois jogadores: o enforcador e o enforcado.");
	printf ("\n\n\t\t\t-> O enforcador escolhe uma palavra e uma dica e o enforcado tenta adivinhar.");
	printf ("\n\n\t\t\t-> O enforcador tem que garantir que o enforcado não veja a palavra que irá digitar.");
	printf ("\n\n\t\t\t-> A palavra e a dica podem ter no máximo 50 letras.");
	printf ("\n\n\t\t\t-> O campo da palavra ou da dica não pode ser vazio.");
	printf ("\n\n\t\t\t-> O enforcado tenta acertar a palavra chutando letras.");
	printf ("\n\n\t\t\t-> São concedidas apenas 7 chances de erro.");
	printf ("\n\n\t\t\t-> Caso queira tentar chutar a palavra, basta digitar a tecla \"#\".");
	
	printf ("\n\n\n\n\n\n\t\t\t\t\tDigite uma tecla para voltar ao menu ->");
	scanf ("%c", &voltar);
	
	system ("cls");
	
}

void multiPlayer () {
	char palavra[50], chute[50], dica[50], letra, mostraPalavra[50];
	char resp, tecla;
	int contadorErros = 0, i, contador;
	int chances = 7, pontos = 0;

	do {
		system ("cls");
		
		printf ("\tCERTIFIQUE-SE DE QUE SEU AMIGO NÃO O VEJA ESCREVENDO A PALAVRA!");
		printf ("\n\n\tInforme a a palavra para começar.\n");

		do {
			printf ("\n\tPALAVRA -> ");
			gets (palavra);

			system ("cls");

			if (strlen (palavra) == 0) {
				printf ("\tPor favor, digite uma palavra para começar o jogo!");
			}

		} while (strlen (palavra) == 0);

		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}
		fflush (stdin);

		printf ("\n\tAgora informe a dica para ficar mais facil de seu amigo conseguir acertar.\n");

		do {

			printf ("\n\tDICA -> ");
			gets (dica);

			system ("cls");

			for (i = 0; i < strlen (dica); i++) {
				dica[i] = toupper (dica[i]);
			}
			fflush (stdin);

			if (strlen(dica) == 0) {
				printf ("\n\tPor favor, digite uma dica!");
			}

		} while (strlen (dica) == 0);

		system ("cls");

		printf ("\n\t\t\t\t\t\t\t*ATENÇÃO*");
		printf ("\n\n\tTem certeza de que deseja escolher a palavra \"%s\" com a dica \"%s\"? <S> SIM <Outra> NAO\n", palavra, dica);
		printf ("\n\t-> ");
		scanf ("%c", &resp);
		fflush (stdin);

	} while (resp != 's');

	system ("cls");
	
	for (contador = 0; contador < strlen (palavra); contador++) {
		mostraPalavra[contador] = '_';
	}

	for (contador = 0; contadorErros < 8; contador++) {
  		printf ("------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\tINSTRUÇÕES:");
		printf ("\n\n\t\t\t*Agora, você pode escolher uma letra ou tentar acertar sua palavra!");
		printf ("\n\t\t\t*Lembrando que você pode errar até 6 vezes.");
		printf ("\n\t\t\t*Basta Digitar \"#\" quando souber a palavra e quiser chutar.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");
			
		printf ("\n\n\tDICA: %s", dica);
		printf ("\n\n\tQuantidade de letras na palavra: %d", strlen (palavra));
		printf ("\n\tChances disponíveis: %d", chances);

		boneco (contadorErros);
			
		for (contador = 0; contador < strlen (palavra); contador ++) {
			printf ("%c ", mostraPalavra[contador]);

			if (palavra[contador] == ' ') {
				mostraPalavra[contador] = '-';
			}
		}

		printf ("\n\n\tLetras já escolhidas: %c ", letra);
		printf ("\n\n\tTentar uma letra -> ");
		scanf ("%c", &letra);
		letra = toupper(letra);
		fflush (stdin);
		
		for (contador = 0; contador < strlen(palavra); contador++) {

			if (letra == palavra[contador]) {
				mostraPalavra[contador] = letra;
				pontos++;
			} else {
				contadorErros++;
			}

		}
			
		if (letra == '#') {
			printf ("\n\tDigite o seu chute -> ");
			gets (chute);
			fflush (stdin);

			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}

			if (strcmp (chute, palavra) == 0) {
				printf ("\n\t\t\t\t\t     VOCÊ GANHOU! Palavra: %s", palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
			} else {
				system ("cls");
				boneco (contadorErros = 7);
				printf ("\n\t\t\t\t\t     VOCÊ PERDEU! A palavra era: %s", palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
			}
		}

		if (pontos == strlen (palavra)) {
			printf ("\n\t\t\t\t\t     VOCÊ GANHOU! Palavra: %s", palavra);
			printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
			scanf ("%c", &tecla);
			fflush (stdin);
			system ("cls");
			menu ();
		}

		if (contadorErros == 7) {
			system ("cls");
			boneco (contadorErros);
			printf ("\n\t\t\t\t\t     VOCÊ PERDEU! A palavra era: %s", palavra);
			printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
			scanf ("%c", &tecla);
			fflush (stdin);
			system ("cls");
			menu ();
		}
		
		system ("cls");
	}
}


void boneco (int contadorErros) {

	if (contadorErros == 0) {
		printf ("\n\t_________________");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
	}else if (contadorErros == 1) {
		printf ("\n\t_________________");
		printf ("\n\t|            ***");
		printf ("\n\t|           *   *");
		printf ("\n\t|            ***");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 2) {
		printf ("\n\t_______________");
		printf ("\n\t|           ***");
		printf ("\n\t|          *   *");
		printf ("\n\t|           ***");
		printf ("\n\t|            |");
		printf ("\n\t|            |");
		printf ("\n\t|            |");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 3) {
		printf ("\n\t _______________");
		printf ("\n\t|            ***");
		printf ("\n\t|           *   *");
		printf ("\n\t|            ***");
		printf ("\n\t|             |\\");
		printf ("\n\t|             | \\");
		printf ("\n\t|             |");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 4) {
		printf ("\n\t _______________");
		printf ("\n\t|            ***");
		printf ("\n\t|           *   *");
		printf ("\n\t|            ***");
		printf ("\n\t|            /|\\");
		printf ("\n\t|           / | \\");
		printf ("\n\t|             |");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 5) {
		printf ("\n\t_______________");
		printf ("\n\t|           ***");
		printf ("\n\t|          *   *");
		printf ("\n\t|           ***");
		printf ("\n\t|           /|\\");
		printf ("\n\t|          / | \\");
		printf ("\n\t|            |");
		printf ("\n\t|             \\");
		printf ("\n\t|              \\");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 6) {
		printf ("\n\t________________");
		printf ("\n\t|            ***");
		printf ("\n\t|           *   *");
		printf ("\n\t|            ***");
		printf ("\n\t|            /|\\");
		printf ("\n\t|           / | \\");
		printf ("\n\t|             |");
		printf ("\n\t|            / \\");
		printf ("\n\t|           /   \\");
		printf ("\n\t|");
		printf ("\n\t|");
	} else if (contadorErros == 7) {
		printf ("\n\t________________");
		printf ("\n\t|            ***");
		printf ("\n\t|           *   *");
		printf ("\n\t|            ***");
		printf ("\n\t|          -------");
		printf ("\n\t|            /|\\");
		printf ("\n\t|           / | \\");
		printf ("\n\t|             |");
		printf ("\n\t|            / \\");
		printf ("\n\t|           /   \\");
		printf ("\n\t|");
		printf ("\n\t|");
	}
}

