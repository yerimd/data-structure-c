#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
// 공백 이진 트리 생성 연산
BinTree* createBT(){
BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
bt->key = EMPTY;
bt->left = NULL;
bt->right = NULL;
return bt;
}
// 이진 트리가 비어있는지 검사하는 연산
int isBTEmpty(BinTree* bt) {
if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
return TRUE;
else
return FALSE;
}
// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는
이진트리 반환
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
bt->key = x;
bt->left = bt1;
bt->right = bt2;
return bt;
}
// bt2를 bt1의 왼쪽 서브트리로 연결
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
if (bt1->left != NULL)
free(bt1->left);
bt1->left = bt2;
}
// bt2를 bt1의 오른쪽 서브트리로 연결
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
if (bt1->right != NULL)
free(bt1->right);
bt1->right = bt2;
}
// bt의 왼쪽 서브트리를 반환
BinTree* getLSubtree(BinTree* bt) {
return bt->left;
}
// bt의 오른쪽 서브트리를 반환
BinTree* getRSubtree(BinTree* bt) {
return bt->right;
}
// bt의 root 노드에 x 값 저장
void setData(BinTree* bt, BTData x) {
bt-> key = x;
}
// bt의 root에 저장된 데이터를 반환
BTData getData(BinTree* bt) {
return bt->key;
}
// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸
void deleteBT(BinTree* bt) {
if(bt == NULL)
return;
deleteBT(bt->left);
deleteBT(bt->right);
printf("delete tree data: %d \n", bt->key);
free(bt);
}
// 중위 순회
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
if (bt == NULL)
return;
InorderTraverse(bt->left, action);
action(bt->key);
InorderTraverse(bt->right, action);
}
// 전위 순회
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {
if (bt == NULL)
return;
action(bt->key);
PreorderTraverse(bt->left, action);
PreorderTraverse(bt->right, action);
}
// 후위 순회
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {
if (bt == NULL)
return;
PostorderTraverse(bt->left, action);
PostorderTraverse(bt->right, action);
action(bt->key);
}
// 데이터 x가 저장된 노드 탐색
BinTree* searchBST(BinTree* bt, BTData x) {
BinTree* p = bt;
while (p != NULL) {
if (x == p->key) return p;
if (x < p->key) p = p->left;
else p = p->right;
}
printf("ERROR: 찾는 키가 없습니다.\n");
return NULL;
}
// 데이터 x 저장
void insertBST(BinTree* bt, BTData x) {
BinTree* p = bt;
BinTree* parent = NULL;
// 삽입할 노드 탐색
while (p != NULL) {
if (x == p->key) {
printf("ERROR: 이미 같은 키가 있습니다.\n");
return;
}
parent = p;
if (x < p->key) p = p->left;
else p = p->right;
}
// 삽입할 노드 생성
BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
newNode->key = x;
newNode->left = NULL;
newNode->right = NULL;
// 삽입 노드 연결
if (bt == NULL) bt = newNode;
if (x < parent->key) parent->left = newNode;
else parent->right = newNode;
}
// 데이터 x 노드 삭제
void deleteBST(BinTree* bt, BTData x) {
BinTree* q;
BinTree* p = bt;
BinTree* parent = NULL;
p = searchBST(bt, x);
if (p == NULL) {
printf("ERROR\n");
return bt;
}
else if (parent == NULL){
if (p->left == NULL && p->right == NULL){
if (p == bt) {
bt = NULL;
bt->left = NULL;
bt->right = NULL;
return bt;
}
}
else if (p->right == NULL && p->left != NULL){
q = getLSubtree(p->left);
p->key = q->key;
if (p->left == q && q->left == NULL && q->right == NULL) {
p->left = NULL;
}
else deleteBST(p->left, p->key);
}
else if (p->left == NULL && p->right != NULL) {
q = getRSubtree(p->right);
p->key = q->key;
if (p->right == q && q->left == NULL && q->right == NULL)
{
p->right = NULL;
}
else deleteBST(p->right, p->key);
}
else if (p->left != NULL && p->right != NULL) {
q = getLSubtree(p->left);
p->key = q->key;
if (p->left == q && q->left == NULL && q->right == NULL) {
p->left = NULL;
}
else deleteBST(p->left, p->key);
}
}
else {
if (p->left == NULL && p->right == NULL) {
if (parent->left == p)
parent->left = NULL;
else parent->right = NULL;
}
else if (p->left == NULL || p->right == NULL) {
if (p->left != NULL) {
if (parent->left == p)
parent->left = p->left;
else parent->right = p->left;
}
else {
if (parent->left == p)
parent->left = p->right;
else parent->right = p->right;
}
}
else if (p->left != NULL && p->right != NULL) {
q = getLSubtree(p->left);
p->key = q->key;
deleteBST(p->left, p->key);
}
return bt;
}
}
