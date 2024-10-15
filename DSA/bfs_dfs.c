#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

// Function for Depth-First Search
void dfs(int vertex) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex + 1); // Print vertex as 1-indexed

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

// Function for Breadth-First Search
void bfs(int startVertex) {
    int queue[MAX], front = -1, rear = -1;
    visited[startVertex] = 1; // Mark as visited
    printf("%d ", startVertex + 1); // Print vertex as 1-indexed
    
    queue[++rear] = startVertex; // Enqueue the start vertex
    if (front == -1) front = 0; // Set front if it was -1

    while (front <= rear) {
        int currentVertex = queue[front++]; // Dequeue
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1; // Mark as visited
                printf("%d ", i + 1); // Print vertex as 1-indexed
                queue[++rear] = i; // Enqueue
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Start DFS from vertex 1 (index 0)
    printf("DFS starting from vertex 1:\n");
    dfs(0);

    // Reset visited array for BFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start BFS from vertex 1 (index 0)
    printf("\nBFS starting from vertex 1:\n");
    bfs(0);

    return 0;
}
