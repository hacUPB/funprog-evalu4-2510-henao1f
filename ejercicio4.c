#include <stdio.h>

int main() {
    int arr1[5], arr2[5], arr3[10];
    int i;

    
    for(i = 0; i < 10; i++) {
        printf("Ingrese el número %d: ", i + 1);
        scanf("%d", &arr3[i]);

        if(i < 5) {
            arr1[i] = arr3[i];  
        } else {
            arr2[i - 5] = arr3[i];  
        }
    }

    
    printf("\nArray combinado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }

    printf("\n");
    return 0;
}

