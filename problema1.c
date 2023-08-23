#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Ingrese la cantida de numeros a ingresar\n");
    int v;

    scanf("%d",&v);
    
  int valor[v];
printf("ingrese valores \n");

for (int i = 0; i <v; i++)
{ 
    scanf("%i",&valor[i]);
}
printf("ingrese la operacion a realizar\n");
printf("1) sumar\n");
printf("2) multiplicar\n");
int op;

int salida =  0 ;
scanf("%d",&op);

switch (op)
{
case 1:

for (int c = 0; c < v; c++)
{
    salida = valor[c] + salida;
}
printf("el resultado de la suma total es %d\n",salida);

  break;

case 2:

for (int c = 0; c < v; c++)
{
    salida = valor[c] * salida;
}
printf("el resultado de la multiplicacion total es %d\n",salida);

  break;  

default:
printf("opcion no valida\n");
    break;
}

    

}
