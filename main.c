#include <stdio.h>
#include <stdlib.h>

FILE* abrirArquivo (char nome[], char modo[]);
FILE* fecharArquivo (Arquivo* jogo);

int main () {
	FILE *temp;
	temp = abrirAnrquivo ("teste.txt", "r");
	temp = fecharArquiv0 (temp);
	return 0;
}
FILE* abrirArquivo (char nome[], char modo[]) {
	FILE *jogo;
	arq = fopen (nome, modo);
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
