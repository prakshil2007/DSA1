#include <stdio.h>

#define MAX 20

int adj[MAX][MAX]; // 2D array to represent the graph (0 = no edge, 1 = edge)
int visited[MAX];  // Keeps track of visited vertices (0 = no, 1 = yes)
int queue[MAX];    // Queue for BFS
int front = 0, rear = 0;

void bfs(int start, int vertexCount) {
    // 1. Mark start node as visited and add to queue
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        // 2. Remove the front vertex from queue and print it
        int current = queue[front++];
        printf("%d ", current);

        // 3. Check all possible vertices to find unvisited neighbors
        for (int i = 0; i < vertexCount; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;      // Mark as visited
                queue[rear++] = i;   // Add to queue
            }
        }
    }
}

int main() {
    int vertexCount, edgeCount, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    // Read edges and mark them in the 2D array
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1; // Connection from u to v
        adj[v][u] = 1; // Connection from v to u (undirected)
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start, vertexCount);
    printf("\n");

    return 0;
}

