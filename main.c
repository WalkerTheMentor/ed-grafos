#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main(){
    /*
    * Testando criação de um grafo simples;
    */
    
    int num_vertices = 0, i = 0;
    char cidade[30], *aux1, *aux2;
    int cidade1, cidade2, distancia;
    
    // INSERINDO VERTICES ----------------------------------------------------------

    // 1. Criando o grafo vazio;
    grafo *GRAFO = aloca_grafo();

    // 2. Criando VERTICES vazios e inserindo no grafo

    char url[]="cidades.txt";
	FILE *arq;
	arq = fopen(url, "r"); //Abrindo arquivo das cidades

	if(arq == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
    } else{
		while( (fgets(cidade, sizeof(cidade), arq))!=NULL){
            printf("%d execução \n", i + 1);
            vertice *V = aloca_vertice(i, cidade);
            inserir_vertice(GRAFO,V);// Inserindo vertice no grafo
        }
    }
    

    // 3. Criando arestas
    
    // char url2[]="rotas.txt";
	// FILE *arq2;
	// arq2 = fopen(url2, "r"); //Abrindo arquivo das cidades

	// if(arq2 == NULL){
	// 		printf("Erro, nao foi possivel abrir o arquivo\n");
    // } else{
	// 	while( (fscanf(arq2,"%d %d %d \n", &cidade1, &cidade2, &distancia)) != EOF ){
    //         aux1 = get_cidade(GRAFO, cidade1); //Recebe o nome da cidade 1
    //         aux2 = get_cidade(GRAFO, cidade2); //Recebe o nome da cidade 2
    //         inserir_aaresta(aux1, aux2, distancia, GRAFO);
    //     }
    // }
	// fclose(arq2); //fechando arquivo

    // 3. Imprimindo informações das arestas:
    //get_arestas(GRAFO);
    get_grafo(GRAFO);
    
}