#include <stdio.h>

int main(){
int op;
FILE *archivo = fopen("salida.txt","r");
    if (archivo == NULL ){
        printf("lo siento archivo de texto no encontrado");
        fclose(archivo);}else{
do
{


    printf("\nINGRESE UN NUMERO ENTERO POSITIVO\n");
    double n;
    scanf("%lf",&n);


    double L;
int T;
double c;
int m = 1;
int i = 1;
while (m != 0)
{
    if(i == n){
        m = 0;
        printf("el numero %.2lf es primo\n",n);
        FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nnumero %.2lf es primo\n",n);
        fclose(archivo);

    }else
    {
 L = n/i;
    T = n/i;
    if(T == n || L == n){
        i = i +1;
    }else{
        
 c = L - T;
 if(c == 0){
    m = 0;
    printf("el numero %.2lf es compuesto\n",n);
        FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nnumero %.2lf es compuesto\n",n);
        fclose(archivo);

 }
 i = i + 1;
}
    }
   

}

printf("pulse numero (1) para ver historial\n");
printf("pulse (2) para borrar el historial\n");
printf("pulse (3) para salir\n");
printf("pulso otro numero para continuar\n");

scanf("%d",&op);

switch (op)
{
case 1:
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
case 2:
        archivo = fopen("salida.txt","w");
        fclose(archivo);
        printf("\nHistorial borrado\n");   
        break; 


}



} while (op != 3);}







}



