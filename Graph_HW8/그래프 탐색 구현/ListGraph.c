#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
// 공백 그래프를 생성하는 연산
Graph* createGraph(int type) {
int i;
Graph* G = (Graph*)malloc(sizeof(Graph));
G->n = 0;
G->type = type;
for(i=0; i<MAX_SIZE; i++) {
G->adjList_H[i] = NULL;
G->visited[i] = FALSE;
G->pred[i] = -1;
}
return G;
}
// 그래프가 공백인지 검사
int isEmptyGraph(Graph* G) {
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
void insertEdge(Graph* G, int u, int v) {
Linsert(&(G->adjList_H[u]), v);
Linsert(&(G->adjList_H[v]), u);
G->n += 1;
}
// 그래프 G의 리소스 해제
void destroyGraph(Graph* G) {
int i;
for(i=0; i<G->n; i++) {
if(G->adjList_H[i] != NULL)
free(G->adjList_H[i]);
}
free(G);
}
// 그래프 G의 인접 리스트 정보 출력
void displayGraph(Graph* G) {
int i;
graphNode* p;
for(i=0; i<G->n; i++) {
printf("정점 %d의 인접리스트", i);
p = G->adjList_H[i];
while(p) {
printf(" -> %d ", p->vertex);
p = p->link;
}
printf("\n");
}
}
// visited[], pred[] 초기화
void initSearch(Graph* G) {
int i;
for(i=0; i<G->n; i++) {
G->visited[i] = FALSE;
G->pred[i] = -1;
}
}
// 깊이 우선 탐색 iterative version
void dfs_iter(Graph* G, int v) {
}
// 깊이 우선 탐색 recursive version
void dfs_recur(Graph* G, int v) {
int i;
if (G ->visited[v]) {
return;
} G-> visited[v] = 0;
printf("%d ", v);
for(int i=0; i< G->adjList_H[v]; i++)
{
int x = *adjList_H[v][i]; dfs(x);
}
}
// 너비 우선 탐색
void bfs(Graph* G, int v) {
}
