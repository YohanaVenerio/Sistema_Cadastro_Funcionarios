/*Autor....: Yohana
  Data.....: 02/10/2024
  Objetivo.: Lista Simplesmente encadeada */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Função Contrução de Tela Padrão
void tela()
{
    system("Color 80"); 
    int lin;
    system("cls");
    for (lin = 1; lin < 27; lin++)
    {
        gotoxy(01, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 04);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 26);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(03, 02);
    printf("UNICV");
    gotoxy(60, 02);
    printf("Estrutura de Dados |");
    gotoxy(03, 03);
    printf("SISTEMA DE FOLHA DE PAGAMENTOS");
    gotoxy(64, 03);
    printf("Yohana Venerio");
    gotoxy(02, 25);
    printf("MSG:");
}

//Cria tela inicial
void tela_principal(){
        gotoxy(20,6);
        printf("1 - CADASTRAR FUNCIONARIO NO FINAL");
        gotoxy(20,8);
        printf("2 - CADASTRAR FUNCIONARIO NO INICIO");
        gotoxy(20,10);
        printf("3 - CADASTRAR FUNCIONARIO NA POSICAO _");
        gotoxy(20,12);
        printf("4 - REMOVER FUNCIONARIO NO INICIO");
        gotoxy(20,14);
        printf("5 - REMOVER FUNCIONARIO NO FINAL");
        gotoxy(20,16);
        printf("6 - REMOVER FUNCIONARIO NA POSICAO _");
        gotoxy(20,18);
        printf("7 - ALTERACAO DO CADASTRO DE FUNCIONARIO");
        gotoxy(20,20);
        printf("8 - CONSULTAR FUNCIONARIOS");
        gotoxy(20,22);
        printf("9 - SAIR");
        
}

//Cria Tipo Registro
typedef struct{
    int codigo;
    char nome[50];
    char endereco[50];
    char cargo[50];
    char dt_admissao[11];
    char telefone[15];
    float salario;
}reg_funcionario;

//Cria ponteiro
typedef struct TipoItem *TipoApontador;

//Cria Tipo Item
typedef struct TipoItem{
    reg_funcionario conteudo;
    TipoApontador proximo;
} TipoItem;

//Cria Tipo Lista
typedef struct{
    TipoApontador primeiro;
    TipoApontador ultimo;
    
} TipoLista;

TipoApontador pesquisa(TipoLista *L, int cod)
{
    TipoApontador aux;
    aux = L->primeiro;
    while (aux != NULL)
    {
       if (aux ->conteudo.codigo == cod)
       {
         return aux;
       } 
        aux = aux -> proximo;
    }
    return NULL;
}
//Tela de cadastro
void tela_cadastro(){
    gotoxy(15,8);
    printf("CODIGO........: ");
    gotoxy(15,10);
    printf("NOME..........: ");
    gotoxy(15,12);
    printf("ENDERECO......: ");
    gotoxy(15,14);
    printf("CARGO.........: ");
    gotoxy(15,16);
    printf("DATA_ADMISSAO.: ");
    gotoxy(15,18);
    printf("TELEFONE......: ");
    gotoxy(15,20);
    printf("SALARIO.......: ");

    
}

//Função Cadastrar
int cadastrar(TipoLista*L){
    
    reg_funcionario reg_funci;
    TipoApontador p;
    int cod;
    int resp;
    TipoApontador aux;
    do
    {
        do {
            tela();
            tela_cadastro();
            gotoxy(30,3);
            printf("CADASTRAR");
            gotoxy(31,8);
            printf("                  ");
            gotoxy(31,8);
            scanf("%d",&reg_funci.codigo);
            aux = pesquisa(L, reg_funci.codigo);
            if (aux != NULL)
            {
                gotoxy(07,25);
                printf("CODIGO JA CADASTRADO");
                getch();
            }
        } while (aux != NULL);
        gotoxy(31,10);
        fflush(stdin);
        fgets(reg_funci.nome, 50, stdin);
        gotoxy(31,12);
        fflush(stdin);
        fgets(reg_funci.endereco, 50,stdin);
        gotoxy(31,14);
        fflush(stdin);
        fgets(reg_funci.cargo, 50, stdin);
        gotoxy(31,16);
        fflush(stdin);
        fgets(reg_funci.dt_admissao, 11, stdin);
        gotoxy(31,18);
        fflush(stdin);
        fgets(reg_funci.telefone, 15,stdin);
        gotoxy(31,20);
        scanf("%f",&reg_funci.salario);
        
        gotoxy(7,25);
        printf("DESEJA SALVAR AS INFORMACOES ? [1-SIM / 2-NAO] : ");
        scanf("%d", &resp);
        
        if(resp==1){
            p=(TipoApontador)malloc(sizeof(TipoItem));
            p->conteudo = reg_funci;
            p->proximo = NULL;
            if(L->primeiro == NULL){
                L->primeiro = p; 
                L->ultimo = p;
            }else{
                L->ultimo->proximo = p;
                L->ultimo = p;
            }
            gotoxy(7,25);
            printf("                                                         ");
            gotoxy(30,23);
            printf("CADASTRO SALVO");
            gotoxy(7,25);
            printf("CADASTRAR NOVO FUNCIONARIO ? [1-SIM / 2-NAO] : ");
            scanf("%d", &resp);
            
            
        }
    }while(resp==1);

    return 0;
}

//Função consultar
int consultar(TipoLista *L){
    TipoApontador p;
    int opcao;
    int i = 1;

    if (L->primeiro == NULL) {
        tela();
        gotoxy(30, 12);
        printf("LISTA VAZIA");
        gotoxy(7,25);
        printf("PRESSIONE ENTER PARA CONTINUAR");
        getch();
    } else {
        p = L->primeiro;                     
        tela();
        do {
             
            gotoxy(15,6);
            printf("CADASTRO......: %d", i);
            gotoxy(15,8);
            printf("CODIGO........: %d", p->conteudo.codigo);
            gotoxy(15,10);
            printf("NOME..........: %s", p->conteudo.nome);
            gotoxy(15,12);
            printf("ENDERECO......: %s", p->conteudo.endereco);
            gotoxy(15,14);
            printf("CARGO.........: %s", p->conteudo.cargo);
            gotoxy(15,16);
            printf("DATA_ADMISSAO.: %s", p->conteudo.dt_admissao);
            gotoxy(15,18);
            printf("TELEFONE......: %s", p->conteudo.telefone);
            gotoxy(15,20);
            printf("SALARIO.......: %.2f", p->conteudo.salario);

            gotoxy(51,25);
            printf("         ");
            gotoxy(7, 25);
            printf("MOSTRAR PROXIMO CADASTRO ? [1-SIM / 2-NAO]: ");
            scanf(" %d", &opcao);
            

            if (opcao == 1) {
                p = p->proximo;
                i++;
            }
            if(p==NULL){
                tela();
                gotoxy(26,12);
                printf("FIM DA LISTA DE CADASTROS");
                gotoxy(7,25);
                printf("PRESSIONE ENTER PARA CONTINUAR");
                getch();
            }
        } while (opcao==1 && p!=NULL);
        
    }
    return 0;
}


int main()
{
    tela();

    TipoLista L;
    int opc;
    L.primeiro = NULL;
    L.ultimo = NULL;

    do
    {
        
        tela();
        tela_principal();
        gotoxy(7,25);
        printf("DIGITE SUA OPCAO : ");
        scanf("%d", &opc);


        switch (opc)
        {
        case 1:
            cadastrar(&L);
            break;
        case 8:
            consultar(&L);
        }
    }while(opc != 3);
    
    
    return 0;
}