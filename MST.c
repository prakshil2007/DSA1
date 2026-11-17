#include <stdio.h>

#define MAX 20

// Structure to represent an edge between two vertices
struct Edge {
    int u;      // Start vertex
    int v;      // End vertex
    int weight; // Cost of the edge
};

int parent[MAX];

// 1. Simple function to find the main leader (root) of a vertex
int findParent(int vertex) {
    while (parent[vertex] != vertex) {
        vertex = parent[vertex];
    }
    return vertex;
}

int main() {
    int V, E;
    struct Edge edges[MAX * MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Step 1: Read all edges
    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Step 2: Sort edges from smallest weight to largest (Simple Bubble Sort)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Step 3: Initially, every vertex is its own parent (disconnected)
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalWeight = 0;
    int edgesSelected = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Step 4: Pick the smallest edges one by one without forming a cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int parentU = findParent(u);
        int parentV = findParent(v);

        // If they have different parents, adding this edge won't form a cycle
        if (parentU != parentV) {
            printf("%d - %d (weight %d)\n", u, v, w);
            totalWeight += w;
            edgesSelected++;

            // Connect the two components together
            parent[parentU] = parentV;
        }

        // Stop early once we have V - 1 edges
        if (edgesSelected == V - 1) {
            break;
        }
    }

    printf("Total weight of MST = %d\n", totalWeight);

    return 0;
}