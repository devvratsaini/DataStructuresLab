#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

void initializeGraph(int vertices) {
	int i, j;
    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    adjacencyMatrix[start][end] = 1;
}

void DFS(int start, int vertices) {
    push(start);
    visited[start] = 1;

    while (!isStackEmpty()) {
        int current = pop();
        printf("%d ", current);

		int i;
        for (i = 1; i <= vertices; i++) {
            if (adjacencyMatrix[current][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, choice, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(vertices);

	int i, j;
    for (i = 1; i <= vertices; i++) {
        visited[i] = 0;
        for (j = 1; j <= vertices; j++) {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Adjency Matrix:\n\n");
    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            printf(" %d", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("\nGRAPH OPERATIONS:\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source vertex: ");
                scanf("%d", &source);
                printf("DFS starting from vertex %d: ", source);
                DFS(source, vertices);
                printf("\n");
                break;
                
            case 2:
                exit(0);
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
