
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algorithms.h"

void chromatic_number_greedy(struct a_graph *graph){

    int iterator_1;
    int iterator_2;
    int *colors;
    int min_of_colors=1;

    colors=calloc(graph->no_nodes, sizeof(*colors));

    for(iterator_1=0;iterator_1<graph->no_nodes;iterator_1++){
      *(colors + iterator_1)=1;
      for(iterator_2=0;iterator_2<iterator_1;iterator_2++){
            if(adj_check(graph, iterator_1, iterator_2)==1 && *(colors + iterator_1)==*(colors + iterator_2)){
                 *(colors + iterator_1)=*(colors + iterator_2)+1;
                 min_of_colors=*(colors + iterator_2)+1;
            }
        }
    }

    printf("\n");
    for(iterator_1=0;iterator_1<graph->no_nodes;iterator_1++){
        printf("Node [%d] is colored with color %d \n",iterator_1 , *(colors + iterator_1));
    }
    printf("Minimun of colors : %d\n", min_of_colors);
}


void print_chromatic_number(int *colors, struct a_graph *graph){

    int iterator;
    int min_of_colors;

    min_of_colors=0;
    for(iterator=0;iterator<graph->no_nodes;iterator++){
        printf("Node[%d] is colored with color %d \n",iterator , *(colors + iterator));
        if(*(colors + iterator)> min_of_colors){
             min_of_colors=*(colors + iterator);
        }
    }
    printf("\n");
    printf("Colors needed : %d\n", min_of_colors);
}

int check_same_color(int node, struct a_graph *graph, int *colors, int color){
    int iterator;

    for (iterator = 0; iterator < graph->no_nodes; iterator++){
        if(adj_check(graph, node,iterator)==1 && color == *(colors + iterator))
        return 0;
    }

    return 1;
}

int recursive_backtracking_coloring(struct a_graph *graph, int max_no_colors, int *colors, int node){
    int colors_iterator;

    if (node == graph->no_nodes + 1){
        return 1;
    }

    for (colors_iterator = 1; colors_iterator <= max_no_colors; colors_iterator++){
        if (check_same_color(node, graph, colors, colors_iterator)){
           *(colors + node) = colors_iterator;
            if (recursive_backtracking_coloring(graph, max_no_colors, colors, node+1) == 1){
                return 1;
            }
           *(colors + node) = 0;
        }
    }

    return 0;
}

int chromatic_number_backtracking(struct a_graph *graph, int max_no_colors){
    int *colors;

    colors=calloc(graph->no_nodes+1, sizeof(*colors));

    if (recursive_backtracking_coloring(graph, max_no_colors, colors, 0) == 0){
      printf("Solution does not exist");
      return 0;
    }
    print_chromatic_number(colors, graph);

    return 1;
}


