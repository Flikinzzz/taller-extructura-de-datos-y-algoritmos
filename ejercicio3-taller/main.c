#include <stdio.h>

void descomponer(int n, int k, int *v) {
    if (n == 0) {
        for (int i = 0; i < k; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (k == 0 || v[k - 1] >= i) {
                v[k] = i;
                descomponer(n - i, k + 1, v);
            }
        }
    }
}

int main() {
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d", &n);
    int v[n];
    descomponer(n, 0, v);
    return 0;
}
