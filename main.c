#include<stdio.h>
#include <stdlib.h>
#include "headers.h"




int main()
{
int total_cost;

    FILE *file_in;
    int iterator_rows;
    int iterator_columns;
    int aux;
    file_in = fopen("test.in", "r+");
    if (file_in == NULL){
        printf("\n File does not exist.");
        fclose(file_in);
    }

    fscanf(file_in, "%d", &n);

    for (iterator_rows = 0; iterator_rows < n; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns< n; iterator_columns++ ){
             fscanf(file_in, "%d ", &aux);
             graph[iterator_rows][iterator_columns]=aux;
        }
    }
    fclose(file_in);
    printf("=== Reading from file successfull ===\n");
     for (iterator_rows = 0; iterator_rows < n; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns< n; iterator_columns++ ){

             printf("%d  ",graph[iterator_rows][iterator_columns]);
        }
        printf("\n");
    }

     printf("\n");
    printf("Kruskal Algorithm");
      kruskal();
      print();
     printf("\n");
    printf("Prim's Algorithm\n");
     total_cost=prims();
    printf("\nspanning tree matrix:\n");

    for(iterator_rows=0;iterator_rows<n;iterator_rows++)
    {
        for(iterator_columns=0;iterator_columns<n;iterator_columns++)
            printf("%d ",spanning[iterator_rows][iterator_columns]);
    printf("\n");
    }


    printf("\n\nTotal cost of spanning tree=%d",total_cost);


return 0;
}

