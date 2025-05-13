void estadisticas( const char *txt, int *c, int *p, int *esp, int *l)
{
    *c = *p = *esp = *l = 0;
    int reto = 0;
    for ( int i = 0; txt[i]; i++)
    {
        if (txt[i] != '\n') (*c)++;
        if (txt[i] == ' ') { (*esp)++; reto = 0; }
        else if (txt[i] =='\n') { (*l)++; reto = 0; }
        else if (!reto) { (*p)++; reto = 1; }
    }
    if (*txt) (*l)++;
}