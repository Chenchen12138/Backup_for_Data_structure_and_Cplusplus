#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#define MAX_SIZE 10000
typedef int Elem;
typedef struct tagNode
{
	Elem data;
	struct tagNode *next;
}Node;
Node *head;
Node *tail;
Node *cur;
int length;
bool listCreate(int maxsize)
{
	head = NULL;
	tail = NULL;
	cur = NULL;
	length = 0;
	return true;
}
void listPrint()
{
	Node *temp=head;
	printf("<");
	if (head!=NULL)
	{
		while (temp != cur)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("*");
		while (temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf(">\n");
	}
}
bool listAppend(const Elem &it)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp) return false;
	temp->data = it;
	temp->next = NULL;
	if (tail!=NULL)
	{
		tail->next = temp;
		tail = temp;
	}
	if(head==NULL)
	{
		head = temp;
		tail = temp;
		cur = temp;
	}
	length++;
	return true;
}
bool listInsert(const Elem &it)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp) return false;
	temp->data = it;
	if (head!=NULL)
	{
		if (cur != tail)
		{
			temp->next = cur->next;
			cur->next = temp;
		}
		else
		{
			temp->next = NULL;
			cur->next = temp;
			tail = temp;
		}
	}
	else
	{
		head = temp;
		tail = temp;
		cur = temp;
	}
	length++;
	return true;
}
bool listMin(Elem &it,int &k)
{
	Node *temp;
	int i;
	k = 0;
	if (head)
	{
		temp = head;
		it = head->data;
		for(i=0;temp;i++)
		{
			if (temp->data < it)
			{
				it = temp->data;
				k = i;
			}

			temp = temp->next;
		}
		return true;
	}
	return false;
}
bool listClear()
{
	Node *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	head = NULL;
	tail = NULL;
	cur = NULL;
	length = 0;
	return true;
}

int main()
{
	int n,i,k;
	Elem m;
	srand((unsigned)time(0));
	printf("Please input n:\n");
	scanf_s("%d", &n);
	listCreate(1000);
	for (i = 0; i < n; i++)
		listInsert(rand() % 1000);
	listPrint();
	listMin(m, k);
	printf("The minimum is %d\nThe number is %d\n", m, k);
	listClear();
	system("pause");
	return 0;
}