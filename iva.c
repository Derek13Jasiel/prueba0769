#include <stdio.h>

int main(){
    int precio;
    int op;
    double iva = 0.12;
        FILE *archivo = fopen("salida.txt","r");
        if (archivo == NULL)
        {
            printf("archivo no encontrado");
            fclose(archivo);
        }else{
    do
    {

        
        printf("ingrese un precio \n");
        scanf("%d",&precio);
double final;
final = (double)precio * iva;
printf("el iva es %.2lf \n",final);
printf("el precio sin iva es %d \n", precio);

FILE *archivo = fopen("salida.txt","a");
fprintf(archivo,"iva %d  precio %d\n",precio, final);
             
printf("para salir oprima 1\n");
printf("para continuar oprima un numero\n");
scanf("%d",&op);
    } while (op != 1);}
    
}