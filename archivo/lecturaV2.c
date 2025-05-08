#include <stdio.h>
 
int main(void)
{
    // 0. Declaración de variables
    int cant_registros;
    float peso[3], estatura[3], imc[3];
    // 1. Declarar el puntero
    FILE *p_datos;
 
    // 2. Abrir el archivo
    p_datos = fopen("datos.txt", "r");
 
    // 3. Verficar que se pudo abrir el archivo
    if (!p_datos)
    {
        perror("No se pudo abrir.\n");
        return 1;
    }
 
    // 4. Operaciones de lectura
    fscanf(p_datos, "%d", &cant_registros);
    printf("Cantidad registros = %d\n", cant_registros);
 
    for (int i = 0; i < cant_registros; i++)
    {
        fscanf(p_datos, "%f", &peso[i]);
        printf("Peso = %f\n", peso[i]);
        fscanf(p_datos, "%f", &estatura[i]);
        printf("Estatura = %f\n", estatura[i]);
        imc[i] = peso[i] / (estatura[i] * estatura[i]);
        printf("IMC = %f\n", imc[i]);
    }
 
    return 0;
}
 