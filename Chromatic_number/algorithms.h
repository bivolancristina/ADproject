
#ifndef ALGORITHMS_H_INCLUDED
#define ALGORITHMS_H_INCLUDED

void chromatic_number_greedy(struct a_graph *graph);
void print_chromatic_number(int *colors, struct a_graph *graph);
int check_same_color(int node, struct a_graph *graph, int *colors, int color);
int recursive_backtracking_coloring(struct a_graph *graph, int max_no_colors, int *colors, int node);
int chromatic_number_backtracking(struct a_graph *graph, int max_no_colors);

#endif
