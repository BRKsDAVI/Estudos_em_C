#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void MediaNotas() {
    printf("Questao 1: Media de 3 notas\n");
    printf("______________________________________\n");
    float num1, num2, num3, media;
    printf("Insira a primeira nota: ");
    scanf("%f", &num1);
    printf("Insira a segunda nota: ");
    scanf("%f", &num2);
    printf("Insira a terceira nota: ");
    scanf("%f", &num3);

    media = (num1 + num2 + num3)/3;

    printf("Sua media eh de %.2f\n", media);
}

void AreaCirculo() {
    printf("Questao 2: Area de um circulo\n");
    printf("______________________________________\n");
    float raio, area;
    float pi = 3.14;

    printf("Digite um raio para calcular a area de um circulo: ");
    scanf("%f", &raio);

    area = pi * (raio*raio);

    printf("Area do circulo eh: %.2f\n", area);
}

void NumeroAzulejo () {
    printf("Questao 3: Numero de azulejos\n");
    printf("______________________________________\n");
    float altParede, altAzulejo, largParede, largAzulejo, areaParede, areaAzulejo, numAzulejos;

    printf("Digite a altura da parede: ");
    scanf("%f", &altParede);
    printf("Digite a comprimento da parede: ");
    scanf("%f", &largParede);
    printf("Digite a altura do azulejo: ");
    scanf("%f", &altAzulejo);
    printf("Digite a cumprimento do azulejo: ");
    scanf("%f", &largAzulejo);

    areaParede = altParede * largParede;
    areaAzulejo = (altAzulejo/100) * (largAzulejo/100); // Convertendo para m²
    printf("Area da parede eh: %.2f\n", areaParede);
    printf("Area do azulejo eh: %.2f\n", areaAzulejo);

    numAzulejos = areaParede / areaAzulejo;
    printf("Voce precisara de %.2f azulejos para cobrir a parede\n", numAzulejos);
}

void CampusParty() {
    printf("Questao 4: Permissao para ir a Campus Party\n");
    printf("______________________________________\n");
    char dinheiro[10], permissao[10];
    printf("Voce tem dinheiro para ir a Campus Party? (sim/nao): ");
    scanf("%s", dinheiro);
    printf("Voce tem permissao dos pais para ir a Campus Party? (sim/nao): ");
    scanf("%s", permissao);

    if (strcmp(dinheiro, "sim") == 0 && strcmp(permissao, "sim") == 0) {
        printf("Voce pode ir a Campus Party!\n");
    } else {
        printf("Voce nao pode ir a Campus Party!\n");
    }
}

void Alistamento() {
    printf("Questao 5: Verificacao se presica se alistar\n");
    printf("______________________________________\n");
    int idade;
    char sexo;
    printf("Digite seu sexo (m para masculino, f para feminino): ");
    scanf("%s", &sexo);
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (sexo == 'm' && idade >= 18) {
        printf("Voce deve se alistar!\n");
    } else if (sexo == 'm' && idade < 18) {
        printf("Voce ainda nao pode se alistar!\n");
    } else {
        printf("Voce nao precisa se alistar!\n");
    }
}

void Numero100a200() {
    printf("Questao 6: Verificacao se o numero esta entre 100 e 200\n");
    printf("______________________________________\n");
    int num;
    printf("Digite um numero entre 0 e 1000: ");
    scanf("%d", &num);

    if (num >= 100 && num <= 200) {
        printf("O numero %d esta entre 100 e 200\n", num);
    } else {
        printf("O numero %d nao esta entre 100 e 200\n", num);
    }
}

void Maioridade() {
    printf("Questao 7: Verificacao se eh maior de idade\n");
    printf("______________________________________\n");
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18) {
        printf("Voce eh maior de idade!\n");
    } else if (idade < 18) {
        printf("Voce eh menor de idade!\n");
    } else {
        printf("Idade invalida!\n");
    }
}

void Iguadade() {
    printf("Questao 8: Verificacao se os numeros sao iguais ou diferentes\n");
    printf("______________________________________\n");
    int num1, num2, num3;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    if (num1 == num2 && num1 == num3) {
        printf("Todos os numeros sao iguais!\n");
    } else if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("Dois numeros sao iguais!\n");
    } else {
        printf("Os numeros sao diferentes!\n");
    }
}

void EmprestimoBancario () {
    printf("Qestao 9: Emprestimo Bancario\n");
    printf("______________________________________\n");
    float salario, valorEmprestimo, numParcelas, valorParcela;

    printf("Digite seu salario: ");
    scanf("%f", &salario);
    printf("Digite o valor do emprestimo: ");
    scanf("%f", &valorEmprestimo);
    printf("Digite o numero de parcelas: ");
    scanf("%f", &numParcelas);

    valorParcela = valorEmprestimo / numParcelas;

    if (valorParcela > (salario * 0.3)) {
        printf("Emprestimo negado!\n");
    } else {
        printf("Emprestimo aprovado!\n");
    }
}

void Aprovado() {
    printf("Questao 10: Verifica se um aluno esta aprovado\n");
    printf("______________________________________\n");
    float nota1, nota2,nota3, nota4, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);
    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    if (media >= 7) {
        printf("Aprovado!\n");
    } else if (media >= 5 && media < 7) {
        printf("Recuperacao!\n");
    } else {
        printf("Reprovado!\n");
    }
}

void Crecente() {
    printf("Questao 11: Organiza os numeros em ordem crescente\n");
    printf("______________________________________\n");
    int num1, num2, num3;

    printf("Digite o primeiro numero: ");  
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    if (num1 < num2 && num1 < num3) {
        printf("%d ", num1);
        if (num2 < num3) {
            printf("%d %d\n", num2, num3);
        } else {
            printf("%d %d\n", num3, num2);
        }
    } else if (num2 < num1 && num2 < num3) {
        printf("%d ", num2);
        if (num1 < num3) {
            printf("%d %d\n", num1, num3);
        } else {
            printf("%d %d\n", num3, num1);
        }
    } else {
        printf("%d ", num3);
        if (num1 < num2) {
            printf("%d %d\n", num1, num2);
        } else {
            printf("%d %d\n", num2, num1);
        }
    }
}

void Fibonacci() {
    printf("Questao 12: Sequencia de Fibonacci\n");
    printf("______________________________________\n");
    int num, i, termo1 = 0, termo2 = 1, proximoTermo = 0;

    printf("Digite o numero de termos: ");
    scanf("%d", &num);

    printf("Sequencia de Fibonacci: %d, %d, ", termo1, termo2);

    for (i = 3; i <= num; ++i) {
        proximoTermo = termo1 + termo2;
        printf("%d, ", proximoTermo);
        termo1 = termo2;
        termo2 = proximoTermo;
    }
}

int main()
{
    int opcao;
    
    while (opcao != 29) {
        printf("\nEscolha uma questao de 1 a 28\n");
        printf("29. Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                MediaNotas();
                break;
            case 2:
                AreaCirculo();
                break;
            case 3:
                NumeroAzulejo();
                break;
            case 4:
                CampusParty();
                break;
            case 5:
                Alistamento();
                break;
            case 6:
                Numero100a200();
                break;
            case 7:
                Maioridade();
                break;
            case 8:
                Iguadade();
                break;
            case 9:
                EmprestimoBancario();
                break;
            case 10:   
                Aprovado();
                break;
            case 11:
                Crecente();
                break;
            case 12:
                Fibonacci();
                break;
            case 13:
                
                break;
            case 14:
                
                break;
            case 15:
                
                break;
            case 16:
                
                break;
            case 17:
                
                break;
            case 18:
                
                break;
            case 19:
                
                break;
            case 20:
                
                break;
            case 21:
                
                break;
            case 22:
                
                break;
            case 23:
                
                break;
            case 24:
                
                break;
            case 25:
                
                break;
            case 26:
                
                break;
            case 27:
                
                break;
            case 28:
                
                break;
            case 29:
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
