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
	int contadorErros = 0, i, contador = 0;
	int escolha;

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
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t*Agora, você pode escolher uma letra ou tentar acertar sua palavra!");
		printf ("\n\t\t\t*Lembrando que você pode errar até 5 vezes.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");

		printf ("\n\n\tDICA: %s", dica);
		printf ("\n\n\tQuantidade de letras na palavra: %d", strlen (palavra));
		
		boneco (contadorErros);
		
		do {
			printf ("_ ");
			i++;
		
		} while (i < strlen (palavra));
		
		
		
		printf ("\n\n\tLetras já escolhidas: %c", letra);

		printf ("\n\n\tTentar uma letra: ");

		do {
			scanf ("%c", &letra);
			letra = toupper(letra);
			fflush (stdin);
		} while (contadorErros < 5);

		if (letra == '#') {
			printf ("\n\tDigite o seu chute: ");
			gets (chute);
			
			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}
			
			fflush (stdin);
		}
		
		system ("pause");

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
