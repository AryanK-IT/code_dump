#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int mstGraph[MAX_VERTICES][MAX_VERTICES] = {0};
    int totalCost = 0;

    printf("\nCost Adjacency Matrix of the Minimum Spanning Tree:\n");

    for (int i = 1; i < V; i++) {
        int u = parent[i];
        int v = i;
        int weight = graph[u][v];
        
        mstGraph[u][v] = weight;
        mstGraph[v][u] = weight; 
        totalCost += weight;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t", mstGraph[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalCost);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];
    FILE *file;

    file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL) {
        printf("Error: Could not open file 'inUnAdjMat.dat'.\n");
        printf("Please ensure the file exists in the same directory.\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    if (V <= 0 || V > MAX_VERTICES) {
        printf("Error: Invalid number of vertices. Please enter a number between 1 and %d.\n", MAX_VERTICES);
        fclose(file);
        return 1;
    }

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);
    
    if (startVertex <= 0 || startVertex > V) {
        printf("Error: Invalid starting vertex. Please enter a number between 1 and %d.\n", V);
        fclose(file);
        return 1;
    }

    printf("\nReading graph from 'inUnAdjMat.dat'...\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (fscanf(file, "%d", &graph[i][j]) != 1) {
                printf("Error reading matrix from file. Ensure it is formatted correctly.\n");
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);

    primMST(graph, V, startVertex - 1);

    return 0;
}