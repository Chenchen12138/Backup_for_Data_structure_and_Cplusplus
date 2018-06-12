#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class LinkedList
{
private:
	template <class T>
	class LNode
	{
	public:
		T data;
		LNode* next;
	};
	LNode<T> *head;
	LNode<T> *tail;
	LNode<T> *cur;
	int size;
public:
	LinkedList();
	LinkedList(const LinkedList<T> &a);
	~LinkedList();
	void Clear();
	LinkedList<T>* Locate(int pos);
	void LinkInsert(T &a, int pos);
	void LinkDelete(T &a,int pos);
	void Linkchange(T &a, int pos);
	LinkedList<T> &operator =(const LinkedList<T> &a);
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	cur = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &a)
{
	int n = a.size;
	size = n;
	head = new LNode<T>;
	LNode<T> *temp1 = head;
	LNode<T> *temp2 = a.head;
	while (n--)
	{
		temp1->data = temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

template <class T>
void LinkedList<T>::Clear()
{
	LNode<T>* temp = head;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	head = NULL;
	tail = NULL;
	cur = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

template <class T>
LinkedList<T>* LinkedList<T>::Locate(int pos)
{
	int i = 0;
	LNode<T>* temp = head;
	if (pos < 0)
		return NULL;
	while (temp != NULL && i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

template <class T>
void LinkedList<T>::LinkInsert(T &a,int pos)
{
	LNode<T> *p = Locate(pos);
	LNode<T> *temp = new LNode<T>(a);
	temp->next = p->next;
	p->next = temp;
	size++;
}

template <class T>
void LinkedList<T>::LinkDelete(T &a, int pos)
{
	LNode<T> *p = Locate(pos);
	LNode<T> *temp = head;
	while (temp->next != p)
	{
		temp = temp->next;
	}
	temp->next = p->next;
	delete p;
	size--;
}

template <class T>
void LinkedList<T>::Linkchange(T &a, int pos)
{
	LNode<T> *p = Locate(pos);
	p->data = a;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T> &a)
{
	int n = a.size;
	clear();
	head = new LNode<T>;
	LNode<T> *temp1 = head;
	LNode<T> *temp2 = a.head;
	while (n--)
	{
		temp1->data = temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

int main()
{
	return 0;
}