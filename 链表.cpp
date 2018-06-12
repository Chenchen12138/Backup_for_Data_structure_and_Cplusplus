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
	LinkedList<T>* Locate(int pos);
	void LinkInsert(T &a, int pos);
	void Linkdelete(T a);
	void Linkchange(T a);
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
LinkedList<T>::~LinkedList()
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
LinkedList<T>* LinkedList<T>::Locate(int pos)
{
	int i = 0;
	LNode<T>* temp = head;
}

template <class T>
void LinkedList<T>::LinkInsert(T &a,int pos)
{

}
