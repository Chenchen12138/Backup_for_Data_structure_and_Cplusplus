#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#define LIST_MAXSIZE 10000
typedef int Elem;
Elem *listArray;
int listLength;
int listSize;
int listCurpos;
bool listCreate(int maxsize)
{
	if (maxsize < 0 || maxsize > LIST_MAXSIZE)
		return false;
	listArray = (Elem*)malloc(maxsize * sizeof(Elem));
	if (listArray == NULL)
		return false;
	listLength = 0;
	listSize = maxsize;
	listCurpos = 0;
	return true;
}
bool listClear()
{
	if (listArray)
	{
		free(listArray);
		listArray = NULL;
	}
	listLength = 0;
	listSize = 0;
	listCurpos = 0;
	return true;
}
bool listSetStart()
{
	if (listLength > 0)
	{
		listCurpos = 0;
		return true;
	}
	return false;
}
bool listSetEnd()
{
	if (listLength > 0)
	{
		listCurpos = listLength - 1;
		return true;
	}
	return false;
}
bool listNext()
{
	if (listCurpos < listLength - 1)
	{
		listCurpos++;
		return true;
	}
	return false;
}
bool listPrev()
{
	if (listCurpos <= 0)
		return false;
	else
	{
		listCurpos--;
		return true;
	}
}
bool listSetPos(Elem pos)
{
	if (pos >= 0 && pos <= listLength - 1)
	{
		listCurpos = pos;
		return true;
	}
	return false;
}
Elem listGetLength()
{
	return listLength;
}
bool listGetValue(Elem &it)
{
	if (listCurpos >= 0 && listCurpos <= listLength - 1)
	{
		it = listArray[listCurpos];
		return true;
	}
	return false;
}
void listPrint()
{
	int i;
	printf("<");
	for (i = 0; i < listCurpos; i++)
		printf("%d ", listArray[i]);
	printf("*");
	for (; i < listLength; i++)
		printf("%d ", listArray[i]);
	printf(">\n");
}
bool listInsert(const Elem &it)
{
	int i;
	if (listLength >= listSize)
		return false;
	for (i = listLength; i > listCurpos; i--)
		listArray[i] = listArray[i - 1];
	listArray[listCurpos] = it;
	listLength++;
	return true;
}
bool listRemove(Elem &it)
{
	int i;
	if (listLength == 0)
		return false;
	it = listArray[listCurpos];
	for (i = listCurpos; i < listLength - 1; i++)
		listArray[i] = listArray[i + 1];
	if (listCurpos == listLength - 1)
		listCurpos--;
	listLength--;
	return true;
}
bool listAppend(const Elem &it)
{
	if (listLength >= listSize)
		return false;
	listArray[listLength] = it;
	listLength++;
	return true;
}
bool listIsEnd()
{
	if (listLength > 0 && listCurpos == listLength - 1)
		return true;
	return false;
}
void Josephus(int n, int m, int k)
{
	int i, j, a;
	listCreate(LIST_MAXSIZE);
	for (i = 1; i <= n; i++)
		listAppend(i);
	listPrint(); printf("Out:");
	for (i = k; i <= n; i++)
	{
		for (j = 1; j <= m - 1; j++)
		{
			if (listIsEnd()!=1)
				listNext();
			else listSetStart();

		}
		if (listIsEnd()!=1)
			listRemove(a);
		else
		{
			listRemove(a);
			listSetStart();
		}
		printf("%d ", a);
	}
	printf("\nwinner:%d\n", a);
	listClear();
}
int main()
{
	int n, m, k;
	printf("Please input n,m,k\n");
	scanf_s("%d,%d,%d", &n, &m, &k);
	Josephus(n, m, k);
	system("pause");
	return 0;

}
