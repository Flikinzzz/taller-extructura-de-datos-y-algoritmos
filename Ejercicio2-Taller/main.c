#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

double calcularPromedio(const double arreglo[], int tamano) {
    double sumatoria = 0;
    for (int i = 0; i < tamano; i++) {
        sumatoria += arreglo[i];
    }
    return sumatoria / tamano;
}

double calcularDesviacionEstandar(double arreglo[], int tamano, double promedio) {
    double sumatoria = 0;
    for (int i = 0; i < tamano; i++) {
        sumatoria += pow(arreglo[i] - promedio, 2);
    }
    double varianza = sumatoria / tamano;
    return sqrt(varianza);
}

double calcularMin(const double arreglo[], int tamano) {
    double min = arreglo[0];
    for (int i = 1; i < tamano; i++) {
        double val = arreglo[i];
        if (val < min)
            min = val;
    }
    return min;
}

double calcularMax(const double arreglo[], int tamano) {
    double max = arreglo[0];
    for (int i = 1; i < tamano; i++) {
        double val = arreglo[i];
        if (val > max)
            max = val;
    }
    return max;
}

// Generates a random array of size n with elements between 1 and 1000
void generar_arreglo(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// Optimized bubble sort
int burbuja(int arr[], int n) {
    int operaciones = 0;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                operaciones++;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
    return operaciones;
}

// Optimized selection sort
int seleccion(int arr[], int n) {
    int operaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
                operaciones++;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    return operaciones;
}

// Optimized insertion sort
int insercion(int arr[], int n) {
    int i, j, key, operaciones = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            operaciones++;
        }
        arr[j + 1] = key;
    }
    return operaciones;
}

int main() {
    srand(time(NULL));
    int sizes[] = {100, 1000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int ops;
        long long total_operaciones_burbuja = 0;
        long long total_operaciones_seleccion = 0;
        long long total_operaciones_insercion = 0;
        double total_tiempo_burbuja = 0;
        double total_tiempo_seleccion = 0;
        double total_tiempo_insercion = 0;

        double promedio_bur, promedio_sel, promedio_ins;
        double desviacion_estandar_bur, desviacion_estandar_sel, desviacion_estandar_ins;
        double maximo_bur, maximo_sel, maximo_ins;
        double minimo_bur, minimo_sel, minimo_ins;

        double arr_bur_ops[100];
        double arr_sel_ops[100];
        double arr_ins_ops[100];

        for (int j = 0; j < 100; j++) {
            int* arr = malloc(size * sizeof(int));
            generar_arreglo(arr, size);

            clock_t start_t, end_t;

            // Burbuja
            int* arr_bur = malloc(size * sizeof(int));
            memcpy(arr_bur, arr, size * sizeof(int));
            start_t = clock();
            ops = burbuja(arr_bur, size);
            arr_bur_ops[j] = ops;
            total_operaciones_burbuja += ops;
            end_t = clock();
            total_tiempo_burbuja += (double)(end_t - start_t) / CLOCKS_PER_SEC;
            free(arr_bur);

            // Selección
            int* arr_sel = malloc(size * sizeof(int));
            memcpy(arr_sel, arr, size * sizeof(int));
            start_t = clock();
            ops = seleccion(arr_sel, size);
            arr_sel_ops[j] = ops;
            total_operaciones_seleccion += ops;
            end_t = clock();
            total_tiempo_seleccion += (double)(end_t - start_t) / CLOCKS_PER_SEC;
            free(arr_sel);

            // Inserción
            int* arr_ins = malloc(size * sizeof(int));
            memcpy(arr_ins, arr, size * sizeof(int));
            start_t = clock();
            ops = insercion(arr_ins, size);
            arr_ins_ops[j] = ops;
            total_operaciones_insercion += ops;
            end_t = clock();
            total_tiempo_insercion += (double)(end_t - start_t) / CLOCKS_PER_SEC;
            free(arr_ins);

            // Liberando arreglos
            free(arr);
        }

        promedio_bur = calcularPromedio(arr_bur_ops, 100);
        desviacion_estandar_bur = calcularDesviacionEstandar(arr_bur_ops, 100, promedio_bur);
        minimo_bur = calcularMin(arr_bur_ops, 100);
        maximo_bur = calcularMax(arr_bur_ops, 100);

        promedio_sel = calcularPromedio(arr_sel_ops, 100);
        desviacion_estandar_sel = calcularDesviacionEstandar(arr_sel_ops, 100, promedio_sel);
        minimo_sel = calcularMin(arr_sel_ops, 100);
        maximo_sel = calcularMax(arr_sel_ops, 100);

        promedio_ins = calcularPromedio(arr_ins_ops, 100);
        desviacion_estandar_ins = calcularDesviacionEstandar(arr_ins_ops, 100, promedio_ins);
        minimo_ins = calcularMin(arr_ins_ops, 100);
        maximo_ins = calcularMax(arr_ins_ops, 100);

        printf("----------------------------\n");
        printf("Tamano del arreglo: %d\n", size);
        printf("<  Burbuja  >\n");
        printf("> Operaciones Totales: %lld, Tiempo: %.3fs\n", total_operaciones_burbuja, total_tiempo_burbuja);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_bur, desviacion_estandar_bur, (int)minimo_bur, (int)maximo_bur);
        printf("----------------------------\n");
        printf("< Seleccion >\n");
        printf("> Operaciones: %lld, Tiempo: %.3fs\n", total_operaciones_seleccion, total_tiempo_seleccion);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_sel, desviacion_estandar_sel, (int)minimo_sel, (int)maximo_sel);
        printf("----------------------------\n");
        printf("< Insercion >\n");
        printf("> Operaciones: %lld, Tiempo: %.3fs\n", total_operaciones_insercion, total_tiempo_insercion);
        printf("> Promedio: %.2f, Desviacion estandar: %.2f, Minimo: %d, Maximo: %d\n", promedio_ins, desviacion_estandar_ins, (int)minimo_ins, (int)maximo_ins);
        printf("----------------------------\n");
        printf("\n");
    }
    return 0;
}
