#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); 
    int numero_secreto, palpite, tentativas = 0, aleatorio = rand() % 101;
    int numero = aleatorio;
    
    do {
        printf("Adivinhe o número entre 0 e 100: ");
        scanf("%d", &palpite);

        if (palpite == numero) {
            printf("Parabéns! Você adivinhou o número %d em %d tentativas.\n", numero, tentativas + 1);
            break;
        } else if (palpite < numero) {
            printf("O número é maior que %d.\n", palpite);
            tentativas++;
        } else {
            printf("O número é menor que %d.\n", palpite);
            tentativas++;
        }

    }while (tentativas < 5);

    if (tentativas == 5) {
        printf("Você não adivinhou o número. O número era %d.\n", numero);
    }

    return 0;
}
