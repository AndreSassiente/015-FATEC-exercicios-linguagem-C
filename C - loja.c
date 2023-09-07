#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// variaveis
struct produto {
	int id;
	char nome[20];
	int quantidade;
	float valor;
};

struct produto pdt_estoque[99];		// produtos do estoque
struct produto pdt_carrinho[99];	// produtos do carrinho

int menu_escolha;					// escolha do switch princiopal

int ie = 1; 						// indice posicao estoque
int id_estoque = 1;					// indice id dos produtos adicionados no estoque
int id_carrinho = 1;				// indice id dos produtos adicionados no carrinho
int i = 1;							// indice geral utilizado para for's

int pdt_editado;					// produto a ser editado
int pdt_removido;					// produto a ser removido
int pdt_vendido;					// produto a ser vendido

int carrinho_quantidade = 0;				// quantidade deseja do produto no carrinho
float carrinho_subtotal[99];					// subtotal dos produtos adicionados no carrinho
float carrinho_total = 0;
int retorno;						// validacao de entradas

// funcoes
int cadastro() {

	system("cls");
	printf("\nCADASTRO ===============================================================================================================\n");


	printf("\n[ 1 ]  ADICIONAR");
	printf("\n[ 2 ]  EDITAR");
	printf("\n[ 3 ]  REMOVER\n");

	printf("\n[ 4 ]  VOLTAR");

	printf("\n\n-> ");

	retorno = scanf("%d", &menu_escolha);
	fflush(stdin);

	while (retorno == 0 || retorno < 1) { // por algum motivo se eu digito uma letra na primeira vez ele aceita como 1, por isso coloquei esse bloco de codigo
		printf("\n[ OPCAO INVALIDA. TENTE NOVAMENTE. ]\n\n");
		system("pause");
		cadastro();
	}

	switch(menu_escolha) {

		case 1:
			adicionar();
		break;
		case 2:
			if (ie <= 1) {
				printf("\n[ ESTOQUE VAZIO ] \n\n\n");
				system("pause");
				cadastro();
			} else { editar(); }
		break;
		case 3:
			if (ie <= 1) {
				printf("\n[ ESTOQUE VAZIO ] \n\n\n");
				system("pause");
				cadastro();
			} else { remover(); }

		break;
		case 4:
			main();
		break;
		default:
			printf("\n[ OPCAO INVALIDA. TENTE NOVAMENTE. ]\n\n");
			system("pause");
			cadastro();
		break;
	}

}

int adicionar() {

	system("cls");
	printf("\nADICIONAR ==============================================================================================================\n");

	printf("\nID\t\t#%d\n", id_estoque);
	pdt_estoque[ie].id = id_estoque;

	printf("\nNOME\t\t");
	fgets(pdt_estoque[ie].nome, 8, stdin);
	fflush(stdin);

	printf("\nVALOR\t\tR$ ");
	scanf("%f", &pdt_estoque[ie].valor);

	printf("\nQUANTIDADE\t");
	scanf("%d", &pdt_estoque[ie].quantidade);

	printf("\n[  ITEM ADICIONADO COM SUCESSO  ] \n\n");
	ie++;
	id_estoque++;

	system("pause");
}

int editar() {
	system("cls");
	printf("\nEDITAR =================================================================================================================\n\n");
	printf("\nID \t\t NOME \t\t QUANTIDADE \t\t VALOR\n");

	for(i = 1; i < ie; i++) {

		printf("\n#%d \t\t %s \t\t %d \t\t %0.2f ", pdt_estoque[i].id, pdt_estoque[i].nome, pdt_estoque[i].quantidade, pdt_estoque[i].valor);

	}

	printf("\n\nSELECIONE ID: \n");
	printf("\n-> ");
	scanf("%d", &pdt_editado);
	fflush(stdin);

	printf("\n[ 1 ]  QUANTIDADE");
	printf("\n[ 2 ]  VALOR\n");
	printf("\n-> ");
	scanf("%d", &menu_escolha);
	fflush(stdin);

	switch(menu_escolha) {

		case 1:

			printf("\nQUANTIDADE\t\t");
			scanf("%d", &pdt_estoque[pdt_editado].quantidade);

			printf("\n[  ITEM EDITADO COM SUCESSO  ]\n\n");
			system("pause");
			break;

		case 2:

			printf("\nVALOR\tR$ ");
			scanf("%f", &pdt_estoque[pdt_editado].valor);

			printf("\n[  ITEM EDITADO COM SUCESSO  ]\n\n");
			system("pause");
			break;

		default:

			printf("\n[ OPCAO INVALIDA. TENTE NOVAMENTE. ]\n\n");
			system("pause");
			break;
	}

}

int remover() {

	system("cls");
	printf("\nREMOVER ================================================================================================================\n\n");

	estoque();

	printf("\n\nSELECIONE ID: \n");
	printf("\n-> ");
	scanf("%d", &pdt_removido);
	fflush(stdin);

	for (i = pdt_removido; i < ie; i++) {

		pdt_estoque[i].id = pdt_estoque[i+1].id;
		pdt_estoque[i].quantidade = pdt_estoque[i+1].quantidade;
		pdt_estoque[i].valor = pdt_estoque[i+1].valor;
		strcpy(pdt_estoque[i].nome, pdt_estoque[i+1].nome);

	}

	--ie;

	system("cls");
	printf("\nEXCLUIR ================\n\n");

	estoque();

	printf("\n\n\n[  ITEM REMOVIDO COM SUCESSO  ]\n\n");
	system("pause");

}

int estoque() {

	printf("\nID \t\t NOME \t\t QUANTIDADE \t\t VALOR\n");

	for(i = 1; i < ie; i++) {

		printf("\n#%d \t\t %s \t\t %d \t\t %0.2f", pdt_estoque[i].id, pdt_estoque[i].nome, pdt_estoque[i].quantidade, pdt_estoque[i].valor);

	}

}

int vender() {

	system("cls");
	printf("\nVENDA ==================\n\n");

	estoque();

	printf("\n\nSELECIONE ID: \n");
	printf("\n-> ");
	scanf("%d", &pdt_vendido);
	fflush(stdin);

	pdt_carrinho[id_carrinho].id = pdt_vendido;
	strcpy(pdt_carrinho[id_carrinho].nome, pdt_estoque[pdt_vendido].nome);
	pdt_carrinho[id_carrinho].quantidade = pdt_estoque[pdt_vendido].quantidade;
	pdt_carrinho[id_carrinho].valor = pdt_estoque[pdt_vendido].valor;

	printf("\nQUANTIDADE\t\t");
	printf("\n-> ");
	scanf("%d", &carrinho_quantidade);

	while (carrinho_quantidade > pdt_estoque[pdt_vendido].quantidade) {

		printf("\n qtd. desejada: %d", carrinho_quantidade);
		printf("\n qtd. disponivel: %d", pdt_estoque[pdt_vendido].quantidade);

		printf("\n qtd. insuficiente. tente novamente");
		printf("\nQUANTIDADE\t\t");
		printf("\n-> ");
		scanf("%d", &carrinho_quantidade);

	}

	pdt_carrinho[id_carrinho].quantidade = carrinho_quantidade;
	pdt_estoque[pdt_vendido].quantidade = pdt_estoque[pdt_vendido].quantidade - carrinho_quantidade;
	carrinho_subtotal[id_carrinho] = carrinho_quantidade * pdt_carrinho[id_carrinho].valor;
	id_carrinho++;

}

int gerarNota() {
	system("cls");
	printf("\nNOTA FISCAL ==================\n\n");

	printf("\nID \t\t NOME \t\t QUANTIDADE \t\t VALOR \t\t SUBTOTAL\n");

	for(i = 1; i < id_carrinho; i++) {

		carrinho_subtotal[i] = pdt_carrinho[i].valor * pdt_carrinho[i].quantidade;
		carrinho_total += carrinho_subtotal[i];
		printf("\n#%d \t\t %s \t\t %d \t\t %0.2f \t\t %.02f", pdt_carrinho[i].id, pdt_carrinho[i].nome, pdt_carrinho[i].quantidade, pdt_carrinho[i].valor, carrinho_subtotal[i]);

	}

	printf("\n\n======================");
	printf("\n\nTOTAL R$ %0.2f", carrinho_total);

	printf("\n\n");
	system("pause");
}

int main() {

	do {
		system("cls");
		printf("\nFATEC STORE ============================================================================================================\n");

		printf("\n[ 1 ]  CADASTRO");
		printf("\n[ 2 ]  ESTOQUE");
		printf("\n[ 3 ]  VENDA");
		printf("\n[ 4 ]  GERAR NOTA\n");

		printf("\n[ 5 ]  ENCERRAR");

		printf("\n\n-> ");

		scanf("%d", &menu_escolha);
		fflush(stdin);

		switch(menu_escolha) {

			case 1:
				cadastro();
			break;

			case 2:
				if (ie <= 1) {
					printf("\n[ ESTOQUE VAZIO ] \n\n\n");
					system("pause");
					main();
				} else {
					system("cls");
					printf("\nESTOQUE ================================================================================================================\n\n");
					estoque();
				}

				printf("\n\n");
				system("pause");
			break;

			case 3:
				if (ie <= 1) {
					printf("\n[ ESTOQUE VAZIO ] \n\n\n");
					system("pause");
					main();
				} else { vender(); }
			break;

			case 4:
				gerarNota();
			break;

			case 5:
				return 0;
			break;

			default:
				main();
			break;
		}

	} while (menu_escolha != 5);

	return 0;
}
