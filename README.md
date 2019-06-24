## JOGO DA FORCA

Jogo da forca desenvolvido em linguagem c.

# MENU

### Menu do jogo.

```c
void menu () {

	int opcao;
	int i, j;

	system ("cls");

	//Simulação de tela de load.
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
		//Simulação de saída do jogo.
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
```
![MENU]()

# ADICIONAR PALAVRA E TEMA

# VALIDAÇÕES
### Leitura e validação das letras digitadas, podendo ser somente do alfabeto e não podendo se repetir.
```c
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
		printf (ANSI_COLOR_PURPLE"\n\n\tTENTAR UMA LETRA "ANSI_COLOR_RED">"ANSI_COLOR_RESET ANSI_COLOR_GREEN"> "ANSI_COLOR_RESET);
		scanf ("%c", &letra);
		fflush (stdin);
		letra = toupper (letra);
		letrasDigitadas[contador] = letra;
		flag = validaIgual (letra, letrasDigitadas, contador);

		//Validação para o enforcado não digitar uma letra já existente.
		if (flag == 1) {
			printf (ANSI_COLOR_RED"\tLETRA JÁ EXISTENTE!"ANSI_COLOR_RESET);
		}

		//Validação para o enforcado digitar apenas letras do alfabeto.
		if (letra < 64 || letra > 90) {
			printf (ANSI_COLOR_RED"\tLETRA INVÁLIDA!"ANSI_COLOR_RESET);
			Sleep (80);
		}

	} while (letra < 64 || letra > 90 || flag == 1);

	return letra;
}
```
![VALIDAÇÃO] ()

### Leitura e validação dos textos digitados, como a palavra, o tema e o chute, usando um ponteiro para a palavra a ser informada.
```c
void leValidaTextos (char *palavra) {

	do {
		gets (palavra);

		if (strlen (palavra) == 0) {
			printf (ANSI_COLOR_RED"\tPOR FAVOR, DIGITE ALGO >> "ANSI_COLOR_RESET);
		}
	} while (strlen (palavra) == 0);

}
```

![VALIDAÇÃO] ()

# RESULTADOS
![RESULTADO] ()
![RESULTADO] ()

# PALAVRA E UNDERLINES

### Atribuição dos underlines a palavra.
```c
for (contador = 0; contador < strlen (palavra); contador++) {
		mostraPalavra[contador] = '_';
}
```
[UNDERLINES] ()
### Substituição dos underlines pela letra digitada.
```c
for (contador = 0; contador < strlen(palavra); contador++) {
			if (letra == palavra[contador]) {
				mostraPalavra[contador] = letra;
				pontos++;
				aux = 0;
			}
	}
```
[SUBSTIRUIÇÃO] ()



