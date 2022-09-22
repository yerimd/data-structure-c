#include <stdio.h>
#include "SLinkedList2.h"
int main(){
linkedList* L;
listNode* p;
printf("(1)공백리스트 생성하기\n");
init(&list);
printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");
L.insertLastNode("월");
L.insertLastNode("수");
L.insertLastNode("일");
L.printList();
printf("\n(3)목 노드 뒤에 일 노드 삽입하기\n");
ListNode pre = L.searchNode("목");
if (pre == null) {
}
else {
L.insertMiddleNode(L, "일");
L.printList();
printf("\n(4)리스트에서 수 노드 탐색하기\n");
listNode* search(L, "수")
printf("\n(5)리스트 순서를 역순으로 바꾸기\n");
// Fill your code
clear(L);
return 0;
}
