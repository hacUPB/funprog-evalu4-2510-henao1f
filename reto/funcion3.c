void contarVocales (const char *txt, *a, *e, *i, *o, *u)
{
    *a = *e = *i = *o = *u = 0;
    for(int j = 0; txt[j]; j++)
    {
        char c = txt[j];
        if ( c =='a' || c =='A') (*a)++;
        else if ( c =='e' || c =='E') (*e)++;
        else if ( c =='i' || c =='I') (*i)++;
        else if ( c =='o' || c =='O') (*o)++;
        else if ( c =='u' || c =='U') (*u)++;
    }
}