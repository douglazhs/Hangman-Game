/*****************************************************************************
*                     			JOGO DA FORCA							     *
* - Roda no proprio terminal						     					 *
* - Uma pessoa escolhe uma palavra e o outro tenta adivinhar	             *
*									     									 *
* - Douglas Henrique de Souza Pereira - maio/junho 2019			             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

void menu ();
void jogar ();
char chute ();
char adivinharPalavra ();
void adicionarPalavra ();
void boneco (int contadorErros);
void adicionarDica ();
void resultado ();

int main () {
	setlocale (LC_ALL, "");

	menu ();

	return 0;
}


void menu () {
	int opcao;
	do {
		printf ("\n========================================================================================================================");
		printf ("\n                                            ");
		printf ("\n\t\t\t\t\t              JOGO DA FORCA       ");
		printf ("\n                                            ");
		printf ("\n========================================================================================================================");
		printf ("\n\t\t\t\t\t              [1] JOGAR            ");
		printf ("\n\n\t\t\t\t\t         [Outra tecla] SAIR     ");
		printf ("\n\t\t\t\t\t");


		printf ("\n\n\t\t\t\t\t\tDigite uma das opções: ");
		scanf ("%d", &opcao);
		fflush (stdin);

		if (opcao == 1) {
			jogar ();
		} else {
			break;
		}

	} while (opcao != 1);
}

void jogar () {
	char palavra[50], chute[50];
	char dica[50];
	char letra;
	char resp;
	char esconde[] = "_";
	int contadorErros = 0, i, contador = 0;
	int escolha;
	int chances = 6;

	do {

		system ("cls");


		printf ("\n\t\t\t\t\t   Informe a a palavra para começar.\n");

		do {
			printf ("\n\t\t\t\t\t\t      PALAVRA: ");
			gets (palavra);

			system ("cls");

			if (strlen (palavra) == 0) {
				printf ("\t\t\t\tPor favor, digite uma palavra para começar o jogo!");
			}

		} while (strlen (palavra) == 0);

		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}
		fflush (stdin);


		printf ("\n\t\t\tAgora informe a dica para ficar mais facil de seu amigo conseguir acertar.\n");

		do {

			printf ("\n\t\t\t\t\t\t      DICA: ");
			gets (dica);

			system ("cls");

			for (i = 0; i < strlen (dica); i++) {
				dica[i] = toupper (dica[i]);
			}
			fflush (stdin);

			if (strlen(dica) == 0) {
				printf ("\n\t\t\t\t\t   Por favor, digite uma dica!");
			}

		} while (strlen (dica) == 0);

		system ("cls");

		printf ("\n\t\t\t\t\t\t\t*ATENÇÃO*");
		printf ("\n\n\t\tTem certeza de que deseja escolher a palavra \"%s\" com a dica \"%s\"? <S> SIM <Outra> NAO\n", palavra, dica);
		printf ("\n\t\tR: ");
		scanf ("%c", &resp);
		fflush (stdin);

	} while (resp != 's' && strlen (palavra) == 0 && strlen (dica) == 0);

	system ("cls");
	
	do {
		for (contador = 0; contadorErros < 7; contador++) {
            for (contador = 0; contador < strlen(palavra); contador++) {
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

				printf ("%s", esconde);
			
				printf ("\n\n\tLetras já escolhidas: %c ", letra);
				printf ("\n\n\tTentar uma letra: ");
				scanf ("%c", &letra);
				letra = toupper(letra);
				fflush (stdin);

				if (letra == palavra[contador]) {
					esconde[contador] = letra;
				} else if (letra == '#') {
					printf ("\n\tDigite o seu chute: ");
					gets (chute);
					fflush (stdin);
					for (i = 0; i < strlen (chute); i++) {
						chute[i] = toupper (chute[i]);
					}
				} else {
					contadorErros++;
					chances--;
				}

				if (palavra[contador] == ' ') {
					esconde[contador] = '-';
				}
				
			system ("cls");

			}

		}
		
		if (letra == '#') {
			printf ("\n\tDigite o seu chute: ");
			gets (chute);
			fflush (stdin);

			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}

		}

	} while (letra != '#');

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
		}
		else if (contadorErros == 1) {
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
			printf ("\n\t|            ***");
			printf ("\n\t|           *   *");
			printf ("\n\t|            ***");
			printf ("\n\t|             |");
			printf ("\n\t|             |");
			printf ("\n\t|             |");
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
			printf ("\n\t|             ***");
			printf ("\n\t|            *   *");
			printf ("\n\t|             ***");
			printf ("\n\t|             /|\\");
			printf ("\n\t|            / | \\");
			printf ("\n\t|              |");
			printf ("\n\t|               \\");
			printf ("\n\t|                \\");
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
		}
}

//void resultado (char palavra [201], bool resultado) {
//	SYSTEM ("cls");
//	printf ("----------RESULTADO----------");
//	if (palavra)
//	}
//}
