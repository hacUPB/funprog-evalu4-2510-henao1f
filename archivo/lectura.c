#include <stdio.h>

int main(void)
{
    //0. declaracion de variables
    int cant_registros;
    float peso, estatura, imc;
    //1. declarar el puntero
    FILE *p_datos, *p_imc;

    //2. abrir el archivo
    p_datos = fopen("datos.txt", "r");

    //3. verificar si se pudo abrir el archivo
    i(!p_datos)
    {
        perror("no se pudo abrir.\n");
        return 1;
    }

    //4. operaciones de lectura
    fscanf(p_datos, "%d", &cant_registros);
    printf("cantidad registros = %d\n", cant_registros);
    fscanf(p_datos, "%d", &peso);
    printf("peso = %d\n", cant_registros);
    fscanf(p_datos, "%d", &estatura);
    printf("estatura = %d\n", cant_registros);

    imc = peso / (estatura * estatura);
    printf("IMC = %f\n", imc);

    return 0;
}