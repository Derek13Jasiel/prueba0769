#include <stdio.h>
#include <string.h>

int main(){
char frase[20];
printf("introdusca una palabra\n");
scanf("%s",&frase);

int n = strlen(frase);

for (int i = 0; i < n; i++)
{
   for (int c = 0; c < 2; c++)
   {
    printf("%c",frase[i]);
   }
    
}



}