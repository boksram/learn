#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SLTDateType x);
void SListPrint(SListNode* plist);
void SListPushFront(SListNode** pplist, SLTDateType x);
void SListPushBack(SListNode** pplist, SLTDateType x);
void SListPopBack(SListNode** pplist);
void SListPopFront(SListNode** pplist);
SListNode* SListFind(SListNode* plist, SLTDateType x);
void SListInsertAfter(SListNode* pos, SLTDateType x);
void SListEraseAfter(SListNode* pos);
void SListDestroy(SListNode* plist);