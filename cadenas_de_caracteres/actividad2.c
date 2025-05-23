#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char frase[100];
    int contador = 0;
    char letra;
    //pedimos  al usuario que ingrese una frase
    printf("ingrese una frase: \n");
    fgets(frase, sizeof(frase), stdin);
    printf ("%s\n", frase);
    
    for (int i = 0; i < strlen(frase); i++)
    {
        letra = tolower(frase[i]);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        {
            contador++:
        }
    }
    printf("en la frase hay %d vocales\n", contador);

    return 0;
}    
