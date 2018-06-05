#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "graph.h"
void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value){
    int position;

    assert(row_index <= graph->no_nodes);
    assert(column_index <= graph->no_nodes);
    position = row_index * graph->no_nodes + column_index;
    *(graph->adj_matrix + position) = element_value;
}
void init_graph(struct a_graph *graph){
    ///\ reading graph from keyboard
    int iterator_rows;
    int iterator_columns;
    int aux;

    printf("\nGive no nodes = ");
    scanf("%d", &graph->no_nodes);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes,sizeof(int));

    for (iterator_rows = 0; iterator_rows < graph->no_nodes-1; iterator_rows++ ){
        for (iterator_columns = (iterator_rows+1); iterator_columns< graph->no_nodes; iterator_columns++ ){
            printf(" graph[%d][%d]= ",iterator_rows, iterator_columns);
            scanf("%d", &aux);
            set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
            set_adj_matrix_value(graph, iterator_columns, iterator_rows, aux);
                }

        }
}
void write_graph_file(struct a_graph *graph){
     FILE *file_in;
    int iterator_rows;
    int iterator_columns;
    int aux;
    time_t t;
    srand((unsigned) time(&t));
     file_in = fopen("test.in", "w");
    if (file_in == NULL){
        printf("\n File does not exist.");
        fclose(file_in);
        return;
    }

    graph->no_nodes=1 + rand() % 5;
      fwrite(&graph,sizeof(struct a_graph),1,file_in);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes, sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
            aux=rand()%2;
            fprintf(file_in, "%d ", aux);
        }
    }
    fclose(file_in);
    printf("=== Writing file successfull ===\n");

}

void init_graph_file(struct a_graph *graph){
    ///\ reading graph from file
    FILE *file_in;
    int iterator_rows;
    int iterator_columns;
    int aux;

    file_in = fopen("test.in", "r+");
    if (file_in == NULL){
        printf("\n File does not exist.");
        fclose(file_in);
        return;
    }
    fscanf(file_in, "%d", &graph->no_nodes);
    printf("nr noduri %d",graph->no_nodes);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes, sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
            fscanf(file_in, "%d ", &aux);
            set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
        }
    }
    fclose(file_in);
    printf("=== Reading from file successfull ===\n");
}

int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index) {
    int position;

    assert(row_index <= graph->no_nodes);
    assert(column_index <= graph->no_nodes);
    if (graph->init == 1){
        position = row_index * graph->no_nodes + column_index;
        return *(graph->adj_matrix + position);
    }else{
        printf("Please read the graph first");
        return -1;
    }
}
void print_adj_matrix(struct a_graph *graph){
    int iterator_rows;
    int iterator_columns;
    int aux;
     printf("Number of nodes: %d\n",graph->no_nodes);
    if (graph->init == 1){
        printf("=== Printing adj_matrix ===\n");
        for (iterator_rows = 0; iterator_rows <graph->no_nodes; iterator_rows++ ){
            for (iterator_columns = 0 ;iterator_columns < graph->no_nodes; iterator_columns++ ){
                aux = get_adj_matrix_value(graph, iterator_rows, iterator_columns);
                printf(" %d ", aux);
            }
            printf("\n");
        }
    }else{
        printf("\nPlease read the adj_matrix first");
    }
}
int adj_check(struct a_graph *graph, int node_1, int node_2){
 ///\ checking if node_1 is adjacent with node_2
    if(get_adj_matrix_value(graph,node_1,node_2)==1){
        return 1;
    }else{
        return 0;
    }
}

