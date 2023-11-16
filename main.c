#include <stdio.h>
#include "ABP.h"


int main() {
    ABP* minhaABP = criaABP();
    int opcao;
    char nome[100];
    Aluno aluno;


    do {
        printf("\nMenu:\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um Aluno\n");
        printf("3 - Buscar um Aluno pelo nome e imprimir suas informacoes\n");
        printf("4 - Remover um Aluno pelo nome\n");
        printf("5 - Imprimir a ABP em ordem\n");
        printf("6 - Imprimir as informacoes do aluno com a maior nota\n");
        printf("7 - Imprimir as informacoes do aluno com a menor nota\n");
        printf("8 - Destruir a ABP\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                if (*minhaABP != NULL) {
                    destroiABP(minhaABP);
                }
                minhaABP = criaABP();
                printf("ABP criada com sucesso!\n");
                break;


            case 2:
                printf("Digite o nome do Aluno: ");
                scanf("%s", aluno.nome);
                fflush(stdin);
                printf("Digite a matricula do Aluno: ");
                scanf("%d", &aluno.matricula);
                fflush(stdin);
                printf("Digite a nota do Aluno: ");
                scanf("%lf", &aluno.nota);
                fflush(stdin);


                if (insereAluno(minhaABP, aluno)) {
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir o Aluno. Nome ja existente.\n");
                }
                break;


            case 3:
                printf("Digite o nome do Aluno a ser buscado: ");
                scanf("%s", nome);
                aluno = buscaAluno(minhaABP, nome);
                if (strcmp(aluno.nome, "") == 0) {
                    printf("Aluno nao encontrado.\n");
                } else {
                    printf("Aluno encontrado:\n");
                    printf("Nome: %s, Matricula: %d, Nota: %.2lf\n", aluno.nome, aluno.matricula, aluno.nota);
                }
                break;


            case 4:
                printf("Digite o nome do Aluno a ser removido: ");
                scanf("%s", nome);
                if (removeAluno(minhaABP, nome)) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Aluno nao encontrado.\n");
                }
                break;


            case 5:
                printf("Imprimindo a ABP em ordem:\n");
                em_ordem(*minhaABP);
                break;


            case 6:
                {
                    NO* maximo = encontraMaximo(*minhaABP);
                    printf("Aluno com a maior nota:\n");
                    printf("Nome: %s, Matricula: %d, Nota: %.2lf\n", maximo->aluno.nome, maximo->aluno.matricula, maximo->aluno.nota);
                    break;
                }


            case 7:
                {
                    NO* minimo = encontraMinimo(*minhaABP);
                    printf("Aluno com a menor nota:\n");
                    printf("Nome: %s, Matricula: %d, Nota: %.2lf\n", minimo->aluno.nome, minimo->aluno.matricula, minimo->aluno.nota);
                    break;
                }


            case 8:
                destroiABP(minhaABP);
                printf("ABP destruida com sucesso!\n");
                break;


            case 9:
                printf("Saindo do programa. Ate mais!\n");
                destroiABP(minhaABP);
                break;


            default:
                printf("Opção invalida. Por favor, tente novamente.\n");
        }


    } while (opcao != 9);


    return 0;
}
