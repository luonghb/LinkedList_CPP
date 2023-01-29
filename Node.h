#ifndef NODE_H
#define NODE_H

#include <cstddef>

template<class T> class Node
{
	public:
		explicit Node();
		explicit Node(T newData);
		explicit Node(T newData, Node<T> *newPNext);
		~Node();
		
		T GetData() const;
		
		Node<T>* GetPNext() const;
		
		void SetData(T newData);
		
		void SetPNext(Node<T> *newPNext);
		
		void DeletePNext();
	private:
		T data;
		Node<T> *pNext;
};

#endif
