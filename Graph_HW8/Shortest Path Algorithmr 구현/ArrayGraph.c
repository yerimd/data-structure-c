#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// 공백 그래프를 생성하는 연산
Graph* createGraph() {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<MAX_SIZE; j++) {
			if(i==j)
				G->cost[i][j] = 0;
			else
				G->cost[i][j] = INF;
			G->A[i][j] = INF;
		}
		G->dist[i] = INF;
		G->pred[i] = NONE;
		G->S[i] = 0;
	}
	return G;
}

// 그래프가 공백인지 검사	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;	
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteVertex(Graph* G, int v) {
	int i;
	for(i=0; i<G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}	
}

// 그래프 G에 간선 (u, v)를 삭제
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// 그래프 G의 리소스 해제
void destroyGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(i != j)
				G->cost[i][j] = INF;
	}
		G->dist[i] = INF;
		G->pred[i] = NONE;
	}
	G->n = 0;
}

// 그래프 G의 인접 행렬 정보 출력
void displayGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++){
			if(G->cost[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->cost[i][j]);
		}			
		printf("\n");
	}
}

// 최소 비용을 갖는 다음 정점을 찾는 연산
// Dijkstra Algorithm 구현시 필요할 경우 이용 
int nextVertex(Graph* G) {
	int i, minCost, minVertex;
	minCost = INF;
	minVertex = -1;
	for(i=0; i<G->n; i++) {
		if(G->dist[i] < minCost && !G->S[i]) {
			minCost = G->dist[i];
			minVertex = i;
		}
	}
	return minVertex;
}	

// Dijkstra Algorithm
void dijkstra(Graph* G, int v) {
	for (int i = 0; i < G.n(); i++) // Initialize
		D[i] = Integer.MAX_VALUE;
	D[s] = 0;
	for (int i = 0; i < G.n(); i++) {
		int v = minVertex(G, D);
		G.setMark(v, VISITED);
		if (D[v] == Integer.MAX_VALUE) return;
		for (int w = G.first(v); w < G.n();
			w = G.next(v, w))
			if (D[w] > (D[v] + G.weight(v, w)))
				D[w] = D[v] + G.weight(v, w);
}

// Bellman-Ford Algorithm
int bellmanFord(Graph* G, int v) {
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	dist[v] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {

			int u = graph->edge[j].u;
			int v = graph->edge[j].v;
			int w = graph->edge[j].w;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].u;
		int v = graph->edge[i].v;
		int w = graph->edge[i].w;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			printf("Graph contains negative w cycle");
			return;
		}
	}

	printAllPairShortestCost(dist, V);

	return;
}	

// Floyd-Warshall Algorithm
void floyd(Graph* G){
	int V = G.getvCount();
	float dist[][] = new float[V][V];

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k <= g.edgeList.size(); k++) {
				if (g.edgeList.get(i).head.equals(i) && g.edgeList.get(j).tail.equals(j)) {
					int label = Integer.parseInt(g.edgeList.get(k).label);
					dist[i][j] = label;
				}
			}
		}
	}

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int z = 0; z < V; z++) {
		for (int j = 0; j < V; j++) {
			if (dist[z][j] == Float.MAX_VALUE)
				System.out.print("INF ");
			else
				System.out.print(dist[z][j] + "   ");
		}
		System.out.println();
	}
}	

// 최단경로 출력
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로: %c", src+65, dst+65, src+65);
	int v = dst;
	Stack* stack = createStack();
	struct adjlistnode* temp = getnewnode(dst);
	temp->next = G->array[src].head;
	G->array[src].head = temp;

	printf(" \n enter the weight \n ");
	int n;
	scanf("%d", &n);
	G->weight[src][dst] = n;
	G->weight[dst][src] = n;
	printf("\n");
	clearStack(stack);
}	

// 최단경로 비용 출력
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c 최단 경로 비용: %d\n", src+65, dst+65, G->dist[dst]);
}

// 모든 정점 쌍 사이의 최단 경로 비용 출력 
void printAllPairShortestCost(Graph* G) {
	int i, j;
	
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(G->A[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->A[i][j]);
		}			
		printf("\n");
	}
}		
