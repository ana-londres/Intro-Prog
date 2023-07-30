#include <stdio.h>

int main(){
    /*Parte 1: para o array com os valores definidos:

    int ar[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, sum = 0;
    */

    int ar[10];
    int i, sum = 0;
    float media = 0;
    int valor;
    int maior = -1000;

    /*Parte 2: solicitar ao usuario os valores */
    printf("Digite 10 numeros para o array: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &ar[i]);
    }

    printf("Crescente:\n");

    for(i = 0; i < 10; i++){
        printf("%d\n", ar[i]);
    }

    printf("Decrescente:\n");

    for(i = 9; i >= 0; i--){
        printf("%d\n", ar[i]);
    }

    printf("Elemento na quinta posicao: %d\n", ar[4]);

    printf("Impares: \n");

    for(i = 0; i < 10; i++){
        if (ar[i] % 2 != 0)
            printf("%d\n", ar[i]);
    }

    for(i = 0; i < 10; i++){
        sum = sum + ar[i];
    }

    printf("Soma dos valores do array: %d\n", sum);

    /*Parte 3: Calculando a media dos valores */
    for(i = 0; i < 10; i++){
        media = media + ar[i];
    }

    printf("A media dos valores do array: %.2f\n", media/10.0);

    /*Parte 4: posição do valor no array, se presente */
    printf("Digite um valor: ");
    scanf("%d", &valor);

    for(i = 0; i < 10; i++){
        if(valor == ar[i]){
            printf("A posicao do novo valor no array eh: %d\n", i + 1);
        }
    }

    /*Parte 5: instruções pra procurar e informar o valor do maior elemento */
    for(i = 0; i < 10; i++){
        if (maior < ar[i]){
            maior = ar[i];
        }
    }

    printf("Maior elemento eh: %d", maior);

    return 0;
}