#include <stdio.h>
#include <string.h>
#include "../common.h"
#include "../queue.h"
#include "../stack.h"

#define GRAPH_CAPACITY 6
#define NAME_LENGTH 5

typedef struct {
    int edges [GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][NAME_LENGTH];
    int size;
} Graph;

void initGraph(Graph *g);
int addVertex(Graph *g, char vertex[NAME_LENGTH]);
int addEdge(Graph *g, char vertexSource[NAME_LENGTH], char vertexDestiny[NAME_LENGTH]);
int removeVertex(Graph *g, char vertex[NAME_LENGTH]);
int removeEdge(Graph *g, char vertexSource[NAME_LENGTH], char vertexDestiny[NAME_LENGTH]);
int existsEdge(Graph g, char vertexSource[NAME_LENGTH], char vertexDestiny[NAME_LENGTH]);
int findVertex(Graph graph, char vertex[NAME_LENGTH]);
void printGraph(Graph graph);
void allRelationsVertex(Graph graph, int searchedInd, Stack *s);
void DFS(Graph graph, Stack *visited, char vertex[NAME_LENGTH]);
void BFS(Graph graph, char vertex[NAME_LENGTH]);

int main()
{
    Graph graph;
    initGraph(&graph);
    char n1[] = "SLP";
    char n2[] = "QRT";
    char n3[] = "AGC";
    char n4[] = "CMX";
    char n5[] = "NL";

    addVertex(&graph, n1);
    addVertex(&graph, n2);
    addVertex(&graph, n3);
    addVertex(&graph, n3);
    addVertex(&graph, n4);
    addVertex(&graph, n5);

    addEdge(&graph, n1, n2);
    addEdge(&graph, n1, n3);
    addEdge(&graph, n2, n4);
    addEdge(&graph, n5, n4);
    addEdge(&graph, n3, n5);

    printf("Original:\n");
    printGraph(graph);

    Stack visited;
    setup(&visited);
    printf("\nDFS:\n");
    DFS(graph, &visited, n4);
    printf("\nBFS:\n");
    BFS(graph, n1);

    printf("\nRemove edge SLP - AGC:\n");
    removeEdge(&graph, n1, n3);
    printGraph(graph);

    printf("\nRemove vertex AGC:\n");
    removeVertex(&graph, n3);
    printGraph(graph);
}

void initGraph(Graph *g)
{
    g->size = 0;
}

int addVertex(Graph *g, char vertex[NAME_LENGTH])
{
    if(g->size < GRAPH_CAPACITY && findVertex(*g, vertex) == -1)
    {
        strcpy(g->vertices[g->size], vertex);

        for(int r = 0 ; r < GRAPH_CAPACITY ; r++)
            g->edges[r][g->size] = 0;

        for(int c = 0 ; c < GRAPH_CAPACITY ; c++)
            g->edges[g->size][c] = 0;

        g->edges[g->size][g->size] = 1;
        g->size++;
        return 1;
    }
    return 0;
}

int findVertex(Graph graph, char vertex[NAME_LENGTH])
{
    for(int i = 0 ; i < graph.size ; i++)
        if(strcmp(graph.vertices[i], vertex) == 0)
            return i;
    return -1;
}

int addEdge(Graph *g, char vertexSource[], char vertexDestiny[])
{
    int posSource = findVertex(*g, vertexSource);
    int posDestiny = findVertex(*g, vertexDestiny);

    if(posSource != -1 && posDestiny != -1)
    {
        g->edges[posSource][posDestiny] = 1;
        g->edges[posDestiny][posSource] = 1;
        return 1;
    }
    return 0;
}

void printGraph(Graph graph)
{
    printf("\t");
    for(int i = 0 ; i < graph.size ; i++)
        printf("%s\t", graph.vertices[i]);
    printf("\n");

    for(int r = 0 ; r < graph.size ; r++)
    {
        printf("%s\t", graph.vertices[r]);
        for(int c = 0 ; c < graph.size ; c++)
            printf("%d\t", graph.edges[r][c]);
        printf("\n");
    }
}

int removeVertex(Graph *g, char vertex[NAME_LENGTH])
{
    int removedVertexIndex = findVertex(*g, vertex);
    if(removedVertexIndex != -1)
    {
        --g->size;
        for(int i = removedVertexIndex ; i < g->size ; i++)
            strcpy(g->vertices[i], g->vertices[i + 1]);
        //Horizontal move
        for(int r = 0 ; r <= g->size ; r++)
            if(r >= removedVertexIndex)
                for(int c = 0 ; c <= g->size ; c++)
                    g->edges[r][c] = g->edges[r+1][c];

        //Vertical move
        for(int r = 0 ; r <= g->size ; r++)
            for(int c = 0 ; c <= g->size ; c++)
                if(c >= removedVertexIndex)
                    g->edges[r][c] = g->edges[r][c+1];

        return 1;
    }
    return 0;
}

int removeEdge(Graph *g, char vertexSource[NAME_LENGTH], char vertexDestiny[NAME_LENGTH])
{
    int posSource = findVertex(*g, vertexSource);
    int posDestiny = findVertex(*g, vertexDestiny);

    if(posSource != -1 && posDestiny != -1)
    {
        g->edges[posSource][posDestiny] = 0;
        g->edges[posDestiny][posSource] = 0;
        return 1;
    }
    return 0;
}

int existsEdge(Graph g, char vertexSource[NAME_LENGTH], char vertexDestiny[NAME_LENGTH])
{
    int posSource = findVertex(g, vertexSource);
    int posDestiny = findVertex(g, vertexDestiny);

    if(posSource != -1 && posDestiny != -1 && g.edges[posSource][posDestiny] == 1 && g.edges[posDestiny][posSource] == 1)
        return 1;
    return 0;
}

void allRelationsVertex(Graph graph, int searchedInd, Stack *s)
{
    for(int i = 0 ; i < graph.size ; i++)
        if(i != searchedInd && graph.edges[searchedInd][i] == 1)
            push(s, i);
}

void DFS(Graph graph, Stack *visited, char vertex[NAME_LENGTH])
{
    int index = findVertex(graph, vertex);
    push(visited, index);
    printf("Nodo procesado %s\n", vertex);

    Stack vertexRelations;
    setup(&vertexRelations);
    allRelationsVertex(graph, index, &vertexRelations);

    for(int i = 0 ; i <= vertexRelations.top ; i++)
        if(findIndex(*visited, vertexRelations.data[i]) == -1)
            DFS(graph, visited, graph.vertices[vertexRelations.data[i]]);
}

void BFS(Graph graph, char vertex[NAME_LENGTH])
{
    Cola toBeVisited;
    Stack visited;
    inicializarCola(&toBeVisited);
    setup(&visited);
    int index = findVertex(graph, vertex);
    insertarCola(&toBeVisited, index);

    while(!colaVacia(toBeVisited))
    {
        int indexCurrentVertex;
        eliminarCola(&toBeVisited, &indexCurrentVertex);
        printf("Nodo procesado %s\n", graph.vertices[indexCurrentVertex]);
        push(&visited, indexCurrentVertex);

        Stack vertexRelations;
        setup(&vertexRelations);
        allRelationsVertex(graph, indexCurrentVertex, &vertexRelations);

        for(int i = 0 ; i <= vertexRelations.top ; i++)
            if(findIndex(visited, vertexRelations.data[i]) == -1)
                insertarCola(&toBeVisited, vertexRelations.data[i]);
    }
}