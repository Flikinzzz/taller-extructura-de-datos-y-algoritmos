#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

struct tuple {
    int operations, swaps;
};

typedef struct tuple Tuple;

double calcularPromedio(const double arreglo[], int tamano) {
    double sumatoria = 0;
    int i;
    for (i = 0; i < tamano; i++) {
        sumatoria += arreglo[i];
    }
    return sumatoria / tamano;
}


double calcularDesviacionEstandar(double arreglo[], int tamano, double promedio) {
    double sumatoria = 0;
    int i;
    for (i = 0; i < tamano; i++) {
        sumatoria += pow(arreglo[i] - promedio, 2);
    }
    double varianza = sumatoria / tamano;
    return sqrt(varianza);
}

double calcularMin(const double arreglo[], int tamano) {
    int i;
    double min = arreglo[0];
    for (i = 1; i < tamano; i++) {
        double val = arreglo[i];
        if (val < min)
            min = val;
    }
    return min;
}

double calcularMax(const double arreglo[], int tamano) {
    int i;
    double max = arreglo[0];
    for (i = 1; i < tamano; i++) {
        double val = arreglo[i];
        if (val > max)
            max = val;
    }
    return max;
}

// Genera un arreglo aleatorio de tamaño n con elementos entre 1 y 1000
int* generar_arreglo(int n) {
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    return arr;
}

int* duplicarArreglo(const int* arr, int size) {
    int* duplicate = (int*)malloc(size * sizeof(int));
    if (duplicate == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        duplicate[i] = arr[i];
    }

    return duplicate;
}

// Ordena un arreglo utilizando el algoritmo burbuja y retorna el número de operaciones
Tuple burbuja(int arr[], int n) {
    int operaciones = 0;
    int swaps = 0;
    bool has_swapped;
    for (int i = 0; i < n - 1; i++) {
        has_swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            operaciones++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                has_swapped = true;
                swaps++;
            }
        }
        if (!has_swapped) {
            break;
        }
    }
    Tuple t;
    t.operations = operaciones;
    t.swaps = swaps;
    return t;
}

// Ordena un arreglo usando el algoritmo de selección y retorna el número de operaciones
Tuple seleccion(int arr[], int n) {
    int operaciones = 0;
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            operaciones++;
            if (arr[j] < arr[min_index]) {
                swaps++;
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    Tuple t;
    t.operations = operaciones;
    t.swaps = swaps;
    return t;
}

// Ordena un arreglo utilizando el algoritmo de inserción y retorna el número de operaciones
Tuple insercion(int arr[], int n) {
    int i, j, key;
    int operaciones = 0;
    int swaps = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        operaciones++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++;
        }
        arr[j + 1] = key;
    }
    Tuple t;
    t.operations = operaciones;
    t.swaps = swaps;
    return t;}

int main() {
    srand(time(NULL));
    int sizes[] = {100, 1000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    FILE *file = fopen("arrays.csv", "w");
    fprintf(file, "Tamano, Tipo, Tiempo, Operaciones, Swaps, Promedio, Desviacion Estandar, Minimo, Maximo\n");

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int ops;
        int swaps;
        long long total_operaciones_burbuja = 0;
        long long total_operaciones_seleccion = 0;
        long long total_operaciones_insercion = 0;
        long long total_swaps_burbuja = 0;
        long long total_swaps_seleccion = 0;
        long long total_swaps_insercion = 0;
        double total_tiempo_burbuja = 0;
        double total_tiempo_seleccion = 0;
        double total_tiempo_insercion = 0;

        double promedio_bur, promedio_sel, promedio_ins;
        double desviacion_estandar_bur, desviacion_estandar_sel, desviacion_estandar_ins;
        double maximo_bur, maximo_sel, maximo_ins;
        double minimo_bur, minimo_sel, minimo_ins;

        double arr_bur_swaps[100];
        double arr_sel_swaps[100];
        double arr_ins_swaps[100];

        for (int j = 0; j < 100; j++) {
            int* arr = generar_arreglo(size);
            int* arr_bur = duplicarArreglo(arr, size);
            int* arr_sel = duplicarArreglo(arr, size);
            int* arr_ins = duplicarArreglo(arr, size);

            clock_t start_t, end_t;
            Tuple t;

            // Burbuja
            start_t = clock();
            t = burbuja(arr_bur, size);
            ops = t.operations;
            swaps = t.swaps;
            arr_bur_swaps[j] = swaps;
            total_operaciones_burbuja += ops;
            total_swaps_burbuja += swaps;
            end_t = clock();
            total_tiempo_burbuja += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Selección
            start_t = clock();
            t = seleccion(arr_sel, size);
            ops = t.operations;
            swaps = t.swaps;
            arr_sel_swaps[j] = swaps;
            total_operaciones_seleccion += ops;
            total_swaps_seleccion += swaps;
            end_t = clock();
            total_tiempo_seleccion += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Inserción
            start_t = clock();
            t = insercion(arr_ins, size);
            ops = t.operations;
            swaps = t.swaps;
            arr_ins_swaps[j] = swaps;
            total_operaciones_insercion += ops;
            total_swaps_insercion += swaps;
            end_t = clock();
            total_tiempo_insercion += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Liberando arreglos
            free(arr);
            free(arr_bur);
            free(arr_sel);
            free(arr_ins);
        }

        promedio_bur = calcularPromedio(arr_bur_swaps, 100);
        desviacion_estandar_bur = calcularDesviacionEstandar(arr_bur_swaps, 100, promedio_bur);
        minimo_bur = calcularMin(arr_bur_swaps, 100);
        maximo_bur = calcularMax(arr_bur_swaps, 100);

        promedio_sel = calcularPromedio(arr_sel_swaps, 100);
        desviacion_estandar_sel = calcularDesviacionEstandar(arr_sel_swaps, 100, promedio_sel);
        minimo_sel = calcularMin(arr_sel_swaps, 100);
        maximo_sel = calcularMax(arr_sel_swaps, 100);

        promedio_ins = calcularPromedio(arr_ins_swaps, 100);
        desviacion_estandar_ins = calcularDesviacionEstandar(arr_ins_swaps, 100, promedio_ins);
        minimo_ins = calcularMin(arr_ins_swaps, 100);
        maximo_ins = calcularMax(arr_ins_swaps, 100);

        printf("----------------------------\n");
        printf("Tamano del arreglo: %d\n", size);
        printf("<  Burbuja  >\n");
        printf("> Operaciones Totales: %lld, Swaps Totales: %lld, Tiempo: %.3fs\n", total_operaciones_burbuja, total_swaps_burbuja, total_tiempo_burbuja);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_bur, desviacion_estandar_bur, (int)minimo_bur, (int)maximo_bur);
        printf("----------------------------\n");
        printf("< Seleccion >\n");
        printf("> Operaciones: %lld, Swaps Totales: %lld, Tiempo: %.3fs\n", total_operaciones_seleccion, total_swaps_seleccion, total_tiempo_seleccion);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_sel, desviacion_estandar_sel, (int)minimo_sel, (int)maximo_sel);
        printf("----------------------------\n");
        printf("< Insercion >\n");
        printf("> Operaciones: %lld, Swaps Totales: %lld, Tiempo: %.3fs\n", total_operaciones_insercion, total_swaps_insercion, total_tiempo_insercion);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_ins, desviacion_estandar_ins, (int)minimo_ins, (int)maximo_ins);
        printf("----------------------------\n");
        printf("\n");

        fprintf(file, "%d, Burbuja, %.3fs, %lld, %lld, %.2f, %.2f, %d, %d\n",
                size, total_tiempo_burbuja, total_operaciones_burbuja, total_swaps_burbuja, promedio_bur, desviacion_estandar_bur, (int)minimo_bur, (int)maximo_bur);

        fprintf(file, "%d, Seleccion, %.3fs, %lld, %lld, %.2f, %.2f, %d, %d\n",
                size, total_tiempo_seleccion, total_operaciones_seleccion, total_swaps_seleccion, promedio_sel, desviacion_estandar_sel, (int)minimo_sel, (int)maximo_sel);

        fprintf(file, "%d, Insercion, %.3fs, %lld, %lld, %.2f, %.2f, %d, %d\n",
                size, total_tiempo_insercion, total_operaciones_insercion, total_swaps_insercion, promedio_ins, desviacion_estandar_ins, (int)minimo_ins, (int)maximo_ins);
    }
    fclose(file);
    return 0;
}
#pragma clang diagnostic pop