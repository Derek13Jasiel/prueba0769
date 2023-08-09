#include <stdio.h>
#include <stdlib.h>

int main(){
    double num1, num2;
    system("cls");
    printf("ingrese el primer numero:");
    if (scanf("%lf",&num1)!= 1){
        printf("error: Ingrese un número real valido.\n");
        return 1;

    }
printf("ingrese el segundo numero:");
    if (scanf("%lf",&num2)!= 1){
        printf("error: Ingrese un número real valido.\n");
        return 1;
    }   

    double suma = num1 + num2;
    double resta = num1 - num2;
    double multiplicacion = num1 * num2;

    if(num2 == 0){
        printf("Error: No se puede dividir entre cero.\n");
        return 1;
    }
    double division = num1 / num2;


    printf("\nResultados:\n");
     printf("suma: %.4lf\n" , suma);
      printf("resta: %.4lf\n",resta);
       printf("multiplicacion: %.4lf\n" , multiplicacion);
        printf("division: %.4lf\n" , division);

        return 0;
}