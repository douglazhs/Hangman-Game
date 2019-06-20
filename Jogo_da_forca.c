/*****************************************************************************
*                               JOGO DA FORCA                                *
* - Roda no proprio terminal                                                 *
* - Uma pessoa escolhe uma palavra e o outro tenta adivinhar                 *
*                                                                            *
* - Douglas Henrique de Souza Pereira - maio/junho 2019                      *
* - UC19107076                                                               *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\e[0;32m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_PURPLE   "\e[0;35m"
#define ANSI_COLOR_YELLOW   "\e[1;33m"
#define ANSI_COLOR_BLUE     "\e[1;34m"

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
	int i, j;

	system ("cls");
	for (i = 0; i < 3; i++) {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCarregando");
        for (j = 0; j < 3; j++) {
            printf(ANSI_COLOR_BLUE"."ANSI_COLOR_RESET);
            Sleep(200);
        }
        system ("cls");
    }

	do {
		printf ("\n========================================================================================================================");
		printf ("\n");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t                 JOGO DA FORCA"ANSI_COLOR_RESET);
		printf ("\n\t\t\t\t\t\t________________");
		printf ("\n\t\t\t\t\t\t|             ***");
		printf ("\n\t\t\t\t\t\t|            *   *");
		printf ("\n\t\t\t\t\t\t|             ***");
		printf ("\n\t\t\t\t\t\t|             /|\\");
		printf ("\n\t\t\t\t\t\t|            / | \\");
		printf ("\n\t\t\t\t\t\t|             / \\");
		printf ("\n\t\t\t\t\t\t|            /   \\");
		printf ("\n========================================================================================================================");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [1]"ANSI_COLOR_RESET" JOGAR MULTIPLAYER");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [2]"ANSI_COLOR_RESET" JOGAR SINGLE PLAYER");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [3]"ANSI_COLOR_RESET" INSTRUÇÕES");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [4]"ANSI_COLOR_RESET" SAIR");

		printf (ANSI_COLOR_BLUE"\n\n\t\t\t\t\t\tOPÇÃO -> "ANSI_COLOR_RESET);
		scanf ("%d", &opcao);
		fflush (stdin);

		if (opcao == 1) {
			multiPlayer ();
		} else if (opcao == 3) {
			instrucoes ();
		} else if (opcao == 4) {
			system ("cls");
			for (i = 0; i < 5; i++) {
        		printf("\n\t\t\t\t\t\t\tSAINDO");
        		for (j = 0; j < 3; j++) {
            		printf(ANSI_COLOR_BLUE"."ANSI_COLOR_RESET);
            		Sleep(200);
				}
				system ("cls");
        	}
			break;
		}

		system ("cls");

	} while (opcao != 1);
}

void instrucoes () {

	char voltar;

	system ("cls");

	printf (ANSI_COLOR_PURPLE"\n\t\t\t->"ANSI_COLOR_RESET" Existem dois jogadores: o enforcador e o enforcado.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador escolhe uma palavra e uma dica e o enforcado tenta adivinhar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador tem que garantir que o enforcado não veja a palavra que irá digitar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" A palavra e a dica podem ter no máximo 50 letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O campo da palavra ou da dica não pode ser vazio.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcado tenta acertar a palavra chutando letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" São concedidas apenas 7 chances de erro.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" Caso queira tentar chutar a palavra, basta digitar a tecla \"#\".");

	printf ("\n\n\n\n\n\n\t\t\t\t\tDigite uma tecla para voltar ao menu"ANSI_COLOR_PURPLE" ->"ANSI_COLOR_RESET);
	scanf ("%c", &voltar);
	fflush (stdin);

	system ("cls");

}

void multiPlayer () {

	char palavra[50], chute[50], dica[50], letra, mostraPalavra[50];
	char resp, tecla;
	int contadorErros = 0, i, contador;
	int chances = 7, pontos = 0;
	int aux = 1;

	do {
		system ("cls");

		printf ("\n\tCERTIFIQUE-SE DE QUE SEU AMIGO NÃO O VEJA ESCREVENDO A PALAVRA!");
		printf ("\n\n\tInforme a a palavra para começar.\n");

		do {
			printf (ANSI_COLOR_YELLOW"\n\tPALAVRA -> "ANSI_COLOR_RESET);
			gets (palavra);
			fflush (stdin);

			system ("cls");

			if (strlen (palavra) == 0) {
				printf (ANSI_COLOR_RED"\tPor favor, digite uma palavra para começar o jogo!"ANSI_COLOR_RESET);
			}
		} while (strlen (palavra) == 0);

		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}

		printf ("\n\tAgora informe a dica para ficar mais facil de seu amigo conseguir acertar.\n");

		do {

			printf (ANSI_COLOR_YELLOW"\n\tDICA -> "ANSI_COLOR_RESET);
			gets (dica);
			fflush (stdin);

			system ("cls");

			for (i = 0; i < strlen (dica); i++) {
				dica[i] = toupper (dica[i]);
			}

			if (strlen(dica) == 0) {
				printf (ANSI_COLOR_RED"\n\tPor favor, digite uma dica!"ANSI_COLOR_RESET);
			}

			if (strcmp (dica, palavra) == 0) {
				printf (ANSI_COLOR_RED"\n\tVocê não pode escolher a mesma palavra para a dica!"ANSI_COLOR_RESET);
			}

		} while (strlen (dica) == 0 || strcmp (dica, palavra) == 0);

		system ("cls");

		printf (ANSI_COLOR_YELLOW"\n\t\t\t\t\t\t          ATENÇÃO"ANSI_COLOR_RESET);
		printf ("\n\n\tTem certeza de que deseja escolher a palavra \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" com a dica \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" ?\n", palavra, dica);
		printf (ANSI_COLOR_YELLOW"\n\t(S/N) -> "ANSI_COLOR_RESET);
		scanf ("%c", &resp);
		fflush (stdin);

	} while (resp != 's');

	system ("cls");

	for (contador = 0; contador < strlen (palavra); contador++) {
		mostraPalavra[contador] = '_';
	}

	for (contador = 0; contadorErros < 8; contador++) {
  		printf ("------------------------------------------------------------------------------------------------------------------------");
		printf (ANSI_COLOR_YELLOW"\n\t\t\tRELEMBRANDO:"ANSI_COLOR_RESET);
		printf ("\n\n\t\t\t*Agora, você pode escolher uma letra ou tentar acertar sua palavra!");
		printf ("\n\t\t\t*Lembrando que você pode errar até 6 vezes.");
		printf ("\n\t\t\t*Basta Digitar \"#\" quando souber a palavra e quiser chutar.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");

		printf ("\n\n\tDICA:"ANSI_COLOR_YELLOW" %s"ANSI_COLOR_RESET, dica);
		printf ("\n\n\tQuantidade de letras na palavra:"ANSI_COLOR_YELLOW " %d"ANSI_COLOR_RESET, strlen (palavra));
		printf ("\n\tChances disponíveis: "ANSI_COLOR_YELLOW"%d"ANSI_COLOR_RESET, chances);

		boneco (contadorErros);

		for (contador = 0; contador <= strlen (palavra); contador ++) {
			if (pontos < strlen (palavra)) {
				printf ("%c ", mostraPalavra[contador]);
			} else if (pontos == strlen (palavra) ) {
				printf (ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, mostraPalavra);
				printf ("\n\t\t\t\t\t     VOCÊ GANHOU! Palavra: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
			}
			
			if (strcmp (chute, palavra) == 0) {
				printf (ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\t\t\t\t\t     VOCÊ GANHOU! Palavra: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
			}

			if (palavra[contador] == ' ') {
				mostraPalavra[contador] = '-';
			}
		}
		
		printf ("\n\n\tLetras já escolhidas: %c ", letra);
		printf (ANSI_COLOR_YELLOW"\n\n\tTentar uma letra -> "ANSI_COLOR_RESET);
		scanf ("%c", &letra);
		letra = toupper(letra);
		fflush (stdin);

		for (contador = 0; contador < strlen(palavra); contador++) {
			if (letra == palavra[contador]) {
				mostraPalavra[contador] = letra;
				pontos++;
				aux = 0;
			}
		}

		if (aux == 1) {
			//contadorErros++;
			chances--;
		}

		if (letra == '#') {
			printf (ANSI_COLOR_YELLOW"\n\tDigite o seu chute -> "ANSI_COLOR_RESET);
			gets (chute);
			fflush (stdin);

			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}
			
			if (strcmp (chute, palavra) != 0) {
				system ("cls");
				boneco (contadorErros = 7);
				printf ("\n\t\t\t\t\t     VOCÊ PERDEU! A palavra era: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
				break;
			}
			
		}

		if (contadorErros == 7) {
			system ("cls");
			boneco (contadorErros);
			printf ("\n\t\t\t\t\t     VOCÊ PERDEU! A palavra era: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
			printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
			scanf ("%c", &tecla);
			fflush (stdin);
			system ("cls");
			menu ();
			break;
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
		printf ("\n\t|"ANSI_COLOR_RED"            ***"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"           *   *"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"            ***"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"          -------"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"            /|\\"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"           / | \\"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"             |"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"            / \\"ANSI_COLOR_RESET);
		printf ("\n\t|"ANSI_COLOR_RED"           /   \\"ANSI_COLOR_RESET);
		printf ("\n\t|");
		printf ("\n\t|");
	}
}
