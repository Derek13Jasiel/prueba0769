#include <stdio.h>
#include <stdlib.h>

int main(){
    int op, uno, dos;
    do{
        printf(" --- Calculadora ---\n");
        printf("\n ¿Que desea hacer\n");
        printf("1) Sumar\n");
        printf("2) Restar\n");
        printf("3) Multiplicar\n");
        printf("4) Dividir\n");
        printf("5) Salir\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
             printf("\nsumar\n");
             printf("\nIntroduzca los numeros a sumar searados por comas \n");
             scanf("%d,%d", &uno, &dos);
             printf("%d + %d = %d\n", uno, dos, (uno + dos));      
            break;

         case 2:
             printf("\nrestar\n");
             printf("\nIntroduzca los numeros a restar searados por comas \n");
             scanf("%d,%d", &uno, &dos);
             printf("%d - %d = %d\n", uno, dos, (uno - dos));      
            break;

         case 3:
             printf("\nmultiplicacionr\n");
             printf("\nIntroduzca los numeros a multiplicar searados por comas \n");
             scanf("%d,%d", &uno, &dos);
             printf("%d * %d = %d\n", uno, dos, (uno * dos));      
            break; 

         case 4:
             printf("\ndividir\n");
             printf("\nIntroduzca los numeros a dividir searados por comas \n");
             scanf("%d,%d", &uno, &dos);
             printf("%d / %d = %.2lf\n", uno, dos, ((double)uno / dos));      
            break;

         case 5:
             printf("\nsalir\n");
            break;                                           
        
        default:
            printf("\nopcion invalida.");

            
        }
       
        
        

    }while (op != 5);
    return 0;
}