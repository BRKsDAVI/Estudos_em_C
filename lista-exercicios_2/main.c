#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numLidos() {
    int num[6], count = 0;
    printf("Digite 6 numeros inteiros:\n");
    for (int i = 0; i < 6; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &num[i]);
        if (num[i] > 0) {
            count++;
        }
    };

    printf("Os numeros digitados foram: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", num[i]);
    }
}

void palavrasInverso() {
    char palavras[3][20];

    printf("Digite 3 palavras:\n");
    for (int i = 0; i < 3; i++) {
        printf("Digite a %d palavra: ", i + 1);
        scanf("%s", palavras[i]);
    }
    printf("______________________________\n");
    printf("As palavras digitadas em ordem inversa:\n");
    for (int i = 2; i >= 0; i--) {
        printf("Palavra %d: %s\n", i + 1, palavras[i]);
    }   
}

void quadradoVetor() {
    float vetor[10], quadrado[10];
    int i;
    printf("Digite 10 numeros reais:\n");
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%f", &vetor[i]);
        quadrado[i] = vetor[i] * vetor[i];
    }

    printf("______________________________\n");

    printf("O vetor eh: ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", vetor[i]);
    }
    printf("\nO quadrado do vetor eh: ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", quadrado[i]);
    }
}

void quantosPares() {
    int vetor[10], i, pares = 0, numPares[10];
    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0) {
            numPares[pares] = vetor[i];
            pares++;
        }
    }

    printf("______________________________\n");
    printf("Os numeros digitados foram: ");
    
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nA quantidade de numeros pares eh: %d\n", pares);
    printf("Os numeros pares digitados foram: ");
    
    for (i = 0; i < pares; i++) {
        printf("%d ", numPares[i]);
    }
}

void maiorMEnor() {
    int vetor[10], i, maior = 0, menor = 0;
    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        } else {
            menor = vetor[i];
        }
    }

    printf("______________________________\n");
    printf("Os numeros digitados foram: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\nO maior numero eh: %d\n", maior);
    printf("O menor numero eh: %d\n", menor);
}

void posicaoMaior() {
    int vetor[10], i, maior = 0, posicao = 0;
    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("______________________________\n");
    printf("Os numeros digitados foram: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\nO maior numero eh: %d\n", maior);
    printf("A posicao do maior numero eh: %d\n", posicao);
}

void mediaGeral() {
    int  i;
    float vetor[15], media = 0;
    printf("Digite 15 notas dos alunos:\n");
    for (i = 0; i < 15; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &vetor[i]);
        media += vetor[i];
    }
    media /= 15;

    printf("______________________________\n");
    printf("As notas digitadas foram: ");
    for (i = 0; i < 15; i++) {
        printf("%.2f ", vetor[i]);
    }
    
    printf("\nA media geral da sala eh: %.2f\n", media);
}

int main() {
    int opcao;
    do {
        printf("\n_______________//_______________\n");
        printf("Menu de Opcoes\n");
        printf("selecione uma opcao de 1 a 20 (0 para sair):\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("_______________//_______________\n");
                printf("Opcao 1 selecionada\n");
                printf("________________________________\n");
                numLidos();
                break;
            case 2:
                printf("_______________//_______________\n");
                printf("Opcao 2 selecionada\n");
                printf("________________________________\n");
                palavrasInverso();
                break;
            case 3:
                printf("_______________//_______________\n");
                printf("Opcao 3 selecionada\n");
                printf("________________________________\n");
                quadradoVetor();
                break;
            case 4:
                printf("_______________//_______________\n");
                printf("Opcao 4 selecionada\n");
                printf("________________________________\n");
                quantosPares();
                break;
            case 5:
                printf("_______________//_______________\n");
                printf("Opcao 5 selecionada\n");
                printf("________________________________\n");
                maiorMEnor();
                break;
            case 6:
                printf("_______________//_______________\n");
                printf("Opcao 6 selecionada\n");
                printf("________________________________\n");
                posicaoMaior();
                break;
            case 7:
                printf("_______________//_______________\n");
                printf("Opcao 7 selecionada\n");
                printf("________________________________\n");
                mediaGeral();
                break;
            case 8:
                printf("_______________//_______________\n");
                printf("Opcao 8 selecionada\n");
                printf("________________________________\n");
                break;
            case 9:
                printf("_______________//_______________\n");
                printf("Opcao 9 selecionada\n");
                printf("________________________________\n");
                break;
            case 10:
                printf("_______________//_______________\n");
                printf("Opcao 10 selecionada\n");
                printf("________________________________\n");
                break;
            case 11:
                printf("_______________//_______________\n");
                printf("Opcao 11 selecionada\n");
                printf("________________________________\n");
                break;
            case 12:
                printf("_______________//_______________\n");
                printf("Opcao 12 selecionada\n");
                printf("________________________________\n");
                break;
            case 13:
                printf("_______________//_______________\n");
                printf("Opcao 13 selecionada\n");
                printf("________________________________\n");
                break;
            case 14:
                printf("_______________//_______________\n");
                printf("Opcao 14 selecionada\n");
                printf("________________________________\n");
                break;
            case 15:
                printf("_______________//_______________\n");
                printf("Opcao 15 selecionada\n");
                printf("________________________________\n");
                break;
            case 16:
                printf("_______________//_______________\n");
                printf("Opcao 16 selecionada\n");
                printf("________________________________\n");
                break;
            case 17:
                printf("_______________//_______________\n");
                printf("Opcao 17 selecionada\n");
                printf("________________________________\n");
                break;
            case 18:
                printf("_______________//_______________\n");
                printf("Opcao 18 selecionada\n");
                printf("________________________________\n");
                break;
            case 19:
                printf("_______________//_______________\n");
                printf("Opcao 19 selecionada\n");
                printf("________________________________\n");
                break;
            case 20:
                printf("_______________//_______________\n");
                printf("Opcao 20 selecionada\n");
                printf("________________________________\n");
                break;
            case 0:
                printf("_______________//_______________\n");
                printf("Opcao 0 selecionada\n");
                printf("Saindo do programa...\n");
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida, tente novamente.\n");
                }
        }
    } while (opcao != 0);
    
    return 0;
}