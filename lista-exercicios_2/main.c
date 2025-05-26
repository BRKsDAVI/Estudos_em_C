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

void negativosEPositivos() {
    float vetor[10], somaPositivos = 0;
    int negativos = 0;
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%f", &vetor[i]);
        if (vetor[i] < 0) {
            negativos++;
        } else {
            somaPositivos += vetor[i];
        }
    }
    printf("Quantidade de numeros negativos: %d\n", negativos);
    printf("Soma dos numeros positivos: %.2f\n", somaPositivos);
}

void posicaoMaiorMenor() {
    int vetor[5], i, posMaior = 0, posMenor = 0;

    printf("Digite 5 valores inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 1; i < 5; i++) {
        if (vetor[i] > vetor[posMaior]) {
            posMaior = i;
        }
        if (vetor[i] < vetor[posMenor]) {
            posMenor = i;
        }
    }
    printf("______________________________\n");
    printf("O maior valor esta na posicao: %d\n", posMaior);
    printf("O menor valor esta na posicao: %d\n", posMenor);
}

void zeraNegativos() {
    int vetor[10];
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
        if (vetor[i] < 0) {
            vetor[i] = 0;
        }
    }
    printf("______________________________\n");
    printf("Vetor resultante:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
}

void vetorCodigo() {
    float vetor[5];
    int codigo, i;

    printf("Digite 5 numeros reais:\n");
    for (i = 0; i < 5; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    printf("Digite o codigo (0 para sair, 1 para ordem direta, 2 para ordem inversa): ");
    scanf("%d", &codigo);

    if (codigo == 0) {
        printf("Programa finalizado pelo usuario.\n");
        return;
    } else if (codigo == 1) {
        printf("Vetor na ordem direta:\n");
        for (i = 0; i < 5; i++) {
            printf("%.2f ", vetor[i]);
        }
        printf("\n");
    } else if (codigo == 2) {
        printf("Vetor na ordem inversa:\n");
        for (i = 4; i >= 0; i--) {
            printf("%.2f ", vetor[i]);
        }
        printf("\n");
    } else {
        printf("Codigo invalido!\n");
    }
}

void contaMaioresQueDez() {
    int matriz[4][4];
    int i, j, cont = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > 10) {
                cont++;
            }
        }
    }
    printf("Quantidade de valores maiores que 10: %d\n", cont);
}

void matrizDiagonalPrincipal() {
    int matriz[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    printf("Matriz 5x5 com 1 na diagonal principal e 0 nos demais:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void maiorValorMatriz() {
    int matriz[4][4];
    int i, j, maior, linhaMaior = 0, colunaMaior = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0) {
                maior = matriz[i][j];
            } else if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("Matriz digitada:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("O maior valor eh %d e esta na linha %d e coluna %d.\n", maior, linhaMaior, colunaMaior);
}

void buscaValorMatriz() {
    int matriz[5][5];
    int i, j, x, encontrado = 0;

    printf("Digite os elementos da matriz 5x5:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor X para buscar na matriz: ");
    scanf("%d", &x);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matriz[i][j] == x) {
                printf("Valor %d encontrado na linha %d e coluna %d.\n", x, i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Valor %d nao encontrado na matriz.\n", x);
    }
}

void maiorValorMatriz4x4() {
    int matriz1[4][4], matriz2[4][4], matriz3[4][4];
    int i, j;
    printf("Digite os elementos da matriz 1 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da matriz 2 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    printf("Resultado dos maiores elementos de cada matriz:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (matriz1[i][j] > matriz2[i][j]) {
                matriz3[i][j] = matriz1[i][j];
            } else {
                matriz3[i][j] = matriz2[i][j];
            }
        }
    }

    printf("Matriz resultante:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }
}

void somaDiagonalMatriz() {
    int matriz[3][3];
    int i, j, soma = 0;

    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("A soma dos elementos da diagonal principal eh: %d\n", soma);
}

void matrizTriangularInferior() {
    int matriz[4][4];
    int i, j;

    printf("Digite os elementos da matriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz triangular inferior:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i >= j) {
                printf("%d ", matriz[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void notasAlunos() {
    int alunos[5][4];
    int i, maiorNota = -1, indiceMaior = 0;
    float somaNotas = 0;

    printf("Digite os dados dos 5 alunos:\n");
    for (i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Numero de matricula: ");
        scanf("%d", &alunos[i][0]);
        printf("Media das provas: ");
        scanf("%d", &alunos[i][1]);
        printf("Media dos trabalhos: ");
        scanf("%d", &alunos[i][2]);
        // Calcula nota final
        alunos[i][3] = alunos[i][1] + alunos[i][2];
        somaNotas += alunos[i][3];
        // Verifica maior nota final
        if (alunos[i][3] > maiorNota) {
            maiorNota = alunos[i][3];
            indiceMaior = i;
        }
    }

    

    printf("\nMatricula do aluno com maior nota final: %d\n", alunos[indiceMaior][0]);
    printf("Media aritmetica das notas finais: %.2f\n", somaNotas / 5.0);
}

void corrigeProva() {
    char gabarito[10];
    char respostas[10];
    int i, nota = 0;

    printf("Digite o gabarito da prova (10 letras - a, b, c ou d):\n");
    for (i = 0; i < 10; i++) {
        printf("Questao %d: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    printf("\nDigite as respostas do aluno (10 letras - a, b, c ou d):\n");
    for (i = 0; i < 10; i++) {
        printf("Resposta da questao %d: ", i + 1);
        scanf(" %c", &respostas[i]);
        if (respostas[i] == gabarito[i]) {
            nota++;
        }
    }

    printf("\nNota do aluno: %d\n", nota);
    if (nota >= 7) {
        printf("Aluno aprovado!\n");
    } else {
        printf("Aluno reprovado.\n");
    }
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
                negativosEPositivos();
                break;
            case 9:
                printf("_______________//_______________\n");
                printf("Opcao 9 selecionada\n");
                printf("________________________________\n");
                posicaoMaiorMenor();
                break;
            case 10:
                printf("_______________//_______________\n");
                printf("Opcao 10 selecionada\n");
                printf("________________________________\n");
                zeraNegativos();
                break;
            case 11:
                printf("_______________//_______________\n");
                printf("Opcao 11 selecionada\n");
                printf("________________________________\n");
                vetorCodigo();
                break;
            case 12:
                printf("_______________//_______________\n");
                printf("Opcao 12 selecionada\n");
                printf("________________________________\n");
                contaMaioresQueDez();
                break;
            case 13:
                printf("_______________//_______________\n");
                printf("Opcao 13 selecionada\n");
                printf("________________________________\n");
                matrizDiagonalPrincipal();
                break;
            case 14:
                printf("_______________//_______________\n");
                printf("Opcao 14 selecionada\n");
                printf("________________________________\n");
                maiorValorMatriz();
                break;
            case 15:
                printf("_______________//_______________\n");
                printf("Opcao 15 selecionada\n");
                printf("________________________________\n");
                buscaValorMatriz();
                break;
            case 16:
                printf("_______________//_______________\n");
                printf("Opcao 16 selecionada\n");
                printf("________________________________\n");
                maiorValorMatriz4x4();
                break;
            case 17:
                printf("_______________//_______________\n");
                printf("Opcao 17 selecionada\n");
                printf("________________________________\n");
                somaDiagonalMatriz();
                break;
            case 18:
                printf("_______________//_______________\n");
                printf("Opcao 18 selecionada\n");
                printf("________________________________\n");
                matrizTriangularInferior();
                break;
            case 19:
                printf("_______________//_______________\n");
                printf("Opcao 19 selecionada\n");
                printf("________________________________\n");
                notasAlunos();
                break;
            case 20:
                printf("_______________//_______________\n");
                printf("Opcao 20 selecionada\n");
                printf("________________________________\n");
                corrigeProva();
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