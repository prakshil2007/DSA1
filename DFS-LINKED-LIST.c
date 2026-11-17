#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// 1. Structure for a linked list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX]; // Array of linked list heads
int visited[MAX];      // Tracks visited vertices

// 2. Helper to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 3. Add edge (Insert at the beginning - No while loops!)
void addEdge(int u, int v) {
    // Connect u -> v
    struct Node* node1 = createNode(v);
    node1->next = adj[u];
    adj[u] = node1;

    // Connect v -> u (because it's undirected)
    struct Node* node2 = createNode(u);
    node2->next = adj[v];
    adj[v] = node2;
}

// 4. Core DFS Function
void dfs(int vertex) {
    visited[vertex] = 1;       // Mark as visited
    printf("%d ", vertex);     // Print vertex

    // Walk through this vertex's linked list of neighbors
    struct Node* temp = adj[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor);     // Go deeper
        }
        temp = temp->next;     // Move to next neighbor in list
    }
}

int main() {
    int vertices, edges, u, v, start;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}