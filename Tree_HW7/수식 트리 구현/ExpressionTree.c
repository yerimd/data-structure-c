#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "LinkedStack.h"
BinTree* createExpTree(char exp[]) {
Stack* S = createStack();
BinTree* bNode;
int expLen = strlen(exp);
int i;
for (i = 0; i < expLen; i++)
{
bNode = createBT();
if (isdigit(exp[i]))
{
setData(bNode, exp[i] - '0');
}
else
{
makeRSubtree(bNode, pop(&S));
makeLSubtree(bNode, pop(&S));
setData(bNode, exp[i]);
}
push(&S, bNode);
}
return pop(&S);
}
int evalExpTree(BinTree* bt) {
int op1, op2;
if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL)
return getData(bt);
op1 = evalExpTree(getLSubtree(bt));
op2 = evalExpTree(getRSubtree(bt));
if (op2 == 0) {
switch (getData(bt)) {
case '+':
return op1 + op2;
case '-':
return op1 - op2;
case '*':
return op1 * op2;
case '/':
printf("ERROR - divide by 0\n");
exit(-1);
}
}
else {
switch (getData(bt)) {
case '+':
return op1 + op2;
case '-':
return op1 - op2;
case '*':
return op1 * op2;
case '/':
return op1 / op2;
}
}
return 0;
}
void showNodeData(int x) {
if(0<=x && x<=9) // 피연산자 출력
printf("%d ", x);
else // 연산자 출력
printf("%c ", x);
}
void showPrefixExp(BinTree* bt) {
PreorderTraverse(bt, showNodeData);
}
void showInfixExp(BinTree* bt) {
if(bt == NULL)
return;
if(bt->left != NULL || bt->right != NULL)
printf(" ( ");
showInfixExp(bt->left); // 첫 번째 피연산자 출력
showNodeData(bt->data); // 연산자 출력
showInfixExp(bt->right); // 두 번째 피연산자 출력
if(bt->left != NULL || bt->right != NULL)
printf(" ) ");
}
void showPostfixExp(BinTree* bt) {
PostorderTraverse(bt, showNodeData);
}
