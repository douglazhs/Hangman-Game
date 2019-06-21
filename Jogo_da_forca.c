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

char leValidaTextos ();
void multiPlayer ();

void instrucoes () {

	char voltar;

	system ("cls");

	printf (ANSI_COLOR_PURPLE"\n\t\t\t->"ANSI_COLOR_RESET" Existem dois jogadores: o enforcador e o enforcado.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador escolhe uma palavra e uma dica e o enforcado tenta adivinhar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador tem que garantir que o enforcado n�o veja a palavra que ir� digitar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" A palavra e a dica podem ter no m�ximo 50 letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O campo da palavra ou da dica n�o pode ser vazio.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcado tenta acertar a palavra chutando letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" S�o concedidas apenas 7 chances de erro.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" Caso queira tentar chutar a palavra, basta digitar a tecla \"#\".");

	printf ("\n\n\n\n\n\n\t\t\t\t\tDigite uma tecla para voltar ao menu"ANSI_COLOR_PURPLE" ->"ANSI_COLOR_RESET);
	scanf ("%c", &voltar);
	fflush (stdin);

	system ("cls");

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
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [2]"ANSI_COLOR_RESET" INSTRU��ES");
		printf (ANSI_COLOR_BLUE"\n\t\t\t\t\t        [3]"ANSI_COLOR_RESET" SAIR");

		printf (ANSI_COLOR_BLUE"\n\n\t\t\t\t\t\tOP��O -> "ANSI_COLOR_RESET);
		scanf ("%d", &opcao);
		fflush (stdin);

		if (opcao == 1) {
			multiPlayer ();
		} else if (opcao == 2) {
			instrucoes ();
		} else if (opcao == 3) {
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

void multiPlayer () {

	char palavra[50], chute[50], tema[50], letra, mostraPalavra[50];
	char resp, tecla;
	int contadorErros = 0, i, contador;
	int chances = 7, pontos = 0;
	int aux = 1;

	do {
		system ("cls");

		printf ("\n\tCERTIFIQUE-SE DE QUE SEU AMIGO N�O O VEJA ESCREVENDO A PALAVRA!");
		printf ("\n\n\tInforme a a palavra para come�ar.\n");

		printf (ANSI_COLOR_YELLOW"\n\tPALAVRA -> "ANSI_COLOR_RESET);
		palavra = leValidaTextos ();
		fflush (stdin);

		system ("cls");

		if (strlen (palavra) == 0) {
			printf (ANSI_COLOR_RED"\tPor favor, digite uma palavra para come�ar o jogo!"ANSI_COLOR_RESET);
		}

		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}

		printf ("\n\tAgora informe o tema para ficar mais facil de seu amigo conseguir acertar.\n");


		printf (ANSI_COLOR_YELLOW"\n\tTEMA -> "ANSI_COLOR_RESET);
		tema = leValidaTextos ();
		fflush (stdin);

		system ("cls");

		for (i = 0; i < strlen (tema); i++) {
			tema[i] = toupper (tema[i]);
		}

		system ("cls");

		printf (ANSI_COLOR_YELLOW"\n\t\t\t\t\t\t          ATEN��O"ANSI_COLOR_RESET);
		printf ("\n\n\tTem certeza de que deseja escolher a palavra \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" com o tema \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" ?\n", palavra, tema);
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
		printf ("\n\n\t\t\t*Agora, voc� pode escolher uma letra ou tentar acertar sua palavra!");
		printf ("\n\t\t\t*Lembrando que voc� pode errar at� 6 vezes.");
		printf ("\n\t\t\t*Basta Digitar \"#\" quando souber a palavra e quiser chutar.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");

		printf ("\n\n\tTEMA:"ANSI_COLOR_YELLOW" %s"ANSI_COLOR_RESET, tema);
		printf ("\n\n\tQuantidade de letras na palavra:"ANSI_COLOR_YELLOW " %d"ANSI_COLOR_RESET, strlen (palavra));
		printf ("\n\tChances dispon�veis: "ANSI_COLOR_YELLOW"%d"ANSI_COLOR_RESET, chances);

		boneco (contadorErros);

		for (contador = 0; contador <= strlen (palavra); contador ++) {
			if (pontos < strlen (palavra)) {
				printf ("%c ", mostraPalavra[contador]);
			} else if (pontos == strlen (palavra) ) {
				printf (ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\t\t\t\t\t     VOC� GANHOU! Palavra: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDigite uma tecla pra voltar ao menu ->> ");
				scanf ("%c", &tecla);
				fflush (stdin);
				system ("cls");
				menu ();
			}

			if (strcmp (chute, palavra) == 0) {
				printf (ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\t\t\t\t\t     VOC� GANHOU! Palavra: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
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

		printf ("\n\n\tLetras j� escolhidas: %c ", letra);
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
			contadorErros++;
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
				printf ("\n\t\t\t\t\t     VOC� PERDEU! A palavra era: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
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
			printf ("\n\t\t\t\t\t     VOC� PERDEU! A palavra era: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
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

int main () {

	setlocale (LC_ALL, "");

	menu ();

	return 0;
}

char leValidaTextos () {
	
	char texto[50];

	do {
		gets (texto);
		
		if (strlen (texto) == 0) {
			printf ("Por favor, digite algo: ");
		}
	} while (strlen (texto) == 0);

	return texto;
}

