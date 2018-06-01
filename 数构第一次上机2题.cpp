#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int ET;
typedef struct SNode
{
	ET data;
	SNode *next;
}Node;
Node *head;
Node *tail;
Node *cur;
int length;
bool listCreate()
{
	head = NULL;
	tail = NULL;
	cur = NULL;
	length = 0;
	return true;
}
ET listGet(int i)
{
	int k;
	Node *temp = head;
	for (k = 1; k<i; k++)
	{
		temp = temp->next;
	}
	return temp->data;
}
int listLocate(ET const &it)
{
	int i = 0;
	Node *temp = head;
	while (temp->data != it)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
void listInsert(ET const &it)
{
	Node *temp;
	temp = new Node;
	if (temp == NULL) return;
	temp->data = it;
	if (cur != NULL)
	{
		temp->next = cur->next;
		cur->next = temp;
		if (tail == cur)
			tail = temp;
	}
	else
	{
		temp->next = NULL;
		head = temp;
		tail = temp;
		cur = temp;
	}
	length++;
}
void listAppend(const ET &it)
{
	Node *temp;
	temp = new Node;
	if (temp == NULL) return;
	temp->data = it;
	temp->next = NULL;
	if (tail != NULL)
		tail->next = temp;
	tail = temp;
	if (head == NULL)
	{
		head = temp;
		cur = head;
	}
	length++;
}
void listDelete(ET &it)
{
	Node *prev, *temp;
	if (cur == NULL) return;
	it = cur->data;
	temp = cur;
	if (cur == head)
	{
		cur = cur->next;
		head = cur;
		if (cur == NULL)
			tail = NULL;
	}
	else
	{
		prev = head;
		while (prev&&prev->next != cur)
			prev = prev->next;
		prev->next = cur->next;
		if (cur->next != NULL)
			cur = cur->next;
		else
		{
			tail = prev;
			cur = prev;
		}
	}
	delete temp;
	length--;
}
void display()
{
	if (head == NULL)
		return;
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void listSort()
{
	if (length <= 1) return;
	int i, j, t;
	Node *p, *q, *temp = head;
	for (i = 0; i < length - 1; i++)
	{
		temp = head;
		for (j = 0; j < length - i - 1; j++)
		{
			p = temp;
			q = temp->next;
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			temp = temp->next;
		}
	}
}
void Josephus(int n, int m)
{
	int i, j, out;
	listCreate();
	for (i = 1; i <= n; i++)
		listAppend(i);
	display();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m - 1; j++)
		{
			if (cur->next == NULL) cur = head;
			else cur = cur->next;
		}
		if (cur->next != NULL) listDelete(out);
		else
		{
			listDelete(out);
			cur = head;
		}
		printf(" %d", out);
	}
	printf("\nWinner is: %d\n", out);
}
int main()
{
	ET it;
	listCreate();
	int a[5] = { 320,321,453,213,776 };
	for (int i = 0; i < 5; i++)
		listInsert(a[i]);
	display();
	printf("%d\n", listGet(3));
	printf("%d\n", listLocate(213));
	listDelete(it);
	display();
	listSort();
	display();
	Josephus(8, 3);	
	return 0;
}

