#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX]; // Array of linked lists
int visited[MAX];      // Tracks visited vertices

// Helper function to create a new box (node)
struct Node *createNode(int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Connect u and v by inserting at the FRONT of each list (No while loop needed!)
void addEdge(int u, int v) {
    // Add v to u's list
    struct Node *node1 = createNode(v);
    node1->next = adj[u];
    adj[u] = node1;

    // Add u to v's list (because the graph is undirected)
    struct Node *node2 = createNode(u);
    node2->next = adj[v];
    adj[v] = node2;
}

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Walk through all neighbors of 'current'
        struct Node *temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next; // Move to next box in the chain
        }
    }
}

int main() {
    int vertexCount, edgeCount, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);
    printf("\n");

    return 0;
}