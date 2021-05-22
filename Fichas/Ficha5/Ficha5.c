#include <stdio.h>

typedef struct aluno
{
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

void dumpV(int v[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
}
void imprimeAluno(Aluno *a)
{
    int i;
    printf("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for (i = 1; i < 6; i++)
        printf(", %d", a->miniT[i]);
    printf(") %5.2f %d\n", a->teste, nota(*a));
}

float notaMiniTestes(Aluno a)
{
    float r = 0.0;
    int i;
    for (i = 0; i < 6; i++)
    {
        r += a.miniT[i];
    }

    return r * ((float)20 / 12);
}

int nota(Aluno a)
{
    float miniTestes = notaMiniTestes(a);
    float notaTeste = a.teste;
    if (notaTeste >= 8.0 && miniTestes >= 8.0)
    {
        return 0.3 * miniTestes + 0.7 * notaTeste;
    }
    return 0;
}

int procuraNum(int num, Aluno t[], int N)
{
    int i;
    for (i = 0; i < N && t[i].numero <= num; i++)
    {
        if (t[i].numero == num)
            return i;
    }
    return -1;
}

void swap(Aluno v[], int i, int j)
{
    Aluno a = v[i];
    v[i] = v[j];
    v[j] = a;
}

int partition(Aluno v[], int N, int x)
{
    int i = 0, c = 0;

    for (i = 0; i + c < N; i++)
    {
        if (v[i].numero > x)
        {
            swap(v, i, N - 1 - c);
            c++;
            i--;
        }
    }

    return i;
}

void ordenaPorNum(Aluno t[], int N)
{
    if (N <= 1)
        return;
    int i = 0;
    int pivot = t[0].numero;
    int menores = partition(t + 1, N - 1, pivot);

    swap(t, 0, menores);
    ordenaPorNum(t, menores);

    ordenaPorNum(t + menores + 1, N - menores - 1);
}

int indMaiorAluno(Aluno t[], int N, int max)
{
    if (N == 0)
        return -1;

    int maior = 0;
    int i;

    for (i = 0; i < N; i++)
    {
        if (t[i].numero < max)
        {
            maior = i;
            break;
        }
    }

    for (i = 0; i < N; i++)
    {
        if (t[i].numero < max && t[i].numero > t[maior].numero)
            maior = i;
    }

    return maior;
}

int procuraNumInd(int num, int ind[], Aluno t[], int N)
{
    return -1;
}

void criaIndPorNum(Aluno t[], int N, int ind[])
{
    int i, maior, max = 9999999;
    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            maior = indMaiorAluno(t, N, max);
            ind[N - 1 - i] = maior;
            max = t[maior].numero;
        }
    }
}