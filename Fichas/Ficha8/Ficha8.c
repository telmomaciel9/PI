#include <stdio.h>

typedef struct slist
{
    int valor;
    struct slist *prox;
} * LInt;
LInt newLInt(int x, LInt xs)
{
    LInt r = malloc(sizeof(struct slist));
    if (r != NULL)
    {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct
{
    LInt inicio, fim;
} Queue;

void initStack(Stack *s)
{
    *s = NULL;
}
int SisEmpty(Stack s)
{
    return s == NULL;
}
int push(Stack *s, int x)
{
    int r = 0;
    Stack nova = (Stack)malloc(sizeof(struct slist));
    if (nova != NULL)
    {
        nova->valor = x;
        nova->prox = *s;
        *s = nova;
    }
    else
        r = 1;
    return r;
}
int pop(Stack *s, int *x)
{
    int r = 0;
    Stack aux;
    if (SisEmpty(*s) == 0)
    {
        *x = (*s)->valor;
        aux = *s;
        *s = (*s)->prox;
        free(aux);
    }
    else
        r = 1;
    return r;
}

int top(Stack s, int *x)
{
    int r = 0;
    if (SisEmpty(s) == 0)
    {
        *x = (s)->valor;
    }
    else
        r = 1;

    return r;
}

//incompleta