#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("¿Cuántas resistencias en paralelo? ");
    scanf("%d", &n);
    if (n <= 0) return 1;

    float *r = (float *)calloc(n, sizeof(float)), sum = 0;
    if (!r) return 1;

    for (int i = 0; i < n; i++) {
        do {
            printf("R#%d (ohm): ", i + 1);
            scanf("%f", &r[i]);
        } while (r[i] <= 0);
        sum += 1.0 / r[i];
    }

    for (int i = 0; i < n; i++) {
        if (resistencias[i] == 0) {
            printf("Error: resistencia %d no puede ser cero.\n", i + 1);
            return 1;
    return 0;
}
