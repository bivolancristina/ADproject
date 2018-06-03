/// The minimum number of colors needed to colors each node in an undirected graph such that no two adjacent vertices share the same color.
///
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algorithms.h"

int main(){

    struct a_graph *graph;///\var *graph -a graph of type struct a_graph

    int choose_algorithm;///\var choose_algorithm for chosing which algorithm to use

    graph=calloc(1, sizeof(struct a_graph));///Allocate memory dynamically to the graph
    printf("\n");
    printf("Choose how to read graph :\n");
    printf("1.From keyboard\n");
    printf("2.From file\n");
    printf("\n");

    scanf("%d", &choose_algorithm);

    if(choose_algorithm == 1)
        init_graph(graph);
        else
            init_graph_file(graph);

    print_adj_matrix(graph);
     ///Solve chromatic number with one of the algorithms by choice.
    printf("\n");
    printf("WChoose which algorithm to use : \n");
    printf("1.Greedy Algorithm\n");
    printf("2.Backtracking Algorithm\n");
    scanf("%d", &choose_algorithm);

    if(choose_algorithm == 1){
        chromatic_number_greedy(graph);
    }else if(choose_algorithm == 2){
        chromatic_number_backtracking(graph, graph->no_nodes);
    }
    ///Free memory for adjacent matrix, graph.
    free(graph->adj_matrix);;
    free(graph);

    return 0;
}
