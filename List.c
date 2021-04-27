#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct noLista
{
    int matriz[3][3];
    int key;
    struct noLista *prox;
};

struct noLista *raizDaLista = NULL;
struct noLista *aux = NULL;

void imprimirLista()
{
    struct noLista *ptr = raizDaLista;

    while (ptr != NULL)
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf(" [%i]", ptr->matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        ptr = ptr->prox;
    }
}

void inserirNoInicio(int key, int matriz[3][3])
{
    struct noLista *link = (struct noLista *)malloc(sizeof(struct noLista));

    link->key = key;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            link->matriz[i][j] = matriz[i][j];
        }
    }

    link->prox = raizDaLista;
    raizDaLista = link;
}

int tamanhoDaLista()
{
    int tamanhoDaLista = 0;
    struct noLista *aux;

    for (aux = raizDaLista; aux != NULL; aux = aux->prox)
    {
        tamanhoDaLista++;
    }

    return tamanhoDaLista;
}

int verificacao(int matrixA[3][3], int matrixB[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrixA[i][j] != matrixB[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

struct noLista *pesquisarMatriz(int matriz[3][3])
{

    struct noLista *aux = raizDaLista;

       if (raizDaLista == NULL)
    {
        return NULL;
    }

    while (verificacao(aux->matriz, matriz) == 0)
    {

        if (aux->prox == NULL)
        {
            return NULL;
        }
        else
        {
            aux = aux->prox;
        }
    }

    return aux;
}

struct noLista *remover(int matriz[3][3])
{

    struct noLista *aux = raizDaLista;
    struct noLista *ant = NULL;

    if (raizDaLista == NULL)
    {
        return NULL;
    }
    while (verificacao(aux->matriz, matriz) == 0)
    {

        if (aux->prox == NULL)
        {
            return NULL;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    if (aux == raizDaLista)
    {
        raizDaLista = raizDaLista->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }

    return aux;
}
