#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu() 
{
	printf("******1、ADD      2、DELETE******\n");
	printf("******3、SEARCH   4、EDIT  ******\n");
	printf("******5、SHOW     6、CLEAR ******\n");
	printf("******7、SORT     0、EXIT  ******\n");
}

enum SELECT
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	EDIT,
	SHOW,
	CLEAR,
	SORT
};

struct contact con;

void test()
{
	contact_init(&con);
	int i;
	do
	{
		menu();
		scanf("%d", &i);
		switch (i)
		{
		case ADD:
			contact_add(&con);
			break;
		case DELETE:
			contact_delete(&con);
			break;
		case SEARCH:
			contact_search(&con);
			break;
		case EDIT:
			contact_edit(&con);
			break;
		case SHOW:
			contact_show(&con);
			break;
		case CLEAR:
			contact_init(&con);
			printf("清空成功:>\n");
			break;
		case SORT:
			contact_sort_name(&con);
			break;
		case EXIT:
			printf("退出成功:>\n");
		}
		printf("\n");
	} while (i);
}

int main()
{
	test();
	return 0;
}