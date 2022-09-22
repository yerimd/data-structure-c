#ifndef __POLY_LINKED_LIST_H__
#define __POLY_LINKED_LIST_H__

typedef struct PolyNode {
	float coef;
	int exp;
	struct PolyNode* link;
}Node;

typedef struct PolyList {
	Node* head;
	Node* last;
}polyList;

polyList* initList();		// 공백리스트 생성 
void appendTerm(polyList* PL, float coef, int exp);		// 다항식 리스트 마지막 노드로 항 추가 
polyList* addPoly(polyList* A, polyList* B);			// 두 다항식의 덧셈 
void displayPoly(polyList* PL);							// 다항식 리스트의 모든 요소 출력

#endif
