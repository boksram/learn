#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void contact_init(struct contact* p);
void contact_add(struct contact* p);
void contact_delete(struct contact* p);
void contact_search(struct contact* p);
void contact_edit(struct contact* p);
void contact_show(struct contact* p);
void contact_sort_name(struct contact* p);

struct personaldata
{
	char name[20];
	char sex[10];
	int age;
	char number[12];
	char address[20];
};

struct contact
{
	struct personaldata DS[100];
	int sz;
};