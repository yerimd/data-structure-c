#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList2.h"
linkedList* initList() {
linkedList* L;
L = (linkedList*)malloc(sizeof(linkedList));
L->head = NULL;
L->length = 0;
return L;
}
int getLength(linkedList* L) { // SLinkedList.c와 동일
return L->length;
}
void insert(linkedList* L, listNode* pre, element x) { // SLinkedList.c와 동일
listNode* newNode;
newNode = (listNode*)malloc(sizeof(listNode));
listNode* newNode;
newNode = (listNode*)malloc(sizeof(listNode));
newNode->data = x;
if (L->head == NULL) {
newNode->link = NULL;
L->head = newNode;
}
else if (pre == NULL) {
newNode->link = L->head;
L->head = newNode;
}
else {
newNode->link = pre->link;
pre->link = newNode;
}
L->length++;
}
void insertFirst(linkedList* L, element x) { // SLinkedList.c와 동일
listNode* newNode;
newNode = (listNode*)malloc(sizeof(listNode));
newNode->data = x;
newNode->link = L->head;
L->head = newNode;
L->length++;
}
}
void insertLast(linkedList* L, element x) { // SLinkedList.c와 동일
listNode *newNode, *temp;
newNode = (listNode*)malloc(sizeof(listNode));
newNode->data = x;
newNode->link = NULL;
if (L->head == NULL)
L->head = newNode;
else {
temp = L->head;
while (temp->link != NULL)
temp = temp->link;
temp->link = newNode;
}
L->length++;
}
int delete(linkedList* L, listNode* p) { // SLinkedList.c와 동일
listNode* pre;
if (L->head == NULL) return FALSE;
if (p == NULL) return FALSE;
if (L->head == p) {
L->head = p->link;
free(p);
}
else {
pre = L->head;
while (pre->link != p) {
pre = pre->link;
if (pre == NULL) return FALSE;
}
pre->link = p->link;
free(p);
}
L->length--;
return TRUE;
}
listNode* search(linkedList* L, element x) { // SLinkedList.c와 동일
listNode* temp = L->head;
while (temp != NULL) {
if (temp->data == x)
return temp;
else
temp = temp->link;
}
return temp;
}
void displayList(linkedList* L) {
listNode* p;
printf("L=(");
p = L->head;
while(p != NULL) {
printf("%s", p->data);
p = p->link;
if(p != NULL) printf(", ");
}
printf(")\n");
}
void clear(linkedList* L) {
listNode* p;
while(L->head != NULL) {
p = L->head;
L->head = L->head->link;
free(p);
p = NULL;
}
}
void reverse(linkedList* L) {
ListNode* p, * q, * r;
p = head;
q = NULL;
while (p != NULL) {
r = q;
q = p;
p = p->link;
q->link = r;
}
return q;
}
