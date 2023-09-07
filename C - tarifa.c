#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

	int produtos;
	int retorno;
	int i;
	int pais[99];

	float preco[produtos];
	float precoTotal[99];
	float imposto[99];
	float porcentagem[99];
	float frete[99];
	float seguro[99];

	char transporte[99];
	char freteID[99];

	printf("\n QUANTIDADE DE PRODUTOS \t\t  ");
	retorno = scanf("%d", &produtos);

	system("cls");

	//VALIDAR SE A QUANTIDADE DE PRODUTOS É UM NÚMERO E SE MAIOR QUE ZERO
	while (retorno == 0 || produtos <= 0) {

		fflush(stdin);
		printf("\n ERRO. TENTE NOVAMENTE. \n\n");

		system("pause");
		system("cls");


		printf("\n QUANTIDADE DE PRODUTOS \t\t  ");
		retorno = scanf("%d", &produtos);
		system("cls");

	}



	for (i = 1; i <= produtos; i++) {

		printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
		printf("\n ID PRODUTO\t\t\t\t# %d", i);
		printf("\n VALOR \t\t\t\t R$ ");
		retorno = scanf("%f", &preco[i]);
		fflush(stdin);

		while (retorno == 0 || preco[i] <= 0) {

			fflush(stdin);
			printf("\n ERRO. TENTE NOVAMENTE. \n\n");

			system("pause");
			system("cls");


			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n ID PRODUTO\t\t\t\t# %d", i);
			printf("\n VALOR \t\t\t\t R$ ");
			retorno = scanf("%f", &preco[i]);

		}

		fflush(stdin);
		printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
		printf("\n [ 1 ] \t EUA");
		printf("\n [ 2 ] \t MEXICO");
		printf("\n [ 3 ] \t OUTROS \n");
		printf("\n PAIS DE ORIGEM \t\t\t ");
		retorno = scanf("%d", &pais[i]);
		fflush(stdin);

		while (retorno == 0 || pais[i] != 1 && pais[i] != 2 && pais[i] != 3) {
            fflush(stdin);
			printf("\n ERRO. TENTE NOVAMENTE. \n\n");

			system("pause");
			system("cls");


			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n ID PRODUTO\t\t\t\t# %d", i);
			printf("\n VALOR \t\t\t\t R$ %.02f \n", preco[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ 1 ] \t EUA");
			printf("\n [ 2 ] \t MEXICO");
			printf("\n [ 3 ] \t OUTROS \n");
			printf("\n PAIS DE ORIGEM \t\t\t ");
			retorno = scanf("%d", &pais[i]);

		}


		fflush(stdin);
		printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
		printf("\n [ T ] \t TERRESTRE");
		printf("\n [ F ] \t FLUVIAL");
		printf("\n [ A ] \t AEREO \n");
		printf("\n MEIO DE TRANSPORTE \t\t\t ");
		retorno = scanf(" %c", &transporte[i]);
		transporte[i] = toupper(transporte[i]);
		fflush(stdin);

		while (retorno == 0 || transporte[i] != 'T' && transporte[i] != 'F' && transporte[i] != 'A') {

			printf("\n ERRO. TENTE NOVAMENTE. \n\n");

			system("pause");
			system("cls");


			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n ID PRODUTO\t\t\t\t# %d", i);
			printf("\n PREÇO \t\t\t\t R$ %.02f \n", preco[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ 1 ] \t EUA");
			printf("\n [ 2 ] \t MEXICO");
			printf("\n [ 3 ] \t OUTROS \n");
			printf("\n PAIS DE ORIGEM \t\t\t %d \n", pais[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ T ] \t TERRESTRE");
			printf("\n [ F ] \t FLUVIAL");
			printf("\n [ A ] \t AEREO \n");
			printf("\n MEIO DE TRANSPORTE \t\t\t ");
			retorno = scanf(" %c", &transporte[i]);
			transporte[i] = toupper(transporte[i]);
			fflush(stdin);
		}


		printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
		printf("\n [ S ] \t SIM");
		printf("\n [ N ] \t NAO \n");
		printf("\n CARGA PERIGOSA \t\t\t ");
		retorno = scanf(" %c", &freteID[i]);
		freteID[i] = toupper(freteID[i]);
		fflush(stdin);

		while (retorno == 0 || freteID[i] != 'S' && freteID[i] != 'N') {

			printf("\n ERRO. TENTE NOVAMENTE. \n\n");

			system("pause");
			system("cls");


			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n ID PRODUTO\t\t\t\t# %d", i);
			printf("\n VALOR \t\t\t\t R$ %.02f \n", preco[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ 1 ] \t EUA");
			printf("\n [ 2 ] \t MEXICO");
			printf("\n [ 3 ] \t OUTROS \n");
			printf("\n PAÍS DE ORIGEM \t\t\t %d \n", pais[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ T ] \t TERRESTRE");
			printf("\n [ F ] \t FLUVIAL");
			printf("\n [ A ] \t AEREO \n");
			printf("\n MEIO DE TRANSPORTE \t\t\t %c \n", transporte[i]);

			printf("\n :::::::::::::::::::::::::::::::::::::::::: \n");
			printf("\n [ S ] \t SIM");
			printf("\n [ N ] \t NAO \n");
			printf("\n CARGA PERIGOSA \t\t\t ");
			retorno = scanf(" %c", &freteID[i]);
			freteID[i] = toupper(freteID[i]);
			fflush(stdin);

		}

		// PERCENTUAL DE IMPOSTO
		if (preco[i] < 100) { porcentagem[i] = 0.05; }
		else if (preco[i] > 100) { porcentagem[i] = 0.10; }

		// VALOR DO FRETE
		if 		(freteID[i] == 'S' && pais[i] == 1) {frete[i] = 50;}
		else if (freteID[i] == 'S' && pais[i] == 2) {frete[i] = 35;}
		else if (freteID[i] == 'S' && pais[i] == 3) {frete[i] = 24;}

		else if (freteID[i] == 'N' && pais[i] == 1) {frete[i] = 12;}
		else if (freteID[i] == 'N' && pais[i] == 2) {frete[i] = 35;}
		else if (freteID[i] == 'N' && pais[i] == 3) {frete[i] = 60;}

		// VALOR DO SEGURO
		if (pais[i] == 2 || transporte[i] == 'A') {seguro[i] = preco[i] / 2;}
		else {seguro[i] = 0;}

		imposto[i] = preco[i] * porcentagem[i];
		precoTotal[i] = preco[i] + imposto[i] + frete[i] + seguro[i];

		system("cls");
	}

	printf("\n ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: \n");
	printf("\n PRODUTO\t\tVALOR\t\tIMPOSTO\t\tFRETE\t\tSEGURO\t\tTOTAL\n");

	for (i = 1; i <= produtos; i++) {
		printf("\n %d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, preco[i], imposto[i], frete[i], seguro[i], precoTotal[i]);
	}

	printf("\n ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: \n");

	return 0;
}

//se eu colocar duas letras ele passa...
