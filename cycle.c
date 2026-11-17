#include <stdio.h>

#define MAX 20

int graph[MAX][MAX]; // Adjacency matrix (0 = no edge, 1 = edge)
int state[MAX];      // 0 = Unvisited, 1 = Visiting (in current path), 2 = Completely Done
int V;               // Number of vertices

// 1. Cycle check for DIRECTED graph
int checkDirectedCycle(int curr) {
    state[curr] = 1; // Mark as "Currently Visiting"

    for (int next = 0; next < V; next++) {
        if (graph[curr][next] == 1) {
            // If 'next' is currently being visited in this same path -> CYCLE!
            if (state[next] == 1) {
                return 1;
            }
            // If 'next' is unvisited, explore it
            if (state[next] == 0 && checkDirectedCycle(next)) {
                return 1;
            }
        }
    }

    state[curr] = 2; // Mark as "Completely Done" (safe, no cycle here)
    return 0;
}

// 2. Cycle check for UNDIRECTED graph
int checkUndirectedCycle(int curr, int parent) {
    state[curr] = 1; // Mark as "Visited"

    for (int next = 0; next < V; next++) {
        if (graph[curr][next] == 1) {
            // Ignore the edge we just came from
            if (next == parent) {
                continue;
            }
            // If we hit an already visited node that isn't our parent -> CYCLE!
            if (state[next] == 1) {
                return 1;
            }
            // If unvisited, keep exploring
            if (state[next] == 0 && checkUndirectedCycle(next, curr)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int type, edges, u, v;

    printf("Graph Type (1 = Directed, 2 = Undirected): ");
    scanf("%d", &type);

    printf("Number of vertices and edges: ");
    scanf("%d %d", &V, &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (type == 2) {
            graph[v][u] = 1; // Undirected edges go both ways
        }
    }

    // Check every vertex (in case the graph is disconnected)
    int hasCycle = 0;
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (type == 1 && checkDirectedCycle(i)) hasCycle = 1;
            if (type == 2 && checkUndirectedCycle(i, -1)) hasCycle = 1;
        }
    }

    if (hasCycle)
        printf("Cycle Found!\n");
    else
        printf("No Cycle.\n");

    return 0;
}