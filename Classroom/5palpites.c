#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, correto, contagem;

	srand(time(NULL));
	correto = 4;

	palpite = -1;
	contagem = 0;
	while (palpite != correto && contagem < 5) {
        printf("Adivinhe o numero: ");
        scanf("%d", &palpite);
        contagem = contagem + 1;
        printf("Voce tentou %d vezes\n", contagem);

            if (palpite > correto){
                puts("Palpite alto!\n");
            }else if (palpite < correto){
                puts("Palpite foi baixo!\n");
            }
	}

    if (palpite == correto){
        puts("Voce acertou!");
    }else{
        puts("Acabaram as suas tentativas");
    }

	return 0;
}