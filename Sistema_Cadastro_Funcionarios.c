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

// Cria tela inicial
void tela_principal()
{
    gotoxy(20, 6);
    printf("1 - CADASTRAR FUNCIONARIO NO FINAL");
    gotoxy(20, 8);
    printf("2 - CADASTRAR FUNCIONARIO NO INICIO");
    gotoxy(20, 10);
    printf("3 - CADASTRAR FUNCIONARIO NA POSICAO _");
    gotoxy(20, 12);
    printf("4 - REMOVER FUNCIONARIO NO INICIO");
    gotoxy(20, 14);
    printf("5 - REMOVER FUNCIONARIO NO FINAL");
    gotoxy(20, 16);
    printf("6 - REMOVER FUNCIONARIO NA POSICAO _");
    gotoxy(20, 18);
    printf("7 - ALTERACAO DO CADASTRO DE FUNCIONARIO");
    gotoxy(20, 20);
    printf("8 - CONSULTAR FUNCIONARIOS");
    gotoxy(20, 22);
    printf("9 - SAIR");
}

// Cria Tipo Registro
typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char cargo[50];
    char dt_admissao[11];
    char telefone[15];
    float salario;
} reg_funcionario;

// Cria ponteiro
typedef struct TipoItem *TipoApontador;

// Cria Tipo Item
typedef struct TipoItem
{
    reg_funcionario conteudo;
    TipoApontador proximo;
} TipoItem;

// Cria Tipo Lista
typedef struct
{
    TipoApontador primeiro;
    TipoApontador ultimo;

} TipoLista;

// Pesquisa códigos para validação
TipoApontador pesquisa(TipoLista *L, int cod)
{
    TipoApontador aux;
    aux = L->primeiro;
    while (aux != NULL)
    {
        if (aux->conteudo.codigo == cod)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// Contagem de cadastros
int contagem(TipoLista *L)
{
    int cont;
    TipoApontador aux;
    aux = L->primeiro;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

// Tela de cadastro
void tela_cadastro()
{
    gotoxy(15, 8);
    printf("CODIGO........: ");
    gotoxy(15, 10);
    printf("NOME..........: ");
    gotoxy(15, 12);
    printf("ENDERECO......: ");
    gotoxy(15, 14);
    printf("CARGO.........: ");
    gotoxy(15, 16);
    printf("DATA_ADMISSAO.: ");
    gotoxy(15, 18);
    printf("TELEFONE......: ");
    gotoxy(15, 20);
    printf("SALARIO.......: ");
}

// Função Cadastrar no final da lista
void cadastro_fim(TipoLista *L)
{
    reg_funcionario reg_funci;
    TipoApontador p;
    int resp;
    TipoApontador aux;
    do
    {
        do
        {
            tela();
            tela_cadastro();
            gotoxy(25, 6);
            printf("CADASTRAR FINAL");
            gotoxy(31, 8);
            printf("                  ");
            gotoxy(31, 8);
            scanf("%d", &reg_funci.codigo);
            aux = pesquisa(L, reg_funci.codigo);
            if (aux != NULL)
            {
                gotoxy(07, 25);
                printf("CODIGO JA CADASTRADO");
                getch();
            }
        } while (aux != NULL);
        gotoxy(31, 10);
        fflush(stdin);
        fgets(reg_funci.nome, 50, stdin);
        gotoxy(31, 12);
        fflush(stdin);
        fgets(reg_funci.endereco, 50, stdin);
        gotoxy(31, 14);
        fflush(stdin);
        fgets(reg_funci.cargo, 50, stdin);
        gotoxy(31, 16);
        fflush(stdin);
        fgets(reg_funci.dt_admissao, 11, stdin);
        gotoxy(31, 18);
        fflush(stdin);
        fgets(reg_funci.telefone, 15, stdin);
        gotoxy(31, 20);
        scanf("%f", &reg_funci.salario);

        gotoxy(7, 25);
        printf("DESEJA SALVAR AS INFORMACOES ? [1-SIM / 2-NAO] : ");
        scanf("%d", &resp);

        if (resp == 1)
        {
            p = (TipoApontador)malloc(sizeof(TipoItem));
            p->conteudo = reg_funci;
            p->proximo = NULL;
            if (L->primeiro == NULL)
            {
                L->primeiro = p;
                L->ultimo = p;
            }
            else
            {
                L->ultimo->proximo = p;
                L->ultimo = p;
            }
            gotoxy(7, 25);
            printf("                                                         ");
            gotoxy(30, 23);
            printf("CADASTRO SALVO");
            gotoxy(7, 25);
            printf("CADASTRAR NOVO FUNCIONARIO ? [1-SIM / 2-NAO] : ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}

// Função Cdastrar no inicio da lista
void cadastro_inicio(TipoLista *L)
{
    reg_funcionario reg_funci;
    TipoApontador p;
    int resp;
    TipoApontador aux;
    do
    {
        do
        {
            tela();
            tela_cadastro();
            gotoxy(35, 6);
            printf("CADASTRAR INICIO");
            gotoxy(31, 8);
            printf("                  ");
            gotoxy(31, 8);
            scanf("%d", &reg_funci.codigo);
            aux = pesquisa(L, reg_funci.codigo);
            if (aux != NULL)
            {
                gotoxy(07, 25);
                printf("CODIGO JA CADASTRADO");
                getch();
            }
        } while (aux != NULL);
        gotoxy(31, 10);
        fflush(stdin);
        fgets(reg_funci.nome, 50, stdin);
        gotoxy(31, 12);
        fflush(stdin);
        fgets(reg_funci.endereco, 50, stdin);
        gotoxy(31, 14);
        fflush(stdin);
        fgets(reg_funci.cargo, 50, stdin);
        gotoxy(31, 16);
        fflush(stdin);
        fgets(reg_funci.dt_admissao, 11, stdin);
        gotoxy(31, 18);
        fflush(stdin);
        fgets(reg_funci.telefone, 15, stdin);
        gotoxy(31, 20);
        scanf("%f", &reg_funci.salario);

        gotoxy(7, 25);
        printf("DESEJA SALVAR AS INFORMACOES ? [1-SIM / 2-NAO] : ");
        scanf("%d", &resp);

        if (resp == 1)
        {
            p = (TipoApontador)malloc(sizeof(TipoItem));
            p->conteudo = reg_funci;
            p->proximo = NULL;
            if (L->primeiro == NULL)
            {
                L->primeiro = p;
                L->ultimo = p;
            }
            else
            {
                p->proximo = L->primeiro;
                L->primeiro = p;
                if (L->ultimo = NULL)
                {
                    L->ultimo = L->primeiro;
                }
            }
            gotoxy(7, 25);
            printf("                                                         ");
            gotoxy(30, 23);
            printf("CADASTRO SALVO");
            gotoxy(7, 25);
            printf("CADASTRAR NOVO FUNCIONARIO ? [1-SIM / 2-NAO] : ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}

// Função Cadastrar em uma posição X
void cadastro_posicao(TipoLista *L)
{
    reg_funcionario reg_funci;
    TipoApontador p;
    TipoApontador q;
    TipoApontador r;
    int cntg;
    int posi;
    int resp;
    TipoApontador aux;
    do
    {
        do
        {
            tela();
            tela_cadastro();
            gotoxy(25, 6);
            printf("CADASTRAR POSICAO");
            gotoxy(31, 8);
            printf("                  ");
            gotoxy(31, 8);
            scanf("%d", &reg_funci.codigo);
            aux = pesquisa(L, reg_funci.codigo);
            if (aux != NULL)
            {
                gotoxy(07, 25);
                printf("CODIGO JA CADASTRADO");
                getch();
            }
        } while (aux != NULL);
        gotoxy(31, 10);
        fflush(stdin);
        fgets(reg_funci.nome, 50, stdin);
        gotoxy(31, 12);
        fflush(stdin);
        fgets(reg_funci.endereco, 50, stdin);
        gotoxy(31, 14);
        fflush(stdin);
        fgets(reg_funci.cargo, 50, stdin);
        gotoxy(31, 16);
        fflush(stdin);
        fgets(reg_funci.dt_admissao, 11, stdin);
        gotoxy(31, 18);
        fflush(stdin);
        fgets(reg_funci.telefone, 15, stdin);
        gotoxy(31, 20);
        scanf("%f", &reg_funci.salario);
        do
        {
            cntg = contagem(L);
            gotoxy(7, 25);
            printf("                       ");
            gotoxy(7, 25);
            printf("DIGITE A POSICAO : ");
            scanf("%d", &posi);
            if (posi < 1 || posi > cntg)
            {
                gotoxy(7, 25);
                printf("POSICAO INVALIDA ");
                getch();
            }

        } while (posi < 1 || posi > cntg + 1);

        gotoxy(7, 25);
        printf("DESEJA SALVAR AS INFORMACOES ? [1-SIM / 2-NAO] : ");
        scanf("%d", &resp);

        if (resp == 1)
        {

            if (L->primeiro == NULL)
            {
                p = (TipoApontador)malloc(sizeof(TipoItem));
                p->conteudo = reg_funci;
                p->proximo = NULL;
                L->primeiro = p;
                L->ultimo = p;
            }
            else if (posi == 1)
            {
                r = (TipoApontador)malloc(sizeof(TipoItem));
                r->conteudo = reg_funci;
                r->proximo = L->primeiro;
                L->primeiro = r;
            }
            else
            {
                r = (TipoApontador)malloc(sizeof(TipoItem));
                r->conteudo = reg_funci;
                if (posi == cntg + 1)
                {
                    L->ultimo->proximo = r;
                    r->proximo = NULL;
                    L->ultimo = r;
                }
                else
                {
                    q = L->primeiro;
                    for (int x = 1; x < posi - 1; x++)
                    {
                        q = q->proximo;
                    }
                    r->proximo = q->proximo;
                    q->proximo = r;
                }
            }
            gotoxy(7, 25);
            printf("                                                         ");
            gotoxy(30, 23);
            printf("CADASTRO SALVO");
            gotoxy(7, 25);
            printf("CADASTRAR NOVO FUNCIONARIO ? [1-SIM / 2-NAO] : ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}

// Função Deletar no inicio da Lista
void exclusao_inicio(TipoLista *L)
{
    TipoApontador t;
    int opc;
    t = L->primeiro;
    do
    {
        if (L->primeiro == NULL) 
        {
            gotoxy(7,25);
            printf("LISTA VAZIA, NADA A EXCLUIR.");
            getch();
            return;
        }
        tela();
        gotoxy(35, 6);
        printf("EXCLUSAO PRIMEIRO CADASTRO");
        gotoxy(15, 8);
        printf("CODIGO........: %d", t->conteudo.codigo);
        gotoxy(15, 10);
        printf("NOME..........: %s", t->conteudo.nome);
        gotoxy(15, 12);
        printf("ENDERECO......: %s", t->conteudo.endereco);
        gotoxy(15, 14);
        printf("CARGO.........: %s", t->conteudo.cargo);
        gotoxy(15, 16);
        printf("DATA_ADMISSAO.: %s", t->conteudo.dt_admissao);
        gotoxy(15, 18);
        printf("TELEFONE......: %s", t->conteudo.telefone);
        gotoxy(15, 20);
        printf("SALARIO.......: %.2f", t->conteudo.salario);

        gotoxy(51, 25);
        printf("         ");
        gotoxy(7, 25);
        printf("CONFIRMAR EXCLUSAO?: [1-SIM / 2-NAO]: ");
        scanf(" %d", &opc);

        if (opc == 1)
        {
            if (L->primeiro->proximo == NULL)
            {
                free(L->primeiro);
                L->primeiro = NULL;
                L->ultimo = NULL;
            }
            else
            {
                t = L->primeiro;
                L->primeiro = t->proximo;
                free(t);
            }
        }
        gotoxy(7, 25);
        printf("                                                         ");
        gotoxy(30, 23);
        printf("CADASTRO EXCLUIDO");
        getch();
        gotoxy(7, 25);
        printf("EXCLUIR PROXIMO CADASTRO? [1-SIM / 2-NAO]: ");
        scanf(" %d", &opc);
        if (opc == 1)
        {
            t = t->proximo;
        }

    } while (opc == 1);
}

// Função Deletar no Final da Lista
void exclusao_final(TipoLista *L)
{
    TipoApontador t;
    TipoApontador r;
    TipoApontador s;
    int opc;
    do
    {
        if (L->primeiro == NULL) 
        {
            gotoxy(7,25);
            printf("LISTA VAZIA, NADA A EXCLUIR.");
            getch();
            return;
        }
        r = L->primeiro;
        t = r->proximo;
        while (t->proximo != NULL)
        {
            r = t;
            t = t->proximo;
        }
        tela();
        gotoxy(35, 6);
        printf("EXCLUSAO ULTIMO CADASTRO");
        gotoxy(15, 8);
        printf("CODIGO........: %d", t->conteudo.codigo);
        gotoxy(15, 10);
        printf("NOME..........: %s", t->conteudo.nome);
        gotoxy(15, 12);
        printf("ENDERECO......: %s", t->conteudo.endereco);
        gotoxy(15, 14);
        printf("CARGO.........: %s", t->conteudo.cargo);
        gotoxy(15, 16);
        printf("DATA_ADMISSAO.: %s", t->conteudo.dt_admissao);
        gotoxy(15, 18);
        printf("TELEFONE......: %s", t->conteudo.telefone);
        gotoxy(15, 20);
        printf("SALARIO.......: %.2f", t->conteudo.salario);

        gotoxy(51, 25);
        printf("         ");
        gotoxy(7, 25);
        printf("CONFIRMAR EXCLUSAO?: [1-SIM / 2-NAO]: ");
        scanf(" %d", &opc);

        if (opc == 1)
        {
            if (L->primeiro->proximo == NULL)
            {
                s = L->primeiro; 
                free(s);
                L->primeiro = NULL;
                L->ultimo = NULL;
            }
            else
            {
                r->proximo = NULL;
                L->ultimo = r;
                free(t);
            }
        }
        gotoxy(7, 25);
        printf("                                                         ");
        gotoxy(30, 23);
        printf("CADASTRO EXCLUIDO");
        getch();
        return;
    } while (opc == 1);
}

//Função Excluir em uma posição X
void excluir_posicao(TipoLista*L)
{
    TipoApontador t;
    TipoApontador r;
    int opc;
    int cntg;
    int posi;
    int cont = 1;
    cntg = contagem(L);
    do
    {
        if (L->primeiro == NULL) 
        {
            gotoxy(7,25);
            printf("LISTA VAZIA, NADA A EXCLUIR.");
            getch();
            return;
        }
        do
        {
            gotoxy(7, 25);
            printf("                       ");
            gotoxy(7, 25);
            printf("DIGITE A POSICAO : ");
            scanf("%d", &posi);
            if (posi < 1 || posi > cntg)
            {
                gotoxy(7, 25);
                printf("                         ");
                gotoxy(7, 25);
                printf("POSICAO INVALIDA ");
                getch();
            }

        } while (posi < 1 || posi > cntg);
        if (posi == 1)
        {
            t = L->primeiro;
            L->primeiro = t->proximo;
            if (L->primeiro == NULL)
            {
                L->ultimo = NULL;
            }
            tela();
            gotoxy(35, 6);
            printf("EXCLUSAO CADASTRO NA PRIMEIRA POSICAO");
            gotoxy(15, 8);
            printf("CODIGO........: %d", t->conteudo.codigo);
            gotoxy(15, 10);
            printf("NOME..........: %s", t->conteudo.nome);
            gotoxy(15, 12);
            printf("ENDERECO......: %s", t->conteudo.endereco);
            gotoxy(15, 14);
            printf("CARGO.........: %s", t->conteudo.cargo);
            gotoxy(15, 16);
            printf("DATA_ADMISSAO.: %s", t->conteudo.dt_admissao);
            gotoxy(15, 18);
            printf("TELEFONE......: %s", t->conteudo.telefone);
            gotoxy(15, 20);
            printf("SALARIO.......: %.2f", t->conteudo.salario);

            gotoxy(7, 25);
            printf("CONFIRMAR EXCLUSAO? [1-SIM / 2-NAO]: ");
            scanf("%d", &opc);

            if (opc == 1)
            {
                free(t);
            }
            gotoxy(7, 25);
            printf("                                                         ");
            gotoxy(30, 23);
            printf("CADASTRO EXCLUIDO");
            getch();
            return;
        }
        cont = 1;
        r = L->primeiro;
        t = r->proximo;

        while (cont < posi - 1)
        {
            r = r->proximo;
            t = t->proximo;
            cont++;
        }

        tela();
        gotoxy(35, 6);
        printf("EXCLUSAO CADASTRO NA POSICAO %d", posi);
        gotoxy(15, 8);
        printf("CODIGO........: %d", t->conteudo.codigo);
        gotoxy(15, 10);
        printf("NOME..........: %s", t->conteudo.nome);
        gotoxy(15, 12);
        printf("ENDERECO......: %s", t->conteudo.endereco);
        gotoxy(15, 14);
        printf("CARGO.........: %s", t->conteudo.cargo);
        gotoxy(15, 16);
        printf("DATA_ADMISSAO.: %s", t->conteudo.dt_admissao);
        gotoxy(15, 18);
        printf("TELEFONE......: %s", t->conteudo.telefone);
        gotoxy(15, 20);
        printf("SALARIO.......: %.2f", t->conteudo.salario);

        gotoxy(7, 25);
        printf("CONFIRMAR EXCLUSAO? [1-SIM / 2-NAO]: ");
        scanf("%d", &opc);

        if (opc == 1)
        {
            if (t == L->ultimo)
            {
                L->ultimo = r;
            }
            r->proximo = t->proximo;
            free(t); 
        }
        gotoxy(7, 25);
        printf("                                                         ");
        gotoxy(30, 23);
        printf("CADASTRO EXCLUIDO");
        getch();
        return;
    } while (opc == 1);
}

// Função consultar
void consultar(TipoLista *L)
{
    TipoApontador p;
    int opcao;

    gotoxy(30, 6);
    printf("CONSULTAR");
    if (L->primeiro == NULL)
    {
        tela();
        gotoxy(30, 12);
        printf("LISTA VAZIA");
        gotoxy(7, 25);
        printf("PRESSIONE ENTER PARA CONTINUAR");
        getch();
    }
    else
    {
        p = L->primeiro;
        tela();
        do
        {
            gotoxy(15, 8);
            printf("CODIGO........: %d", p->conteudo.codigo);
            gotoxy(15, 10);
            printf("NOME..........: %s", p->conteudo.nome);
            gotoxy(15, 12);
            printf("ENDERECO......: %s", p->conteudo.endereco);
            gotoxy(15, 14);
            printf("CARGO.........: %s", p->conteudo.cargo);
            gotoxy(15, 16);
            printf("DATA_ADMISSAO.: %s", p->conteudo.dt_admissao);
            gotoxy(15, 18);
            printf("TELEFONE......: %s", p->conteudo.telefone);
            gotoxy(15, 20);
            printf("SALARIO.......: %.2f", p->conteudo.salario);

            gotoxy(51, 25);
            printf("         ");
            gotoxy(7, 25);
            printf("MOSTRAR PROXIMO CADASTRO ? [1-SIM / 2-NAO]: ");
            scanf(" %d", &opcao);

            if (opcao == 1)
            {
                p = p->proximo;
            }
            if (p == NULL)
            {
                tela();
                gotoxy(26, 12);
                printf("FIM DA LISTA DE CADASTROS");
                gotoxy(7, 25);
                printf("PRESSIONE ENTER PARA CONTINUAR");
                getch();
            }
        } while (opcao == 1 && p != NULL);
    }
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
        gotoxy(7, 25);
        printf("DIGITE SUA OPCAO : ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastro_fim(&L);
            break;
        case 2:
            cadastro_inicio(&L);
            break;
        case 3:
            cadastro_posicao(&L);
            break;
        case 4:
            exclusao_inicio(&L);
            break;
        case 5:
            exclusao_final(&L);
            break;
        case 6:
            excluir_posicao(&L);
            break;
        case 8:
            consultar(&L);
            break;
        }
    } while (opc != 9);

    return 0;
}