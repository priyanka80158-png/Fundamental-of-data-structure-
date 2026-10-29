#include<stdio.h>
//#include<stdlib.h>
#define MAXNODE 4
typedef struct node
{
int vertexno;
struct node	*next;
}node;

typedef struct list
{
	node *head;
} List;

List *adjlist[MAXNODE] = {0};

void addnode(int s,int d)
{
	node *dest,*temp,*src;
	
	if(adjlist[s]->head == NULL)
	{
		dest = (node*)malloc(sizeof(node));
		dest->vertexno = d;
		dest->next = NULL;
		adjlist[s]->head = dest;
	}
	else
	{
		dest = (node*)malloc(sizeof(node));
		dest->vertexno = d;
		dest->next = NULL;
		temp = adjlist[s]->head;
		while(temp->next != NULL)
		    temp = temp->next;
		temp->next = dest;
	}
}
printlist()
{
	int i;
	for(i=0;i<MAXNODE;i++)
	{
		node *p = adjlist[i]->head;
		printf("adjacency list of %d :",i);
		while(p!=NULL)
		{
			printf("%d ",p->vertexno);
			p = p->next;
		}
		printf("\n");
	}
}
int main()
{
	int i;
	for(i=0;i<MAXNODE;i++)
	{
		adjlist[i] = (List*)malloc(sizeof(List));
		adjlist[i]->head = NULL;
	}
	addnode(0,1);
	addnode(0,3);
	addnode(1,2);
	addnode(3,2);
	addnode(2,3);
	
	printlist();
}

//// Adjascency List representation in C
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//  int vertex;
//  struct node* next;
//};
//struct node* createNode(int);
//
//struct Graph {
//  int numVertices;
//  struct node** adjLists;
//};
//
//// Create a node
//struct node* createNode(int v) {
//  struct node* newNode = malloc(sizeof(struct node));
//  newNode->vertex = v;
//  newNode->next = NULL;
//  return newNode;
//}
//
//// Create a graph
//struct Graph* createAGraph(int vertices) {
//  struct Graph* graph = malloc(sizeof(struct Graph));
//  graph->numVertices = vertices;
//
//  graph->adjLists = malloc(vertices * sizeof(struct node*));
//
//  int i;
//  for (i = 0; i < vertices; i++)
//    graph->adjLists[i] = NULL;
//
//  return graph;
//}
//
//// Add edge
//void addEdge(struct Graph* graph, int s, int d) {
//  // Add edge from s to d
//  struct node* newNode = createNode(d);
//  newNode->next = graph->adjLists[s];
//  graph->adjLists[s] = newNode;
//
//  // Add edge from d to s
//  newNode = createNode(s);
//  newNode->next = graph->adjLists[d];
//  graph->adjLists[d] = newNode;
//}
//
//// Print the graph
//void printGraph(struct Graph* graph) {
//  int v;
//  for (v = 0; v < graph->numVertices; v++) {
//    struct node* temp = graph->adjLists[v];
//    printf("\n Vertex %d\n: ", v);
//    while (temp) {
//      printf("%d -> ", temp->vertex);
//      temp = temp->next;
//    }
//    printf("\n");
//  }
//}
//
//int main() {
//  struct Graph* graph = createAGraph(4);
//  addEdge(graph, 0, 1);
//  addEdge(graph, 0, 2);
//  addEdge(graph, 0, 3);
//  addEdge(graph, 1, 2);
//
//  printGraph(graph);
//
//  return 0;
//}
