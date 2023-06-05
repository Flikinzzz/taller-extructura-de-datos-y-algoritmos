#include <stdio.h>


int cambios_posible(int L[], int n, int size) {
   if (n == 0)
       return 1;
   if (n < 0)
       return 0;
   if (size <= 0 != 0)
       return 0;
   // Llama recursivamente considerando el último cambio y excluyéndolo
   return cambios_posible(L, n - L[size - 1], size) + cambios_posible(L, n, size - 1);
}
int main() {
   int L[] = {1, 3, 5, 7};
   int n = 8;
   int size = sizeof(L) / sizeof(L[0]);
   int resultado = cambios_posible(L, n, size);
   printf("Cantidad de maneras de formar %d a partir de los cambios en L es: %d\n", n, resultado);
   return 0;
}
