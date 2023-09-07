#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct dados
{
    int codigo;
    char nome[20];
    char sobrenome[20];
    int rg;
    int telefone;
    float salario;
    int status;
} CLIENTE;

// FUNÇÕES

inserir()
{
    char numstr[10];
    char resp;

    FILE *fptr;
    CLIENTE fatec;

    fptr=fopen("arquivo", "ab");

    if (fptr == NULL)
    {
        printf("\n [ FALHA AO ABRIR O ARQUIVO ]");
        system("pause");
    }

    system("cls");

    do
    {
        printf("\n CADASTRO DE REGISTRO ===================================================================================\n");

        printf("\n CODIGO CLIENTE: ");
        scanf("%d", &fatec.codigo);
        fflush(stdin);

        if (fatec.codigo == "")
        {
            printf("\n [ CAMPO NÃO FICAR VAZIO ] \n");
        }

        printf("\n NOME: ");
        gets(fatec.nome);
        fflush(stdin);

        printf("\n SOBRENOME: ");
        gets(fatec.sobrenome);
        fflush(stdin);

        printf("\n RG: ");
        gets(numstr);
        fatec.rg = atoi(numstr);
        fflush(stdin);

        printf("\n TELEFONE: ");
        gets(numstr);
        fatec.telefone = atoi(numstr);
        fflush(stdin);

        printf("\n SALARIO: R$ ");
        gets(numstr);
        fatec.salario = atof(numstr);
        fflush(stdin);

        fwrite(&fatec, sizeof(fatec), 1, fptr);

        printf("\n CONTINUAR CADASTRO [ S ]IM   [ N ]AO   --> ");
        resp = getchar();
    }
    while (resp == 's' || resp == 'S');

    fclose(fptr);
}

pesquisar()
{
    char numstr[20];
    int found = 0;		// FLAG

    FILE *fptr;
    CLIENTE fatec;

    fptr = fopen("arquivo", "rb");

    if (fptr == NULL)
    {
        printf("\n [ FALHA AO ABRIR O ARQUIVO ] \n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n PESQUISA POR SOBRENOME ========================================================\n");

        printf("\n SOBRENOME: ");
        scanf("%s", &numstr);
        fflush(stdin);

        while (fread(&fatec, sizeof(CLIENTE), 1, fptr))
        {
            if (strcmp(numstr, fatec.sobrenome) == 0)
            {
                printf("\n CODIGO: \t\t %d", fatec.codigo);
                printf("\n NOME: \t\t %s", fatec.nome);
                printf("\n SOBRENOME: \t\t %s", fatec.sobrenome);
                printf("\n RG: \t\t %d", fatec.rg);
                printf("\n TELEFONE: \t\t %d", fatec.telefone);
                printf("\n SALARIO: \t\t %.2f", fatec.salario);

                system("pause");
                found = 1;
                break;
            }
        }

    }

    if (found == 0)
    {
        printf("\n [ SOBRENOME NÃO ENCONTRADO. TENTE NOVAMENTE ] \n");
        system("pause");
    }

    fclose(fptr);
}

exibir()
{
    float total;
    FILE *fptr;
    CLIENTE fatec;

    fptr = fopen("arquivo", "rb");

    if (fptr == NULL)
    {
        printf("\n [ FALHA AO ABRIR O ARQUIVO ] \n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n RELATORIO DO ARQUIVO ========================================================\n");
        printf("\n CODIGO \t NOME \t TELEFONE \t SALARIO");

        while (fread(&fatec, sizeof(CLIENTE), 1, fptr))
        {
            printf("\n %-10d \t %-20s \t %-10d \t %10.2f", fatec.codigo, fatec.nome, fatec.telefone, fatec.salario);
            total += fatec.salario;
        }

        printf("\n TOTAL SALARIO: R$ %.f", total);
        system("pause");
        fclose(fptr);
    }
}

alterar()
{
    char numstr[20];
    int c = 0;

    FILE *fptr;
    CLIENTE fatec;

    fptr = fopen("arquivo", "rb+");

    if (fptr == NULL)
    {
        printf("\n [ FALHA AO ABRIR O ARQUIVO ] \n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n ALTERACAO DO REGISTRO ========================================================\n");

        printf("\n NOME DO CLIENTE A SER ALTERADO: ");
        gets(numstr);
        fflush(stdin);

        fread(&fatec, sizeof(CLIENTE), 1, fptr);

        while (!feof(fptr) && strcmp(numstr, fatec.nome) != 0)
        {
            fread(&fatec, sizeof(CLIENTE), 1, fptr);
            c++;
        }

        if (feof(fptr))
        {
            printf("\n [ REGISTRO NÃO CONSTA NO ARQUIVO ] \n");
            system("pause");
        }
        else
        {
            fseek(fptr, c*sizeof(CLIENTE), SEEK_SET);
            printf("\n NOME: \t\t %s", fatec.nome);
            printf("\n SOBRENOME: \t\t %s", fatec.sobrenome);
            printf("\n RG: \t\t %d", fatec.rg);

            printf("\n TELEFONE: \t\t %d", fatec.telefone);
            scanf("%d", &fatec.telefone);

            printf("\n SALARIO: \t\t %.2f", fatec.salario);
            scanf("%f", &fatec.salario);

            fwrite(&fatec, sizeof(CLIENTE), 1, fptr);
        }
    }

    fclose(fptr);
}

void deletar()
{
    char numstr[20];
    int found = 0;

    FILE *fptr;
    FILE *temp;
    CLIENTE fatec;

    fptr = fopen("arquivo", "rb+");
    temp = fopen("temfile", "wb"); 		// temporary file for writing modified records

    if (fptr == NULL || temp == NULL)
    {
        printf("\n [ FALHA AO ABRIR O ARQUIVO ] \n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n DELETAR REGISTRO ========================================================\n");

        printf("\n NOME DO CLIENTE A SER DELETADO: ");
        gets(numstr);
        fflush(stdin);

        while (fread(&fatec, sizeof(CLIENTE), 1, fptr))
        {
            if (strcmp(numstr, fatec.nome) != 0)
            {
                fwrite(&fatec, sizeof(CLIENTE), 1, temp); // write records to temporary file except the one to be deleted
            }
            else
            {
                found = 1; // record found and deleted
            }
        }

        fclose(fptr);
        fclose(temp);

        remove("arquivo"); // delete the original file
        rename("tempfile", "arquivo"); // rename the temporary file to the original file name

        if (found)
        {
            printf("\n [ REGISTRO DELETADO COM SUCESSO ] \n");
        }
        else
        {
            printf("\n [ REGISTRO NÃO ENCONTRADO ] \n");
        }

        system("pause");
    }
}

int main()
{
    int op;

    do
    {
        system("cls");
        printf("\n [ 1 ]  INSERIR REGISTRO");
        printf("\n [ 2 ]  CONSULTAR REGISTRO");
        printf("\n [ 3 ]  RELATORIO DE CLIENTES");
        printf("\n [ 4 ]  ALTERAR REGISTRO");
        printf("\n [ 5 ]  DELETAR REGISTRO");
        printf("\n [ 6 ]  SAIR");

        printf("\n --> ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            inserir();
            break;

        case 2:
            pesquisar();
            break;

        case 3;
            exibir();
            break;

        case 4:
            alterar();
            break;

        case 5:
            deletar();
            break;

        case 6:
            exit(0);

        default:
            printf("\n [ OPCAO INVALIDA. TENTE NOVAMENTE ]");
            system("pause");
        }

    }
    while (op != 6);
}
