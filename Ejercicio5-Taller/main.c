#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

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

// Function to insert a new node at the beginning of the linked list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

struct Node* generateLista(int n) {
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int randomNumber = (rand() % 1000) + 1;  // Generate a random number between 1 and 1000
        push(&head, randomNumber);
    }
    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to clone a linked list
struct Node* duplicarLista(struct Node* head) {
    if (head == NULL)
        return NULL;

    // Create a new head node for the cloned list
    struct Node* clonedHead = (struct Node*)malloc(sizeof(struct Node));
    clonedHead->data = head->data;
    clonedHead->next = NULL;

    struct Node* current = head;
    struct Node* clonedCurrent = clonedHead;

    // Copy remaining nodes of the original list to the cloned list
    while (current->next != NULL) {
        current = current->next;

        // Create a new node for the cloned list
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;

        clonedCurrent->next = newNode;
        clonedCurrent = clonedCurrent->next;
    }

    return clonedHead;
}

// Bubble sort for linked list
int bubbleSort(struct Node* start) {
    int ops = 0;
    int swapped;
    struct Node* ptr;
    struct Node* lptr = NULL;

    if (start == NULL)
        return 0;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                ops++;
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
    return ops;
}

int sortedInsert(struct Node** headRef, struct Node* newNode) {
    struct Node* current;
    int ops = 0;
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
            ops++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return ops;
}

// Insertion sort for linked list
int insertionSort(struct Node** headRef) {
    int ops = 0;
    struct Node* sorted = NULL;
    struct Node* current = *headRef;

    while (current != NULL) {
        struct Node* next = current->next;
        ops += sortedInsert(&sorted, current);
        current = next;
    }

    *headRef = sorted;
    return ops;
}

// Selection sort for linked list
int selectionSort(struct Node* head) {
    int ops = 0;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* minNode = current;
        struct Node* temp = current->next;

        while (temp != NULL) {
            if (temp->data < minNode->data) {
                minNode = temp;
                ops++;
            }
            temp = temp->next;
        }

        int tempData = current->data;
        current->data = minNode->data;
        minNode->data = tempData;

        current = current->next;
    }
    return ops;
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
            struct Node* base = generateLista(size);
            struct Node* lis_bur = duplicarLista(base);
            struct Node* lis_sel = duplicarLista(base);
            struct Node* lis_ins = duplicarLista(base);

            clock_t start_t, end_t;

            // Burbuja
            start_t = clock();
            ops = bubbleSort(lis_bur);
            arr_bur_ops[j] = ops;
            total_operaciones_burbuja += ops;
            end_t = clock();
            total_tiempo_burbuja += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Selección
            start_t = clock();
            ops = selectionSort(lis_sel);
            arr_sel_ops[j] = ops;
            total_operaciones_seleccion += ops;
            end_t = clock();
            total_tiempo_seleccion += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Inserción
            start_t = clock();
            ops = insertionSort(&lis_ins);
            arr_ins_ops[j] = ops;
            total_operaciones_insercion += ops;
            end_t = clock();
            total_tiempo_insercion += (double) (end_t-start_t) / CLOCKS_PER_SEC;

            // Liberando arreglos
            free(base);
            free(lis_bur);
            free(lis_sel);
            free(lis_ins);
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
