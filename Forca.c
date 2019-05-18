#include <stdio.h>
#include <stdlib.h>

Arquivo *abrirArquivo (char nome[], char modo[]);
Arquivo *fecharArquivo (Arquivo* jogo);
int main () {
	Arquivo *temp;
	temp = abrirAnrquivo ("texte.txt", "r");
	temp = fecharArquiv0 (temp);
	return 0;
}

Arquivo* (char nome[], char modo[]) {
	Arquivo *jogo;
	arq = fopen (nome, modo);
	if (jogo == NULL) {
		printf ("\nNao foi possível abrir o jogo %s\n", nome);
	}
	return jogo;	
}

Arquivo* (Arquivo *jogo) {
	if (jogo == NULL)
		printf ("Erro ao fechar o arquivo");
	fclose (jogo);
	return jogo;
}
