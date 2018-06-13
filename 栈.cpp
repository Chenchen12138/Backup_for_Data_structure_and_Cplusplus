#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class ZNode
{
public:
	T data;
	ZNode<T>* next;
	ZNode(ZNode<T>* ptr=NULL) { next=ptr; }
	ZNode(const T& a, ZNode<T>* ptr=NULL)
	{
		data=a;
		next=ptr;
	}
};

template <class T>
class Stack:public ZNode<T>
{
public:
	Stack();
	Stack(const T &item) { rear = new ZNode<T>(item); }
	Stack(const Stack<T> &a);
	~Stack();
	void Clear();
	ZNode<T>* Locate(int pos);
	void StackInsert(const T &a);
	void StackDelete();
	void Stackchange(const T &a, int pos);
	Stack<T> &operator =(const Stack<T> &a);
	void Stackdisplay();
private:
	ZNode<T>* stackTop;
	int size;
};

template <class T>
void Stack<T>::StackInsert(const T& a)
{
	ZNode<T>* temp=new ZNode<T>;
	temp->date=a;
	temp->next=stackTop;
	stackTop=temp;
	size++;
}

template <class T>
void Stack<T>::StackDelete()
{
	if(stackTop==NULL)
		return;
	ZNode<T>* temp=stackTop;
	stackTop=stackTop->next;
	delete temp;
	size--;
}