
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

struct a_graph {
    int no_nodes;
    int init;
    int *adj_matrix;
};

struct a_list_node{
    int info;
    struct a_list_node *next;
};
void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value);
void init_graph(struct a_graph *graph);
void init_graph_file(struct a_graph *graph);
int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index);
void print_adj_matrix(struct a_graph *graph);
int adj_check(struct a_graph *my_graph, int node_1, int node_2);
#endif
