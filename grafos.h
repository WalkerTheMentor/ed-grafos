#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Estrutura que representa as arestas
*/
struct Aresta{
    char *cidade;
    int distancia;
    struct Aresta *prox_aresta;
};
typedef struct Aresta aresta;

/*
* Estrutura que representa os vertices
*/
struct Vertice{
    int chave;
    char *cidade;
    struct Aresta *primeira_aresta;
    struct Aresta *ultima_aresta;
    struct Vertice *prox_vertice;
};
typedef struct Vertice vertice;

/*
* Estrutura que representa o Grafo
*/
struct Grafo{
    int num_vertices;
    struct Vertice *primeiro_vertice;
    struct Vertice *ultimo_vertice;
};
typedef struct Grafo grafo;

/*
* Função que cria e aloca espaço para uma nova Aresta
*/
aresta *aloca_aresta(char *c, int d);

/*
* Funcão que cria e aloca espaço para um novo Vertice
*/
vertice *aloca_vertice(int n, char *c);

/*
* Funcão que cria e aloca espaço para um grafo vazio
*/
grafo *aloca_grafo();

/*
* Função que retorna o nome da cidade
*/
char *get_cidade(grafo *g, int c);
 
/*
* Função que insere um novo vertice
*/
void inserir_vertice(grafo *G, vertice *V);

/*
* Função que complementa a função insere aresta
*/
void inserir_aresta(vertice *V, aresta *A);

/*
* Função que insere aresta
*/
void inserir_aaresta(char *c1, char *c2, int d, grafo *GRAFO);

/*
* Função que exibe informações do grafo
*/
void get_grafo(grafo *g);

/*
* Função que exibe informações das arestas 
*/
void get_arestas(grafo *g);
