#ifndef ABP_H
#define ABP_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[100];
    int matricula;
    double nota;
} Aluno;


typedef struct NO {
    Aluno aluno;
    struct NO* esq;
    struct NO* dir;
} NO;


typedef struct NO* ABP;


NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}


ABP* criaABP() {
    ABP* raiz = (ABP*)malloc(sizeof(ABP));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}


void destroiRec(NO* no) {
    if (no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    free(no);
}


void destroiABP(ABP* raiz) {
    if (raiz != NULL) {
        destroiRec(*raiz);
        free(raiz);
    }
}


int estaVazia(ABP* raiz) {
    if (raiz == NULL) return 1;
    return (*raiz == NULL);
}


int insereAluno(ABP* raiz, Aluno aluno) {
    if (raiz == NULL) return 0;


    NO* novo = alocarNO();
    if (novo == NULL) return 0;
    novo->aluno = aluno;
    novo->esq = NULL;
    novo->dir = NULL;


    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        NO* atual = *raiz;
        NO* ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (strcmp(aluno.nome, atual->aluno.nome) < 0) {
                atual = atual->esq;
            } else if (strcmp(aluno.nome, atual->aluno.nome) > 0) {
                atual = atual->dir;
            } else {
                free(novo);
                return 0;
            }
        }


        if (strcmp(aluno.nome, ant->aluno.nome) < 0) {
            ant->esq = novo;
        } else {
            ant->dir = novo;
        }
    }


    return 1;
}


NO* buscaAlunoRec(NO* raiz, char* nome) {
    if (raiz == NULL || strcmp(nome, raiz->aluno.nome) == 0) {
        return raiz;
    }


    if (strcmp(nome, raiz->aluno.nome) < 0) {
        return buscaAlunoRec(raiz->esq, nome);
    } else {
        return buscaAlunoRec(raiz->dir, nome);
    }
}


Aluno buscaAluno(ABP* raiz, char* nome) {
    NO* no = buscaAlunoRec(*raiz, nome);
    Aluno alunoNulo = {"", 0, 0.0};
    return (no != NULL) ? no->aluno : alunoNulo;
}


NO* encontraMinimo(NO* raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}


NO* encontraMaximo(NO* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}


int removeAluno(ABP* raiz, char* nome) {
    if (*raiz == NULL) return 0;


    NO* atual = *raiz;
    NO* ant = NULL;


    while (atual != NULL) {
        if (strcmp(nome, atual->aluno.nome) == 0) {
            if (atual->esq == NULL && atual->dir == NULL) {
                free(atual);
                if (ant == NULL) {
                    *raiz = NULL;
                } else if (ant->esq == atual) {
                    ant->esq = NULL;
                } else {
                    ant->dir = NULL;
                }
            } else if (atual->esq == NULL) {
                NO* temp = atual->dir;
                free(atual);
                if (ant == NULL) {
                    *raiz = temp;
                } else if (ant->esq == atual) {
                    ant->esq = temp;
                } else {
                    ant->dir = temp;
                }
            } else if (atual->dir == NULL) {
                NO* temp = atual->esq;
                free(atual);
                if (ant == NULL) {
                    *raiz = temp;
                } else if (ant->esq == atual) {
                    ant->esq = temp;
                } else {
                    ant->dir = temp;
                }
            } else {
                NO* temp = encontraMinimo(atual->dir);
                atual->aluno = temp->aluno;
                return removeAluno(&(atual->dir), temp->aluno.nome);
            }
            return 1;
        }
        ant = atual;
        if (strcmp(nome, atual->aluno.nome) < 0) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }


    return 0;
}


void em_ordem(NO* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("Nome: %s, Matricula: %d, Nota: %.2lf\n", raiz->aluno.nome, raiz->aluno.matricula, raiz->aluno.nota);
        em_ordem(raiz->dir);
    }
}


#endif
