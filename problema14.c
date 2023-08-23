#include <stdio.h>
#include <stdlib.h>

int main(){
        printf("Ingre el numero de filas\n");
        int n;
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
             
             for (int c = 0; c < i + 1 ; c++)
            {
             printf("*");
            }
            
            
           printf("\n");
          
        }


}