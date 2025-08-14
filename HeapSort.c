#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "heapsort.h"

// troca o conteúdo de duas posições do vetor
static void trocar(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

// ajusta o heap a partir de um índice para manter a propriedade de max heap
static void ajustarHeap(int vetor[], int tamanho, int indice) {
    int maior = indice;
    int filhoEsq = 2 * indice + 1;
    int filhoDir = 2 * indice + 2;

    // verifica se o filho da esquerda é maior que o pai
    if (filhoEsq < tamanho && vetor[filhoEsq] > vetor[maior]) {
        maior = filhoEsq;
    }

    // verifica se o filho da direita é maior que o atual maior
    if (filhoDir < tamanho && vetor[filhoDir] > vetor[maior]) {
        maior = filhoDir;
    }

    // se algum filho for maior que o pai, troca e continua ajustando
    if (maior != indice) {
        trocar(&vetor[indice], &vetor[maior]);
        ajustarHeap(vetor, tamanho, maior);
    }
}

// constrói o max heap a partir do vetor
static void criarMaxHeap(int vetor[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        ajustarHeap(vetor, tamanho, i);
    }
}

// implementação do algoritmo Heap Sort
void heapSort(int vetor[], int tamanho) {
    criarMaxHeap(vetor, tamanho);

    for (int i = tamanho - 1; i > 0; i--) {
        trocar(&vetor[0], &vetor[i]);
        ajustarHeap(vetor, i, 0);
    }
}

// exibe os elementos de um vetor
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
