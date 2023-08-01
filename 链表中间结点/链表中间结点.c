#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* p1 = head;
    struct ListNode* p2 = head;
    while (p2->next->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if (p2->next)
    {
        p1 = p1->next;
    }
    return p1;
}

int main()
{
    struct ListNode* p1 = malloc(sizeof(struct ListNode));
    struct ListNode* p2 = malloc(sizeof(struct ListNode));
    struct ListNode* p3 = malloc(sizeof(struct ListNode));
    struct ListNode* p4 = malloc(sizeof(struct ListNode));
    struct ListNode* p5 = malloc(sizeof(struct ListNode));
    struct ListNode* p6 = malloc(sizeof(struct ListNode));
    struct ListNode* p7 = malloc(sizeof(struct ListNode));
    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p5->val = 5;
    p6->val = 6;
    p7->val = 7;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = NULL;
    struct ListNode* ps = middleNode(p1);
}