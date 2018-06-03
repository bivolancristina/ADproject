/// The minimum number of colors needed to colors each node in an undirected graph
///
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algorithms.h"

int main(){

    struct a_graph *graph;

    int choose_algorithm;
    graph=calloc(1, sizeof(struct a_graph));
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
    free(graph->adj_matrix);;
    free(graph);


    return 0;
}
