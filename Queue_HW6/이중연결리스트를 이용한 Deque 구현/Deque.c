#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
// 공백덱 생성
Deque* create() {
Deque* DQ = (Deque*)malloc(sizeof(Deque));
DQ->front = NULL;
DQ->rear = NULL;
return DQ;
}
// 덱이 포화상태인지 확인하는 연산
int isFull(Deque* DQ) {
// Fill your code
}
// 덱이 공백상태인지 확인하는 연산
int isEmpty(Deque* DQ) {
if (DQ->front == NULL) {
printf("\n Linked Queue is empty! \n");
return 1;
}
else return 0;
}
// 덱의 머리에 요소 추가하는 연산
void insertFront(Deque* DQ, element x) {
// Fill your code
dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
newNode->data = x;
if (DQ->front == NULL) {
DQ->front = newNode;
DQ->rear = newNode;
newNode->rlink = NULL;
newNode->llink = NULL;
}
else {
DQ->front->llink = newNode;
newNode->rlink = DQ->front;
newNode->llink = NULL;
DQ->front = newNode;
}
}
// 덱의 꼬리에 요소 추가하는 연산
void insertRear(Deque* DQ, element x) {
// Fill your code
dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
newNode->data = x;
if (DQ->front == NULL) {
DQ->front = newNode;
DQ->rear = newNode;
newNode->rlink = NULL;
newNode->llink = NULL;
}
else {
DQ->rear->rlink = newNode;
newNode->rlink = NULL;
newNode->llink = DQ->rear;
DQ->rear = newNode;
}
}
// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산
element deleteFront(Deque* DQ) {
// Fill your code
dequeNode* old = DQ->front;
element x;
if (isEmpty(DQ)) return 0;
else {
x = old->data;
if (DQ->front->rlink == NULL) {
DQ->front = NULL;
DQ->rear = NULL;
}
else {
DQ->front = DQ->front->rlink;
DQ->front->llink = NULL;
}
free(old);
return x;
}
}
// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산
element deleteRear(Deque* DQ) {
// Fill your code
dequeNode* old = DQ->rear;
element x;
if (isEmpty(DQ)) return 0;
else {
x = old->data;
if (DQ->rear->llink == NULL) {
DQ->front = NULL;
DQ->rear = NULL;
}
else {
DQ->rear = DQ->rear->llink;
DQ->rear->rlink = NULL;
}
free(old);
return x;
}
}
// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X
element getFront(Deque* DQ) {
// Fill your code
element x;
if (isEmpty(DQ)) return 0;
else {
x = DQ->front->data;
return x;
}
}
// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X
element getRear(Deque* DQ) {
// Fill your code
element x;
if (isEmpty(DQ)) return 0;
else {
x = DQ->rear->data;
return x;
}
}
// 덱의 모든 요소 출력
void displayDeque(Deque* DQ) {
dequeNode* p = DQ->front;
printf("Deque [ ");
while(p) {
printf("%d ", p->data);
p = p->rlink;
}
printf(" ]\n");
}
// 덱 비우기
void clear(Deque* DQ) {
dequeNode* p;
while(DQ->front) {
p = DQ->front;
DQ->front = DQ->front->rlink;
free(p);
p = NULL;
}
}
