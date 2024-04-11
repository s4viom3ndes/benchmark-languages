#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Average complexity: O(n^2)
// Worst case complexity: O(n^2)

int main() {
    FILE *arquivo;
    int* array = malloc(MAX * sizeof(int));
    int arraySize = 0;
    clock_t executionTime;
    if (array == NULL) {
        perror("Erro ao alocar memoria");
        return 0;
    }

    arquivo = fopen("../../Dataset/dataset_95_sorted.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while (!feof(arquivo) && arraySize < MAX) {
        fscanf(arquivo, "%d", &array[arraySize]);
        arraySize++;
    }

    fclose(arquivo);

    executionTime = clock();
    executionTime = clock();
    int currentIndex, currentValue;
    for (int sortedIndex = 1; sortedIndex < arraySize; sortedIndex++) {
        currentIndex = sortedIndex - 1;
        currentValue = array[sortedIndex];
    
        while (currentIndex >= 0 && currentValue < array[currentIndex]) {
            array[currentIndex + 1] = array[currentIndex];
            currentIndex--;
        }
        array[currentIndex + 1] = currentValue;
    }

    executionTime = clock() - executionTime;
    printf("Tempo de execucao: %lf ms\n", ((double)executionTime) / ((CLOCKS_PER_SEC / 1000)));
    
    free(array);
    return 0;
}