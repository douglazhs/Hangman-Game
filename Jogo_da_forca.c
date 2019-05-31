/*****************************************************************************
*                     			JOGO DA FORCA							     *
* - Roda no proprio terminal						     					 *
* - Uma pessoa escolhe uma palavra e o outro tenta adivinhar	             *
*									     									 *
* 			Douglas Henrique de Souza Pereira - maio/junho 2019			     *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define UNDERLINE "_"

void menu ();
void jogar ();
char chute ();
char adivinharPalavra ();
void adicionarPalavra ();
void adicionarDica ();
void boneco (int contadorErros);
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
	char palavra [50], chute[50];
	char dica [50];
	char resp;
	char letra;
	int contadorErros = 0, i, contador = 0;
	int escolha;

	system ("cls");
	printf ("\n\t\t\t\t\t   Informe a a palavra para começar.\n");
	printf ("\n\t\t\t\t\t\t      PALAVRA: ");
	gets (palavra);
	fflush (stdin);

	printf ("\n-----------------------------------------------------------------------------------------------------------------------");

	printf ("\n\t\t\tAgora informe a dica para ficar mais facil de seu amigo conseguir acertar.\n");
	printf ("\n\t\t\t\t\t\t      DICA: ");
	gets (dica);
	fflush (stdin);

	system ("cls");

	printf ("\n\t\t\t\t\t\t\t*ATENÇÃO*");
	printf ("\n\n\t\tTem certeza de que deseja escolher a palavra \"%s\" com a dica \"%s\"? <S> SIM <Outra> NAO\n", palavra, dica);
	printf ("\n\t\tR: ");
	scanf ("%c", &resp);

	system ("cls");



	printf ("\n------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t\t\tAgora, você pode escolher uma letra ou tentar acertar sua palavra!");
	printf ("\n\t\t\t*Lembrando que você pode errar até 5 vezes.");
	printf ("\n------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t\t\t\t\t\t\tVALENDO!");



	boneco (contadorErros);
	printf ("\n");
	do {
		printf ("_");
		i++;
	} while (i < strlen (palavra));



	printf ("\n\n\t[1] Chutar");
	printf ("\n\t[2] Adivinhar");
	printf ("\n\t");
	scanf ("%d", &escolha);
	fflush (stdin);

	do {
		if (escolha == 1) {
			printf ("\n\tDigite uma letra: ");
			scanf ("%c", &letra);
			fflush (stdin);
		} else if (escolha == 2) {
			printf ("\n\tDigite o seu chute: ");
			gets (chute);
		}
		contador++;
	} while (contador < strlen (palavra));

	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == letra && palavra[i + 1] == letra) {
			palavra[i] = letra;
		} else {
			contadorErros++;
		}
	}
}

void boneco (int contadorErros) {

		if (contadorErros = 0) {
			printf ("\n_________________");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
		}
		else if (contadorErros == 1) {
			printf ("\n_________________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
		} else if (contadorErros == 2) {
			printf ("\n _______________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|			 |");
			printf ("\n|		     |");
			printf ("\n|	         |");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
		} else if (contadorErros == 3) {
			printf ("\n _______________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|			 |\\");
			printf ("\n|		     | \\");
			printf ("\n|	         |");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
		} else if (contadorErros == 4) {
			printf ("\n _______________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|			/|\\");
			printf ("\n|		   / | \\");
			printf ("\n|	         |");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
			printf ("\n|");
		} else if (contadorErros == 5) {
			printf ("\n _______________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|			/|\\");
			printf ("\n|		   / | \\");
			printf ("\n|	         |");
			printf ("\n|	          \\");
			printf ("\n|               \\");
			printf ("\n|");
			printf ("\n|");
		} else if (contadorErros == 6) {
			printf ("\n________________");
			printf ("\n|			***");
			printf ("\n|		   *	*");
			printf ("\n|		   	***");
			printf ("\n|			/|\\");
			printf ("\n|		   / | \\");
			printf ("\n|	         |");
			printf ("\n|	        / \\");
			printf ("\n|           /   \\");
			printf ("\n|");
			printf ("\n|");
		}
}

//void resultado (char palavra [201], bool resultado) {
//	SYSTEM ("cls");
//	printf ("----------RESULTADO----------");
//	if (palavra)
//	}
//}
