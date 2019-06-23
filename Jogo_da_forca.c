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

//Definição de códigos de cores no padrão ANSI.

#define ANSI_COLOR_RED      "\e[1;31m"
#define ANSI_COLOR_GREEN    "\e[1;32m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_PURPLE   "\e[1;35m"
#define ANSI_COLOR_YELLOW   "\e[1;33m"
#define ANSI_COLOR_BLUE     "\e[1;34m"
#define ANSI_COLOR_CYAN     "\e[1;36m"

//Declaração de algumas funções.

void leValidaTextos (char *);
void multiPlayer ();

//Intruções do jogo.

void instrucoes () {

	system ("cls");

	printf (ANSI_COLOR_PURPLE"\n\t\t\t>>"ANSI_COLOR_RESET" EXISTEM DOIS JOGADORES: O ENFORCADOR E O ENFOCADO.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" O ENFORCADOR ESCOLHE UMA PALAVRA E UMA DICA E O ENFORCADO TENTA ADIVINHAR.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" O ENFORCADOR TEM QUE GARANTIR QUE O ENFORCADO NÃO VEJA A PALAVRA QUE IRÁ DIGITAR.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" A PALAVRA E A DICA PODEM TER NO MÁXIMO 50 LETRAS.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" O CAMPO DA PALAVRA OU DA DICA NÃO PODEM SER VAZIOS.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" O ENFORCADO TENTA ACERTAR A PALAVRA, CHUTANDO LETRAS QUE ACHA QUE EXISTE NELA.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" SÃO CONCEDIDAS APENAS 7 CHANCES AO ENFORCADO.");
	printf (ANSI_COLOR_PURPLE"\n\n\t\t\t>>"ANSI_COLOR_RESET" CASO QUEIRA TENTAR CHUTAR A PALAVRA, BASTA DIGITAR O CARACTER \"@\".");

	printf ("\n\n\n\n\n\n\t\t\t\t\tAPERTE UMA TELCA PARA VOLTAR AO MENU "ANSI_COLOR_PURPLE">>"ANSI_COLOR_RESET);
	getch ();

	system ("cls");

}

//Função para o desenho do boneco, que recebe como parâmetro o número de erros para desenhar as partes do corpo correspondentes a esse número.

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

//Menu do jogo, onde a pessoa pode iniciar o jogo, acessar as instruções ou sair, bastando digitar a opção correspondente.

void menu () {

	int opcao;
	int i, j;

	system ("cls");

	for (i = 0; i < 3; i++) {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCARREGANDO");
        for (j = 0; j < 3; j++) {
            printf(ANSI_COLOR_PURPLE"."ANSI_COLOR_RESET);
            Sleep(200);
        }
        system ("cls");
    }

	do {

		printf (ANSI_COLOR_PURPLE"\n\t\t\t\t         __                  _        ___                 "ANSI_COLOR_RESET);
		printf (ANSI_COLOR_RED   "\n\t\t\t\t      __|  |___ ___ ___    _| |___   |  _|___ ___ ___ ___ "ANSI_COLOR_RESET);
		printf (ANSI_COLOR_GREEN "\n\t\t\t\t     |  |  | . | . | . |  | . | .'|  |  _| . |  _|  _| .'|"ANSI_COLOR_RESET);
		printf (ANSI_COLOR_CYAN  "\n\t\t\t\t     |_____|___|_  |___|  |___|__,|  |_| |___|_| |___|__,|"ANSI_COLOR_RESET);
		printf (ANSI_COLOR_YELLOW"\n\t\t\t\t               |___|                                      "ANSI_COLOR_RESET);
		printf ("\n");

		printf (ANSI_COLOR_CYAN"\n\n========================================================================================================================"ANSI_COLOR_RESET);
		printf ("\n\n\t\t\t\t\t        ["ANSI_COLOR_PURPLE"1"ANSI_COLOR_RESET"] JOGAR MULTIPLAYER");
		printf ("\n\t\t\t\t\t        ["ANSI_COLOR_RED"2"ANSI_COLOR_RESET"] INSTRUÇÕES");
		printf ("\n\t\t\t\t\t        ["ANSI_COLOR_GREEN"3"ANSI_COLOR_RESET"] SAIR");



		printf (ANSI_COLOR_RED"\n\n\t\t\t\t\t\t >"ANSI_COLOR_RESET ANSI_COLOR_PURPLE"> "ANSI_COLOR_RESET);
		scanf ("%d", &opcao);
		fflush (stdin);

		if (opcao == 1) {
			multiPlayer ();
		} else if (opcao == 2) {
			instrucoes ();
		} else if (opcao == 3) {
			system ("cls");
			for (i = 0; i < 4; i++) {
        		printf("\n\t\t\t\t\t\t\tSAINDO");
        		for (j = 0; j < 3; j++) {
            		printf(ANSI_COLOR_RED"."ANSI_COLOR_RESET);
            		Sleep(200);
				}
				system ("cls");
        	}
			exit(0);
		}

		system ("cls");

	} while (opcao != 3);
}

//Leitura e validação das letras digitadas.

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
		printf (ANSI_COLOR_PURPLE"\n\tTENTAR UMA LETRA "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
		scanf ("%c", &letra);
		fflush (stdin);
		letra = toupper (letra);
		letrasDigitadas[contador] = letra;
		flag = validaIgual (letra, letrasDigitadas, contador);

		if (flag == 1) {
			printf (ANSI_COLOR_RED"\tLETRA JÁ EXISTENTE!"ANSI_COLOR_RESET);
		}

		if (letra < 64 || letra > 90) {
			printf (ANSI_COLOR_RED"\tLETRA INVÁLIDA!"ANSI_COLOR_RESET);
			Sleep (80);
		}

	} while (letra < 64 || letra > 90 || flag == 1);

	return letra;
}

/* - Parte multiplayer do jogo, onde é necessário inserir a palavra e o tema relacionado a ela para iniciar, que são validaddas pelo
sub-algorítmo "leValidaTextos".
   - O enforcado tenta digitar uma letra do alfabeto para acertar a palavra, e essa letra é validada pelo sub-algorítmo "leValidaLetra".
   - Após o enforcado errar ou acertar a palavra o algorítmo retornará para o menu, após o usuário apertar uma tecla.
*/

void multiPlayer () {

	char palavra[50], chute[50], tema[50], letra, mostraPalavra[50], letrasDigitadas[26];
	char resp;
	int contadorErros = 0, i, contador;
	int chances = 7, pontos = 0;
	int aux;

	do {
		system ("cls");

		printf ("\n\tCERTIFIQUE-SE DE QUE SEU AMIGO NÃO O VEJA ESCREVENDO A PALAVRA!");
		printf ("\n\n\tINFORME A PALAVRA.\n");

		printf (ANSI_COLOR_PURPLE"\n\tPALAVRA "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
		leValidaTextos (palavra);
		fflush (stdin);

		system ("cls");

		//Estrutura de repetição para deixar a palavra maiúscula.
		for (i = 0; i < strlen (palavra); i++) {
			palavra[i] = toupper (palavra[i]);
		}

		printf ("\n\tAGORA INFORME O TEMA PARA FICAR MAIS FÁCIL DE SEU AMIGO ACERTAR.\n");


		printf (ANSI_COLOR_PURPLE"\n\tTEMA "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
		leValidaTextos (tema);
		fflush (stdin);

		system ("cls");

		//Estrutura de repetição para deixar o tema maiúsculo.
		for (i = 0; i < strlen (tema); i++) {
			tema[i] = toupper (tema[i]);
		}

		system ("cls");

		printf (ANSI_COLOR_RED"\n\t\t\t\t\t\t          ATENÇÃO"ANSI_COLOR_RESET);
		printf ("\n\n\tTEM CERTEZA QUE DESEJA ESCOLHER A PALAVRA \""ANSI_COLOR_PURPLE"%s"ANSI_COLOR_RESET"\" COM O TEMA \""ANSI_COLOR_PURPLE"%s"ANSI_COLOR_RESET"\" ?\n", palavra, tema);
		printf ("\n\t("ANSI_COLOR_GREEN"S"ANSI_COLOR_RESET"/"ANSI_COLOR_RED"N"ANSI_COLOR_RESET") "ANSI_COLOR_PURPLE">> "ANSI_COLOR_RESET);
		scanf ("%c", &resp);
		resp = toupper (resp);
		fflush (stdin);

	} while (resp != 'S');

	system ("cls");

	for (contador = 0; contador < strlen (palavra); contador++) {
		mostraPalavra[contador] = '_';
	}

	for (contador = 0; contadorErros < 8; contador++) {
		aux = 1;
  		printf ("------------------------------------------------------------------------------------------------------------------------");
		printf (ANSI_COLOR_PURPLE"\n\t\t\tRELEMBRANDO:"ANSI_COLOR_RESET);
		printf ("\n\n\t\t\t*AGORA, VOCÊ PODE ESCOLHER UMA LETRA OU ARRISCAR UM CHUTE.");
		printf ("\n\t\t\t*VOCÊ PODE ERRAR ATÉ 6 VEZES.");
		printf ("\n\t\t\t*BASTA DIGITAR \"@\" QUANDO SOUBER A PALAVRA E QUISER ARRISCAR UM CHUTE.");
		printf ("\n------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t\tVALENDO!");

		printf ("\n\n\tTEMA:"ANSI_COLOR_PURPLE" %s"ANSI_COLOR_RESET, tema);
		printf ("\n\n\tQUANTIDADE DE LETRAS NA PALAVRA:"ANSI_COLOR_PURPLE" %d"ANSI_COLOR_RESET, strlen (palavra));
		printf ("\n\tCHANCES DISPONÍVEIS: "ANSI_COLOR_PURPLE"%d"ANSI_COLOR_RESET, chances);

		boneco (contadorErros);

		//Lógica para substituição dos underlines pelas letras digitadas, caso estejam certas e desenhamento do boneco, caso erradas.
		for (contador = 0; contador < strlen (palavra) && palavra[contador] != '\0'; contador ++) {
			if (pontos < strlen (palavra)) {
				printf ("%c ", mostraPalavra[contador]);
			} else if (pontos == strlen (palavra) ) {
				printf (ANSI_COLOR_GREEN"%s", palavra);
				printf (ANSI_COLOR_GREEN"\n\t\t\t\t\t\t\tVOCÊ GANHOU!"ANSI_COLOR_RESET);
				printf (ANSI_COLOR_PURPLE"\n\n\n\tAPERTE UMA TECLA PARA VOLTAR AO MENU "ANSI_COLOR_RESET ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
				getch();
				fflush (stdin);
				system ("cls");
				menu ();
			}

			if (palavra[contador] == '-' || palavra[contador] == ' '){
				mostraPalavra[contador] = '-';
			}

		}

		fflush (stdin);

		//Printar letras já digitadas.
 		printf ("\n\n\tLETRAS JÁ ESCOLHIDAS "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
		for (i = 0; i < strlen (letrasDigitadas); i++) {
			printf (" %c -", letrasDigitadas[i]);
		}

		letra = leValidaLetras (letrasDigitadas, strlen(letrasDigitadas));

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
			printf (ANSI_COLOR_PURPLE"\n\tDIGITE SEU CHUTE "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
			leValidaTextos (chute);
			fflush (stdin);

			for (i = 0; i < strlen (chute); i++) {
				chute[i] = toupper (chute[i]);
			}

			if (strcmp(chute, palavra) == 0) {
				printf (ANSI_COLOR_GREEN"\n\t\t\t\t\tVOCÊ GANHOU!"ANSI_COLOR_RESET" PALAVRA = "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf (ANSI_COLOR_PURPLE"\n\n\n\tAPERTE UMA TECLA PARA VOLTAR AO MENU "ANSI_COLOR_RESET ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
				getch ();
				fflush (stdin);
				system ("cls");
				menu ();
				break;
			} else {
				system ("cls");
				boneco (contadorErros = 7);
				printf (ANSI_COLOR_RED"\n\t\t\t\t\t\tVOCÊ PERDEU!"ANSI_COLOR_RESET" PALAVRA = "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
				printf (ANSI_COLOR_PURPLE"\n\n\n\tAPERTE UMA TECLA PARA VOLTAR AO MENU "ANSI_COLOR_RESET ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
				getch ();
				fflush (stdin);
				system ("cls");
				menu ();
				break;
			}

		}

		if (contadorErros == 7) {
			system ("cls");
			boneco (contadorErros);
			printf (ANSI_COLOR_RED"\n\t\t\t\t\t\tVOCÊ PERDEU!"ANSI_COLOR_RESET" PALAVRA = "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, palavra);
			printf (ANSI_COLOR_PURPLE"\n\n\n\tAPERTE UMA TECLA PARA VOLTAR AO MENU "ANSI_COLOR_RESET ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
			getch ();
			fflush (stdin);
			system ("cls");
			menu ();
			break;
		}

		system ("cls");
	}

}

//Algorítmo principal.

int main () {

	setlocale (LC_ALL, "");

	menu ();

	return 0;
}

//Leitura e validação dos textos digitados, como a palavra, o tema e o chute.

void leValidaTextos (char *palavra) {

	do {
		gets (palavra);

		if (strlen (palavra) == 0) {
			printf (ANSI_COLOR_RED"\tPOR FAVOR, DIGITE ALGO >> "ANSI_COLOR_RESET);
		}
	} while (strlen (palavra) == 0);

}
