#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

bool is_safe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

void print_solution(int path[]) {
    printf("Hamiltonian Cycle found: ");
    for (int i = 0; i < V; i++) {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]);
}

bool ham_cycle_util(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) {
        if (is_safe(v, graph, path, pos)) {
            path[pos] = v;

            if (ham_cycle_util(graph, path, pos + 1) == true) {
                return true;
            }

            path[pos] = -1; 
        }
    }

    return false;
}

int ham_cycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    path[0] = 0;

    if (ham_cycle_util(graph, path, 1) == false) {
        printf("Solution does not exist\n");
        return 0;
    }

    print_solution(path);
    return 1;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
    };

    ham_cycle(graph);

    return 0;
}
