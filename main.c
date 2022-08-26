#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int pos;
char letrasJaUsadas[40];
int contLetrasUsadas=0;
char *devolve();
char *dica();
bool verifica(char letra);

int main(){
    char*palavra=devolve();
    char *pista=dica();
    int tamPista=strlen(pista);
    int tam=strlen(palavra);
    int contVitoria=0;
    int chances=7;
    char aux,letra;
    int i;

    for(i=0;i<tam;i++)
    {
        if(palavra[i]=='\n')
        {
            palavra[i]='\0';
        }
    }

    char palavraAmostrar[tam];
    for(i=0;i<tam;i++){
        palavraAmostrar[i]='-';
    }

    printf("Insira a letra\n");
    while(1)
    {   //pede letra e mete em lower
        printf("%s\n",letrasJaUsadas);
        bool falso=true; //assumo que todas as letras nao sao iguais
        for(i=0;i<tam;i++)
        printf("%c",palavraAmostrar[i]);

        printf("\n");
        scanf("%c",&aux);
        system("cls");
        fflush(stdin);
        letra=tolower(aux);
        //verifica se a letra ja foi usada
        if(verifica(letra)==false)
        {
            letrasJaUsadas[contLetrasUsadas]=letra;
            contLetrasUsadas++;
        }
        else
        {
            while(verifica(letra))
            {
                system("cls");
                for(i=0;i<tam;i++)
                printf("%c",palavraAmostrar[i]);
                printf("\n Letra ja verificada, insira outra: ");
                scanf("%c",&letra);
                if(verifica(letra)==false)
                {
                    letrasJaUsadas[contLetrasUsadas]=letra;
                }
                fflush(stdin);
                system("cls");
            }
        }
        //verifica se a letra está na palavra
        for(i=0;i<tam;i++)
        {
            if(letra==palavra[i])
            {
                palavraAmostrar[i]=palavra[i];
                falso=false;
                contVitoria++;
            }
        }
        //Se não houver letra igual
        if(falso)
        {
            chances--;
            printf("Letra errada tem %d chances\n",chances);
        }
        if(chances==1)
        {
             for(i=0;i<tamPista;i++)
             {
                 printf("%c",pista[i]);
             }
             char palavraFinal[10];
             printf("Agora insira a palavra completa: ");
             fgets(palavraFinal,sizeof(palavraFinal),stdin);
             if(strcmp(palavra,palavraFinal)==0)
             {
                 printf("Ganhou o jogo");
                 break;
             }
             else
             {
                printf("Perdeu \n%s\n",palavra);
                break;
             }


             printf("\n");
        }
        //se ganhou o jogo
        if(contVitoria==tam)
        {
            printf("Parabens ganhou o jogo");
            break;
        }
        //se perdeu o jogo
        if(chances==0)
        {
            printf("Perdeu \n%s\n",palavra);
            break;
        }

    }

}

char *devolve(){
    char *palavras[]={"gato","rato","televisao","cadeira","bola"};
    char word[10];
    time_t t;
    srand((unsigned)time(&t));
    pos=rand()%5;
    return palavras[pos];
}

char *dica(){
    char *dicas[]={"cao","gato","canal","sentado","chuta"};
    return dicas[pos];
}

bool verifica(char letra){
    int i;
    bool flag;
    for(i=0;i<contLetrasUsadas;i++)
    {
        if(letra==letrasJaUsadas[i])
        {
            flag=true;
            break;
        }
        else
        {
            flag=false;
        }
    }
    return flag;
}
