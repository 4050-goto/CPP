#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <limits.h>
#pragma warning(disable:4996)

#define node 9
#define off 0
#define on 1
#define INF INT_MAX

typedef struct Graph_data
{
	int front;
	int next;
	int cost;
}graph;
graph* gra;

typedef struct ENode
{
	int next;
	int weight;
	struct ENode* next_link;
}ENode;

typedef struct VNode
{
	int data;
	ENode* first_link;
}VNode;
VNode* gra_vnode;

void Create_graph()
{
	ENode* node_data;
	gra_vnode = (VNode*)malloc(sizeof(VNode) * node);
	for (int i = 0; i < node; i++)
	{
		gra_vnode[i].data = i;
		gra_vnode[i].first_link = NULL;
	}
	FILE* fp;
	gra = (graph*)malloc(sizeof(graph) * 24);
	fp = fopen("graph_data.txt", "r");
	if (!fp)puts("Open Fail!");
	for (int i = 0; i < 24 && !feof(fp); i++)
	{
		if (fscanf_s(fp, "%d %d %d", &gra[i].front, &gra[i].next, &gra[i].cost) != 3)
		{
			printf("読み込みエラー(%d行目)", i + 1);
			break;
		}
		ENode* new_edge = (ENode*)malloc(sizeof(ENode));
		new_edge->next = gra[i].next;
		new_edge->weight = gra[i].cost;
		new_edge->next_link = gra_vnode[gra[i].front].first_link;
		gra_vnode[gra[i].front].first_link = new_edge;
	}
	fclose(fp);
}

void Dijkstra(int s, int* dist, int* prev)
{
	int i, j, u, v, min, mark[node], dist[node], prev[node];
	//初期化
	for (i = 0; i < node; i++)
	{
		dist[i] = INF;
		mark[i] = off;
		prev[i] = -1;
	}
	//始点ノードの初期化
	dist[s] = 0;
	mark[s] = on;
	//始点隣接ノードのdist設定
	//始点隣接ノードのprev設定
	for (int i = 0; i < node; i++)
	{
		int min = INF;
		int u = -1;
		for (int j = 0; j < node; j++)
		{

			if (!mark[j] && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		if (u == -1) break;
		mark[u] = 1;

		ENode* edge = gra_vnode[u].first_link;
		while (edge)
		{
			int v = edge->next;
			int weight = edge->weight;
			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				prev[v] = u;
			}
			edge = edge->next_link;
		}
	}

}
void Print_path(int* prev, int s, int end) {
	if (end == s) {
		printf("%d", s);
		return;
	}
	Print_path(prev, s, prev[end]);
	printf(" -> %d", end);
}

int main() {
	Create_graph();

	int dist[node], prev[node];
	int s, end;

	printf("Enter start and end vertices: ");
	scanf("%d %d", &s, &end);

	Dijkstra(s, dist, prev);

	printf("Shortest distance from %d to %d is %d\n", s, end, dist[end]);
	printf("Path: ");
	Print_path(prev, s, end);
	printf("\n");

	return 0;
}