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
        printf("para calcular iva oprima 1\n");
printf("para ver el historial oprima 2\n");
printf("para salir oprima 3\n");
scanf("%d",&op);


switch (op)
{
case 1: 
        printf("ingrese un precio \n");
        scanf("%d",&precio);
double final;
final = (double)precio * iva;
printf("el iva es %.2lf \n",final);
printf("el precio sin iva es %d \n", precio);

FILE *archivo = fopen("salida.txt","a");
fprintf(archivo,"iva %.2lf  precio %d\n",final, precio);
fclose(archivo);
default: 
    break;

case 2: 
archivo = fopen("salida.txt","r");
char historial[100];
printf("\nHistorial\n\n");
while (feof(archivo) == 0)
{
    fgets( historial, 100, archivo);
    printf(historial);

}  
fclose(archivo);
break;

printf("opcion invalida\n");
    break;
}
        


    } while (op != 3);}
    
}