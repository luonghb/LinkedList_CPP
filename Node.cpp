#include "Node.h"


template<class T> Node<T>::Node() { pNext = NULL; }

template<class T> Node<T>::Node(T newData) {
	data = newData;
	pNext = NULL;
}

template<class T> Node<T>::Node(T newData, Node<T> *newPNext) {
	data = newData;
	pNext = newPNext;
}

template<class T> Node<T>::~Node() { DeletePNext(); }

template<class T> T Node<T>::GetData() const { return data; }
		
template<class T> Node<T>* Node<T>::GetPNext() const { return pNext; }
		
template<class T> void Node<T>::SetData(T newData) { data = newData; }
		
template<class T> void Node<T>::SetPNext(Node<T> *newPNext) {
	if (newPNext != NULL) {
		if (pNext != NULL) { newPNext->SetPNext(pNext); }
	}
	pNext = newPNext;
}
		
template<class T> void Node<T>::DeletePNext() {
	if (pNext != NULL) {
		Node<T> *pTmp = pNext;
		pNext = pTmp->GetPNext();
		pTmp->SetPNext(NULL);
		delete pTmp;
		pTmp = NULL;
	}
}

template class Node<int>;
