#include <stdio.h>

typedef struct nodo
{
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// Questão 1
ABin removeMenor(ABin *a)
{
    ABin t = *a, ant, menorDir;
    int aux;
    if ((*a) != NULL)
    {
        if ((*a)->esq == NULL)
        {
            while (t->esq)
            {
                ant = t;
                t = t->esq;
            }

            menorDir = removeMenor(&(t->dir));
            if (menorDir == NULL)
            {
                ant->esq = NULL;
                return t;
            }
            else
            {
                aux = menorDir->valor;
                menorDir->valor = t->valor;
                t->valor = aux;
                return menorDir;
            }
        }
    }
    return NULL;
}

void removeRaiz(ABin *a)
{
    ABin menorDir = removeMenor(&((*a)->dir));
    ABin aux;
    if (menorDir == NULL)
    {
        aux = (*a)->esq;
    }
    else
    {
        menorDir->esq = (*a)->esq;
        menorDir->dir = (*a)->dir;
        aux = menorDir;
    }
    free(*a);
    *a = aux;
}

int removeElem(ABin *a, int x)
{
    if ((*a) != NULL)
    {
        if ((*a)->valor == x)
        {
            removeRaiz(a);
            return 0;
        }
        else if ((*a)->valor < x)
        {
            return removeElem(&((*a)->dir), x);
        }
        else
        {
            return removeElem(&((*a)->esq), x);
        }
    }
    return (-1);
}

// Questão 2
void rodaEsquerda(ABin *a)
{
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita(ABin *a)
{
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

void promoveMenor(ABin *a)
{
    if ((*a) != NULL)
    {
        promoveMenor(&((*a)->esq));
        if ((*a)->esq)
            rodaDireita(a);
    }
}

//incompleta