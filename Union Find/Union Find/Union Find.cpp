// Union Find.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
/*
typedef struct {
	int src;
	int dst;
} Edge;

typedef struct {
	int V; // Number of vertices
	int E; // Number of edges
	Edge* edge; // graph is represented as an array of edges
} Graph;

// find the root of the specified element's subset
int findRoot(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return findRoot(parent, parent[i]);
}

// do union of two subsets 
void doUnion(int parent[], int x, int y)
{
	int xRoot = findRoot(parent, x);
	int yRoot = findRoot(parent, y);
	parent[xRoot] = yRoot;
}

// check whether a given graph contains cycle or not
int containsCycle(Graph* graph)
{
	int* parent = (int*)malloc(graph->V * sizeof(int));

	// initialize all subsets as single element sets
	for (int i = 0; i < graph->V; ++i)
		parent[i] = -1;

	// find subset of both vertices of every edge, 
	// if both subsets are same, then there is cycle in graph.
	for (int i = 0; i < graph->E; ++i)
	{
		int x = findRoot(parent, graph->edge[i].src);
		int y = findRoot(parent, graph->edge[i].dst);

		if (x == y)
			return 1;

		doUnion(parent, x, y);
	}

	return 0;
}

int main()
{
	/* Let us create following graph
	0
	| \
	|  \
	1---2 */
/*	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = 3;
	graph->E = 3;
	graph->edge = (Edge*)malloc(sizeof(Edge) * graph->E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dst = 1;

	// add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dst = 2;

	// add edge 0-2
	graph->edge[2].src = 0;
	graph->edge[2].dst = 2;

	if (containsCycle(graph))
		printf("graph contains cycle\n");
	else
		printf("graph doesn't contain cycle\n");

	return 0;
}
*/

//parent <- -1 초기화하자
int Find(int x, int *parent)
{
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x], parent);
}
void Union(int x, int y, int *parent)
{
	x = Find(x, parent);
	y = Find(y, parent);
	if (x != y)
	{
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}