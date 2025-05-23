char* reemplazar(const char *txt, const char *buscar, const char *reemp) {
    int n = 0, lb = strlen(buscar), lr = strlen(reemp);
    const char *p = txt;
    while ((p = strstr(p, buscar))) { n++; p += lb; }

    char *nuevo = malloc(strlen(txt) + n * (lr - lb) + 1);
    if (!nuevo) return NULL;

    char *dest = nuevo;
    p = txt;

    while (*p) {
        if (strstr(p, buscar) == p) {
            strcpy(dest, reemp);
            dest += lr; p += lb;
        } else *dest++ = *p++;
    }
    *dest = '\0';
    return nuevo;
}
