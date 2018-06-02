#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000
typedef int Elem;
typedef struct tagNode
{
	Elem data;
	struct tagNode *next;
}Node;
Node *stackTop;
int stackLength;
bool stackCreate(int maxsize)
{
	stackTop = NULL;
	stackLength = 0;
	return true;
}
bool stackClear()
{
	while (stackTop)
	{
		Node *temp = stackTop;
		stackTop = stackTop->next;
		free(temp);
	}
	stackLength = 0;
	return true;
}
bool stackPush(const Elem &it)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp) return false;
	temp->data = it;
	temp->next = stackTop;
	stackTop = temp;
	stackLength++;
	return true;
}
bool stackPop(Elem &it)
{
	if (!stackTop) return false;
	it = stackTop->data;
	Node *temp;
	temp = stackTop;
	stackTop = stackTop->next;
	free(temp);
	stackLength--;
	return true;	
}
int stackGetLength()
{
	return stackLength;
}
bool stackGetTopValue(Elem &it)
{
	if (!stackTop)
		return false;
	it = stackTop->data;
	return true;
}