/*
Author: Matthew Henderson
Assignment Number: Lab Assignment 5
File Name: graph.c
Course/Section: CS 2123 Section 0D1
Due Date: 11/23/20
Instructor: Dr. Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    FALSE,
    TRUE
} bool;

#define MAXV 100

typedef struct edgenode
{
    int endPoint;
    int weight;
    struct edgenode *next;
} edgenodeT;

typedef struct
{
    edgenodeT *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges; // number of directed edges....
    bool directed;
} graphT;

void initialize_graph(graphT *g, bool directed);
void read_graph(graphT *g, char *filename);
void insert_edge(graphT *g, int x, int y, int w);
void print_graph(graphT *g, char *name);
void free_graph(graphT *g);
graphT *copy_graph(graphT *g);
int optionChecker();
int operate(graphT *g, graphT *f, int option);
void insert(graphT *g, int startPoint, int newEndPoint, int newWeight);
void delete (graphT *g, int startPoint, int newEndPoint);
void printDegree(graphT *g, char *name);
void printComplement(graphT *g, char *name);
void eliminateLinks(graphT *g, int minW, int maxW);
bool eliminationBool(int minW, int maxW, int checker);
void differentlinks(graphT *graph1, graphT *graph2);
void commonlinks(graphT *graph1, graphT *graph2);
int dfs(graphT *g, int key, int node);

// put prototypes for other functions here....
int main(int argc, char *argv[])
{
    graphT *myg1 = NULL, *myg2 = NULL;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s graph_filename", argv[0]);
        exit(-1);
    }
    myg1 = (graphT *)malloc(sizeof(graphT));
    if (myg1 == NULL)
    {
        fprintf(stderr, "Cannot allocate memory for the graph");
        exit(-1);
    }
    initialize_graph(myg1, FALSE);
    read_graph(myg1, argv[1]);
    myg2 = copy_graph(myg1);
    // first implement copy_graph function and call it here
    print_graph(myg1, "myg1");
    print_graph(myg2, "myg2");

    int option = 0;
    do
    {
        option = optionChecker();
        operate(myg1, myg2, option);
    } while (option != 0);
    // NOW in a loop get commands and
    // call related functions to perform them...
    free_graph(myg1);
    free_graph(myg2);
}

void initialize_graph(graphT *g, bool directed)
{
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i = 1; i <= MAXV; i++)
        g->edges[i] = NULL;
    for (i = 1; i <= MAXV; i++)
        g->degree[i] = 0;
}

void read_graph(graphT *g, char *filename)
{
    int i;
    int n, m, dir;
    int x, y, w;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Cannot open the graph file");
        exit(-1);
    }
    fscanf(fp, "%d %d %d", &n, &m, &dir);
    g->nvertices = n;
    g->nedges = 0; // insert function will increase it;
    g->directed = dir;
    for (i = 1; i <= m; i++)
    {
        fscanf(fp, "%d %d %d", &x, &y, &w);
        insert_edge(g, x, y, w);
        if (dir == FALSE)
            insert_edge(g, y, x, w);
    }
    fclose(fp);
}

void linsert_edge(graphT *g, int startPoint, int newEndPoint, int w)
{
    //     edgenodeT *newEdge;
    //     newEdge = malloc(sizeof(edgenodeT)); // check if NULL
    //     if (newEdge == NULL)
    //     {
    //         fprintf(stderr, "Cannot allocate memory for an edge");
    //         exit(-1);
    //     }

    //     newEdge->weight = w;
    //     newEdge->endPoint = newEndPoint;
    //     // YOU MUST MODIFY THIS FUNCTION SO IT WILL KEEP LINK LIST SORTED
    //     // W.R.T. NEIGHBOR IDs.

    //     //this function pushes to the front of the linked list
    //     edgenodeT *previousEdge;
    //     edgenodeT *currentEdge;

    //     int i = 0;
    //     if (!g->edges[startPoint])
    //     {
    //         g->edges[startPoint] = malloc(sizeof(edgenodeT));
    //         g->edges[startPoint]->endPoint = newEndPoint;
    //         g->edges[startPoint]->weight = w;
    //         free(newEdge);
    //         i++;
    //     }
    //     else
    //     {
    //         currentEdge = g->edges[startPoint];
    //     }
    //     printf("%d", (g->edges[startPoint])->weight);
    //     while (i == 0)
    //     {

    //         if (newEndPoint > currentEdge->endPoint)
    //         {
    //             newEdge->next = currentEdge;
    //             previousEdge->next = newEdge;
    //             i = 1;
    //         }
    //         else if ((newEndPoint == previousEdge->endPoint) && (w <= previousEdge->weight))
    //         {
    //             newEdge->next = currentEdge;
    //             previousEdge->next = newEdge;
    //             i = 1;
    //         }
    //         else
    //         {
    //             previousEdge = currentEdge;
    //             currentEdge = currentEdge->next;
    //         }
    //     }
    //     g->degree[startPoint]++;
    //     g->nedges++;
}

void print_graph(graphT *g, char *name)
{
    edgenodeT *pe;
    int i;
    if (!g)
        return;
    printf("Graph Name: %s\n", name);
    for (i = 1; i <= g->nvertices; i++)
    {
        printf("Node %d: ", i);
        pe = g->edges[i];
        while (pe)
        {
            // printf(" %d", pe->y);
            printf(" %d(w=%d),", pe->endPoint, pe->weight);
            pe = pe->next;
        }
        printf("\n");
    }
    printf("\n");
}

void free_graph(graphT *g)
{
    edgenodeT *pe, *olde;
    int i;
    for (i = 1; i <= g->nvertices; i++)
    {
        pe = g->edges[i];
        while (pe)
        {
            olde = pe;
            pe = pe->next;
            free(olde);
        }
    }
    free(g);
}

graphT *copy_graph(graphT *sourceGraph)
{
    graphT *newg;
    newg = (graphT *)malloc(sizeof(graphT));
    if (newg == NULL)
    {
        fprintf(stderr, "Cannot allocate memory for the graph");
        exit(-1);
    }

    initialize_graph(newg, FALSE);

    newg->directed = sourceGraph->directed;
    newg->nedges = sourceGraph->nedges;
    newg->nvertices = sourceGraph->nvertices;

    int i;
    for (i = 1; i <= newg->nvertices; i++)
    {
        newg->degree[i] = sourceGraph->degree[i];
    }

    edgenodeT *sourceEdge;
    int x;
    int y;
    int w;
    for (i = 1; i <= newg->nvertices; i++)
    {
        sourceEdge = sourceGraph->edges[i];
        while (sourceEdge)
        {
            x = i;
            y = sourceEdge->endPoint;
            w = sourceEdge->weight;

            insert_edge(newg, x, y, w);
            sourceEdge = sourceEdge->next;
        }
    }
    return newg;
}
// your other functions

void insert_edge(graphT *g, int x, int y, int w)
{
    edgenodeT *pe;
    pe = malloc(sizeof(edgenodeT)); // check if NULL
    pe->weight = w;
    pe->endPoint = y;
    // YOU MUST MODIFY THIS FUNCTION SO IT WILL KEEP LINK LIST SORTED
    // W.R.T. NEIGHBOR IDs.
    pe->next = g->edges[x];
    g->edges[x] = pe;
    g->degree[x]++;
    g->nedges++;
}

int optionChecker()

{
    //this funtion returns the id of the command for the program to follow

    char choice[100];
    printf("Your options for interacting with the graph, please use exact spellings:\n\n");
    printf("insert, delete, printgraph, printdegree, printcomplement, eliminatelinks, differentlinks, commonlinks, dfs, bfs, isconnected, numofconncomp, quit\n");

    scanf("%s", choice);
    int option = 0;
    if (!strcmp(choice, "insert"))
    {
        option = 1;
    }
    if (!strcmp(choice, "delete"))
    {
        option = 2;
    }
    if (!strcmp(choice, "printgraph"))
    {
        option = 3;
    }
    if (!strcmp(choice, "printdegree"))
    {
        option = 4;
    }
    if (!strcmp(choice, "printcomplement"))
    {
        option = 5;
    }
    if (!strcmp(choice, "eliminatelinks"))
    {
        option = 6;
    }
    if (!strcmp(choice, "differentlinks"))
    {
        option = 7;
    }
    if (!strcmp(choice, "commonlinks"))
    {
        option = 8;
    }
    if (!strcmp(choice, "dfs"))
    {
        option = 9;
    }
    if (!strcmp(choice, "bfs"))
    {
        option = 10;
    }
    if (!strcmp(choice, "isconnected"))
    {
        option = 11;
    }
    if (!strcmp(choice, "numofconncomp"))
    {
        option = 12;
    }
    if (!strcmp(choice, "quit"))
    {
        option = 0;
    }
    return option;
}

int operate(graphT *myg1, graphT *myg2, int option)
{
    char name[100];
    int startPoint, endPoint, weight;

    //insert node, not Sorted!
    if (option == 1)
    {
        printf("[myg1 | myg2] x y w\n");
        scanf("%s %d %d %d", name, &startPoint, &endPoint, &weight);
        if (!strcmp(name, "myg1"))
        {
            insert(myg1, startPoint, endPoint, weight);
            if (myg1->directed == FALSE)
            {
                insert(myg1, endPoint, startPoint, weight);
            }
        }
        else if (!strcmp(name, "myg2"))
        {
            insert(myg2, startPoint, endPoint, weight);
            if (myg2->directed == FALSE)
            {
                insert(myg2, endPoint, startPoint, weight);
            }
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //delete node
    else if (option == 2)
    {
        printf("[myg1 | myg2] x y\n");
        scanf("%s %d %d", name, &startPoint, &endPoint);
        if (!strcmp(name, "myg1"))
        {
            delete (myg1, startPoint, endPoint);
            if (myg1->directed == FALSE)
            {
                delete (myg1, endPoint, startPoint);
            }
        }
        else if (!strcmp(name, "myg2"))
        {
            delete (myg2, startPoint, endPoint);
            if (myg2->directed == FALSE)
            {
                delete (myg2, endPoint, startPoint);
            }
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //print graph
    else if (option == 3)
    {
        printf("[myg1 | myg2]\n");
        scanf("%s", name);
        if (!strcmp(name, "myg1"))
        {
            print_graph(myg1, name);
        }
        else if (!strcmp(name, "myg2"))
        {
            print_graph(myg2, name);
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //print degree
    else if (option == 4)
    {
        printf("[myg1 | myg2]\n");
        scanf("%s", name);
        if (!strcmp(name, "myg1"))
        {
            printDegree(myg1, name);
        }
        else if (!strcmp(name, "myg2"))
        {
            printDegree(myg2, name);
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //print complement
    else if (option == 5)
    {
        printf("[myg1 | myg2]\n");
        scanf("%s", name);
        if (!strcmp(name, "myg1"))
        {
            printComplement(myg1, name);
        }
        else if (!strcmp(name, "myg2"))
        {
            printComplement(myg2, name);
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //eliminate links
    else if (option == 6)
    {
        int minW, maxW;
        printf("[myg1 | myg2] minW maxW\n");
        scanf("%s %d %d", name, &minW, &maxW);
        if (!strcmp(name, "myg1"))
        {
            eliminateLinks(myg1, minW, maxW);
        }
        else if (!strcmp(name, "myg2"))
        {
            eliminateLinks(myg2, minW, maxW);
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //different links
    else if (option == 7)
    {
        char name2[100];
        printf("[myg1 | myg2] [myg1 | myg2]\n");
        scanf("%s %s", name, name2);
        printf("These values are not in common from %s.\n", name);
        if (!strcmp(name, "myg1"))
        {
            if (!strcmp(name2, "myg1"))
            {
                differentlinks(myg1, myg1);
            }
            else if (!strcmp(name2, "myg2"))
            {
                differentlinks(myg1, myg2);
            }
        }
        else if (!strcmp(name, "myg2"))
        {
            if (!strcmp(name2, "myg1"))
            {
                differentlinks(myg2, myg1);
            }
            else if (!strcmp(name2, "myg2"))
            {
                differentlinks(myg2, myg2);
            }
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //common links
    else if (option == 8)
    {
        char name2[100];
        printf("[myg1 | myg2] [myg1 | myg2]\n");
        scanf("%s %s", name, name2);
        printf("These values are in common from %s.\n", name);
        if (!strcmp(name, "myg1"))
        {
            if (!strcmp(name2, "myg1"))
            {
                commonlinks(myg1, myg1);
            }
            else if (!strcmp(name2, "myg2"))
            {
                commonlinks(myg1, myg2);
            }
        }
        else if (!strcmp(name, "myg2"))
        {
            if (!strcmp(name2, "myg1"))
            {
                commonlinks(myg2, myg1);
            }
            else if (!strcmp(name2, "myg2"))
            {
                commonlinks(myg2, myg2);
            }
        }
        else
        {
            printf("incorrect name");
            return -1;
        }
    }
    //dfs
    else if (option == 9)
    {
        int key;
        printf("[myg1 | myg2] x\n");
        scanf("%s %d", name, &key);
        if (!strcmp(name, "myg1"))
        {
            dfs(myg1, key, 1);
        }
        else if (!strcmp(name, "myg2"))
        {
            dfs(myg2,key,1);
        }
    }
    else
    {
        printf("incorrect name");
        return -1;
    }
}


void insert(graphT *g, int startPoint, int newEndPoint, int newWeight)

{
    edgenodeT *currentNode;
    currentNode = g->edges[startPoint];
    while (currentNode)
    {
        if (currentNode->endPoint == newEndPoint)
        {
            currentNode->weight = newWeight;
            return;
        }
        currentNode = currentNode->next;
    }

    insert_edge(g, startPoint, newEndPoint, newWeight);
}

void delete (graphT *g, int startPoint, int newEndPoint)
{
    edgenodeT *currentNode;
    edgenodeT *previousNode;
    currentNode = g->edges[startPoint];
    previousNode = g->edges[startPoint];
    while (currentNode)
    {
        if (currentNode->endPoint == newEndPoint)
        {
            previousNode->next = currentNode->next;

            free(currentNode);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

void printDegree(graphT *g, char *name)
{

    int size = g->nvertices;
    int *degreeArray;
    degreeArray = (int *)malloc(sizeof(int) * (size));
    int *inDegreeArray;
    inDegreeArray = (int *)malloc(sizeof(int) * (size));

    int i;
    for (i = 1; i <= 6; i++)
    {
        degreeArray[i] = 0;
        inDegreeArray[i] = 0;
    }

    edgenodeT *currentNode;
    int temp;
    for (i = 1; i <= size; i++)
    {
        currentNode = g->edges[i];

        while (currentNode)
        {
            (degreeArray[i])++;
            temp = (currentNode->endPoint);
            (inDegreeArray[temp])++;
            currentNode = currentNode->next;
        }
    }
    printf("%s degrees\n", name);
    if (g->directed == TRUE)
    {
        printf("Vertex: Out-Degrees In-Degrees\n");
        for (i = 1; i <= size; i++)
        {
            printf("%d: %d %d\n", i, degreeArray[i], inDegreeArray[i]);
        }
    }
    else
    {
        printf("Vertex: Out-Degrees\n");
        for (i = 1; i <= size; i++)
        {
            printf("%d: %d\n", i, degreeArray[i]);
        }
    }
    //causing double free error
    // free(degreeArray);
    // free(inDegreeArray);
}

void printComplement(graphT *g, char *name)
{
    //make complement
    int *complementMatrix;
    int size = g->nvertices;
    complementMatrix = (int *)malloc(sizeof(int) * size * size);
    int collumn, row;
    for (row = 0; row < size; row++)
    {
        for (collumn = 0; collumn < size; collumn++)
        {
            *(complementMatrix + (row * 6) + collumn) = 0;
        }
    }

    edgenodeT *currentNode;
    for (row = 0; row < size; row++)
    {
        {
            currentNode = g->edges[row + 1];

            while (currentNode)
            {
                *(complementMatrix + (row * 6) + ((currentNode->endPoint) - 1)) = 1;
                currentNode = currentNode->next;
            }
        }
    }

    for (row = 0; row < size; row++)
    {
        for (collumn = 0; collumn < size; collumn++)
        {
            if (*(complementMatrix + (row * 6) + collumn) == 1)
            {
                *(complementMatrix + (row * 6) + collumn) = 0;
            }
            else if (*(complementMatrix + (row * 6) + collumn) == 0)
            {
                *(complementMatrix + (row * 6) + collumn) = 1;
            }
        }
    }
    graphT *cg = NULL;
    cg = (graphT *)malloc(sizeof(graphT));
    if (cg == NULL)
    {
        fprintf(stderr, "Cannot allocate memory for the graph");
        exit(-1);
    }
    initialize_graph(cg, g->directed);
    cg->nvertices = size;
    int start, end, check;

    for (row = 0; row < size; row++)

    {
        start = 1 + row;
        for (collumn = 0; collumn < size; collumn++)
        {
            end = collumn + 1;
            check = *(complementMatrix + (row * 6) + collumn);
            if (check == 1)
            {

                insert_edge(cg, start, end, 1);
            }
        }
    }
    print_graph(cg, "cg");
    free_graph(cg);
}

void eliminateLinks(graphT *g, int minW, int maxW)
{
    int row;
    edgenodeT *currentNode;
    int size = g->nvertices;

    for (row = 1; row <= size; row++)
    {
        {
            currentNode = g->edges[row];

            while (currentNode)
            {
                if (eliminationBool(minW, maxW, currentNode->weight))
                {
                    delete (g, row, currentNode->endPoint);
                }
                currentNode = currentNode->next;
            }
        }
    }
}
bool eliminationBool(int minW, int maxW, int checker)
{
    if (checker < minW || checker > maxW)
    {
        return TRUE;
    }
    return FALSE;
}

void differentlinks(graphT *graph1, graphT *graph2)
{
    int row, size, check;
    size = graph1->nvertices;
    edgenodeT *currentNode1;
    edgenodeT *currentNode2;

    for (row = 1; row <= size; row++)
    {
        {
            currentNode1 = graph1->edges[row];
            printf("row %d:", row);
            while (currentNode1)
            {
                check = 0;
                currentNode2 = graph2->edges[row];
                while (currentNode2 && (check == 0))
                {
                    if (currentNode1->endPoint == currentNode2->endPoint)
                    {
                        check++;
                    }
                    currentNode2 = currentNode2->next;
                }
                if (check == 0)
                {
                    printf("%d->%d, ", row, currentNode1->endPoint);
                }
                currentNode1 = currentNode1->next;
            }
            printf("\n");
        }
    }
}

void commonlinks(graphT *graph1, graphT *graph2)
{
    int row, size, check;
    size = graph1->nvertices;
    edgenodeT *currentNode1;
    edgenodeT *currentNode2;

    for (row = 1; row <= size; row++)
    {
        {
            currentNode1 = graph1->edges[row];
            printf("row %d:", row);
            while (currentNode1)
            {
                check = 0;
                currentNode2 = graph2->edges[row];
                while (currentNode2 && (check == 0))
                {
                    if (currentNode1->endPoint == currentNode2->endPoint)
                    {
                        printf("%d->%d, ", row, currentNode1->endPoint);
                        check++;
                    }
                    currentNode2 = currentNode2->next;
                }
                currentNode1 = currentNode1->next;
            }
            printf("\n");
        }
    }
}
//this works better if starting point were sorted by end point
//doesnt work because it is incomlete
int dfs(graphT *g, int key, int node)
{
    printf("%d\n", node);

    if (g->edges[node]->endPoint == key)
    {
        return 1;
    }
    else
    {
        int found = 0;
        edgenodeT *currentNode;

        while (found == 0 && currentNode)
        {
            found = dfs(g, key, currentNode->endPoint);
            currentNode = currentNode->next;
        }
        return found;
    }
}