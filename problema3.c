#include <stdio.h>
#include <string.h>

int main(){
  printf("ingrese una frase\n");
  char frase[20];
  scanf("%s",&frase);
  int n  = strlen(frase);
  printf("su frase tiene %d caractres",n);

}

