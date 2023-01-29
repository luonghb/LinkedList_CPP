#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T> class LinkedList
{
	public:
		explicit LinkedList();
		~LinkedList();
		
		Node<T>* GetPHead() const;
		
		void SetPHead(Node<T> *newPHead);
		
		void AddHead(Node<T> *newPHead);
		
		void AddTail(Node<T> *newPTail);
		
		void AddByPosition(Node<T> *newPNode, int pos);
		
		void DeleteHead();
		
		void DeleteTail();
		
		void DeleteByPosition(int pos);
		
		void Clear();
		
		int NumOfElement();
	private:
		Node<T> *pHead;
};

#endif
