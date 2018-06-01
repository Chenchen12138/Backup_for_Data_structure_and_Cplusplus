#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#define MAX_SIZE 10000
typedef int Elem;
typedef struct tagLink
{
	int data;
	struct tagLink *next;
}Link;
Link *head = NULL;
Link *tail = NULL;
Link *cur = NULL;
int length = 0;
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
	printf("<");
	if (head)
	{
		Link *temp = head;
		while (temp != cur)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("*");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	printf(">\n");
}
bool listClear()
{
	Link *temp;
	while (head != NULL)
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
bool listInsert(const Elem &it)
{
	Link *temp;
	temp = (Link *)malloc(sizeof(Link));
	if (!temp) return false;
	temp->data = it;
	if (cur != NULL)
	{
		temp->next = cur->next;
		cur->next = temp;
		if (tail == cur) tail = temp;
	}
	else
	{
		head = temp;
		temp->next = NULL;
		cur = temp;
		tail = temp;
	}
	length++;
	return true;
}
bool DeleteNode(Link *head, Link *deleted)
{
	Link *temp;
	if (head == NULL||deleted==tail) 
		return false;
	temp = deleted;
	temp = temp->next;
	deleted->data = temp->data;
	deleted->next = temp->next;
	free(temp);
	return true;
}
int main()
{
	int i,n;
	srand((unsigned)time(0));
	listCreate(1000);
	for (i = 0; i < 20; i++)
		listInsert(rand() % 1000);
	listPrint();
	printf("Please input the number to delete(0<n<19)\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		cur = cur->next;
	DeleteNode(head, cur);
	listPrint();
	listClear();
	system("pause");
	return 0;
}