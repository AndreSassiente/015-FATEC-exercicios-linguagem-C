/*
	Faça um programa em C que o usuário digite 10 elementos
	do tipo inteiro, que serão armazenados em um vetor inicial.

	► O programa deve gerar dois novos vetores a partir do vetor
	inicial, sendo um vetor com números pares e outro vetor
	com números ímpares.

	► DICA: Utilize o operador de módulo (%) para determinar se
	um número é par ou ímpar. Quando o número é par o resto
	da divisão do número por 2 é igual a zero.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int vetorPrincipal[10];
	int vetorPar[10];
	int vetorImpar[10];
	int i, np, ni; 				// indice, numero par, numero impar;

	np = 0;
	ni = 0;
	i = 0;

	for (i = 0; i < 10; i++) {

		printf("\nPOSICAO [%d]\t --> ", i + 1);
		scanf("%d", &vetorPrincipal[i]);

		if (vetorPrincipal[i] % 2 == 0) {

			vetorPar[np] = vetorPrincipal[i];
			np++;

		}

		if (vetorPrincipal[i] % 2 != 0) {


			vetorImpar[ni] = vetorPrincipal[i];
			ni++;

		}

	}

	printf("\n------------------------------------------------------------------");

	printf("\n\nNUMEROS PARES\t\n\n");
	for (i = 0; i < np; i++) {

		printf("%d\t", vetorPar[i]);

	}

	printf("\n\nNUMEROS IMPARES\t\n\n");
	for (i = 0; i < ni; i++) {

		printf("%d\t", vetorImpar[i]);

	}

	printf("\n\n\n\n");

	return 0;

}
