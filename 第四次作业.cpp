#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000
typedef int Elem;
typedef struct tagLink
{
	Elem data;
	struct tagLink *next;
}Link;
Link *stackTop;
int stackLength;
Link *listHead;
Link *listTail;
Link *listCur;
int listLength;
bool listCreate(int maxsize)
{
	listHead = NULL;
	listTail = NULL;
	listCur = NULL;
	listLength = 0;
	return true;
}
bool listClear()
{
	Link *temp;
	while (listHead)
	{
		temp = listHead;
		listHead = listHead->next;
		free(temp);
	}
	listLength = 0;
	return true;
}
bool listPrint()
{
	printf("<");
	Link *temp=listHead;
	while (temp != listCur)
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
	return true;
}
bool listInsert(const Elem &it)
{
	Link *temp;
	temp = (Link *)malloc(sizeof(Link));
	if (!temp) return false;
	temp->data = it;
	if (listCur!=NULL)
	{
		temp->next = listCur->next;
		listCur->next = temp;
		if (listCur->next == NULL) listTail = temp;
	}
	else
	{
		listHead = temp;
		listTail = temp;
		listCur = temp;
		temp->next = NULL;		
	}
	listLength++;
	return true;
}
bool stackCreate( int maxsize)
{
	stackTop = NULL;
	stackLength = 0;
	return true;
}
bool stackClear()
{	
	while (stackTop!=NULL)
	{
		Link *temp = stackTop;
		stackTop = stackTop->next;
		free(temp);
	}
	stackLength = 0;
	return true;
}
bool stackPush(const Elem &it)
{
	Link *temp;
	temp = (Link *)malloc(sizeof(Link));
	if (temp==NULL) return false;
	temp->data = it;
	temp->next = stackTop;
	stackTop = temp;
	stackLength++;
	return true;
}
bool stackPop(Elem &it)
{
	Link *temp;
	if (stackTop==NULL) return false;
	it = stackTop->data;
	temp = stackTop;
	stackTop = stackTop->next;
	free(temp);
	stackLength--;
	return true;
}
void listReverse(Link *s)
{
	Link *temp=listHead;
	Elem a;	
	int i;
	printf("The result is:\n");
	stackCreate(1000);
	while (temp!=NULL)
	{
		stackPush(temp->data);
		temp = temp->next;
	}
	printf("<");
	
	for (i = 0; i < 20; i++)
	{
		stackPop(a);
		printf("%d ", a);
	}
	printf(">\n");
	stackClear();
}
int main()
{
	srand((unsigned)time(0));
	listCreate(1000);
	for (int i = 0; i<20; i++)
		listInsert(rand() % 1000);
	listPrint();
	listReverse(listHead);
	listClear();
	system("pause");
	return 0;
}