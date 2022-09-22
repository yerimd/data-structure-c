#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h" // 배열로 구현한 스택 이용시 주석 해제
//#include "LinkedStack.h" // 연결리스트로 구현한 스택 이용시 주석 해제
int testPair(char* exp) {
Stack* S = (Stack*)malloc(sizeof(Stack));
S = create();
char symbol, lparen;
int i, length = strlen(exp);

 for (i = 0; i < length; i++) {
 symbol = exp[i];
 switch (symbol) {
 case '(':
 case '[':
 case '{':
 push(S, symbol);
 break;
 case ')':
 case ']':
 case '}':
 if (isEmpty(S))
 return 0;
 else
 {
 lparen = pop(S);
 if ((lparen == '(') && symbol != ')' || (lparen == '[') &&
symbol != ']' || (lparen == '{') && symbol != '}')
 return 0;
 }
 break;
 }
 }
 if (!isEmpty(S))
 return 0;
 return 1;
}
int main() {
int i;
char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )",
"{A / (B - C)}"};
for(i=0; i<4; i++) {
printf("%s ", x[i]);
if(testPair(x[i]))
printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
else
printf("-> 수식의 괄호가 틀렸습니다!\n");
}
return 0;
}
