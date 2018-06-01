#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#define MAX_SIZE 1000
typedef int Elem;
typedef struct tagNode
{
	Elem data;
	struct tagNode *next;
}Node;
typedef struct
{
	Node *stackTop;
	int stackLength;
}stackTop;
stackTop stackTop1, stackTop2;
Elem minimum;
bool stackCreate(int maxsize,stackTop &s)
{
	s.stackTop = NULL;
	s.stackLength = 0;
	return true;
}
bool stackClear(stackTop &s)
{
	while (s.stackTop)
	{
		Node *temp = s.stackTop;
		s.stackTop = s.stackTop->next;
		free(temp);
	}
	s.stackLength = 0;
	return true;
}
bool stackPush2(const Elem &it, stackTop &s)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp) return false;
	temp->data = it;
	temp->next = s.stackTop;
	s.stackTop = temp;
	s.stackLength++;
	return true;
}
bool stackPush(const Elem &it,stackTop &s)
{
	if (s.stackTop == NULL) minimum = it;
	if (it < minimum) minimum = it;
	stackPush2(minimum, stackTop2);
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp) return false;
	temp->data = it;
	temp->next = s.stackTop;
	s.stackTop = temp;
	s.stackLength++;
	return true;
}

bool stackPop2(Elem &it, stackTop &s)
{
	Node *temp;
	temp = s.stackTop;
	s.stackTop = s.stackTop->next;
	free(temp);
	s.stackLength--;
	return true;
}
bool stackPop(Elem &it,stackTop &s)
{
	if (!s.stackTop) return false;
	it = s.stackTop->data;
	if (it == minimum)
		stackPop2(minimum, stackTop2);
	Node *temp;
	temp = s.stackTop;
	s.stackTop = s.stackTop->next;
	free(temp);
	s.stackLength--;
	return true;
}

Elem MIN()
{
	minimum = stackTop2.stackTop->data;
	return minimum;
}
bool stackPrint(stackTop &s)
{
	printf("<");
	Node *temp = s.stackTop;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf(">\n");
	return true;
}
int main()
{
	srand((unsigned)time(0));
	stackCreate(1000, stackTop1);
	stackCreate(1000, stackTop2);
	for (int i = 0; i < 5; i++)
	{
		stackPush(rand() % 1000, stackTop1);
		stackPrint(stackTop1);
		printf("The minimum is %d\n", MIN());
	}
	for (int i = 0; i < 4; i++)
	{
		stackPop(minimum, stackTop1);
		stackPrint(stackTop1);
		printf("The minimum is %d\n", MIN());
	}
	stackClear(stackTop1);
	stackClear(stackTop2);
	system("pause");
	return 0;
}
