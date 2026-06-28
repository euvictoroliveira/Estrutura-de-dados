/*
    Arquivo relacionado às implementações das funções para manipulação de pilha dinâmica implementada com lista 
    encadeada simples.
    data: 15-08-2025.




    Autor: João Victor Oliveira.

*/
// CABEÇALHO
#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

// Implementa cria_pilha()
void cria_pilha(Pilha **p){
    // Aloca memória para struct pilha
    *p = (Pilha*) malloc(sizeof(Pilha));
    if(!(*p)){
        printf("Erro alocar memoria.\n");
        exit(1);
    }
    // Constrói pilha como vazia.
    (*p)->topo = NULL;
    printf("Pilha criada com sucesso.\n");
    return;
    
}
// Implementa push().
void push(Pilha *p, int n){
    No *novo; // nó para novo elemento da pilha
    novo = (No*) malloc(sizeof(Pilha));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return;
    }
    // faz as devidas atribuições
    novo->info = n;
    novo->proximo = p->topo;
    p->topo = novo;

    printf("Elemento inserido com sucesso.\n");
    return;
}
// Implementa pop()
int pop(Pilha *p){
    // Verifica se a pilha está vazia.
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return 0;
    }
    // Veficia se a pilha é unitária
    No *sai;
    int auxiliar;
    if(p->topo->proximo == NULL){
        sai = p->topo;
        auxiliar = sai->info;
        p->topo = NULL; // pilha agora é vazia

        free(sai);
        return auxiliar;
    }
    // Caso de pilha com multiplos elementos.
    sai = p->topo;
    auxiliar = sai->info;
    p->topo = sai->proximo;
    free(sai);

    return auxiliar;

}
// Implementa top()
int top(Pilha *p){
    // Verifica se a pilha está vazia
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return 0;
    }

    return p->topo->info;

}
// Implementa pilha_vazia()
int pilha_vazia(Pilha *p){

    return (p->topo == NULL);

}
// Implementa libera_pila()
void libera_pilha(Pilha *p){
    // verifica se pilha é vazia
    if(pilha_vazia(p)){
        free(p);

        printf("Pilha esvaziada com sucesso.\n");
        return;
    }
    No *auxiliar = p->topo;
    while(auxiliar != NULL){
        No *auxiliar2;
        auxiliar2 = auxiliar->proximo;

        free(auxiliar);
        auxiliar = auxiliar2;
    }

    printf("Pilha esvaziada com sucesso.\n");
    return;

}
// Implementa exibir_pilha()
void exibir_pilha(Pilha *p){
    // Verifica se a pilha está vazia.
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }
    // Implementa recursão
    printf("Pilha: ");
    exibir_no(p->topo); // chama função recursiva.
    printf("\n");

}
// Implementa exibir Nos
void exibir_no(No *elemento){

    if(elemento){
        printf("%d ", elemento->info); 
        exibir_no(elemento->proximo); // etapa recursiva
    }else
        return; // condição de parada
    

}
