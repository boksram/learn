#define _CRT_SECURE_NO_WARNINGS 1

#include "DSList.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* list = malloc(sizeof(ListNode));
	if (list == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	else
		return list;
}

ListNode* ListCreate()
{
	ListNode* list = malloc(sizeof(ListNode));
	list->next = list->prev = list;
	return list;
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* list = pHead->next;
	while (list != pHead)
	{
		ListNode* temp = list->next;
		free(list);
		list = temp;
	}
	free(pHead);
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* list = pHead->next;
	printf("phead<->", pHead->data);
	while (list != pHead)
	{
		printf("%d<->", list->data);
		list = list->next;
	}
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead,x);
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListErase(pHead->prev);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->prev != pHead);
	ListErase(pHead->next);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* temp = pHead->next;
	while (temp != pHead)
	{
		if (temp->data == x)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* list = BuyListNode(x);
	ListNode* p = pos->prev;
	list->next = pos;
	pos->prev = list;
	list->prev = p;
	p->next = list;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* p = pos->prev;
	ListNode* n = pos->next;
	p->next = n;
	n->prev = p;
	free(pos);
}
