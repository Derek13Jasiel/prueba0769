#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Ingrese la opcion a realizar\n");
    printf("1)Volumen de un cubo\n");
    printf("2)Volumen de una esfera \n");
    printf("3)Volumen de una piramide de base triangular\n");
    printf("4)Volumen de una piramide de base cuadrada\n");
int n; 
float v1;
float v2;
float v3;
float v4; 
float pi = 3.1416;
float num1 = 1.3334;
float num2 = 0.3334;
float num3 = 0.1667;

    scanf("%d",&n);

    switch (n)
    {
    case 1:
        printf("ingrese el lado del cubo\n");
        scanf("%f",&v1);
        v2 = v1 * v1 * v1;
        printf("el volumen del cubo es %.4f", v2);

        break;

     case 2:
        printf("ingrese el radio de la esfera\n");
        scanf("%f",&v1);
        v2 = num1 * pi *v1 * v1 * v1;
        printf("el volumen de la esfera  es %.4f", v2);

        break;  

     case 3:
        printf("ingrese el lado y la altura de la piramide\n");
        scanf("%f, %f",&v1,&v3);
        v2 = num2 * v1 * v1 * v3;
        printf("el volumen de la piramide de base  cuadrada es %.4f", v2);

        break;    

     case 4:
        printf("ingrese  la base, el ancho y la altura de la piramide\n");
        scanf("%f, %f, %f",&v1,&v3,&v4);
        v2 = num3 * v1 * v3 * v4;
        printf("el volumen de la piramide de base triangular es %.4f", v2);

        break;                  
    
    default:
    printf("opcion no valida\n");
        break;
    }


}