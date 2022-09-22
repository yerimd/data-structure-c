#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// 배열의 최대 크기

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// 배열 정의
	int length;		// 현재 배열에 저장된 자료들의 개수
}ArrayListType;

// 오류 처리 함수
void error(char *message)
{
	printf("%s\n", message);
}

// 리스트 초기화
void init(ArrayListType *L)
{
	L->length = 0;
}

// 빈 리스트 검사
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isEmpty(ArrayListType *L)
{
	return L->length == 0;
}

// 리스트가 포화상태인 검사
// 리스트가 가득차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isFull(ArrayListType *L)
{
	return L->length == MAX_SIZE;
}

// 리스트의 모든 요소 출력
void display(ArrayListType *L)
{
	int i;
	printf("===Print Lists===\n");
	for (i=0; i<L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// 삽입 함수 
// pos: 삽입하고자 하는 위치
// item: 삽입하고자 하는 자료
void insert(ArrayListType *L, int pos, element item)
{
	// Fill your code

}

// 리스트 맨 앞에 요소 삽입
void insertFirst(ArrayListType *L, element item)
{
	// Fill your code
	// Fill your code

}

// 리스트 맨 끝에 요소 삽입
void insertLast(ArrayListType *L, element item)
{
	// Fill your code
	
}

// 삭제 함수
// pos: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element delete(ArrayListType *L, int pos)
{
	// Fill your code
		
}

// 리스트의 모든 요소 삭제
void clear(ArrayListType *L)
{
	// Fill your code
	
}

// pos 위치의 요소를 item으로 교체
void replace(ArrayListType *L, int pos, element item)
{
	// Fill your code
	
}


int main()
{
	ArrayListType* plist;

	// ListType를 동적으로 생성하고 ListType를 가리키는 
	// 포인터를 함수의 파라미터로 전달한다.
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	insert(plist, 0, 10);
	insert(plist, 0, 20);
	insertFirst(plist, 5);
	insertLast(plist, 30);
	insert(plist, -1, 3);
	display(plist);
	
	delete(plist, 2);
	display(plist);
	
	replace(plist, 1, 50);
	display(plist);
	free(plist);

	return 0;
}
