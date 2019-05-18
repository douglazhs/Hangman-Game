#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

FILE* abrirArquivo (char nome[], char modo[]);
FILE* fecharArquivo (FILE* jogo);
void menu ();
void adicionarDica ();
void adicionarPalavra ();
void jogar ();
void boneco ();
void jogar ();
void resultado (char resultado [201], bool resultado);

int main () {
	setlocale (LC_ALL, "");
	FILE *temp;
	temp = abrirArquivo ("main.c", "r");
	temp = fecharArquiv0 (temp);
	return 0;
}
FILE* abrirArquivo (char nome[], char modo[]) {
	FILE *jogo;
	jogo = fopen (nome, modo);
	if (jogo == NULL) {
		printf ("\nNao foi possível abrir o jogo %s\n", nome);
	}
	return jogo;	
}

FILE* fecharArquivo (FILE *jogo) {
	if (jogo == NULL)
		printf ("Erro ao fechar o arquivo");
		fclose (jogo);
	return jogo;
}

void menu () {
	do {
		printf ("\n\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
		printf ("\n\tº                            º");
		printf ("\n\tº         JOGO DA FORCA      º");
		printf ("\n\tº                            º");
		printf ("\n\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹");
		printf ("\n\tº         [1] JOGAR                   º");
		printf ("\n\tº         [2] ADICIONAR DICA                  º");
		printf ("\n\tº         [3] ADICIONAR PALAVRA                º");
		printf ("\n\tº         [4] SAIR                  º");
		printf ("\n\tDigite uma das opções: ");
		
		if (opcao == '1') {
			jogar ();
		} else if (opcao == '2') {
			adicionarDica ();
		} else if (opcao == '3') {
			adicionarPalavra ();
		}
		
	} while (opcao != 4);
}

void jogar () {
	char palavra [201];
	char dica [201];
}

void resultado (char palavra [201], bool resultado) {
	SYSTEM ("cls");
	printf ("----------RESULTADO----------");
	if (resultado=true) {
		printf ("\n\t\t VOCÊ GANHOU!");
	} else {
		printf ("\n\t\t VOCÊ PERDEU!");
	}
}

void boneco (int membros) {
	switch (membros) {
	case 1:	
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ");
		printf ("\nÛ");	
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
	case 2:
	default: 
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ			 |");
		printf ("\nÛ		     |");	
		printf ("\nÛ	         |");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
	case 3:
	default: 
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ			 |\\");
		printf ("\nÛ		     | \\");	
		printf ("\nÛ	         |");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
	case 4:
	default: 
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ			/|\\");
		printf ("\nÛ		   / | \\");	
		printf ("\nÛ	         |");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
		printf ("\nÛ");
	
	case 5: 
	default: 
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ			/|\\");
		printf ("\nÛ		   / | \\");	
		printf ("\nÛ	         |");
		printf ("\nÛ	          \\");
		printf ("\nÛ               \\");
		printf ("\nÛ");
		printf ("\nÛ");
		
	case 6:
	default: 
		printf ("\nÛßßßßßßßßßßßßßß");
		printf ("\nÛ			***");
		printf ("\nÛ		   *	*");	
		printf ("\nÛ		   	***");
		printf ("\nÛ			/|\\");
		printf ("\nÛ		   / | \\");	
		printf ("\nÛ	         |");
		printf ("\nÛ	        / \\");
		printf ("\nÛ           /   \\");
		printf ("\nÛ");
		printf ("\nÛ");
	}
}
void pausa () {
	
	printf ("\nAPERTE UMS TECLA PARA VOLTAR AO MENU PRINCIPAL");
	fflush (stdin);
	getchar ();
	
}