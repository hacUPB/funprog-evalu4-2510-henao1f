int main() {
    char *txt = leerArchivo();
    if (!txt) {
        printf("Error al leer el archivo.\n");
        return 1;
    }

    int c, p, esp, l, a, e, i, o, u;
    estadisticas(txt, &c, &p, &esp, &l);
    contarVocales(txt, &a, &e, &i, &o, &u);

    printf("Estadísticas:\n");
    printf("Caracteres: %d\n", c);
    printf("Palabras: %d\n", p);
    printf("Espacios: %d\n", esp);
    printf("Líneas: %d\n", l);
    printf("Frecuencia de vocales:\n");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);

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