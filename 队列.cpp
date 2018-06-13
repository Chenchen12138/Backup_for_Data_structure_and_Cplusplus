#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DNode
{
public:
	T data;
	DNode* next;
	DNode(DNode<T>* ptr=NULL) { next=ptr; }
	DNode(const T& a, DNode<T>* ptr=NULL)
	{
		data=a;
		next=ptr;
	}
};

template <class T>
class Queue:public DNode<T>
{
private:
	DNode<T>* front;
	DNode<T>* rear;
	int size;
public:
	Queue();
	Queue(const T &item) { rear = new DNode<T>(item); }
	Queue(const Queue<T> &a);
	~Queue();
	void Clear();
	DNode<T>* Locate(int pos);
	void QueueInsert(const T &a);
	void QueueDelete();
	void Queuechange(const T &a, int pos);
	Queue<T> &operator =(const Queue<T> &a);
	void Queuedisplay();	
};

template <class T>
void Queue<T>::QueueInsert(const T &a)
{
	DNode<T>* temp=new DNode<T>;
	temp->data=a;
	temp->next=NULL;
	if(tail=NULL)
	{
		front=temp;
	}
	else
		tail->next=temp;
	rear=temp;
	size++;
}

template <class T>
void Queue<T>::QueueDelete()
{
	DNode<T>* temp;
	if(size==0) return;
	temp=front;
	front=front->next;
	delete temp;
	if(front==NULL)
		rear=NULL;
	size--;
}
