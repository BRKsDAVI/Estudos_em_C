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

void InicialFinal() {
    printf("Questao 13: Numero inicial, final e sequencia \n");
    printf("______________________________________\n");
    int numInicial, numFinal;
    printf("Digite o numero inicial: ");
    scanf("%d", &numInicial);
    printf("Digite o numero final: ");
    scanf("%d", &numFinal); 

    for (int i = numInicial; i <= numFinal; i++) {
        printf("%d ", i);
    }
}

void Tabuada() {
    printf("Questao 14: Tabuada\n");
    printf("______________________________________\n");
    int num, i;
    printf("Digite um numero para ver a tabuada: ");
    scanf("%d", &num);

    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

void Imparar100a200() {
    printf("Questao 15: Numeros impares entre 100 e 200\n");
    printf("______________________________________\n");
    for (int i = 101; i < 200; i += 2) {
        printf("%d ", i);
    }
}

void MediaSala() {
    printf("Questao 16: Media da sala\n");
    printf("______________________________________\n");
    int numAlunos, i;
    float nota1, nota2, media;
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);
    
    for (i = 1; i <= numAlunos; i++) {
        printf("Digite a primeira nota do aluno %d: ", i);
        scanf("%f", &nota1);
        printf("Digite a segunda nota do aluno %d: ", i);
        scanf("%f", &nota2);
        
        media = (nota1 + nota2) / 2;
        printf("A media do aluno %d eh: %.2f\n", i, media);
    }
    
}

void Soma10Numeros() {
    printf("Questao 17: Soma de 10 numeros\n");
    printf("______________________________________\n");
    int num, soma = 0;
    for (int i = 1; i <= 10; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &num);
        soma += num;
    }
    printf("A soma dos numeros eh: %d\n", soma);
}

void SomaTodosNUmeros() {
    printf("Questao 18: Soma de todos os numeros\n");
    printf("______________________________________\n");
    int num, soma = 0;
    printf("Digite um numero (0 para sair): ");
    scanf("%d", &num);

    while (num != 0) {
        soma += num;
        printf("Digite um numero (0 para sair): ");
        scanf("%d", &num);
    }

    printf("A soma dos numeros eh: %d\n", soma);
}

void SomaNumerosPares() {
    printf("Questao 19: Soma de numeros pares\n");
    printf("______________________________________\n");
    int num, soma = 0;
    
    while (num != 0) {
        printf("Digite um numero (0 para sair): ");
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            soma += num;
        }
    } 

    printf("A soma dos numeros pares digitado eh: %d\n", soma);
}

void MaiorMenor() {
    printf("Questao 20: Maior e menor numero\n");
    printf("______________________________________\n");
    int num, maior, menor;
    
    printf("Digite um numero (0 para sair): ");
    scanf("%d", &num);
    
    maior = menor = num;
    
    while (num != 0) {
        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
        
        printf("Digite um numero (0 para sair): ");
        scanf("%d", &num);
    }
    
    printf("O maior numero eh: %d\n", maior);
    printf("O menor numero eh: %d\n", menor);
}

void LerSexo() {
    printf("Questao 21: Ler sexo\n");
    printf("______________________________________\n");
    char sexo;
    printf("Digite seu sexo (m para masculino, f para feminino): ");
    scanf("%s", &sexo);

    if (sexo == 'm') {
        printf("Sexo masculino\n");
    } else if (sexo == 'f') {
        printf("Sexo feminino\n");
    } else {
        printf("Sexo invalido\n");
    }
}

void SomaIntervalo() {
    printf("Questao 22: Soma de numeros em um intervalo\n");
    printf("______________________________________\n");
    int num1, num2, soma = 0;
    
    do {
        printf("Digite o primeiro numero: ");
        scanf("%d", &num1);
        printf("Digite o segundo numero: ");
        scanf("%d", &num2);
        
        if (num1 < 1 || num1 > 100 || num2 < 1 || num2 > 100) {
            printf("Ambos os numeros devem estar no intervalo de 1 a 100. Tente novamente.\n");
        }
    } while (num1 < 1 || num1 > 100 || num2 < 1 || num2 > 100);
    soma = num1 + num2;
    printf("A soma dos numeros %d e %d eh: %d\n", num1, num2, soma);
}

void Fatorial() {
    printf("Questao 23: Calculo do fatorial\n");
    printf("______________________________________\n");
    int num, i;
    long long fatorial = 1;
    
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &num);
    
    for (i = 1; i <= num; i++) {
        fatorial *= i;
    }
    
    printf("O fatorial de %d eh: %lld\n", num, fatorial);
}

void MediaTimeVolei() {
    printf("Questao 24: Media de um time de volei\n");
    printf("______________________________________\n");
    int numJogadores, i;
    float altura, mediaAltura = 0;

    printf("Digite o numero de jogadores: ");
    scanf("%d", &numJogadores);

    for(i = 1; i <= numJogadores; i++) {
        printf("Digite a altura do jogador %d: ", i);
        scanf("%f", &altura);
        mediaAltura += altura;
    }
    
    mediaAltura /= numJogadores;
    printf("A media de altura do time eh: %.2f\n", mediaAltura);
}

void MissVencedora() {
    printf("Questao 25: Miss vencedora\n");
    printf("______________________________________\n");
    int numCandidatas = 16, i, nota, missVencedora = 0;
    char nome[50], nomeVencedora[50];
    float maiorNota = 0;

    if (nota > 10 || nota < 0) {
        printf("Nota invalida! A nota deve ser entre 0 e 10.\n");
    } else {
        for(i = 1; i <= numCandidatas; i++) {
            printf("Digite o nome da candidata %d: ", i);
            scanf("%s", nome);
            printf("Digite a nota da candidata %d: ", i);
            scanf("%d", &nota);

            if (nota > maiorNota) {
                maiorNota = nota;
                missVencedora = i;
                strcpy(nomeVencedora, nome);
            }
        }
        printf("A miss vencedora eh a candidata %s com nota %.2f\n", nomeVencedora, maiorNota);  
    }
    
}

void NumeroPrimo() {
    printf("Questao 26: Verifica se o numero eh primo\n");
    printf("______________________________________\n");
    int num, i, divisivel, primo = 1;

    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if (num < 2) {
        primo = 0;
    } else {
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                primo = 0;
                divisivel = i;
                break;
            }
        }
    }
    if (primo) {
        printf("O numero %d eh primo\n", num);
    } else {
        printf("O numero %d nao eh primo\n ele eh divisivel por %d\n", num, divisivel);
    }
}

void BaseExpoente() {
    printf("Questao 27: Calculo de base e expoente\n");
    printf("______________________________________\n");
    int base, expoente, resultado = 1;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    for (int i = 1; i <= expoente; i++) {
        resultado *= base;
    }
    
    printf("%d elevado a %d eh: %d\n", base, expoente, resultado);
}

void SomaNumerosPrimos() {
    printf("Questao 28: Soma de todos numeros primos de 1 ate 100\n");
    printf("______________________________________\n");
    int num, i, soma = 0, primo = 1;
    for (num = 2; num <= 100; num++) {
        primo = 1;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            soma += num;
        }
    }
    printf("A soma dos numeros primos de 1 a 100 eh: %d\n", soma);
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
                InicialFinal();
                break;
            case 14:
                Tabuada();
                break;
            case 15:
                Imparar100a200();
                break;
            case 16:
                MediaSala();
                break;
            case 17:
                Soma10Numeros();
                break;
            case 18:
                SomaTodosNUmeros();
                break;
            case 19:
                SomaNumerosPares();
                break;
            case 20:
                MaiorMenor();
                break;
            case 21:
                LerSexo();
                break;
            case 22:
                SomaIntervalo();
                break;
            case 23:
                Fatorial();
                break;
            case 24:
                MediaTimeVolei();
                break;
            case 25:
                MissVencedora();
                break;
            case 26:
                NumeroPrimo();
                break;
            case 27:
                BaseExpoente();
                break;
            case 28:
                SomaNumerosPrimos();
                break;
            case 29:
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
