#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000
typedef int Elem;
int stackSize;
int stackTop;
Elem *stackArray;
bool stackCreate(int maxsize)
{
	if (maxsize<0 || maxsize>MAX_SIZE)
		return false;
	stackArray = (Elem *)malloc(sizeof(Elem));
	if (!stackArray)
		return false;
	stackSize = maxsize;
	stackTop = 0;
	return true;
}
bool stackClear()
{
	if (stackArray)
		free(stackArray);
	stackArray = NULL;
	stackTop = 0;
	stackSize = 0;
	return true;
}
bool stackPush(const Elem &it)
{
	if (stackTop >= stackSize)
		return false;
	stackArray[stackTop++] = it;
	return true;
}
bool stackPop(Elem &it)
{
	if (stackTop == 0)
		return false;
	it = stackArray[--stackTop];
	return true;
}
int stackGetLength()
{
	return stackTop;
}
bool stackGetTopValue(Elem &it)
{
	if (stackTop == 0)
		return false;
	it = stackArray[stackTop-1];
	return true;
}