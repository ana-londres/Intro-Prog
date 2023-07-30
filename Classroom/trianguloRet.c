#include <stdio.h>
#include <math.h>

float EhTrianguloRetangulo (float a, float b, float c){
    if ((a * a) + (b * b) == (c * c))
        return 1;
    else
        return 0;
}

float FormaTrianguloRetangulo (float a, float b, float c){
    if (a <= 0 && b <= 0 || a <= 0 && c <= 0 || b <= 0 && c <= 0){
        return -1;
    }
    if (a <= 0){
        a = sqrt ((c * c) - (b * b));
        return a;
    }
    if (b <= 0){
        b = sqrt ((c * c) - (a * a));
        return b;
    }
    if (c <= 0){
        c = sqrt ((a * a) + (b * b));
        return c;
    }
}

int main (){
    int triangulo;
    float a, b, c, lado;

    printf("Insira os valores de a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0){
        triangulo = EhTrianguloRetangulo(a, b, c);
        if (triangulo == 1)
            printf("Formam um triangulo retangulo\n");
        else
            printf("Nao formam um triangulo retangulo\n");
    }

    if (a <= 0 || b <= 0 || c <= 0){
        lado = FormaTrianguloRetangulo(a, b, c);
        if (lado == -1){
            printf("Entrada eh invalida");
        }else{
            printf("O novo valor do lado invalido deve ser: %.2f\n", lado);
        }
    }

    return 0;
}