#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("valor de la tabla \n");
    int n;
    int v1 = 0;
    int v2;
    scanf("%d",&n);
    for (int i = 0; i < 9; i++)
    {       
        v1 = v1 + 1 ;
         v2 = v1 * n;
    printf("%d * %d = %d\n",v1, n,v2);
    }
    
}