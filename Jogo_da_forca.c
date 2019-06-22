/*****************************************************************************
*                               JOGO DA FORCA                                *
* - Roda no proprio terminal                                                 *
* - Uma pessoa escolhe uma palavra e o outro tenta adivinhar                 *
*                                                                            *
* - Douglas Henrique de Souza Pereira - maio/junho 2019                      *
* - UC19107076                                                               *
******************************************************************************/

//Bibliotecas utilizadas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

//Defini��o de c�digos de cores no padr�o ANSI.

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\e[0;32m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_PURPLE   "\e[0;35m"
#define ANSI_COLOR_YELLOW   "\e[1;33m"
#define ANSI_COLOR_BLUE     "\e[1;34m"

//Declara��o de algumas fun��es.

void leValidaTextos (char *palavra);
void multiPlayer ();

//Intru��es do jogo.

void instrucoes () {

	system ("cls");

	printf (ANSI_COLOR_PURPLE"\n\t\t\t->"ANSI_COLOR_RESET" Existem dois jogadores: o enforcador e o enforcado.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador escolhe uma palavra e uma dica e o enforcado tenta adivinhar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcador tem que garantir que o enforcado n�o veja a palavra que ir� digitar.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" A palavra e a dica podem ter no m�ximo 50 letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O campo da palavra ou da dica n�o pode ser vazio.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" O enforcado tenta acertar a palavra chutando letras.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" S�o concedidas apenas 7 chances de erro.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t->"ANSI_COLOR_RESET" Caso queira tentar chutar a palavra, basta digitar a tecla \"@\".");

	printf ("\n\n\n\n\n\n\t\t\t\t\tAPERTE UMA TELCA PARA VOLTAR AO MENU ->"ANSI_COLOR_PURPLE" ->"ANSI_COLOR_RESET);
	getch ();

	system ("cls");

}

//Fun��o para o desenho do boneco, que recebe como par�metro o n�mero de erros para desenhar as partes do corpo correspondentes a esse n�mero.

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

//Menu do jogo, onde a pessoa pode iniciar o jogo, acessar as instru��es ou sair, bastando digitar a op��o correspondente.

void menu () {

	int opcao;
	int i, j;

	system ("cls");

	for (i = 0; i < 3; i++) {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCARREGANDO");
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
		printf ("\n\t\t\t\t\t        ["ANSI_COLOR_BLUE"1"ANSI_COLOR_RESET"] JOGAR MULTIPLAYER");
		printf ("\n\t\t\t\t\t        ["ANSI_COLOR_BLUE"2"ANSI_COLOR_RESET"] INSTRU��ES");
		printf ("\n\t\t\t\t\t        ["ANSI_COLOR_BLUE"3"ANSI_COLOR_RESET"] SAIR");

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

//Leitura e valida��o das letras digitadas.

int validaIgual (char letra, char letrasDigitadas[], int contador) {
	int i;
	
	for (i = 0; i < contador; i++) {
		if (letra == letrasDigitadas[i]) {
			return 1;
		}
	}
	return 0;
}

char leValidaLetras (char letrasDigitadas[], int contador) {
	char letra;
	int cont;
	int flag;
		
	do {
		flag = 0;
		fflush (stdin);
		printf (ANSI_COLOR_YELLOW"\n\tTENTAR UMA LETRA -> "ANSI_COLOR_RESET);
		scanf ("%c", &letra);
		fflush (stdin);
		letra = toupper (letra);
		letrasDigitadas[contador] = letra;
		flag = validaIgual (letra, letrasDigitadas, contador);
	
		if (flag == 1) {
			printf (ANSI_COLOR_RED"\n\tLETRA J� EXISTENTE!"ANSI_COLOR_RESET);
		}
		
		if (letra < 64 || letra > 90) {
			printf (ANSI_COLOR_RED"\tLETRA INV�LIDA!"ANSI_COLOR_RESET);
			Sleep (80);
		}

	} while (letra < 64 || letra > 90 || flag == 1);

	return letra;
}

/* - Parte multiplayer do jogo, onde � necess�rio inserir a palavra e o tema relacionado a ela para iniciar, que s�o validaddas pelo
sub-algor�tmo "leValidaTextos".
   - O enforcado tenta digitar uma letra do alfabeto para acertar a palavra, e essa letra � validada pelo sub-algor�tmo "leValidaLetra".
   - Ap�s o enforcado errar ou acertar a palavra o algor�tmo retornar� para o menu, ap�s o usu�rio apertar uma tecla.
*/

void multiPlayer () {

	char palavra[50], chute[50], tema[50], letra, mostraPalavra[50], letrasDigitadas[26] = "";
	char resp;
	int contadorErros = 0, i, contador;
	int chances = 7, pontos = 0;
	int aux;

	do {
		system ("cls");

		printf ("\n\tCERTIFIQUE-SE DE QUE SEU AMIGO N�O O VEJA ESCREVENDO A PALAVRA!");
		printf ("\n\n\tINFORME A PALAVRA.\n");

		printf (ANSI_COLOR_YELLOW"\n\tPALAVRA -> "ANSI_COLOR_RESET);
		leValidaTextos (palavra);
		fflush (stdin);

		system ("cls");

		//Estrutura de repeti��o para deixar a palavra mai�scula.
		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}

		printf ("\n\tAGORA INFORME O TEMA PARA FICAR MAIS F�CIL DE SEU AMIGO ACERTAR.\n");


		printf (ANSI_COLOR_YELLOW"\n\tTEMA -> "ANSI_COLOR_RESET);
		leValidaTextos (tema);
		fflush (stdin);

		system ("cls");

		//Estrutura de repeti��o para deixar o tema mai�sculo.
		for (i = 0; i < strlen (tema); i++) {
			tema[i] = toupper (tema[i]);
		}

		system ("cls");

		printf (ANSI_COLOR_YELLOW"\n\t\t\t\t\t\t          ATEN��O"ANSI_COLOR_RESET);
		printf ("\n\n\tTEM CERTEZA QUE DESEJA ESCOLHER A PALAVRA \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" COM O TEMA \""ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\" ?\n", palavra, tema);
		printf (ANSI_COLOR_YELLOW"\n\t(S/N) -> "ANSI_COLOR_RESET);
		scanf ("%c", &resp);
		resp = toupper (resp);
		fflush (stdin);

	} while (resp != 'S');

	system ("cls");

	for (contador = 0; contador < strlen (palavra); contador++) {
		fflush (stdin);
		strcat (mostraPalavra, "_");
	}

	for (contador = 0; contadorErros < 8; contador++) {
		aux = 1;
  		printf ("------------------------------------------------------------------------------------------------------------------------");
		printf (ANSI_COLOR_YELLOW"\n\t\t\tRELEMBRANDO:"ANSI_COLOR_RESET);
		printf ("\n\n\t\t\t*AGORA, VOC� PODE ESCOLHER UMA LETRA OU ARRISCAR UM CHUTE.");
		printf ("\n\t\t\t*VOC� PODE ERRAR AT� 6 VEZES.");
		printf ("\n\t\t\t*BASTA DIGITAR \"@\" QUANDO SOUBER A PALAVRA E QUISER ARRISCAR UM CHUTE.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");

		printf ("\n\n\tTEMA:"ANSI_COLOR_YELLOW" %s"ANSI_COLOR_RESET, tema);
		printf ("\n\n\tQUANTIDADE DE LETRAS NA PALAVRA:"ANSI_COLOR_YELLOW " %d"ANSI_COLOR_RESET, strlen (palavra));
		printf ("\n\tCHANCES DISPON�VEIS: "ANSI_COLOR_YELLOW"%d"ANSI_COLOR_RESET, chances);

		boneco (contadorErros);

		//L�gica para substitui��o dos underlines pelas letras digitadas, caso estejam certas e desenhamento do boneco, caso erradas.
		for (contador = 0; contador < strlen (palavra) && palavra[contador] != '\0'; contador ++) {
			if (pontos < strlen (palavra)) {
				printf ("%c ", mostraPalavra[contador]);
			} else if (pontos == strlen (palavra) ) {
				printf (ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\t\t\t\t\t     VOC� GANHOU! PALAVRA: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tAPERTE UMA TECLA PARA VOLTAR AO MENU ->> ");
				getch();
				system ("cls");
				menu ();
			}

			if (palavra[contador] == ' '){
				mostraPalavra[contador] = '-';
			}

		}

 		printf ("\n\n\tLETRAS J� ESCOLHIDAS: %c ", letrasDigitadas[contador]);

		letra = leValidaLetras (letrasDigitadas, strlen(letrasDigitadas));
		contador++;

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

		if (letra == '@') {
			printf (ANSI_COLOR_YELLOW"\n\tDIGITE SEU CHUTE -> "ANSI_COLOR_RESET);
			gets (chute);
			fflush (stdin);
            
			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}
			
			if (strcmp(chute, palavra) == 0) {
				printf ("\n\t\t\t\t\t     VOC� GANHOU! A PALAVRA ERA: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDIGITE UMA TECLA PARA VOLTAR AO MENU ->> ");
				getch ();
				system ("cls");
				menu ();
				break;	
			} else {
				system ("cls");
				boneco (contadorErros = 7);
				printf ("\n\t\t\t\t\t     VOC� PERDEU! A PALAVRA ERA: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf ("\n\n\n\tDIGITE UMA TECLA PARA VOLTAR AO MENU ->> ");
				getch ();
				system ("cls");
				menu ();
				break;
			}

		}

		if (contadorErros == 7) {
			system ("cls");
			boneco (contadorErros);
			printf ("\n\t\t\t\t\t     VOC� PERDEU! A PALAVRA ERA: "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
			printf ("\n\n\n\tDIGITE UMA TECLA PARA VOLTAR AO MENU ->> ");
			getch ();
			system ("cls");
			menu ();
			break;
		}

		system ("cls");
	}

}

//Algor�tmo principal.

int main () {

	setlocale (LC_ALL, "");

	menu ();

	return 0;
}

//Leitura e valida��o dos textos digitados, tanto a palavra, quanto o tema.

void leValidaTextos (char *palavra) {

	do {
		gets (palavra);

		if (strlen (palavra) == 0) {
			system ("cls");
			printf (ANSI_COLOR_RED"\tPOR FAVOR, DIGITE ALGO: "ANSI_COLOR_RESET);
		}
	} while (strlen (palavra) == 0);

}
