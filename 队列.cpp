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
}

template Queue:public DNode<T>
{
private:
	
}

