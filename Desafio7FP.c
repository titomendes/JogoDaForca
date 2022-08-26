#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int pos;
char *palavra();
char *dica();

int main(){
palavra();
dica();
}
char *palavra(){
    char *palavras[]={"gato","rato","televisao","cadeira","bola"};
    char word[10];
    time_t t;
    srand((unsigned)time(&t));
    pos=rand()%5;
    printf("%d",strlen(palavras[pos]));
    strcpy(word,palavras[pos]);
    printf("%s",palavras[pos]);
    printf("%s",word);
    return;
}

char *dica(){
    char *dicas[]={"cao","gato","canal","sentado","chuta"};
    printf("%s",dicas[pos]);
}
