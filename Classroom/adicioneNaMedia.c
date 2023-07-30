#include <stdio.h>

double AdicioneNaMedia(double valor){
    static float soma;
    static float nValores;

    nValores ++;
    soma = soma + valor;

    return soma / nValores;
}

int main(){
    int n, i;
    float valor, media;

    printf("Quantos valores voce quer inserir? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        printf("\nInsira um valor ");
        scanf("%f", &valor);
        media = AdicioneNaMedia(valor);
        printf("A media atual eh %.2f", media);
    }

    return 0;
}