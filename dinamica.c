#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int i;  //en la pila
    int *puntero, tamano;  //pila
    printf("ingrese tamaño:");
    scanf("%d",&tamano);
    printf("\n");
    puntero = (int *) malloc(tamano*sizeof(int));
    //tamano*sizeof(int) --> tamaño en bytes a reservar
    //(int *) --> casting a puntero a entero
    for(i=0;i<tamano;i++){
          puntero[i]=i+1;
          printf("%d\n",puntero[i]);
    }
    free(puntero);  //liberar memoria del heap
    return 0;
}