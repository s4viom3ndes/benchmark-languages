#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Average complexity: O(nlog(n))
// Worst complexity: O(nlog(n))

void merge(int* array, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftArray = malloc(leftSize * sizeof(int));
    int* rightArray = malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = array[middle + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            array[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            array[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize) {
        array[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize) {
        array[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
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
    mergeSort(vetor, 0, tamanho - 1);
    executionTime = clock() - executionTime;
    printf("Tempo de execucao: %lf ms\n", ((double)executionTime) / ((CLOCKS_PER_SEC / 1000)));

    free(vetor);
    return 0;
}