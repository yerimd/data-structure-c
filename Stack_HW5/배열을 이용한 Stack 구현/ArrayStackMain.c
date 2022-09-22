#include <stdio.h>
#include "ArrayStack.h"
int main() {
Stack* S;
element item;
int i;
printf("(1) 공백 스택 생성하기\n");
S = create();
displayStack(S);
printf("\n(2) 스택에 10, 20, 30을 차례로 삽입\n");
push(S,10);
push(S,20);
push(S,30);
printf("\n(3) 현재 top의 요소를 출력\n");
peek(S);
printf("\n(4-1) 스택에서 요소 삭제\n");
pop(S);
printf("\n(4-2) 스택에서 요소 삭제\n");
pop(S);
printf("\n(4-3) 스택에서 요소 삭제\n");
pop(S);
printf("\n(4-4) 스택에서 요소 삭제\n");
pop(S);
printf("\n(5) 스택 비우기\n");
clear(S);
displayStack(S);
return 0;
}
