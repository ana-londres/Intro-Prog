#include <stdio.h>

int main(){
    int ar[10], n, i;

    scanf("%d", &n);

    ar[0] = n;
    printf("N[0] = %d\n", n);

    for(i = 1; i < 10; i++){
        ar[i] = 2 * ar[i-1];
        printf("N[%d] = %d\n", i, ar[i]);
    }

    return 0;
}