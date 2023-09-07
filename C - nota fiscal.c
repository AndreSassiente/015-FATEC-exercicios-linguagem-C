/*
    Desenvolva o seguinte programa:

    ENTRADA DE DADOS
    . Numero de itens
    . Codigo do produto
    . Quantidade comprada


    CALCULE E MOSTRE
    . O preco unitario do produto, conforme tabela 1
    . Valor total da nota
    . Valor do desconto, conforme tabela 2
    . Valor final da nota

*/

#include <stdio.h>

int main() {
    int qtdItems, codigo, i, notaItem;
    int produtoCodigo[99];
    int produtoQuantidade[99];
    int produtoValor[99];


    float valorProduto, produtoTotal, desconto, notaDesconto, subtotal, notaTotal;

    qtdItems = 0;
    codigo = 0;
    notaTotal = 0;
    i = 1;

    printf("\n QUANTOS ITEMS? ");
    scanf("%i", &qtdItems);

    for(i = 1; i <= qtdItems; i++){

        printf("\n CODIGO DO PRODUTO N.0%i: ", i);
        scanf("%i", &produtoCodigo[i]);

        while (produtoCodigo[i] <= 0 || produtoCodigo[i] > 40) {

            printf("\n CODIGO INVALIDO. TENTE NOVAMENTE. \n");
            printf("\n CODIGO DO PRODUTO N.0%i: ", i);
            scanf("%i", &produtoCodigo[i]);

        }

        if (produtoCodigo[i] >= 1 && produtoCodigo[i] < 11) {
            produtoValor[i] = 10;
        }

        if (produtoCodigo[i] >= 11 && produtoCodigo[i] < 21) {
            produtoValor[i] = 15;
        }

        if (produtoCodigo[i] >= 21 && produtoCodigo[i] < 31) {
            produtoValor[i] = 20;
        }

        if (produtoCodigo[i] >= 31 && produtoCodigo[i] < 41) {
            produtoValor[i] = 30;
        }

        printf("\n QUANTIDADE: ");
        scanf("%i", &produtoQuantidade[i]);

        subtotal = (produtoValor[i] * produtoQuantidade[i]) + subtotal;

        system("cls");
    }

    //desconto
    if (subtotal > 0 || subtotal <= 250) {
        desconto = 0.05;
    }

    if (subtotal > 250 || subtotal <= 400) {
        desconto = 0,1;
    }

    if (subtotal > 400) {
        desconto = 0.15;
    }

    notaDesconto = subtotal * desconto;
    notaTotal = subtotal - notaDesconto;

    printf("\n ================   NUMERO DE ITENS: 0%i   =============== \n", qtdItems);
    printf("\n[CODIGO] \t\t [QUANTIDADE] \t\t [VALOR] \n");

    for (notaItem = 1; notaItem <= qtdItems; notaItem++){

        produtoTotal = produtoValor[notaItem] * produtoQuantidade[notaItem];

        printf("\n   %i \t\t\t\t %i \t\t %.2f \n", produtoCodigo[notaItem], produtoQuantidade[notaItem], produtoTotal);
    }

    printf("\n\n =======================================================    ");
    printf("\n SUBTOTAL  \t\t\t\t\t %.2f", subtotal);
    printf("\n DESCONTO  \t\t\t\t\t %.2f", notaDesconto);
    printf("\n TOTAL     \t\t\t\t\t %.2f", notaTotal);
    printf("\n ======================================================= \n");

    return 0;
}



