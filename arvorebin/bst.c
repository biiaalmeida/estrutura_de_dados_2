#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Info{
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node{
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};
struct Node *ler_arquivo(struct Node *raiz);
struct Info criarInfo(char *nome, int mat, int turma, float nota);
struct Node *criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
void minhafuncao(void);
struct Node *inserir(struct Node *raiz, struct Info info);

int main(){
    struct Node *arvore = 0;
    arvore = ler_arquivo(arvore);
    //printf("%s\n", arvore->dir->esq->info.nome);
    return 0;
}

struct Info criarInfo(char *nome, int mat, int turma, float nota){
    struct Info res;
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

struct Node *criarNode(struct Info info){
    struct Node *res = (struct Node *)malloc(sizeof(struct Node));
    res->info = info;
    res->dir = 0;
    res->esq = 0;
    return res;
}

int comparar(struct Info a, struct Info b){
    return strcmp(a.nome, b.nome);
}

struct Node *inserir(struct Node *raiz, struct Info info){
    if (raiz == 0){
        return criarNode(info);
    }

    int x = comparar(raiz->info, info);

    if (x < 0){
        raiz->dir = inserir(raiz->dir, info);
        printf("A raiz que tem o nome %s tem o filho a direita %s\n", raiz->info.nome, raiz->dir->info.nome);
    }
    else if (x > 0){
        raiz->esq = inserir(raiz->esq, info);

        printf("A raiz que tem o nome %s tem o filho a esquerda %s\n", raiz->info.nome, raiz->esq->info.nome);
    }
    return raiz;
}

struct Node *ler_arquivo(struct Node *raiz){
    struct Info info;
    FILE *arch = fopen("alunos-arvore.txt", "r");
    if (arch == NULL){
        exit(EXIT_FAILURE);
    }
    char *nome = (char *)malloc(30 * sizeof(char));
    int mat, turma;
    while (fscanf(arch, "%d %d %[^\n]s", &mat, &turma, nome) == 3){
        info = criarInfo(nome, mat, turma, rand() % 10);
        raiz = inserir(raiz, info);
    }
    return raiz;
}