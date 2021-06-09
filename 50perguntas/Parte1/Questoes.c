#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>

#define MAXLINE 1024

char buffer[MAXLINE];

// 1 - Maior da sequência

void one()
{
    int largest = INT_MIN;
    puts("Maior de uma sequência\nInsere uma lista de números (um por linha) terminada em 0:");
    while (1)
    {
        int num;
        assert(scanf("%d", &num) == 1);
        if (num == 0)
            break;
        if (num > largest)
            largest = num;
    }
    printf("Maior: %d\n", largest);
}

// 2 - Média da sequência

void two()
{
    double soma = 0;
    int n = 0;
    while (1)
    {
        int num;
        assert(scanf("%d", &num) == 1);
        if (num == 0)
            break;
        soma += num;
        n++;
    }
    double media = soma / n;
    printf("Média: %.5f\n", media);
}

// 3 - Segundo maior da sequência

void three()
{
    int biggest = INT_MIN, second_biggest = INT_MIN, num;
    while (1)
    {
        assert(scanf("%d", &num) == 1);
        if (num == 0)
            break;
        if (num > biggest)
        {
            second_biggest = biggest;
            biggest = num;
        }
        else if (num > second_biggest)
            second_biggest = num;
    }
    printf("Segundo maior número: %d\n", second_biggest);
}

// 4 - Nº de bits iguais a 1 na representação binária de n

int bitsUm(unsigned int n)
{
    int r = 0;
    while (n)
    {
        r += (n % 2);
        n >>= 1; // Shifts the bits in `n` one bit to the right, i.e., n = n / 2
    }
    return r;
}

// 5

int trailingZ(unsigned int n)
{
    if (n % 2)
        return 0;
    else
        return 1 + trailingZ(n >> 1);
}

// 6

int qDig(unsigned int n)
{
    if (n / 10 < 1)
        return 1;
    else
        return 1 + qDig(n / 10);
}

// 7

char *mystrcat(char s1[], char s2[])
{
    char *cat = s1;
    while (*s1)
        s1++;
    while ((*s1 = *s2))
    {
        s1++;
        s2++;
    }
    *s1 = '\0';
    return cat;
}

char *mystrcat2(char s1[], char s2[])
{
    int i = 0, j;
    for (; s1[i] != '\0'; i++)
        ;
    for (j = 0; s2[j] != '\0'; j++)
    {
        s1[i] = s2[j];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

// 8

char *mystrcpy(char *dest, char source[])
{
    char *result = dest;
    while ((*dest = *source))
    {
        source++;
        dest++;
    }
    return result;
}

char *mystrcpy2(char s1[], const char s2[])
{
    int i;
    for (i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}

// 9

int mystrcmp(char s1[], char s2[])
{
    while (*s1 == *s2 && *s1)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// 10

char *mystrstr(char haystack[], char needle[])
{
    int isContained = 1;
    char *ans = haystack;
    char *needleStart = needle;
    while (*needle && *haystack)
    {
        if (*haystack != *needle)
        {
            isContained = 0;
            needle = needleStart;
        }
        if (*haystack == *needle)
        {
            if (!isContained)
            {
                isContained = 1;
                ans = haystack;
            }
            needle++;
        }
        haystack++;
    }
    if (isContained && !(*needle))
        return ans;
    else
        return NULL;
}

char *mystrstr2(char s1[], char s2[])
{
    int i, j = 0, inicio = 0;
    if (s1[0] == s2[j] && j == 0)
    {
        inicio = i;
        j++;
    }
    else if (s1[i] == s2[j])
        j++;
    else
        j = 0;
    if (s2[j] == '\0')
        return s1 + inicio;
    return NULL;
}

// 11

void mystrrev(char s[])
{
    int len;
    for (len = 0; s[len]; len++)
        ;
    char rev[len];
    for (int i = 0; i < len; i++)
        rev[i] = s[len - i - 1];
    for (int i = 0; i < len; i++)
        s[i] = rev[i];
}

void mystrrev2(char s[])
{
    int i = 0, j = 0;
    for (; s[1] != '\0'; j++)
        ;
    char aux[i];
    i = 0;
    j--;
    for (; j >= 0; j--)
    {
        s[i] = aux[j];
        i++;
    }
}

// 12

void tail(char *s)
{
    for (; *s; s++)
        *s = *(s + 1);
}

void strnoV(char s[])
{
    while (*s)
    {
        if (*s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U' || *s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
            tail(s);
        else
            s++;
    }
}

void strnoV2(char t[])
{
    int i = 0, j;
    for (; t[i] != '\0'; i++)
    {
        if (t[i] == 'a' || t[i] == 'A' || t[i] == 'e' || t[i] == 'E' || t[i] == 'i' || t[i] == 'I' || t[i] == 'o' || t[i] == 'O' || t[i] == 'u' || t[i] == 'U')
        {
            j = i;
            for (; t[j] != '\0'; j++)
                t[j] = t[j + 1];
            i--;
        }
    }
}
// 13

void truncW(char t[], int n)
{
    int wordLen = 0;
    while (*t)
    {
        if (*t == ' ' || *t == '\n' || *t == '\t')
        {
            t++;
            wordLen = 0;
        }
        else
        {
            if (wordLen++ >= n)
                tail(t);
            else
                t++;
        }
    }
}

void truncW2(char t[], int n)
{
    int i = 0, h = n, j, contador = 0, b = 0;
    for (; t[i] != '\0'; i++)
    {
        if (h == 0)
        {
            contador = 0;
            j = i;
            for (; t[j] != '\0' && t[j] != ' '; j++)
            {
                contador++;
                b = j;
            }
            j = i;
            for (; t[j + contador] != '\0'; j++)
            {
                t[j] = '\0';
                h = n;
            }
            if (t[i] != ' ' && h != 0)
                h--;
            else
                h = n;
        }
    }
}

// 14

int freqC(char ch, char s[])
{
    int freq = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ch)
            freq++;
    }
    return freq;
}

char charMaisFreq(char s[])
{
    char maisFreq = 0;
    int freqMax = 0, freq;
    for (int i = 0; s[i]; i++)
    {
        if ((freq = freqC(s[i], s)) > freqMax)
        {
            freqMax = freq;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

int conta_caracter(char bruh[], int i)
{
    int j, contador = 0;
    for (j = i; bruh[j] != '\0'; j++)
    {
        if (bruh[j] == bruh[i])
            contador++;
    }
    return contador;
}

char charMaisfreq2(char s[])
{
    int i, j = conta_caracter(s, 0);
    char c = s[0];
    for (i = 0; s[i] != '\0'; i++)
    {
        if (conta_caracter(s, i))
        {
            j = conta_caracter(s, i);
            c = s[i];
        }
    }
    return c;
}

// 15

int iguaisConsecutivos(char s[])
{
    int consec = 1, max = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == s[i + 1])
            consec++;
        else
        {
            if (consec > max)
                max = consec;
            consec = 1;
        }
    }
    return max;
}

int iguaisConsecutivos2(char s[])
{
    int contador = 0, resultado = 0, i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == s[i + 1])
            contador++;
        else if (contador + 1 > resultado)
        {
            contador++;
            resultado = contador;
            contador = 0;
        }
        else
            contador = 0;
        i++;
    }
    return resultado;
}

// 16

int not_in_prev(char str[], int k, int n)
{
    int ans = 1;
    for (int i = k; i < n; i++)
    {
        if (str[i] == str[n])
        {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[])
{
    int ans = 0;
    for (size_t i = 0; s[i]; i++)
    {
        int consec = 0;
        for (size_t j = i; s[j]; j++)
        {
            if (not_in_prev(s, i, j))
                consec++;
            else
                break;
        }
        if (consec > ans)
            ans = consec;
    }
    return ans;
}

// 17

int maiorPrefixo(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++)
        ;
    return i;
}

int maiorPrefixo2(char s1[], char s2[])
{
    int r = 0, i = 0;
    while (s1[i] == s2[i])
    {
        r++;
        i++;
    }
    return r;
}

// 18

int maiorSufixo(char s1[], char s2[])
{
    int i, j, ans = -1;
    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        ;
    while (s1[i--] == s2[j--])
        ans++;
    return ans;
}

int maiorSufixo2(char s1[], char s2[])
{
    int i = 0, j = 0, r = 0;
    for (; s1[1] != '\0'; i++)
        ;
    for (; s2[j] != '\0'; j++)
        ;
    j--;
    i--;
    while (s1[i] == s2[j])
    {
        r++;
        i--;
        j--;
    }
    return r;
}

// 19

int sufPref(char s1[], char s2[])
{
    int ans = 0, i, j = 0;
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] == s2[j++])
            ans++;
        else
            ans = j = 0;
    }
    return ans;
}

// 20

int contaPal(char s[])
{
    int inWord = 0, total = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ' ' || s[i] == '\n')
        {
            if (inWord)
                total++;
            inWord = 0;
        }
        else
            inWord = 1;
    }
    if (inWord)
        total++;
    return total;
}

// 21

int contaVogais(char s[])
{
    int total = 0;
    for (int i = 0; s[i]; i++)
    {
        switch (s[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            total++;
        }
    }
    return total;
}

int contaVogais2(char t[])
{
    int i = 0, contador = 0;
    while (t[i] != '\0')
    {
        if (t[i] == 'a' || t[i] == 'A' || t[i] == 'e' || t[i] == 'E' || t[i] == 'i' || t[i] == 'I' || t[i] == 'o' || t[i] == 'O' || t[i] == 'u' || t[i] == 'U')
            contador++;
        i++;
    }
    return contador;
}

// 22

int contida(char a[], char b[])
{
    int cont = 1;
    for (int i = 0; a[i]; i++)
    {
        int pertence = 0;
        for (int j = 0; b[j]; j++)
        {
            if (a[i] == b[j])
                pertence = 1;
        }
        if (!pertence)
        {
            cont = 0;
            break;
        }
    }
    return cont;
}

int compara(char a, char b[])
{
    int i;
    for (i = 0; b[i] != '\0'; i++)
    {
        if (b[i] == a)
            return 1;
    }
    return 0;
}

int contida2(char a[], char b[])
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (compara(a[i], b) == 0)
            return 0;
    }
    return 1;
}

// 23

int palindrome(char s[])
{
    int len = 0;
    for (int i = 0; s[i]; i++)
        len++;
    for (int i = 0; s[i]; i++)
        if (s[i] != s[len - 1 - i])
            return 0;
    return 1;
}

int palindroma2(char s[])
{
    int contador, i, bruh, r = 1;
    for (contador = 0; s[contador] != '\0'; contador++)
        ;
    contador--;
    bruh = contador;
    for (i = 0; i < contador; i++)
    {
        if (s[i] != s[bruh])
            r = 0;
        bruh--;
    }
    return r;
}

// 24

int remRep(char x[])
{
    if (!(*x))
        return 0;
    int i = 1;
    char prev = x[0];
    while (x[i])
    {
        if (x[i] == prev)
            tail(x + i);
        else
            prev = x[i++];
    }
    return i;
}

int remRep2(char bruh[])
{
    int r = 0, i = 0, j;
    while (bruh[i] != '\0')
    {
        if (bruh[i] == bruh[i + 1])
        {
            for (j = i; bruh[j] != '\0'; j++)
            {
                bruh[j] = bruh[j + 1];
            }
            i--;
        }
        i++;
    }
    return i;
}
// 25

int limpaEspacos(char t[])
{
    int i = 0;
    int prevSpace = 0;
    while (t[i])
    {
        if (t[i] == ' ')
        {
            if (prevSpace)
            {
                tail(t + i);
                continue;
            }
            else
                prevSpace = 1;
        }
        else
            prevSpace = 0;
        i++;
    }
    return i;
}

void elimina(char bruh[], int indice)
{
    int i;
    for (i = indice; bruh[i] != '\0'; i++)
    {
        bruh[i] = bruh[i + 1];
    }
    bruh[i - 1] = '\0';
}

int limpaEspacos2(char texto[])
{
    int r = 0;
    while (texto[r] != '\0')
    {
        if (texto[r] == ' ' && texto[r + 1] == ' ')
        {
            elimina(texto, r);
            r--;
        }
        r++;
    }

    return r;
}

// 26

void insere(int v[], int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (v[i] > x)
        {
            for (int j = N; j > i; j--)
            {
                v[j] = v[j - 1];
            }
            v[i] = x;
            break;
        }
        if (i == N - 1)
        {
            v[N] = x;
        }
    }
}

void insere2(int s[], int N, int x)
{
    int i = 0, aux = 0;
    while (i < N)
    {
        if (x <= s[i])
        {
            aux = s[i];
            s[i] = x;
            x = aux;
        }
        i++;
    }
    s[i] = x;
}

// 27

void merge(int r[], int a[], int b[], int na, int nb)
{
    int i = 0, j = 0, k = 0;
    while (k < na + nb)
    {
        if ((a[i] < b[j] && i < na) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}

void recursive_merge(int r[], int a[], int b[], int na, int nb)
{
    if (na > 0)
    {
        if (nb > 0)
        {
            if (*a > *b)
            {
                *r = *b;
                recursive_merge(r + 1, a, b + 1, na, nb - 1);
            }
            else
            {
                *r = *a;
                recursive_merge(r + 1, a + 1, b, na - 1, nb);
            }
        }
        else
        {
            *r = *a;
            recursive_merge(r + 1, a + 1, b, na - 1, nb);
        }
    }
    else if (nb > 0)
    {
        *r = *b;
        recursive_merge(r + 1, a, b + 1, na, nb - 1);
    }
}

void merge2(int r[], int a[], int b[], int na, int nb)
{
    int i = 0, j = 0, h = 0;
    while (i < na + nb)
    {
        if (a[j] <= b[h])
        {
            r[i] = a[j];
            j++;
        }
        else
        {
            r[i] = b[h];
            h++;
        }
        if (j == na + 1)
        {
            while (i < na + nb)
            {
                r[i] = b[h];
                i++;
                h++;
            }
        }
        if (h == nb + 1)
        {
            while (i < na + nb)
            {
                r[i] = a[j];
                i++;
                j++;
            }
        }
        i++;
    }
}

// 28

int crescente(int a[], int i, int j)
{
    int cresc = 1;
    for (int k = i; k < j; k++)
    {
        if (a[k + 1] < a[k])
            cresc = 0;
    }
    return cresc;
}

// 29

int retiraNeg(int v[], int N)
{
    int i = 0;
    while (i < N)
    {
        if (v[i] < 0)
        {
            for (int j = i; j < N - 1; j++)
                v[j] = v[j + 1];
            N--;
        }
        else
            i++;
    }
    return N;
}

// 30

int menosFreq(int v[], int N)
{
    int freq = 1, minFreq = N, ans = v[0], i;
    for (i = 1; i < N; i++)
    {
        if (v[i] == v[i - 1])
            freq++;
        if (v[i] != v[i - 1])
        {
            if (freq < minFreq)
            {
                minFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if (freq < minFreq)
    {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

int conta_freq(int bruh[], int n, int N)
{
    int i, contador = 0;
    for (i = 0; i < N; i++)
    {
        if (bruh[i] == n)
            contador++;
    }
    return contador;
}

int menosFreq2(int v[], int N)
{
    int r = v[0], i, x = conta_freq(v, v[0], N);
    for (i = 0; i < N; i++)
    {
        if (conta_freq(v, v[i], N) < x)
        {
            x = conta_freq(v, v[i], N);
            r = v[i];
        }
    }
    return r;
}
// 31

int maisFreq(int v[], int N)
{
    int freq = 1, maxFreq = 0, ans = v[0];
    for (int i = 1; i < N; i++)
    {
        if (v[i] == v[i - 1])
            freq++;
        if (v[i] != v[i - 1])
        {
            if (freq > maxFreq)
            {
                maxFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    return ans;
}

int maisFreq2(int v[], int N)
{
    int r = v[0], i, x = conta_freq(v, v[0], N);
    for (i = 0; i < N; i++)
    {
        if (conta_freq(v, v[i], N) > x)
        {
            x = conta_freq(v, v[i], N);
            r = v[i];
        }
    }
    return r;
}
// 32

int maxCresc(int v[], int N)
{
    int ans = 1, currAns = 1;
    for (int i = 1; i < N; i++)
    {
        if (v[i - 1] > v[i])
        {
            ans = currAns > ans ? currAns : ans;
            currAns = 1;
        }
        else
        {
            currAns++;
        }
    }
    ans = currAns > ans ? currAns : ans;
    return ans;
}

int conta_cres(int bruh[], int n, int N)
{
    int i, contador = 1;
    for (i = n; i < N; i++)
    {
        if (bruh[i] > bruh[i + 1])
        {
            return contador;
        }
        else
            contador++;
    }
    return contador;
}

int maxCresc2(int v[], int N)
{
    int r = conta_cres(v, 0, N), i;
    for (i = 0; i < N; i++)
    {
        if (conta_cres(v, i, N) > r)
            r = conta_cres(v, i, N);
    }
    return r;
}

// 33

int elimRep(int v[], int n)
{
    int i = 1;
    while (i < n)
    {
        int belongs = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[i] == v[j])
                belongs = 1;
        }
        if (belongs)
        {
            for (int j = i; j < n; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
        }
        else
            i++;
    }
    return n;
}

void elimina2(int x, int v[], int N)
{
    while (x + 1 < N)
    {
        v[x] = v[x + 1];
        x++;
    }
}

int elimRep2(int v[], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (v[i] == v[j])
            {
                elimina2(j, v, N);
                N--;
                j--;
            }
        }
    }
    return N;
}

// 34

int elimRepOrd(int v[], int n) { return elimRep(v, n); }

int elimina_ord(int bruh[], int n, int N)
{
    int i, j, contador = 0;
    for (i = n + 1; i < N; i++)
    {
        if (bruh[i] > bruh[n])
            return (N - contador);
        if (bruh[n] == bruh[i])
        {
            for (j = n; j < N - 1; j++)
            {
                bruh[j] = bruh[j + 1];
            }
            contador++;
        }
    }
    return (N - contador);
}

int elimRepOrd2(int v[], int N)
{
    int i, j;
    N = elimina_ord(v, 0, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            N = elimina_ord(v, j, N);
        }
    }
    return N;
}

// 35

int comunsOrd(int a[], int na, int b[], int nb)
{
    int i = 0, j = 0, ans = 0;
    while (i < na && j < nb)
    {
        if (a[i++] == b[j++])
        {
            ans++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    return ans;
}

// 36

int comuns(int a[], int na, int b[], int nb)
{
    int ans = 0;
    for (int i = 0; i < na; i++)
    {
        int belongs = 0;
        for (int j = 0; j < nb; j++)
            if (a[i] == b[j])
                belongs = 1;
        if (belongs)
            ans++;
    }
    return ans;
}

int comuns2(int a[], int na, int b[], int nb)
{
    int r, i, contador = 0;
    for (r = 0; r < nb; r++)
    {
        for (i = 0; i < na; i++)
        {
            if (a[r] == b[i])
            {
                contador++;
                i = na;
            }
        }
    }
    return contador;
}

// 37

int minInd(int v[], int n)
{
    int minIndex = 0;
    for (int i = 1; i < n; i++)
        if (v[i] < v[minIndex])
            minIndex = i;
    return minIndex;
}

int minInd2(int v[], int n)
{
    int r = 0, i, menor = v[0];
    for (i = 0; i < n; i++)
    {
        if (v[i] < menor)
        {
            menor = v[i];
            r = i;
        }
    }
    return r;
}

// 38

void somasAc(int v[], int Ac[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Ac[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            Ac[i] += v[j];
        }
    }
}

void somasAc2(int v[], int Ac[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (i == 0)
            Ac[i] = v[i];
        else
            Ac[i] = Ac[i - 1] + v[i];
    }
}

// 39

int triSup(int N, float m[N][N])
{
    int x = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (m[i][j])
                x = 0;
        }
    }
    return x;
}

int triSup2(int N, int m[N][N])
{
    int i, j, c = 1;
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (j < i && m[i][j] != 0)
                c = 0;
        }
    }
    return c;
}

// 40

void transposta(int N, float m[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

void transposta2(int N, float m[N][N])
{
    int i, j;
    float aux[N][N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            aux[i][j] = m[j][i];
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            m[i][j] = aux[i][j];
        }
    }
}

// 41

void addTo(int N, int M, int a[N][M], int b[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(*(a + i) + j) += b[i][j];
        }
    }
}

void addTo2(int N, int M, int a[N][M], int b[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            a[i][j] = a[i][j] + b[i][j];
    }
}

// 42

int unionSet(int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

int unionSet2(int N, int v1[N], int v2[N], int r[N])
{
    int c = 0, i;
    for (i = 0; i < N; i++)
    {
        if (v1[i] != 0 && v2[i] != 0)
            r[i] = v1[i];
        else if (v1[i] != 0 && v2[i] == 0)
            r[i] = v1[i];
        else if (v1[i] == 0 && v2[i] != 0)
            r[i] = v2[i];
        else
            r[i] = 0;
    }
    return c;
}

// 43

int intersectSet(int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}

int intersectSet2(int N, int v1[N], int v2[N], int r[N])
{
    int c = 0, i;
    for (i = 0; i < N; i++)
    {
        if (v1[i] != 0 && v2[i] != 0)
            r[i] = v1[i];
        else
            r[i] = 0;
    }
    return c;
}

// 44

int intersectMSet(int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
        len += r[i];
    }
    return len;
}

int intersectMSet2(int N, int v1[N], int v2[N], int r[N])
{
    int c = 0, i;
    for (i = 0; i < N; i++)
    {
        if (v1[i] == v2[i])
            r[i] = v1[i];
        else if (v1[i] < v2[i])
            r[i] = v1[i];
        else if (v1[i] > v2[i])
            r[i] = v2[i];
        else
            r[i] = 0;
    }
    return c;
}

// 45

int unionMSet(int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        r[i] = v1[i] + v2[i];
        len += r[i];
    }
    return len;
}

int unionMSet2(int N, int v1[N], int v2[N], int r[N])
{
    int c = 0, i;
    for (i = 0; i < N; i++)
    {
        if (v1[i] == v2[i])
            r[i] = v1[i];
        else if (v1[i] < v2[i])
            r[i] = v2[i];
        else if (v1[i] > v2[i])
            r[i] = v1[i];
        else
            r[i] = 0;
    }
    return c;
}

// 46

int cardinalMSet(int N, int v[N])
{
    int len = 0;
    for (int i = 0; i < N; i++)
        len += v[i];
    return len;
}

// 47

typedef enum movimento
{
    Norte,
    Oeste,
    Sul,
    Este
} Movimento;
typedef struct posicao
{
    int x, y;
} Posicao;

Posicao posFinal(Posicao inicial, Movimento mov[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Movimento x = mov[i];
        if (x == Norte)
            inicial.y++;
        if (x == Este)
            inicial.x++;
        if (x == Sul)
            inicial.y--;
        if (x == Oeste)
            inicial.x--;
    }
    return inicial;
}

Posicao posFinal2(Posicao inicial, Movimento mov[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (mov[i] == Norte)
            inicial.y++;
        else if (mov[i] == Sul)
            inicial.y--;
        else if (mov[i] == Oeste)
            inicial.x--;
        else
            inicial.x++;
    }
    return inicial;
}

// 48

int caminho(Posicao inicial, Posicao final, Movimento mov[], int N)
{
    int *xi = &inicial.x;
    int *yi = &inicial.y;
    int xf = final.x, yf = final.y, i;
    for (i = 0; i < N; i++)
    {
        if ((*xi) < xf)
        {
            (*xi)++;
            mov[i] = Este;
        }
        else if ((*xi) > xf)
        {
            (*xi)--;
            mov[i] = Oeste;
        }
        else if ((*yi) < yf)
        {
            (*yi)++;
            mov[i] = Norte;
        }
        else if ((*yi) > yf)
        {
            (*yi)--;
            mov[i] = Sul;
        }
        else
            break;
    }
    if (inicial.x != final.x || inicial.y != final.y)
        return -1;
    else
        return i;
}

int caminho2(Posicao inicial, Posicao final, Movimento mov[], int N)
{
    int i, contador = 0;
    for (i = 0; i < N; i++)
    {
        if (inicial.y < final.y)
        {
            inicial.y++;
            mov[i] = Norte;
            contador++;
        }
        else if (inicial.y > final.y)
        {
            inicial.y--;
            mov[i] = Sul;
            contador++;
        }
        else if (inicial.x < final.x)
        {
            inicial.x++;
            mov[i] = Este;
            contador++;
        }
        else if (inicial.x > final.x)
        {
            inicial.x--;
            mov[i] = Oeste;
            contador++;
        }
    }
    if (inicial.y != final.y || inicial.x != final.x)
        contador = -1;
    return contador;
}

// 49

int manDist(int x, int y, int x0, int y0) { return abs(x - x0) + abs(y - y0); }

int maisCentral(Posicao pos[], int N)
{
    int minDist = manDist(pos[0].x, pos[0].y, 0, 0);
    int ans = 0, i;
    for (i = 1; i < N; i++)
    {
        if (manDist(pos[i].x, pos[i].y, 0, 0) < minDist)
        {
            ans = i;
            minDist = manDist(pos[i].x, pos[i].y, 0, 0);
        }
    }
    return ans;
}

int maiscentral2(Posicao pos[], int N)
{
    int i, indice = 0;
    double menor = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y);
    for (i = 0; i < N; i++)
    {
        double menorAux = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
        if (menorAux < menor)
        {
            menor = menorAux;
            indice = i;
        }
    }
    return indice;
}

// 50

int vizinhos(Posicao p, Posicao pos[], int N)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (manDist(pos[i].x, pos[i].y, p.x, p.y) == 1)
            ans++;
    }
    return ans;
}

int vizinhos2(Posicao p, Posicao pos[], int N)
{
    int i, contador = 0;
    for (i = 0; i < N; i++)
    {
        if (pos[i].x + 1 == p.x && pos[i].y == p.y)
            contador++;
        else if (pos[i].x - 1 == p.x && pos[i].y == p.y)
            contador++;
        else if (pos[i].x == p.x && pos[i].y + 1 == p.y)
            contador++;
        else if (pos[i].x == p.x && pos[i].y - 1 == p.y)
            contador++;
    }
    return contador;
}

