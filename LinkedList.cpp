#include "LinkedList.h"

template <class T> LinkedList<T>::LinkedList() { pHead = NULL; }

template <class T> LinkedList<T>::~LinkedList() { Clear(); }

template <class T> Node<T>* LinkedList<T>::GetPHead() const { return pHead; }

template <class T> void LinkedList<T>::AddHead(Node<T> *newPHead) {
	if (pHead != NULL) {
		newPHead->SetPNext(pHead);
		pHead = newPHead;
	}
	else { pHead = newPHead; }
}
		
template <class T> void LinkedList<T>::AddTail(Node<T> *newPTail) {
	if (pHead != NULL) {
		Node<T> *pTmp = pHead;
		while (pTmp->GetPNext() != NULL) { pTmp = pTmp->GetPNext(); }
		pTmp->SetPNext(newPTail);
	}
	else pHead = newPTail;
}

template <class T> void LinkedList<T>::AddByPosition(Node<T> *newPNode, int pos) {
	if (pos == 0) { AddHead(newPNode); }
	else {
		int i = 1;
		Node<T> *pTmp = pHead;
		while (pTmp->GetPNext() != NULL && i < pos) {
			++i;
			pTmp = pTmp->GetPNext();
		}
		if (pos == i) { pTmp->SetPNext(newPNode); }
	}
}
		
template <class T> void LinkedList<T>::DeleteHead() {
	if (pHead != NULL) {
		Node<T> *pTmp = pHead;
		pHead = pHead->GetPNext();
		pTmp->SetPNext(NULL);
		delete pTmp;
	}
}
		
template <class T> void LinkedList<T>::DeleteTail() {
	if (pHead != NULL) {
		Node<T> *pTmp = pHead;
		if (pTmp->GetPNext() == NULL) { DeleteHead(); }
		else {
			while (pTmp->GetPNext()->GetPNext() != NULL) {
				pTmp = pTmp->GetPNext();
			}
			pTmp->DeletePNext();
		}
	}
	
}
		
template <class T> void LinkedList<T>::DeleteByPosition(int pos) {
	if (pHead != NULL) {
		if (pos == 0) {	DeleteHead(); }
		else {
			int i = 1;
			Node<T> *pTmp = pHead;
			while (pTmp->GetPNext() != NULL && i < pos) {
				pTmp = pTmp->GetPNext();
				++i;
			}
			if (i == pos) { pTmp->DeletePNext(); }
		}
	}
}

template <class T> void LinkedList<T>::Clear() { 
	while (pHead != NULL) { DeleteHead(); } 
}

template <class T> int LinkedList<T>::NumOfElement() {
	int count = 0;
	Node<T> *pTmp = pHead;
	while (pTmp != NULL) {
		pTmp = pTmp->GetPNext();
		++count;
	}
	return count;
}

template class LinkedList<int>;

