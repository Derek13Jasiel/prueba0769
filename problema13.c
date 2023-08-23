#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Ingrese un numero entero\n");
    int n;
    scanf("%d",&n);

 int v = n/2;
 //printf("tipo entero %d\n",v);

 double c = (double)n;
 c = c/2;
 //printf("tipo float %.f\n",c);

 double d = (double)v;

double resultado = c - d ;

//printf("resultado %d\n",resultado);


 if( resultado == 0){
    printf("el numero %d es Par", n);

 }else{
    printf("el numero %d es Impar", n);
 }


}