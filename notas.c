#include <stdio.h>

int main(){
int op;  int no1 = 6;   int promedio = 0;
char nombre[100];
char materia[100];
int nota[no1];

    FILE *archivo = fopen("salida.txt","r");
    if (archivo == NULL ){
        printf("lo siento archivo de texto no encontrado");
        fclose(archivo);}else{

do
{
    printf("1)Registrar nuevo estudiante y notas\n");
    printf("2)ver historial\n");
        printf("3)borrar historial\n");
            printf("4)salir\n");

            scanf("%d",&op);

        switch (op)
        {
        case 1:
                printf("Nombre del estudiante: ");
    scanf("%s",&nombre);
    FILE *archivo = fopen("salida.txt","a");
    fprintf(archivo,"nombre :%s\n",nombre);

    for (int i = 0; i < no1; i++)
    {
    printf("\nMateria: ");
    scanf("%s",&materia);

    printf("\nnota: ");
    scanf("%d",&nota[i]); 
    fprintf(archivo,"materia %s nota %d", materia, nota);
    fclose(archivo);
    }

 for (int c = 0; c < no1; c++)
 {
     promedio = nota[c] + promedio; 
 }
    int resultado = promedio/no1;
    
    printf("promedio = %d\n",resultado);

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

    case 3:
    
    archivo = fopen("hola.txt","w");
printf("\nHISTORIAL BORRADO\n");
fclose(archivo);
        
        default:
        printf("\n");
            break;
        }


    


   
    
    
} while (op != 4);
}

}