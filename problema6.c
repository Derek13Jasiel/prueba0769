#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1 ; int n2;
    printf("ingrese el numero un rango de numeros divididos por coma\n");
    scanf("%d, %d",&n1, &n2);
    int v1 = n1; 
    int v2 = n2;
    v1 = v1 /2 ;
    v2 = v2 /2;
    int c = v2 - v1;
    n1 = v1 *2;
    printf("hay %d numeros pares \n",c); 
  //*  printf("%d\n",v1);
  //  printf("%d\n",v2);
    

  for (int i = 0; i < c; i++)
 {
       n1 = n1 + 2;
      printf("%d\n",n1);
    }
    
}