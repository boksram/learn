#define _CRT_SECURE_NO_WARNINGS 1
#include "STLNode.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = malloc(sizeof(SListNode));
	if (!newnode)
	{
		perror("malloc");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

void SListPrint(SListNode* plist)
{
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL");
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* p = BuySListNode(x);
	if (p == NULL)
	{
		perror("malloc");
	}
	else
	{
		if (*pplist == NULL)
		{
			*pplist = p;
		}
		else
		{
			SListNode* temp = *pplist;
			while (temp->next)
				temp = temp->next;
			temp->next = p;
		}
	}

}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if (!(*pplist)->next)
	{
		*pplist = NULL;
	}
	else
	{
		SListNode* p = *pplist;
		while (p->next->next)
		{
			p = p->next;
		}
		free(p->next);
		p->next= NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* p = *pplist;
	*pplist = p->next;
	free(p);
	p = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	while (plist)
	{
		if (plist->data == x)
			return plist;
		plist = plist->next;
	}
	return plist;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* p = BuySListNode(x);
	p->next = pos->next;
	pos->next = p;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* p = pos->next;
	pos->next = pos->next->next;
	free(p);
	p = NULL;
}

void SListDestroy(SListNode* plist)
{
	while (plist)
	{
		SListPopBack(&plist);
	}
}

