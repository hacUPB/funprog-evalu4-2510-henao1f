void guardarArchivo(const char *nombre, const char *txt, int c, int p, int esp, int l, int a, int e, int i, int o, int u) {
    FILE *f = fopen(nombre, "w");
    if (!f) return;
    fprintf(f, "Estadísticas:\nCaracteres: %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n\n", c, p, esp, l);
    fprintf(f, "Frecuencia de vocales:\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n\n", a, e, i, o, u);
    fprintf(f, "Texto final:\n%s\n", txt);
    fclose(f);
}