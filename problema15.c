#include <stdio.h>
#include <string.h>

int main(){
printf("ingrese una palabra en Mayuscula\n");
char palabra[30];


scanf("%s",&palabra);
int va1 = strlen(palabra);
int des;

printf("ingrese el desplazamiendo de letra de 1 a 26\n");
scanf("%d",&des);

    char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    char cesar[30];


    for (int i = 0; i < va1 ; i++)
    {

        for (int c = 0; c < 26; c++)
        {

         if(letras[c]==palabra[i])
        {
            cesar[i] = letras[c+des];
            printf("%c",cesar[i]);

        } 
        }
                
       
    }


}