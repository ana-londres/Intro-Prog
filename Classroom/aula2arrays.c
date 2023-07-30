#include <stdio.h>

double MediaArray (int ar[], int t);

int EmArray (int ar[], int t, int elem);

int MaximoValorArray (int ar[], int t);

int EhArrayOrdenado (int ar[], int t);

int main(){
    /* 1ª PARTE: USANDO VALORES FIXOS
    int ar[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, sum = 0;
    */

    int ar[10];
    int i, sum = 0, elem, presente, maior;
    double media;

    // 2ª PARTE: SOLICITANDO OS VALORES
    printf("Digite 10 valores para o array: ");
    for (i = 0; i < 10; i++){
        scanf("%d", &ar[i]);
    }

    printf("Crescente: ");
    for (i = 0; i < 10; i++){
        printf("%d ", ar[i]);
    }

    printf("\n\n");

    printf("Descrescente: ");
    for (i = 9; i >= 0; i--){
        printf("%d ", ar[i]);
    }

    printf("\n\n");

    printf("O quinto elemento do array eh: %d", ar[4]);

    printf("\n\n");

    for (i = 0; i < 10; i++){
        if (ar[i] % 2 == 1)
            printf("%d ", ar[i]);
    }

    printf("\n\n");

    for (i = 0; i < 10; i++){
        sum += ar[i];
    }
    printf("A soma dos valores eh: %d", sum);

    printf("\n\n");

    // 3ª PARTE: FUNÇÃO "MEDIA ARRAY"
    media = MediaArray(ar, 10);
    printf("A media dos valores do array eh: %.2lf", media);

    printf("\n\n");

    // 4ª PARTE: FUNÇÃO "EM ARRAY"
    printf("Digite um valor para ver se ele esta no array: ");
    scanf("%d", &elem);

    presente = EmArray(ar, 10, elem);

    if (presente == 1){
        printf("O valor esta presente no array\n");
    }else{
        printf("O valor NAO esta presente no array\n");
    }

    printf("\n\n");

    // 5ª PARTE: FUNÇÃO "MAXIMO VALOR ARRAY"
    maior = MaximoValorArray(ar, 10);
    printf("O maior valor do array eh: %d", maior);

    printf("\n\n");

    // 6ª PARTE: FUNÇÃO "É ARRAY ORDENADO"
    if (EhArrayOrdenado(ar, 10)){
        printf("Array esta ordenado\n");
    }else{
        printf("Array NAO esta ordenado\n");
    }

      switch(EhArrayOrdenado(ar, 10)){
        case -1:
            puts("Array na ordem decrescente");
            break;
        case 0:
            puts("Array NAO esta ordenado");
            break;
        case 1:
            puts("Array na ordem crescente");
            break;
      }

    return 0;
}


// 3ª PARTE: FUNÇÃO "MEDIA ARRAY"
double MediaArray (int ar[], int t){
    double sum = 0;
    int i;

    for (i = 0; i < t; i++){
        sum += ar[i];
    }

    return sum/t;
}

// 4ª PARTE: FUNÇÃO "EM ARRAY"
int EmArray (int ar[], int t, int elem){
    int i;

    for (i = 0; i < t; i++){
        if (elem == ar[i]){
            return 1;
        }
    }

    return 0;
}

// 5ª PARTE: FUNÇÃO "MAXIMO VALOR ARRAY"
int MaximoValorArray (int ar[], int t){
    int i, maior = -1;

    for (i = 0; i < t; i++){
        if (maior < ar[i]){
            maior = ar[i];
        }
    }

    return maior;
}

// 6ª PARTE: FUNÇÃO "É ARRAY ORDENADO"
int EhArrayOrdenado (int ar[], int t){
    int i, ord;

    ord = 1;
    for (i = 1; i < t; i++){
        if (ar[i] <= ar[i-1])
          ord = 0;
    }

    if (ord)
        return 1;

    ord = 1;
    for (i = 1; i < t; i++){
        if (ar[i] >= ar[i-1])
          ord = 0;
    }

    if (ord)
        return -1;

      return 0;
}