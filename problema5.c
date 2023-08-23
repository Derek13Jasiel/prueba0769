#include <stdio.h>
#include <stdlib.h>

int main(){
printf("ingrese la operacion a realizar\n");
printf("1) Celsius a Fahrenheit\n");
printf("2) Fahrenheit a Celsius \n");
int n;
float v1;
float v2;
float num1 = 1.8;
scanf("%d",&n);

switch (n)
{
case 1:
    printf("ingrese el valor a convertir de grados celcius a fahrenheit\n");
    scanf("%f",&v1);

    v2 = v1 * num1 + 32;
    printf("conversion de celcius a fahrenheit\n");
    printf("%f",v2);
    break;
case 2:
    printf("ingrese el valor a convertir de grados fahrenheit a celcius\n");
    scanf("%f",&v1);

    v2 = (v1 - 32 )/num1;
    printf("conversion de fahrenheit a celcius \n");
    printf("%f",v2);
    break;

default:
printf("opcion no valida\n");
    break;
}




}