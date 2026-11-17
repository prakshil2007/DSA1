#include <stdio.h>

#define MAX 20

int adj[MAX][MAX]; // 2D array to store edges
int visited[MAX];  // Tracks visited vertices (0 = no, 1 = yes)
int vertexCount;   // Total number of vertices

// Simple Stack setup
int stack[MAX];
int top = -1;

// Core Iterative DFS Function (No Recursion!)
void dfs(int start) {
    // 1. Push starting vertex onto the stack
    stack[++top] = start;

    // 2. Repeat until the stack is empty
    while (top != -1) {
        // Pop the top vertex from the stack
        int current = stack[top--];

        // If it hasn't been visited yet, visit & print it
        if (visited[current] == 0) {
            visited[current] = 1;
            printf("%d ", current);
        }

        // Push all unvisited neighbors onto the stack
        // (Looping backwards from vertexCount-1 to 0 visits smaller numbers first)
        for (int i = 0; i < vertexCount; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
    }
}

int main() {
    int edgeCount, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}