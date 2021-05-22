#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
{
    char *palavra;
    int ocorr;
    struct celula *prox;
} * Palavras;

void libertaLista(Palavras);
int quantasP(Palavras);
void listaPal(Palavras);
char *ultima(Palavras);
Palavras acrescentaInicio(Palavras, char *);
Palavras acrescentaFim(Palavras, char *);
Palavras acrescenta(Palavras, char *);
struct celula *maisFreq(Palavras);

void libertaLista(Palavras l)
{
    if (l != NULL)
    {
        libertaLista(l->prox);
        free(l);
    }
}

int quantasP(Palavras l)
{
    int r = 0;
    while (l != NULL)
    {
        r++;
        l = l->prox;
    }

    return r;
}

void listaPal(Palavras l)
{
    while (l != NULL)
    {
        printf("%s -> %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

char *ultima(Palavras l)
{
    char *r = NULL;
    if (l != NULL)
    {
        while (l->prox != NULL)
        {
            l = l->prox;
        }
        r = l->palavra;
    }
    return r;
    /*
    if (l == NULL)
        return NULL;
    if (l->prox == NULL)
        return l->palavra;
    return ultima(l->prox);
    */
}

Palavras acrescentaInicio(Palavras l, char *p)
{
    Palavras nova = (Palavras)malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

Palavras acrescentaFim(Palavras l, char *p)
{
    Palavras l1 = l;
    if (l1 != NULL)
    {
        while (l1->prox != NULL)
        {
            l1 = l1->prox;
        }
    }
    Palavras nova = (Palavras)malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = NULL;

    if (l1 == NULL)
        l = nova;
    else
        l1->prox = nova;
    return l;
}

Palavras encontra(Palavras l, char *p)
{
    Palavras r = NULL;
    if (l != NULL)
    {
        r = l;
        while (strcmp(r->palavra, p) != 0 && r != NULL)
        {
            r = r->prox;
        }
    }
    return r;
}

Palavras encontraOrdenado(Palavras l, char *p)
{
    Palavras r = NULL;
    if (l != NULL)
    {
        r = l;
        if (strcmp(r->palavra, p) == -1)
        {
            while (r->prox != NULL && strcmp(r->prox->palavra, p) == -1)
            {
                r = r->prox;
            }
        }
    }
    return r;
}

Palavras acrescenta(Palavras l, char *p)
{
    Palavras r = l, l1;
    if (l != NULL)
    {
        l1 = encontraOrdenado(l, p);
        if (l1 == l)
            r = acrescentaInicio(l, p);
        else if (l1->prox != NULL)
        {
            if (strcmp(l1->prox->palavra, p) == 0)
            {
                l1->prox->ocorr++;
            }
            else
            {
                Palavras nova = acrescentaInicio(NULL, p);
                nova->prox = l1->prox;
                l1->prox = nova;
            }
        }
        else
            r = acrescentaFim(l, p);
    }
    else
        r = acrescentaInicio(NULL, p);
    return r;
}

struct celula *maisFreq(Palavras l)
{
    //...
    return NULL;
}

int main()
{
    Palavras dic = NULL;

    char *canto1[44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                        "que", "da", "ocidental", "praia", "lusitana",
                        "por", "mares", "nunca", "de", "antes", "navegados",
                        "passaram", "ainda", "alem", "da", "taprobana",
                        "em", "perigos", "e", "guerras", "esforcados",
                        "mais", "do", "que", "prometia", "a", "forca", "humana",
                        "e", "entre", "gente", "remota", "edificaram",
                        "novo", "reino", "que", "tanto", "sublimaram"};

    printf("\n_____________ Testes _____________\n\n");

    int i;
    struct celula *p;
    for (i = 0; i < 44; i++)
        dic = acrescentaInicio(dic, canto1[i]);

    printf("Foram inseridas %d palavras\n", quantasP(dic));
    printf("palavras existentes:\n");
    listaPal(dic);
    printf("última palavra inserida: %s\n", ultima(dic));

    libertaLista(dic);

    dic = NULL;

    srand(42);

    for (i = 0; i < 1000; i++)
        dic = acrescenta(dic, canto1[rand() % 44]);

    printf("Foram inseridas %d palavras\n", quantasP(dic));
    printf("palavras existentes:\n");
    listaPal(dic);
    printf("última palavra inserida: %s\n", ultima(dic));

    p = maisFreq(dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);

    printf("\n_________ Fim dos testes _________\n\n");

    return 0;
}