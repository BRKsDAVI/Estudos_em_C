#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    float saldo = 1000.00, valorDeposito, valorSaque, transferencia;
    do {
        printf("Menu:\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar\n");
        printf("3. Saque\n");
        printf("4. Transferir\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Seu saldo atual eh: R$ %.2f\n", saldo);
                break;
            case 2:
                printf("Digite o valor a ser depositado: R$ ");
                scanf("%f", &valorDeposito);
                saldo += valorDeposito;
                printf("Deposito realizado com sucesso! Seu novo saldo eh: R$ %.2f\n", saldo);
                break;
            case 3:
                printf("Digite o valor a ser sacado: R$ ");
                scanf("%f", &valorSaque);
                if (valorSaque > saldo) {
                    printf("Saldo insuficiente!\n");
                } else {
                    saldo -= valorSaque;
                    printf("Saque realizado com sucesso! Seu novo saldo eh: R$ %.2f\n", saldo);
                }
                break;
            case 4:
                printf("Digite o valor a ser transferido: R$ ");
                scanf("%f", &transferencia);
                if (transferencia > saldo) {
                    printf("Saldo insuficiente para transferencia!\n");
                } else {
                    saldo -= transferencia;
                    printf("Transferencia realizada com sucesso! Seu novo saldo eh: R$ %.2f\n", saldo);
                }
                break;
            case 5:
                printf("Obrigado por usar o sistema bancario!\n");
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}