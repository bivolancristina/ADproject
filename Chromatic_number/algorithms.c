
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algorithms.h"

void chromatic_number_greedy(struct a_graph *graph){
 /**  Colors the graph and prints the colors, using the greedy algorithm
A greedy algorithm is an algorithmic paradigm that follows the problem--
 --solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum
    */
    int iterator_1;
    int iterator_2;
    int *colors;///\ var *colors -vector for storing the colors
    int min_of_colors=1; ///\ var min_of_colors minimum number of colors needed to color--chromatic number
    ///Initialized as 1, becouse we need at least 1 color for every graph posible

    colors=calloc(graph->no_nodes, sizeof(*colors));

    for(iterator_1=0;iterator_1<graph->no_nodes;iterator_1++){
      *(colors + iterator_1)=1;///Initially every node will have the color 1
      ///We go through all the nodes before the "ierator_1" node
      for(iterator_2=0;iterator_2<iterator_1;iterator_2++){
            ///Check if the nodes "ierator_1" - "iterator_2" are adjacent and if they have same color.
            if(adj_check(graph, iterator_1, iterator_2)==1 && *(colors + iterator_1)==*(colors + iterator_2)){
    ///we add 1 to the color- changing the color to the next one
///repeat until we found the first node color that it's not already the color of an adjecent node to the node "iterator_1"
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
///\ checking if node_1 and node_2 are adjacent and have the same color
    for (iterator = 0; iterator < graph->no_nodes; iterator++){
        if(adj_check(graph, node,iterator)==1 && color == *(colors + iterator))
        return 0;
    }

    return 1;
}

int recursive_backtracking_coloring(struct a_graph *graph, int max_no_colors, int *colors, int node){
    /**graph coloring using recursion
    we use var max_no_colors for storing the maximum number of colors a graph can have which is the number of nodes
    */
    int colors_iterator;

    if (node == graph->no_nodes + 1){
        return 1;
    }

    for (colors_iterator = 1; colors_iterator <= max_no_colors; colors_iterator++){
        if (check_same_color(node, graph, colors, colors_iterator)){
        ///\ if checking same color is true we assign the color to the node
           *(colors + node) = colors_iterator;
        ///\ assigning colors to rest of the nodes
            if (recursive_backtracking_coloring(graph, max_no_colors, colors, node+1) == 1){
                return 1;
            }
             ///If the color color_iterator can't lead to a solution, remove it
           *(colors + node) = 0;
        }
    }

    return 0;
}

int chromatic_number_backtracking(struct a_graph *graph, int max_no_colors){
    int *colors;
/** solving chromatic number using backtracking calling the functions created before

Backtracking is a general algorithm for finding all (or some) solutions to some computational problems,--
 --notably constraint satisfaction problems,that incrementally builds candidates to the solutions, and abandons a candidate--
  --("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.
*/
    colors=calloc(graph->no_nodes+1, sizeof(*colors));

    if (recursive_backtracking_coloring(graph, max_no_colors, colors, 0) == 0){
      printf("Solution does not exist");
      return 0;
    }
    print_chromatic_number(colors, graph);

    return 1;
}


