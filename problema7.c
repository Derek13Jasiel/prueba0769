#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("ingrese un numero para sacar factorial(!)\n");
    int n;
    scanf("%d",&n);
    int v1 = 0;
    int v2 =1;

    for (int i = 0; i < n; i++)
    {
        v1 = v1 + 1;
        v2 = v2 * v1;       
    }
          printf("%d!es %d\n",n,v2);
    
}