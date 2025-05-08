#include <stdio.h>

int main(int argc, char const *argv[])
{
    File *pfile;
    int letra;
    pfile = fopen("texto2.txt", "a");
    if (pfile)
    {
        while(letra != '?')
        {
            caracter = fgetc(stdin);
            letra = fputc(caracter, pfile);
        }
    }
    return 0;
}