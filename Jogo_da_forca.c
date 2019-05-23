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

void menu ();
void jogar ();
void adicionarPalavra ();
void adicionarDica ();
void boneco ();
void resultado ();

int main () {
	setlocale (LC_ALL, "");
	

void menu () {
	do {
		printf ("\n\t************************************");
		printf ("\n\t|                            		|");
		printf ("\n\t|           JOGO DA FORCA      	|");
		printf ("\n\t|                            		|");
		printf ("\n\t************************************");
		printf ("\n\t|         	   [1] JOGAR            |");
		printf ("\n\t          [Outra tecla] SAIR       |"); 
		printf ("\n\t************************************");

		
		printf ("\n\tDigite uma das opções: ");
		scanf ("%c", &opcao);
		fflush (stdin);
		
		if (opcao == '1') {
			jogar ();
		} else {
			break;
		}
		
	} while (opcao != '1');
}

void jogar () {
	char palavra [50];
	char dica [50];
	char resp
	int contadorErros;
	
	printf ("_________________________________________________________________________________________")
	printf ("\t\t\tInforme a a palavra para começar.\n");
	printf ("\t\t\tPALAVRA: ");
	scanf ("%s", &palavra [50]);
	fflush (stdin);
	
	printf ("\t\t\tAgora informe a dica para ficar mais fácil de seu amigo conseguir acertar.\n");
	printf ("\t\t\tDICA: ");
	scanf ("%s", dica [50]);
	fflush (stdin);
	
	printf ("Tem certeza de que deseja escolher a palavra %s com a dica %s? <S> SIM <Outra> NÃO\n", palavra, dica);
	scanf ("%c", &resp);
}

void boneco (ref int contadorErros) {

		if (contadorErros == 1) {
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
}

/*void resultado (char palavra [201], bool resultado) {
	SYSTEM ("cls");
	printf ("----------RESULTADO----------");
	if (resultado = true) {
		printf ("\n\t\t VOCÊ GANHOU!");
	} else {
		printf ("\n\t\t VOCÊ PERDEU!");
	}
}*/

