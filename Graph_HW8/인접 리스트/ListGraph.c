#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
// 공백 그래프를 생성하는 연산
Graph* createGraph(int type) {
int i;
Graph* G = (Graph*)malloc(sizeof(Graph));
G->n = 0;
G->type = type;
for(i=0; i<MAX_SIZE; i++) {
G->adjList_H[i] = NULL;
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
void insertEdge(Graph* G, int u, int v) {
Linsert(&(G->adjList_H[u]), v);
Linsert(&(G->adjList_H[v]), u);
G->n += 1;}
// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteVertex(Graph* G, int v) {
Graph* vertex = v;
while (v) {
deleteEdge;
G->n = v;
v = G->n;
}
deleteEdge;
}
// 그래프 G에 간선 (u, v)를 삭제
void deleteEdge(Graph* G, int u, int v) {
graphNode* connectedVertexList = &(G->adjList_H[u]);
int size = connectedVertexList;
Graph* vertex = (Graph*)malloc(sizeof(Graph));
if (vertex!=u) {
return 0;
}
for (int i = 0; i < size; i++) {
int vertex = *((int*)(connectedVertexList, i));
if (vertex == v) {
(connectedVertexList, i);
break;
}
}
connectedVertexList = &(G->adjList_H[v]);
size = (connectedVertexList);
for (int i = 0; i < size; i++) {
int vertex = *((int*)(connectedVertexList, i));
if (vertex == u) {
(connectedVertexList, i);
break;
}
}
G->n -= 1;
return 1;
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
