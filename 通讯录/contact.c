#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void contact_init(struct contact* p)
{
	memset(p->DS, 0, sizeof(p->DS));
	p->sz = 0;
}

void contact_add(struct contact* p)
{
	if (p->sz == 100)
	{
		printf("ͨѶ¼����.\n");
			return;
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", p->DS[p->sz].name);
		printf("�������Ա�:>\n");
		scanf("%s", p->DS[p->sz].sex);
		printf("����������:>\n");
		scanf("%d", &p->DS[p->sz].age);
		printf("������绰����:>\n");
		scanf("%s", p->DS[p->sz].number);
		printf("�������ַ:>\n");
		scanf("%s", p->DS[p->sz].address);
		p->sz++;
	}
}

void contact_delete(struct contact* p)
{
	if (p->sz == 0)
	{
		printf("ͨѶ¼�ѿ�:>\n");
			return;
	}
	else
	{
		char arr[20];
		printf("������Ҫɾ���˵�����:>\n");
		scanf("%s", arr);
		int i;
		for (i = 0; i < p->sz; i++)
		{
			if (strcmp(arr, p->DS[i].name) == 0)
				break;
		}
		for (; i < p->sz - 1; i++)
		{
			p->DS[i] = p->DS[i + 1];
		}
		memset(p->DS + p->sz - 1, 0, sizeof(p->DS[0]));
		p->sz--;
		printf("��ɾ��:>\n");
	}
}

void contact_search(struct contact* p)
{
	char arr[20];
	printf("������Ҫ�����˵�����:>\n");
	scanf("%s", arr);
	int i;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(arr, p->DS[i].name) == 0)
			break;
	}
	if (i < p->sz)
		printf("%-4s %-1s %-3d %-11s %-5s\n", p->DS[i].name, p->DS[i].sex,
			p->DS[i].age, p->DS[i].number, p->DS[i].address);
	else
		printf("���޴���:>\n");
}

void contact_edit(struct contact* p)
{
	char arr[20];
	printf("������Ҫ�޸��˵�����:>\n");
	scanf("%s", arr);
	int i;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(arr, p->DS[i].name) == 0)
			break;
	}
	if (i <= p->sz)
	{
		printf("�������޸ĺ����Ϣ:>\n");
		printf("����������:>\n");
		scanf("%s", p->DS[i].name);
		printf("�������Ա�:>\n");
		scanf("%s", p->DS[i].sex);
		printf("����������:>\n");
		scanf("%d", &p->DS[i].age);
		printf("������绰����:>\n");
		scanf("%s", p->DS[i].number);
		printf("�������ַ:>\n");
		scanf("%s", p->DS[i].address);
		printf("�޸ĳɹ�\n");
	}
	else
		printf("���޴���:>\n");
}

void contact_show(struct contact* p)
{
	printf("��ӡ����:>\n");
	int i = 0;
	while (*p->DS[i].name)
	{
		printf("%-4s %-1s %-3d %-11s %-5s\n", p->DS[i].name, p->DS[i].sex,
			p->DS[i].age, p->DS[i].number, p->DS[i].address);
		i++;
	}
}

int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((struct contact*)p1)->DS->name, ((struct contact*)p2)->DS->name);
}

void contact_sort_name(struct contact* p)
{
	qsort(p->DS, p->sz, sizeof(p->DS[0]), cmp_name);
	printf("�������:>\n");
}
