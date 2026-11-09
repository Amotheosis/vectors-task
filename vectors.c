#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 3
#define NUM_VECTORS 6

double dot_product(double *v1, double *v2, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

int main() {
    srand(time(NULL));
    
    double vectors[NUM_VECTORS][VECTOR_SIZE];
    
    printf("Сгенерированные векторы:\n");
    for (int i = 0; i < NUM_VECTORS; i++) {
        printf("Вектор %d: [", i + 1);
        for (int j = 0; j < VECTOR_SIZE; j++) {
            vectors[i][j] = (double)(rand() % 100) / 10.0;
            printf("%.1f", vectors[i][j]);
            if (j < VECTOR_SIZE - 1) printf(", ");
        }
        printf("]\n");
    }
    
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    fprintf(file, "Сгенерированные векторы:\n");
    for (int i = 0; i < NUM_VECTORS; i++) {
        fprintf(file, "Вектор %d: [", i + 1);
        for (int j = 0; j < VECTOR_SIZE; j++) {
            fprintf(file, "%.1f", vectors[i][j]);
            if (j < VECTOR_SIZE - 1) fprintf(file, ", ");
        }
        fprintf(file, "]\n");
    }
    
    fprintf(file, "\nПопарные скалярные произведения:\n");
    printf("\nПопарные скалярные произведения:\n");
    
    for (int i = 0; i < NUM_VECTORS; i++) {
        for (int j = i + 1; j < NUM_VECTORS; j++) {
            double result = dot_product(vectors[i], vectors[j], VECTOR_SIZE);
            printf("Вектор %d . Вектор %d = %.2f\n", i + 1, j + 1, result);
            fprintf(file, "Вектор %d . Вектор %d = %.2f\n", i + 1, j + 1, result);
        }
    }
    
    fclose(file);
    printf("\nРезультаты записаны в файл results.txt\n");
    
    return 0;
}