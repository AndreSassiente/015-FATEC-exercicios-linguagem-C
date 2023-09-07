#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

inserir()
{
    char numstr[10];
    char resp;

    FILE *fptr;
    CLIENTE fatec;

    fptr=fopen("arquivo","ab");

    if (fptr == NULL)
    {
        printf("\n Problemas com abertura de arquivo");
        system("pause");
    }

    system("cls");

    do
    {
        printf("\n ===================================================");
        printf("\n ============ CADASTRO DE REGISTRO =================");
        printf("\n ===================================================");

        printf("\n CODIGO CLIENTE: ");
        scanf("%i", &fatec.codigo);
        fflush(stdin);

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

        printf("\n SALARIO: ");
        gets(numstr);
        fatec.salario = atof(numstr);
        fflush(stdin);

        fwrite(&fatec, sizeof(fatec), 1, fptr);

        printf("\n CONTINUAR CADASTRO?    [S]IM    [N]AO    : ");
        resp = getchar();


    }
    while (resp == 's' || resp == 'S');

    fclose(fptr);
}

pesquisa()
{
    char numstr[20];
    int achou = 0; // flag

    FILE *fptr;
    CLIENTE fatec;

    fptr = fopen("arquivo", "rb");

    if (fptr == NULL)
    {
        printf("\n Problemas com Abertura do Arquivo");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n ===================================================");
        printf("\n ============ PESQUISA POR SOBRENOME ===============");
        printf("\n ===================================================");

        printf("\n INFORME O SOBRENOME DO CLIENTE A SER PESQUISADO: ");
        scanf("%s", &numstr);
        fflush(stdin);

        while (fread(&fatec, sizeof(CLIENTE), 1, fptr))
        {
            if (strcmp(numstr, fatec.sobrenome) == 0)
            {
                printf("\n CODIGO \t\t %d", fatec.codigo);
                printf("\n NOME \t\t %d", fatec.nome);
                printf("\n RG \t\t %d", fatec.rg);
                printf("\n TELEFONE \t\t %d", fatec.telefone);
                printf("\n SALARIO \t\t %d", fatec.salario);

                system("pause");
                achou = 1;
                break;

            }
        }

        if (achou == 0)
        {
            printf("\n REGISTRO NÃO ENCONTRADO. TENTE NOVAMENTE.");
            syste("pause");
        }
    }
}

exibir()
{
    float total;
    FILE *fptr;
    CLIENTE fatec;

    fptr=fopen("arquivo", "rb");

    if (fptr = NULL)
    {
        printf("\n Problemas na abertura do arquivo.");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n ===================================================");
        printf("\n ============ RELATÓRIO DO ARQUIVO =================");
        printf("\n ===================================================");

        printf("\n CODIGO \t NOME \t TELEFONE \n SALARIO");

        while (fread(&fatec, sizeof(CLIENTE), 1, fptr))
        {
            printf("\n %d \t %-10s \t %-10d \t %-150.2f", fatec.codigo, fatec.nome, fatec.telefone, fatec.salario);

            total += fatec.salario;
        }

        printf("\n  *************************************************");
        printf("\n  ************************* Salario    R$ %.f",total);
        printf("\n  *************************************************");
        printf("\n\n");
        system("pause");

        fclose(fptr);
    }
}

alterar()
{
    char numstr[20];
    int c;
    c=0;
    FILE *fptr;
    CLIENTE fatec;

    fptr=fopen("arquivo","rb+");

    if(fptr == NULL)
    {
        printf("\n Problemas com Abertura do Arquivo");
        system("pause");
    }else {

     system("cls");
     printf("\n *********************************************");
     printf("\n ******** Alteração de Registro **************");
     printf("\n *********************************************");

    printf("\n Informe o Sobrenome do Cliente a ser pesquisado");
    scanf("%s",&numstr);
    fflush(stdin);

    fread(&fatec,sizeof(CLIENTE),1,fptr);

    while(!eof(fptr) && strcmp(numstr,fatec.nome)!=0)
    {
        fread(&fatec,sizeof(CLIENTE),1,fptr);
        c++;

    }

      if(feof(fptr))
         {
             printf("\n Registro não consta no Arquivo");
             printf("\n\n");
             system("pause");

         }

         fseek(fptr,c*sizeof(CLIENTE),SEEK_SET);
         printf("\n Nome .....: %s",fatec.nome);
         printf("\n Sobrenome...%s",fatec.sobrenome);
         printf("\n Rg..........%d",fatec.rg);
         printf("\n Telefone ...%d",fatec.telefone);
         scanf("%d",&fatec.telefone);
         printf("\n Salario ....%.2f",fatec.salario);
         scanf("%f",&fatec.salario);

         fwrite(&fatec,sizeof(CLIENTE),1,fptr);



}
fclose(fptr);
}


main()
{
    int op;
    do
    {
        system("cls");
        printf("\n [1] - Inserir Registro..............");
        printf("\n [2] - Consultar Registro............");
        printf("\n [3] - Exibir - Relatorio de Clientes");
        printf("\n [4] - Alterar Registro..............");
        printf("\n  ****  Informe a Opção Desejada ****");

        scanf("%d",&op);

        switch (op)
        {

        case 1:
            inserir();
            break;
        case 2:
            pesquisa();
            break;
        case 3:
            exibir();
            break;
        case 4:
            alterar();
            break;
        case 5:
            exit(0);
        default :
            printf("\n Opção Invalida.. tente novamente");
            system("pause");
        }
    }
    while(op!=5);
}

