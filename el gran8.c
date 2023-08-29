#include <stdio.h>
int dado1, dado2;

int main(){
    
int n = 0;
int c = 0;
int conteo = 0;
int conteo2 = 0;

int op;
FILE *archivo = fopen("salida.txt","r");
    if (archivo == NULL ){
        printf("lo siento archivo de texto no encontrado");
        fclose(archivo);}else{

        printf("\n\nEl gran 8\n");
        printf("ingrese la opcion deseada\n");
        printf("1)jugar\n");
        printf("2)ver historial\n");
        printf("3)borrar historia\n");
        printf("4)salir\n");
        scanf("%d",&op);
do
{

         switch (op)
        {
case 1:

do
{
if( c == 1){
    

}else{

   do
{
        printf("jugador uno(1)\n");
    printf("cara de los dados\n");
    
    scanf("%d,%d",&dado1,&dado2);
    if(dado1 >= 1 && dado1 <= 6 && dado2 >= 1 && dado2 <= 6){
        if(dado1 + dado2 == 8){
            
            conteo = 1 + conteo;
            if(conteo == 2){
                c = 1;
                printf("ganador jugador 2\n");
        FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 2\n");
        fclose(archivo);                
            }
        }else if(dado1 +dado2 ==7){
            
            if(conteo == 1){
                c = 1; 
                printf("ganador jugador 1\n");
         FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 1\n");
        fclose(archivo);               
            }else if(conteo == 0){
                c = 1;
                printf("ganador jugador 2\n");
         FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 2\n");
        fclose(archivo);               
            }
            
        }else if((dado1 + dado2) != 7 && (dado1 + dado2) != 8){
            if (conteo == 1){
                c = 1; 
                printf("ganador jugador 2\n");
         FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 2\n");
        fclose(archivo);               
            }
        }


        n = 1;
    }
    else if(dado1 < 1 || dado1 > 6 || dado2 < 1 || dado2 > 6){
      printf("valor de dados incorrecto\n");
      n = 0;
    }
 
} while (n == 0);}

//cmabio de jugador
if(c == 1){
    
}else{



do
{
        printf("jugador dos(2)\n");
    printf("cara de los dados\n");
    
    scanf("%d,%d",&dado1,&dado2);
    if(dado1 >= 1 && dado1 <= 6 && dado2 >= 1 && dado2 <= 6){
        if(dado1 + dado2 == 8){
           
            conteo = 1 + conteo; 
            if(conteo == 2){
                c = 1;
                printf("ganador jugador 1\n");
         FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 1\n");
        fclose(archivo);               
            }           
        }else if(dado1 +dado2 ==7){
           
            if(conteo == 1){
                c = 1;
                  printf("ganador jugador 2\n");
         FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 2\n");
        fclose(archivo);                 
            }else if(conteo == 0){
                c = 1;
                 printf("ganador jugador 1\n"); 
        FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 1\n");
        fclose(archivo);                 
            }
            
        }else if((dado1 + dado2) != 7 && (dado1 + dado2) != 8){
            if (conteo == 1){
                c = 1; 
                printf("ganador jugador 1\n");
        FILE *archivo = fopen("salida.txt","a");
        fprintf(archivo,"\nganador jugador 1\n");
        fclose(archivo);
            }
        }

        n = 1;
    }
    else if(dado1 < 1 || dado1 > 6 || dado2 < 1 || dado2 > 6){
      printf("valor de dados incorrecto\n");
      n = 0;
    }
 
} while (n == 0);}

} while (c == 0);
op = 4;

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
op = 4;

            break;
          case 3:
         archivo = fopen("salida.txt","w");
        fclose(archivo);
        printf("\nHistorial borrado\n");
        op = 4;   
        break;   
        

        }

} while (op != 4);


        }

}
