#include <stdio.h>
#include <stdlib.h>
#include "List.c"
#define tabela 3
#define true 1
#define false 0

//estrutura básica de um no;
typedef struct No
{
    int custo;
    int matriz[tabela][tabela];
    struct No *noEsquerto;
    struct No *noDireito;
    struct No *noDeCima;
    struct No *noDeBaixo;
} No;

int testarObjectivo(No *NoToTest);
int xDo0(No *NoTotest);
int yDo0(No *NoTotest);
int testEsquerda(int y);
int testDireita(int y);
int testCima(int x);
int testBaixo(int x);
void imprimirNo(No *raiz);
No *estadoInicial(int matriz[tabela][tabela]);
No *novoNoEsquerdo(No *raiz, int x, int y);
No *novoNoDireito(No *raiz, int x, int y);
No *novoNoDeCima(No *raiz, int x, int y);
No *novoNoDeBaixo(No *raiz, int x, int y);
No *arvoreDeBusca(No *raiz);
void imprimirNo(No *raiz);

int testarObjectivo(No *NoToTest)
{
    int goal[tabela][tabela] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int i;
    for (i = 0; i < tabela; i++)
    {
        int j;
        for (j = 0; j < tabela; j++)
        {
            if (goal[i][j] != NoToTest->matriz[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int xDo0(No *NoTotest)
{
    int x, y;
    for (x = 0; x < tabela; x++)
    {
        for (y = 0; y < tabela; y++)
        {
            if (NoTotest->matriz[x][y] == 0)
            {
                return x;
            }
        }
    }
    return -1;
}
int yDo0(No *NoTotest)
{
    int x, y;
    for (x = 0; x < tabela; x++)
    {
        for (y = 0; y < tabela; y++)
        {
            if (NoTotest->matriz[x][y] == 0)
            {
                return y;
            }
        }
    }
    return -1;
}

//teste de regra do jo se e' possivel deslocar
// [0] a Esquerda,Direita ou C/B
int testEsquerda(int y)
{
    if ((y - 1) >= 0)
    {
        return true;
    }
    else
        return false;
}
int testDireita(int y)
{
    if ((y + 1) <= 2)
    {
        return true;
    }
    else
        return false;
}
int testCima(int x)
{
    if ((x - 1) >= 0)
    {
        return true;
    }
    else
        return false;
}
int testBaixo(int x)
{
    if ((x + 1) <= 2)
    {
        return true;
    }
    else
        return false;
}

//Criar nos que deslocam ainda nas regras do jogo
No *estadoInicial(int matriz[tabela][tabela])
{
    struct No *temp = (struct No *)malloc(sizeof(struct No));
    temp->custo = 0;
    temp->noEsquerto = temp->noEsquerto = NULL;
    temp->noEsquerto = temp->noDireito = NULL;
    temp->noEsquerto = temp->noDeCima = NULL;
    temp->noEsquerto = temp->noDeBaixo = NULL;
    int i, j;
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            temp->matriz[i][j] = matriz[i][j];
        }
    }

    return temp;
}

No *novoNoEsquerdo(No *raiz, int x, int y)
{
    struct No *temp = (struct No *)malloc(sizeof(struct No));
    temp->custo = raiz->custo + 1;
    temp->noEsquerto = temp->noEsquerto = NULL;
    temp->noEsquerto = temp->noDireito = NULL;
    temp->noEsquerto = temp->noDeCima = NULL;
    temp->noEsquerto = temp->noDeBaixo = NULL;
    int i, j;
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            temp->matriz[i][j] = raiz->matriz[i][j];
        }
    }

    //troca de valores no estado do zo a esquerda da posicao em que se encontra
    int aux = temp->matriz[x][(y - 1)];
    temp->matriz[x][(y - 1)] = temp->matriz[x][(y)];
    temp->matriz[x][(y)] = aux;
    return temp;
}

No *novoNoDireito(No *raiz, int x, int y)
{
    struct No *temp = (struct No *)malloc(sizeof(struct No));
    temp->custo = raiz->custo + 1;
    temp->noEsquerto = temp->noEsquerto = NULL;
    temp->noEsquerto = temp->noDireito = NULL;
    temp->noEsquerto = temp->noDeCima = NULL;
    temp->noEsquerto = temp->noDeBaixo = NULL;
    int i, j;
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            temp->matriz[i][j] = raiz->matriz[i][j];
        }
    }

    //troca de valores no estado do zo a esquerda da posicao em que se encontra
    int aux = temp->matriz[x][(y + 1)];
    temp->matriz[x][(y + 1)] = temp->matriz[x][(y)];
    temp->matriz[x][(y)] = aux;
    return temp;
}

No *novoNoDeCima(No *raiz, int x, int y)
{
    struct No *temp = (struct No *)malloc(sizeof(struct No));
    temp->custo = raiz->custo + 1;
    temp->noEsquerto = temp->noEsquerto = NULL;
    temp->noEsquerto = temp->noDireito = NULL;
    temp->noEsquerto = temp->noDeCima = NULL;
    temp->noEsquerto = temp->noDeBaixo = NULL;
    int i, j;
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            temp->matriz[i][j] = raiz->matriz[i][j];
        }
    }

    //troca de valores no estado do zo a esquerda da posicao em que se encontra
    int aux = temp->matriz[(x - 1)][(y)];
    temp->matriz[(x - 1)][(y)] = temp->matriz[x][(y)];
    temp->matriz[x][(y)] = aux;
    return temp;
}

No *novoNoDeBaixo(No *raiz, int x, int y)
{
    struct No *temp = (struct No *)malloc(sizeof(struct No)); // Allocating memory to the No
    temp->custo = raiz->custo + 1;
    temp->noEsquerto = temp->noEsquerto = NULL;
    temp->noEsquerto = temp->noDireito = NULL;
    temp->noEsquerto = temp->noDeCima = NULL;
    temp->noEsquerto = temp->noDeBaixo = NULL;
    int i, j;
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            temp->matriz[i][j] = raiz->matriz[i][j];
        }
    }

    //troca de valores no estado do zo a esquerda da posicao em que se encontra
    int aux = temp->matriz[(x + 1)][(y)];
    temp->matriz[(x + 1)][(y)] = temp->matriz[x][(y)];
    temp->matriz[x][(y)] = aux;
    return temp;
}

No *arvoreDeBusca(No *raiz)
{

    imprimirNo(raiz);

    if (testarObjectivo(raiz) == false)
    {
        int x = xDo0(raiz);
        int y = xDo0(raiz);
        if (testEsquerda(y) == true)
        {

            if (pesquisarMatriz(novoNoEsquerdo(raiz, x, y)->matriz) == NULL)
            {

                No *auxiliar = novoNoEsquerdo(raiz, x, y);
                raiz->noEsquerto = auxiliar;
                // printf("custo:%i NoEsquerto, (%i,%i) ", raiz->custo, xDo0(auxiliar), yDo0(auxiliar));
                inserirNoInicio(raiz->custo, raiz->matriz);
                arvoreDeBusca(raiz->noEsquerto);
            }
        }
        if (testDireita(y) == true)
        {

            if (pesquisarMatriz(novoNoDireito(raiz, x, y)->matriz) == NULL)
            {
                No *auxiliar = novoNoDireito(raiz, x, y);
                //printf("custo:%i NoDireito, (%i,%i) ", raiz->custo, xDo0(auxiliar), yDo0(auxiliar));
                raiz->noDireito = auxiliar;
                inserirNoInicio(raiz->custo, raiz->matriz);
                arvoreDeBusca(raiz->noDireito);
            }
        }
        if (testCima(x) == true)
        {

            if (pesquisarMatriz(novoNoDeCima(raiz, x, y)->matriz) == NULL)
            {
                No *auxiliar = novoNoDeCima(raiz, x, y);

                // printf("custo:%i NODECIMA, (%i,%i) ", raiz->custo, xDo0(auxiliar), yDo0(auxiliar));
                raiz->noDeCima = auxiliar;
                inserirNoInicio(raiz->custo, raiz->matriz);
                arvoreDeBusca(raiz->noDeCima);
            }
        }
        if (testBaixo(x) == true)
        {

            if (pesquisarMatriz(novoNoDeBaixo(raiz, x, y)->matriz) == NULL)
            {
                No *auxiliar = novoNoDeBaixo(raiz, x, y);
                // printf("custo:%i NoDeBaixo, (%i,%i) ", raiz->custo, xDo0(auxiliar), yDo0(auxiliar));
                raiz->noDeBaixo = auxiliar;
                inserirNoInicio(raiz->custo, raiz->matriz);
                arvoreDeBusca(raiz->noDeBaixo);
            }
        }
    }
    else if (testarObjectivo(raiz) == true)
    {
        printf("Solucao achada!\n");
        system("pause");
    }
    else
    {
        printf("O estado inicial inserido nao pode ser solucionado.!\n");
        printf("Tente colocar um solucionavel!!\n");
        system("pause");
    }
}

int main(int argc, char const *argv[])
{
    int in[tabela][tabela] = {4, 1, 3, 2, 0, 8, 7, 5, 6};
    No *raiz = estadoInicial(in);
    imprimirNo(raiz);
    inserirNoInicio(3, in);
    arvoreDeBusca(raiz);
    return 0;
}

void imprimirNo(No *raiz)
{
    int i, j;
    printf("\n+--------------------------------------------+\n");
    printf("+ 1. Custo: %i \n", raiz->custo);
    for (i = 0; i < tabela; i++)
    {
        for (j = 0; j < tabela; j++)
        {
            printf(" [%i]", raiz->matriz[i][j]);
        }
        printf("\n");
    }
    printf("+--------------------------------------------+\n");
}
