#define _CRT_SECURE_NO_WARNINGS 1
#include "STLNode.h"
int main()
{
	SListNode* p1 = malloc(sizeof(SListNode));
	SListNode* p2 = malloc(sizeof(SListNode));
	SListNode* p3 = malloc(sizeof(SListNode));
	SListNode* p4 = malloc(sizeof(SListNode));
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	SListPushFront(&p1, 9);
	SListPushBack(&p1, 8);
	SListPopBack(&p1);
	SListPopFront(&p1);
	SListInsertAfter(p1, 8);
	SListEraseAfter(p2);
	SListPrint(p1);
	SListDestroy(p1);
	return 0;
}