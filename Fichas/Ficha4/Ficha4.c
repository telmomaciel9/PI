#include <stdio.h>

int isVowel (char c){
    return c== 'a' || c=='e' || c=='i' || c=='o' || c=='u'
            ||  c== 'A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int contaVogais (char *s) {
    int vogais = 0;
    int i;
    for (i=0; s[i]!='\0';i++){
        if(isVowel(s[i])) vogais++;
    }
    return vogais;
}

void copia (char *ori, char *dest){
    int i;
    for (i=0; ori[i]|='\0';i++)
         dest[i]= ori[i];

    dest[i]= '\0';
}


int retiraVogaisRep (char *s){
    char aux[64];
    int i, i2=0, removidas=0;

    for (i=0;s[i]!='\0';i++){
        if (isVowel(s[i]) && s[i-1]== s[i]){
            removidas++;
        } 
        else {
            aux[i2]=s[i];
            i2++;
        }
    }
    aux[i2]= '\0';

    copia (aux,s) ;
    return removidas;
}


int duplicaVogais1 (char *s){
    char aux[100];
    int i, duplicadas=0;
    
    for (i=0; s[i]!='\0';i++){
        if ( isVowel(s[i]) ) {
            aux[i+duplicadas]= s[i];
            duplicadas++;
        }
        aux[i+duplicadas]= s[i];
    }
    aux[i+duplicadas]='\0';
    copia (aux, s);
    return duplicadas;
}

void shiftright (char *s, int N){
    int i, length=0;
    for (; s[length]!='\0'; length++);

    for (i=length; i>=N; i--)
        s[i+1]=s[i];
}


int duplicaVogais (char *s){
    int i, duplicadas=0;
    
    for (i=0; s[i+duplicadas]!='\0';i++){
        if ( isVowel(s[i+duplicadas]) ) {
            shiftright(s,i+duplicadas);
            duplicadas++;
        }

    }
    s[i+duplicadas]='\0';
    return duplicadas;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));

    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes\n");

    return 0;

}

