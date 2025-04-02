#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void MediaNotas() {
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
    float raio, area;
    float pi = 3.14;

    printf("Digite um raio para calcular a area de um circulo: ");
    scanf("%f", &raio);

    area = pi * (raio*raio);

    printf("Area do circulo eh: %.2f\n", area);
}

void NumeroAzulejo () {
    float altParede, altAzulejo, largParede, largAzulejo, areaParede, areaAzulejo, numAzulejos;

    printf("Digite a altura da parede: ");
    scanf("%f", &altParede);
    printf("Digite a largura da parede: ");
    scanf("%f", &largParede);
    printf("Digite a altura do azulejo: ");
    scanf("%f", &altAzulejo);
    printf("Digite a largura do azulejo: ");
    scanf("%f", &largAzulejo);

    areaParede = altParede * largParede;
    areaAzulejo = (altAzulejo/100) * (largAzulejo/100); // Convertendo para m²
    printf("Area da parede eh: %.2f\n", areaParede);
    printf("Area do azulejo eh: %.2f\n", areaAzulejo);

    numAzulejos = areaParede / areaAzulejo;
    printf("Voce precisara de %.2f azulejos para cobrir a parede\n", numAzulejos);
}

int main()
{
    //* Exercicio 1: Calcular a media de 3 notas
    MediaNotas();
    //* Exercicio 2: Calcular a area de um circulo
    AreaCirculo();
    //* Exercicio 3: Calcular a area de uma parede e quantos azulejos sao necessarios para cobri-la
    NumeroAzulejo();


    return 0;
}
