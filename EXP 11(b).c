#include <stdio.h>
#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

void depthFirstSearch(int vertex, int vertexCount) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(i, vertexCount);
        }
    }
}

void initializeGraph(int* vertexCount, int* edgeCount) {
    printf("Enter the number of vertices: ");
    scanf("%d", vertexCount);
    for (int i = 0; i < *vertexCount; i++) {
        for (int j = 0; j < *vertexCount; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Enter the number of edges: ");
    scanf("%d", edgeCount);
    for (int i = 0; i < *edgeCount; i++) {
        int u, v;
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);
        if (u < *vertexCount && v < *vertexCount) {
            adjMatrix[u][v] = 1; // Directed edge
        } else {
            printf("Invalid edge: (%d, %d)\n", u, v);
            i--;
        }
    }
}

int main() {
    int vertexCount, edgeCount, startVertex;
    initializeGraph(&vertexCount, &edgeCount);
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    if (startVertex >= 0 && startVertex < vertexCount) {
        printf("Depth-First Search starting from vertex %d:\n", startVertex);
        depthFirstSearch(startVertex, vertexCount);
    } else {
        printf("Invalid starting vertex.\n");
    }
    return 0;
}
