#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"
polyList* initList() {
polyList* PL = (polyList*)malloc(sizeof(polyList));
PL->head = NULL;
PL->last = NULL;
return PL;
}
void appendTerm(polyList* PL, float coef, int exp) {
// Fill your code
Node* newNode;
Node* p; newNode = (Node*)malloc(sizeof(Node));
newNode->coef = coef;
newNode->exp = exp;
newNode->link = NULL;
if (PL->head == NULL) { PL->head = newNode;
return;
}
else { p = PL->head;
while (p->link != NULL) {
p = p->link;
}
p->link = newNode;
}
}
polyList* addPoly(polyList* A, polyList* B) {
polyList* C = initList();
Node* polyA = A->head;
Node* polyB = B->head;
// Fill your code
int sum;
while (polyA && polyB) {
if (polyA->exp == polyB->exp) {
sum = polyA->coef + polyB->coef; appendTerm(C, sum,
polyA->exp);
polyA = polyA->link; polyB = polyB->link;
}
else if (polyA->exp > polyB->exp) {
appendTerm(C, polyA->coef, polyA->exp);
polyA = polyA->link;
}
else {
appendTerm(C, polyB->coef, polyB->exp);
polyB = polyB->link;
}
}
for (; polyA != NULL; polyA = polyA->link)
appendTerm(C, polyA->coef, polyA->exp);
for (; polyB != NULL; polyB = polyB->link)
appendTerm(C, polyB->coef, polyB->exp);
return C;
}
void displayPoly(polyList* PL) {
Node* p = PL->head;
for(; p; p=p->link) {
printf("%3.0fx^%d", p->coef, p->exp);
if(p->link != NULL)
printf(" +");
}
printf("\n");
}
