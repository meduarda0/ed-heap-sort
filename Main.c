#include <stdio.h>
#include <windows.h>
#include "heapsort.h"

int main(void) {
    // configuração do console para aceitar UTF-8 no Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int qtd;

    printf("Informe a quantidade de elementos: ");
    if (scanf("%d", &qtd) != 1 || qtd <= 0) {
        printf("Valor inválido!\n");
        return 1;
    }

    int numeros[qtd];

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    heapSort(numeros, qtd);

    printf("Vetor ordenado: ");
    exibirVetor(numeros, qtd);
    return 0;
}
