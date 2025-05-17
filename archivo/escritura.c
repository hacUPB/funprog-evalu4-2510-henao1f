#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *p_archivo;
    p_archivo = fopen("texto1.txt", "w");
    fprintf(stdout,"ingrese su nombre: \n");
    fgets(Nombre, sizeof(Nombre), stdin);
    Nombre[strlen(Nombre) - 1] = '\0';
    fprintf(stdout, "cuantos años tienes?\n");
    scanf("%d", &edad);
    if (p_archivo != NULL)
    {
        printf("se crea el archivo.\n");
        fprintf(p_archivo,"este texto de prueba para el archivo texto1.txt");
        fprintf(p_archivo, "hola %s bienbenido al curso\n", Nombre);
        fprintf(p_archivo, "Edad = %d\n", edad);
    }
    fclose(p_archivo);
    returno 0;

}