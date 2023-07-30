#include <stdio.h>
#include <math.h>

float Delta (float a, float b, float c){
    float delta;
    delta = (b * b) - (4 * a * c);
    return delta;
}

float RaizX1 (float a, float b, float delta){
    return (-b + sqrt(delta)) / (2 * a);
}

float RaizX2 (float a, float b, float c){
    float delta;
    delta = Delta (a, b ,c);
    return (-b - sqrt(delta)) / (2 * a);
}

int main (){
    float a, b, c, delta, x1, x2;

    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    if (a == 0){
        printf("A equacao nao eh do segundo grau\n");
        return 1;
    }

    delta = Delta(a, b ,c);

    if (delta < 0){
        printf("Raizes nao podem ser calculadas\n");
        return 2;
    }

    x1 = RaizX1 (a, b, delta);
    x2 = RaizX2 (a, b, c);

    if (delta == 0){
        printf("A equacao so possui uma raiz: x1 = x2 = %.1f", x1);
    }else{
        printf("As raizes da equacao sao: %.1f e %.1f", x1, x2);
    }

    return 0;
}