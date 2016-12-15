#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

/*
* Função que cria e aloca espaço para uma nova Aresta
*/
aresta *aloca_aresta(char *c, int d){
    aresta *ARESTA = (aresta *) malloc(sizeof(aresta));
    ARESTA->cidade = c;
    ARESTA->distancia = d;
    ARESTA->prox_aresta = NULL;
    return ARESTA; 
}

/*
* Funcão que cria e aloca espaço para um novo Vertice
*/
vertice *aloca_vertice(int n, char *c){
    vertice *VERTICE = (vertice *) malloc(sizeof(vertice));
    VERTICE->chave = n;
    VERTICE->cidade = c;
    VERTICE->primeira_aresta = NULL;
    VERTICE->ultima_aresta = NULL;
    VERTICE->prox_vertice = NULL;
    return VERTICE;
}

/*
* Funcão que cria e aloca espaço para um grafo vazio
*/
grafo *aloca_grafo(){
    grafo *GRAFO = (grafo *) malloc(sizeof(grafo));
    GRAFO->num_vertices = 0;
    GRAFO->primeiro_vertice = NULL;
    GRAFO->ultimo_vertice = NULL;
    return GRAFO;
}

/*
* Função que retorna o nome da cidade
*/
char *get_cidade(grafo *g, int c){

    // Buscando o vértice pela chave
    if(g!=NULL){
        vertice *aux = g->primeiro_vertice;    
        do{
            if(aux->chave == c){
                return aux->cidade;
            }
            aux = aux->prox_vertice;
        }while(aux!=NULL);
    }else{
        return NULL;
    }
}
 
/*
* Função que insere um novo vertice
*/
void inserir_vertice(grafo *G, vertice *V){

    if (G != NULL){ // Verifico se o grafo foi criado
        if(G->primeiro_vertice == NULL){ // Se o primeiro vertice do grafo ainda não existe..
            G->primeiro_vertice = V; // Atribua o novo vertice à ele
            G->ultimo_vertice = V;
        } else{ // Caso não..
            G->ultimo_vertice->prox_vertice = V; 
            G->ultimo_vertice = G->ultimo_vertice->prox_vertice;
            G->ultimo_vertice->prox_vertice = NULL;
        }
    } else{
        printf("Ainda não existe grafo! \n");
    }
}

/*
* Função que complementa a função insere aresta
*/
void inserir_aresta(vertice *V, aresta *A){
    if (V != NULL){ // Verifico se o grafo foi criado
        if(V->primeira_aresta == NULL){
            V->primeira_aresta = A;
            V->ultima_aresta = A;
        } else{
            V->ultima_aresta->prox_aresta = A;
            V->ultima_aresta = A;
        }
    } else{
        printf("Este vertice não é válido! \n");
    }
}

/*
* Função que insere aresta
*/
void inserir_aaresta(char *c1, char *c2, int d, grafo *GRAFO){
    vertice *aux = GRAFO->primeiro_vertice;
    int x = 0;

    // 2. Buscando os vertices no qual serão feitas as inserções das novas arestas;
    do{
        if(strcmp(aux->cidade, c1) == 0){
            aresta *a1 = aloca_aresta(c2, d);
            inserir_aresta(aux, a1);
            x++;
        } else if (strcmp(aux->cidade, c2) == 0){
            aresta *a2 = aloca_aresta(c1, d);
            inserir_aresta(aux, a2);
            x++;
        } 
        aux = aux->prox_vertice;
    }while(aux!=NULL || x < 2);
}

/*
* Função que exibe informações do grafo
*/
void get_grafo(grafo *g){
    
    // Imprimindo informações do grafo;
    if(g!=NULL){
        printf("Número de vertices do grafo: %d\n", g->num_vertices);

        if(g->primeiro_vertice!=NULL){
            printf("Nome da primeira cidade do grafo: %s \n", g->primeiro_vertice->cidade);
            if(g->ultimo_vertice!=NULL) printf("Nome da ultima cidade do grafo: %s \n", g->ultimo_vertice->cidade);
        } else {
            printf("Não há vertices cadastrados nesse grafo!!\n");
        }
    } else {
        printf("Este grafo não existe!\n");
    }
    
}

/*
* Função que exibe informações das arestas 
*/
void get_arestas(grafo *g){
    
    vertice *aux = g->primeiro_vertice;

    do{
        aresta *a = aux->primeira_aresta;
        do{
            printf("A cidade %s liga-se a cidade %s. Distância: %d",aux->cidade, a->cidade, a->distancia);
            a = a->prox_aresta;
        }while(a != NULL);
        
        aux= aux->prox_vertice;

    }while(aux!=NULL);
}
