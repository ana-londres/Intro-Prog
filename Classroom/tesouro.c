#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#define MAX_DESCRICAO 51

typedef struct {
    char descricao[MAX_DESCRICAO];
    float valor;
    int x;
    int y;
    }tRegistro;

void ApresentaMensagem() {
    printf("Ola, esse programa ...\n");
}

void ApresentaMenu() {
    printf("\n\n*** Opcoes *** \n"
                "\n1 - Cadastra"
                "\n2 - Imprime"
                "\n3 - Distancia a partir de um ponto"
                "\n5 - Sair\n");
}

tRegistro * CadastroRegistro(tRegistro *reg) {
    printf("Digite a descricao do seu tesouro: ");
    scanf("%s", reg->descricao);
    printf("Digite um valor em reais: ");
    scanf("%f", &reg->valor);
    printf("Digite a coordenada X: ");
    scanf("%d", &reg->x);
    printf("Digite a coordenada Y: ");
    scanf("%d", &reg->y);
    //ler do usuario e preencher, use prompts e scanf e preencha a estrutura no parametro

    return reg;
}

void ImprimeRegistro(const tRegistro *reg) {
    printf("Descricao: %s\n", reg->descricao);
    printf("Valor: %.2f reais\n", reg->valor);
    printf("Localizacao: (%d, %d)\n", reg->x, reg->y);

    //mostrar as informacoes do registro do parametro de forma organizad
}

float Distancia(tRegistro reg, int x, int y){
    float dist;

    dist = sqrt((x - reg.x)*(x - reg.x) + (y - reg.y)*(y - reg.y));

    return dist;

	//funcao q retorna a distancia da coordenada dos parametros ate a coordenada do registro
}

int main(void)
{
    tRegistro reg; //guarda o registro
    int opcao, x, y;
    ApresentaMensagem();

    while(1){
        ApresentaMenu();
        scanf("%d", &opcao);

        if (opcao == 5){
            break;
        }


        switch(opcao){
            case 1:
                CadastroRegistro(&reg);
                break;
            case 2:
                ImprimeRegistro(&reg);
                break;
            case 3:
                printf("Digite uma localizacao: ");
                scanf("%d %d", &x, &y);
                printf("A distancia eh: %.2f", Distancia(reg, x, y));
                break;
            default:
                puts("Opcao Invalida\n");
                break;
        }
    }

    puts("Adeus");
    return 0;
}