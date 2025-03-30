#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Media() {
    float num1, num2, num3, media;
    printf("Insira as 3 notas para calcualar uma media: ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    media = (num1 + num2 + num3)/3;

    printf("Sua media eh de %.2f\n", media);
}

void Area () {
    float raio, area;
    float pi = 3.14;

    printf("Digite um raio para calcular a area de um circulo: ");
    scanf("%f", &raio);

    area = pi * (raio*raio);

    printf("Area do circulo eh: %.2f", area);
}

void areaParede () {
    float altParede, altAzulegio, largParede, largAzulegio;
}

int main()
{
    Media();
    Area();


    return 0;
}
