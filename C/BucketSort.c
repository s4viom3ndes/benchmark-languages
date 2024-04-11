#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Average complexity: O(n+k)
// Worst case complexity: O(n^2)

void bucketSort(int* array, int arraySize) {
    int i, j;
    int* buckets = malloc(arraySize * sizeof(int));
    if (buckets == NULL) {
        perror("Erro ao alocar memoria");
        return;
    }

    for (i = 0; i < arraySize; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < arraySize; i++) {
        (buckets[array[i]])++;
    }

    for (i = 0, j = 0; i < arraySize; i++) {
        for (; buckets[i] > 0; (buckets[i])--) {
            array[j++] = i;
        }
    }

    free(buckets);
}

int main() {
    FILE *arquivo;
    int* vetor = malloc(MAX * sizeof(int));
    int tamanho = 0;
    clock_t executionTime;
    if (vetor == NULL) {
        perror("Erro ao alocar memoria");
        return 0;
    }

    arquivo = fopen("../../Dataset/dataset_non_ascending.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while (!feof(arquivo) && tamanho < MAX) {
        fscanf(arquivo, "%d", &vetor[tamanho]);
        tamanho++;
    }

    fclose(arquivo);

    executionTime = clock();
    bucketSort(vetor, tamanho);
    executionTime = clock() - executionTime;
    printf("Tempo de execucao: %lf ms\n", ((double)executionTime) / ((CLOCKS_PER_SEC / 1000)));

    free(vetor);
    return 0;
}