#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso,alt,imc;
    char sexo[1];
    char sexM[1] = "m";

    printf("Digite o seu peso: ");
    scanf("%f", &peso);

    printf("Digite a sua altura: ");
    scanf("%f", &alt);

    printf("Qual seu sexo(m/f): ");
    scanf("%s", &sexo);

    imc = peso/(alt*alt);
    printf("seu IMC eh: %.1f\n",imc);


    if(sexo == sexM) {
        if(imc < 20.7) {
            printf("Voce esta abaixo do peso");
        }else if(imc <= 26.4) {
            printf("Voce esta no peso ideal");
        }else if(imc <= 27.8) {
            printf("Voce esta com sobrepeso");
        }else if(imc <= 31.1) {
            printf("Voce esta com obesidade grau I");
        }else if(imc <= 34.9) {
            printf("Voce esta com obesidade grau II");
        }else {
            printf("Voce esta com obesidade grau III");
        }
    } else {
        if(imc < 19.1) {
            printf("Voce esta abaixo do peso");
        }else if(imc <= 25.8) {
            printf("Voce esta no peso ideal");
        }else if(imc <= 27.3) {
            printf("Voce esta com sobrepeso");
        }else if(imc <= 32.3) {
            printf("Voce esta com obesidade grau I");
        }else if(imc <= 34.9) {
            printf("Voce esta com obesidade grau II");
        }else {
            printf("Voce esta com obesidade grau III");
        }
    }
    return 0;
}
