#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, matriz[5][2];

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 2; j++) {
            printf("Digite o valor da linha %d e coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n_______________Matriz_______________\n");
    printf("\n");
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n_______________Vetor_______________\n");
    printf("\n");

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        
    }

    return 0;
}