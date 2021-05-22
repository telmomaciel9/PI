#include <stdio.h>

typedef struct nodo
{
    int valor;
    struct nodo *esq, *dir;
} * ABin;
ABin newABin(int r, ABin e, ABin d)
{
    ABin a = malloc(sizeof(struct nodo));
    if (a != NULL)
    {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

int altura(ABin a)
{
    int altEsq = 0, altDir = 0;
    if (a == NULL)
        return 0;

    altEsq = altura(a->esq);
    altDir = altura(a->dir);

    return 1 + (altEsq > altDir ? altEsq : altDir);
}

int nFolhas(ABin a)
{
    if (a == NULL)
        return 0;
    if (a->esq == NULL && a->dir == NULL)
        return 1;
    return nFolhas(a->esq) + nFolhas(a->dir);
}

ABin maisEsquerda(ABin a)
{
    if (a == NULL || a->esq == NULL)
        return a;
    return maisEsquerda(a->esq);
}

void imprimeNivel(ABin a, int l)
{
    if (a != NULL)
    {
        if (l == 0)
            printf("%d ", a->valor);
        else
        {
            imprimeNivel(a->esq, l - 1);
            imprimeNivel(a->dir, l - 1);
        }
    }
}

int procuraE(ABin a, int x)
{
    int r = 0;
    if (a != NULL)
    {
        if (x == a->valor)
            r = 1;
        else
        {
            r = procuraE(a->esq, x) || procuraE(a->dir, x);
        }
    }
    return r;
}

struct nodo *procura(ABin a, int x)
{
    if (a != NULL)
    {
        if (a->valor == x)
            return a;
        return (x > a->valor) ? procura(a->dir, x) : procura(a->esq, x);
    }
    return NULL;
}

int nivel(ABin a, int x)
{
    return auxNivel(a, x, 0);
}

int auxNivel(ABin a, int x, int n)
{
    if (a == NULL)
        return (-1);
    if (a->valor == x)
        return n;

    return (x > a->valor) ? auxNivel(a->dir, x, n + 1) : auxNivel(a->esq, x, n + 1);
}

void imprimeAte(ABin a, int x)
{
    if (a != NULL)
    {
        imprimeAte(a->esq, x);
        if (a->valor < x)
        {
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}
