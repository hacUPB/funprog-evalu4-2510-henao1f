#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lee el contenido del archivo
char* leerArchivo() {
    char nombre[100];
    printf("Archivo a leer: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    FILE *f = fopen(nombre, "r");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);

    char *txt = malloc(len + 1);
    if (!txt) {
        fclose(f);
        return NULL;
    }

    fread(txt, 1, len, f);
    txt[len] = '\0';
    fclose(f);
    return txt;
}

// calcula estadísticas básicas del texto
void estadisticas(const char *txt, int *c, int *p, int *esp, int *l) {
    *c = *p = *esp = *l = 0;
    int enPalabra = 0;
    for (int i = 0; txt[i]; i++) {
        if (txt[i] != '\n') (*c)++;
        if (txt[i] == ' ') {
            (*esp)++;
            enPalabra = 0;
        }
        else if (txt[i] == '\n') {
            (*l)++;
            enPalabra = 0;
        }
        else if (!enPalabra) {
            (*p)++;
            enPalabra = 1;
        }
    }
    if (*txt) (*l)++;
}

// cuenta las vocales 
void contarVocales(const char *txt, int *a, int *e, int *i, int *o, int *u) {
    *a = *e = *i = *o = *u = 0;
    for (int j = 0; txt[j]; j++) {
        char c = txt[j];
        if (c == 'a' || c == 'A') (*a)++;
        else if (c == 'e' || c == 'E') (*e)++;
        else if (c == 'i' || c == 'I') (*i)++;
        else if (c == 'o' || c == 'O') (*o)++;
        else if (c == 'u' || c == 'U') (*u)++;
    }
}

// reemplaza una palabra por otra
char* reemplazar(const char *txt, const char *buscar, const char *reemp) {
    int n = 0, lb = strlen(buscar), lr = strlen(reemp);
    const char *p = txt;
    while ((p = strstr(p, buscar))) {
        n++;
        p += lb;
    }

    char *nuevo = malloc(strlen(txt) + n * (lr - lb) + 1);
    if (!nuevo) return NULL;

    char *dest = nuevo;
    p = txt;

    while (*p) {
        if (strstr(p, buscar) == p) {
            strcpy(dest, reemp);
            dest += lr;
            p += lb;
        } else {
            *dest++ = *p++;
        }
    }
    *dest = '\0';
    return nuevo;
}

// guarda resultados en un archivo
void guardarArchivo(const char *nombre, const char *txt, int c, int p, int esp, int l, int a, int e, int i, int o, int u) {
    FILE *f = fopen(nombre, "w");
    if (!f) {
        printf("No se pudo guardar el archivo.\n");
        return;
    }

    fprintf(f, "Estadísticas:\nCaracteres: %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n\n", c, p, esp, l);
    fprintf(f, "Frecuencia de vocales:\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n\n", a, e, i, o, u);
    fprintf(f, "Texto final:\n%s\n", txt);
    fclose(f);
    printf("Resultados guardados en 'resultados.txt'\n");
}

// Función principal
int main() {
    char *txt = leerArchivo();
    if (!txt) {
        printf("Error al leer el archivo.\n");
        return 1;
    }

    int c, p, esp, l, a, e, i, o, u;
    estadisticas(txt, &c, &p, &esp, &l);
    contarVocales(txt, &a, &e, &i, &o, &u);

    printf("\nEstadísticas:\n");
    printf("Caracteres: %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n", c, p, esp, l);
    printf("Frecuencia de vocales:\n");
    printf("a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", a, e, i, o, u);

    printf("\n¿Qué palabra quieres reemplazar? ");
    char buscar[100], reemp[100];
    fgets(buscar, sizeof(buscar), stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    printf("¿Por qué palabra quieres reemplazarla? ");
    fgets(reemp, sizeof(reemp), stdin);
    reemp[strcspn(reemp, "\n")] = '\0';

    char *nuevoTexto = reemplazar(txt, buscar, reemp);
    if (nuevoTexto) {
        printf("\nTexto después de reemplazar:\n%s\n", nuevoTexto);
        guardarArchivo("resultados.txt", nuevoTexto, c, p, esp, l, a, e, i, o, u);
        free(nuevoTexto);
    } else {
        printf("Error al reemplazar la palabra.\n");
    }

    free(txt);
    return 0;
}
