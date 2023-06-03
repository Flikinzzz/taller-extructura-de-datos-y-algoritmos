#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() {
    int arreglo1[100];
    int x;
    int i;
    int key;
    int j;
    int aux;
    int arreglo2[1000];
    int x2;
    int i2;
    int key2;
    int j2;
    int aux2;
    int arreglo3[10000];
    int x3;
    int i3;
    int key3;
    int j3;
    int aux3;

    srand(time(NULL));

    // PRIMER ARREGLO DESORDENADO
    printf("arreglo1 desordenado.\n");
    for (x = 0; x < 100; x++) {
        arreglo1[x] = 1 + rand() % 1000;
        printf("%d\t", arreglo1[x]);
    }

    // SEGUNDO ARREGLO DESORDENADO
    printf("\n\narreglo2 desordenado.\n");
    for (x2 = 0; x2 < 1000; x2++) {
        arreglo2[x2] = 1 + rand() % 1000;
        printf("%d\t", arreglo2[x2]);
    }

    // TERCER ARREGLO DESORDENADO
    printf("\n\narreglo3 desordenado.\n");
    for (x3 = 0; x3 < 10000; x3++) {
        arreglo3[x3] = 1 + rand() % 1000;
        printf("%d\t", arreglo3[x3]);
    }

    // APLICAR ORDENAMIENTO DE BURBUJA PARA ARREGLO 1
    printf("\n\nEl primer arreglo ordenado por burbuja queda como.\n\n");
    clock_t start_time1 = clock(); // Tiempo de inicio
    for (i = 0; i < 100; i++) {
        for (int j = 0; j < 100 - i - 1; j++) {
            if (arreglo1[j] > arreglo1[j + 1]) {
                aux = arreglo1[j + 1];
                arreglo1[j + 1] = arreglo1[j];
                arreglo1[j] = aux;
            }
        }
    }
    clock_t end_time1 = clock(); // Tiempo de finalización

    // IMPRIMIR EL ARREGLO1 ORDENADO POR BURBUJA
    for (i = 0; i < 100; i++) {
        printf("%d\t", arreglo1[i]);
    }

    double time_taken1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el primer arreglo por burbuja: %f segundos\n", time_taken1);

    // APLICAR ORDENAMIENTO DE BURBUJA PARA ARREGLO 2
    printf("\n\nEl segundo arreglo ordenado por burbuja queda como.\n\n");
    clock_t start_time2 = clock(); // Tiempo de inicio
    for (i2 = 0; i2 < 1000; i2++) {
        for (int j2 = 0; j2 < 1000 - i2 - 1; j2++) {
            if (arreglo2[j2] > arreglo2[j2 + 1]) {
                aux2 = arreglo2[j2 + 1];
                arreglo2[j2 + 1] = arreglo2[j2];
                arreglo2[j2] = aux2;
            }
        }
    }
    clock_t end_time2 = clock(); // Tiempo de finalización

    // IMPRIMIR EL ARREGLO2 ORDENADO POR BURBUJA
    for (i2 = 0; i2 < 1000; i2++) {
        printf("%d\t", arreglo2[i2]);
    }

    double time_taken2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el segundo arreglo por burbuja: %f segundos\n", time_taken2);

    // APLICAR ORDENAMIENTO DE BURBUJA PARA ARREGLO 3
    printf("\n\nEl tercer arreglo ordenado por burbuja queda como.\n\n");
    clock_t start_time3 = clock(); // Tiempo de inicio
    for (i3 = 0; i3 < 10000; i3++) {
        for (int j3 = 0; j3 < 10000 - i3 - 1; j3++) {
            if (arreglo3[j3] > arreglo3[j3 + 1]) {
                aux3 = arreglo3[j3 + 1];
                arreglo3[j3 + 1] = arreglo3[j3];
                arreglo3[j3] = aux3;
            }
        }
    }
    clock_t end_time3 = clock(); // Tiempo de finalización

    // IMPRIMIR EL ARREGLO3 ORDENADO POR BURBUJA
    for (i3 = 0; i3 < 10000; i3++) {
        printf("%d\t", arreglo3[i3]);
    }

    double time_taken3 = ((double)(end_time3 - start_time3)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el tercer arreglo por burbuja: %f segundos\n", time_taken3);

    // APLICAR ORDENAMIENTO POR INSERCIÓN PARA ARREGLO 1
    printf("\n\nEl primer arreglo ordenado por inserción queda como.\n\n");
    start_time1 = clock(); // Tiempo de inicio
    for (i = 1; i < 100; i++) {
        key = arreglo1[i];
        j = i - 1;

        while (j >= 0 && arreglo1[j] > key) {
            arreglo1[j + 1] = arreglo1[j];
            j = j - 1;
        }

        arreglo1[j + 1] = key;
    }

    // IMPRIMIR EL ARREGLO1 ORDENADO POR INSERCIÓN
    for (i = 0; i < 100; i++) {
        printf("%d\t", arreglo1[i]);
    }

    end_time1 = clock(); // Tiempo de finalización
    time_taken1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el primer arreglo por inserción: %f segundos\n", time_taken1);

    // APLICAR ORDENAMIENTO POR INSERCIÓN PARA ARREGLO 2
    printf("\n\nEl segundo arreglo ordenado por inserción queda como.\n\n");
    start_time2 = clock(); // Tiempo de inicio
    for (i2 = 1; i2 < 1000; i2++) {
        key2 = arreglo2[i2];
        j2 = i2 - 1;

        while (j2 >= 0 && arreglo2[j2] > key2) {
            arreglo2[j2 + 1] = arreglo2[j2];
            j2 = j2 - 1;
        }

        arreglo2[j2 + 1] = key2;
    }

    // IMPRIMIR EL ARREGLO2 ORDENADO POR INSERCIÓN
    for (i2 = 0; i2 < 1000; i2++) {
        printf("%d\t", arreglo2[i2]);
    }

    end_time2 = clock(); // Tiempo de finalización
    time_taken2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el segundo arreglo por inserción: %f segundos\n", time_taken2);

    // APLICAR ORDENAMIENTO POR INSERCIÓN PARA ARREGLO 3
    printf("\n\nEl tercer arreglo ordenado por inserción queda como.\n\n");
    start_time3 = clock(); // Tiempo de inicio
    for (i3 = 1; i3 < 10000; i3++) {
        key3 = arreglo3[i3];
        j3 = i3 - 1;

        while (j3 >= 0 && arreglo3[j3] > key3) {
            arreglo3[j3 + 1] = arreglo3[j3];
            j3 = j3 - 1;
        }

        arreglo3[j3 + 1] = key3;
    }

    // IMPRIMIR EL ARREGLO3 ORDENADO POR INSERCIÓN
    for (i3 = 0; i3 < 10000; i3++) {
        printf("%d\t", arreglo3[i3]);
    }

    end_time3 = clock(); // Tiempo de finalización
    time_taken3 = ((double)(end_time3 - start_time3)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el tercer arreglo por inserción: %f segundos\n", time_taken3);


    // APLICAR ORDENAMIENTO POR SELECCIÓN PARA ARREGLO 1
    printf("\n\nEl primer arreglo ordenado por selección queda como.\n\n");
    start_time1 = clock(); // Tiempo de inicio
    for (i = 0; i < 100 - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < 100; j++) {
            if (arreglo1[j] < arreglo1[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arreglo1[min_idx];
        arreglo1[min_idx] = arreglo1[i];
        arreglo1[i] = temp;
    }

    // IMPRIMIR EL ARREGLO1 ORDENADO POR SELECCIÓN
    for (i = 0; i < 100; i++) {
        printf("%d\t", arreglo1[i]);
    }

    end_time1 = clock(); // Tiempo de finalización
    time_taken1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el primer arreglo por selección: %f segundos\n", time_taken1);

    // APLICAR ORDENAMIENTO POR SELECCIÓN PARA ARREGLO 2
    printf("\n\nEl segundo arreglo ordenado por selección queda como.\n\n");
    start_time2 = clock(); // Tiempo de inicio
    for (i2 = 0; i2 < 1000 - 1; i2++) {
        int min_idx2 = i2;
        for (j2 = i2 + 1; j2 < 1000; j2++) {
            if (arreglo2[j2] < arreglo2[min_idx2]) {
                min_idx2 = j2;
            }
        }
        int temp2 = arreglo2[min_idx2];
        arreglo2[min_idx2] = arreglo2[i2];
        arreglo2[i2] = temp2;
    }

    // IMPRIMIR EL ARREGLO2 ORDENADO POR SELECCIÓN
    for (i2 = 0; i2 < 1000; i2++) {
        printf("%d\t", arreglo2[i2]);
    }

    end_time2 = clock(); // Tiempo de finalización
    time_taken2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el segundo arreglo por selección: %f segundos\n", time_taken2);

    // APLICAR ORDENAMIENTO POR SELECCIÓN PARA ARREGLO 3
    printf("\n\nEl tercer arreglo ordenado por selección queda como.\n\n");
    start_time3 = clock(); // Tiempo de inicio
    for (i3 = 0; i3 < 10000 - 1; i3++) {
        int min_idx3 = i3;
        for (j3 = i3 + 1; j3 < 10000; j3++) {
            if (arreglo3[j3] < arreglo3[min_idx3]) {
                min_idx3 = j3;
            }
        }
        int temp3 = arreglo3[min_idx3];
        arreglo3[min_idx3] = arreglo3[i3];
        arreglo3[i3] = temp3;
    }

    // IMPRIMIR EL ARREGLO3 ORDENADO POR SELECCIÓN
    for (i3 = 0; i3 < 10000; i3++) {
        printf("%d\t", arreglo3[i3]);
    }

    end_time3 = clock(); // Tiempo de finalización
    time_taken3 = ((double)(end_time3 - start_time3)) / CLOCKS_PER_SEC;
    printf("\n\nTiempo para ordenar el tercer arreglo por selección: %f segundos\n", time_taken3);

    return 0;
}
