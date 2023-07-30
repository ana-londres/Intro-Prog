#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 30

void RemoveBarraN(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
}

typedef struct{
    int matricula;
    char nome[41];
    double nota1, nota2, nota3;
    double recup;
    } tDados;

tDados alunos[MAX_ALUNOS];

void ListarAlunos(tDados *alunos){
    printf("\nDigite a matricula: ");
    scanf("%d%*c", &alunos->matricula);
    printf("Digite o nome do aluno: ");
    fgets(alunos->nome, 41, stdin);
    RemoveBarraN(alunos->nome);
}

void LeituraNotas(tDados *alunos){
    printf("\nNotas aluno %s", alunos->nome);
    printf("\nDigite a primeira nota: ");
    scanf("%lf", &alunos->nota1);
    printf("Digite a segunda nota: ");
    scanf("%lf", &alunos->nota2);
    printf("Digite a teceira nota: ");
    scanf("%lf", &alunos->nota3);
}

void ChecaRecuperacao(tDados *alunos){
    double media;
    media = (alunos->nota1 + alunos->nota2 + alunos->nota3) / 3;

    if(media >= 4 && media < 7){
        printf("\nMedia atual de %s eh: %.1lf", alunos->nome, media);
        printf("\nDigite a nota de recuperacao de %s: ", alunos->nome);
        scanf("%lf", &alunos->recup);
    }
}

void Tabela(tDados *alunos){
    double mediaFinal = (alunos->nota1 + alunos->nota2 + alunos->nota3) / 3;
    char situacao[10];

    if (mediaFinal >= 7){
        strcpy(situacao, "Aprovado");
    }else if (mediaFinal < 4) {
        strcpy(situacao, "Reprovado");
    }else {
        mediaFinal = (mediaFinal*6 + alunos->recup*4) / 10;
        if (mediaFinal >= 5)
            strcpy(situacao, "Aprovado");
        else
            strcpy(situacao, "Reprovado");
    }

    printf("%d\t\t%s\t%.1lf\t%.1lf\t%.1lf", alunos->matricula, alunos->nome, alunos->nota1, alunos->nota2, alunos->nota3);
    if (mediaFinal > 7 || mediaFinal < 4)
        printf("\t-");
    else{
        printf("\t%.1lf", alunos->recup);
    }
    
    printf("\t%.1lf\t%s\n", mediaFinal, situacao);
}

void EscreveArquivoAlunos(tDados *alunos){
    FILE *fptr = fopen("aluno.txt", "a");

    if(fptr == NULL){
        puts("Erro ao abrir arquivo dos alunos.");
        return;
    }

    fprintf(fptr, "%d %lf %lf %lf %lf", alunos->matricula,
                                           alunos->nota1,
                                           alunos->nota2,
                                           alunos->nota3,
                                           alunos->recup);
    fprintf(fptr, " %s\n", alunos->nome);

    fclose(fptr);
}

void CarregaArquivoAlunos(){
    FILE *fptr;

    fptr = fopen("aluno.txt", "r");

    if(fptr == NULL){
        puts("Arquivo de alunos nao encontrado.");
        return;
    }

    int i = 0;

    while(1){
        fscanf(fptr, "%d %lf %lf %lf %lf", &alunos[i].matricula,
                                           &alunos[i].nota1,
                                           &alunos[i].nota2,
                                           &alunos[i].nota3,
                                           &alunos[i].recup);
        
        if(feof(fptr)){
            break;
        }

        fgets(alunos->nome, 41, fptr);

        RemoveBarraN(alunos->nome);

        i++;
    }

    fclose(fptr);
}

int main(){
    char disciplina[51];
    int qAlunos, i;

    CarregaArquivoAlunos();


    printf("Seja bem-vindo ao programa de controle de disciplina!\n");

    printf("\nDigite o nome da disciplina (max. 50 caracteres): ");
    fgets(disciplina, 51, stdin);
    RemoveBarraN(disciplina);
    printf("Digite a quantidade de alunos (max. 30): ");
    scanf("%d", &qAlunos);

    for(i = 0; i < qAlunos; i++){
        ListarAlunos(&alunos[i]);
    }

    for(i = 0; i < qAlunos; i++){
        LeituraNotas(&alunos[i]);
    }

    for(i = 0; i < qAlunos; i++){
        ChecaRecuperacao(&alunos[i]);
    }

    printf("Disciplina: %s\n", disciplina);
    puts("---------------------------------------------------------------------------");
    puts("Matricula\tNome\tNota1\tNota2\tNota3\tRec\tMedia\tSituacao");
    puts("---------------------------------------------------------------------------");
    for (i = 0; i < qAlunos; i++){
        Tabela(&alunos[i]);
    }

    for(i = 0; i < qAlunos; i++){
        EscreveArquivoAlunos(&alunos[i]);
    }

    return 0;
}