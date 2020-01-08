#pragma once

#include<memory>
#include "DLLNode.h"

template <class T>
class DLL
{

private:
	unsigned int m_listSize; //!< The size of the double linked list based on how many nodes are present.

	shared_ptr<DLLNode<T>> p_frontNode; //!< Shared pointer to the first node in the linked list.
	shared_ptr<DLLNode<T>> p_backNode; //!< Shared pointer to the last node in the linked list.
	shared_ptr<DLLNode<T>> p_currentNode; //!< Shared pointer to the current node in the linked list.
public:

	DLL();
	~DLL();

	//! Node Adding Methods :
	void AddNext(T newNext);
	void AddPrev(T newPrev);
	void AddFront(T newFront);
	void AddBack(T newBack);
	//! Node Removing Methods :
	void RemNext();
	void RemPrev();
	void RemFront();
	void RemBack();
	//! Getters : 
	T GetFront();
	T GetBack();
	unsigned int GetSize();
	bool ListEmpty();

};

template <class T>
DLL<T>::DLL() //!< Constructor
{
	m_listSize = 0; //!< List default size set to empty.
	p_frontNode = nullptr; //!< No current data set, so the front is null to begin.
	p_backNode = nullptr;
	p_currentNode = nullptr;
}
template <class T>
DLL<T>::~DLL() //!< Deconstructor
{

}
template <class T>
void DLL<T>::AddNext(T newNext) //!< Adds a node between the current and next nodes in the list:
{

}

template<class T>
void DLL<T>::AddPrev(T newPrev) //!< Adds a node between the current and previous nodes in the list:
{

}

template<class T>
void DLL<T>::AddFront(T newFront) //!< Adds a node to the start of the list:
{
	cout << "Adding " << newFront << " to the front of the list..." << endl;
	if (m_listSize == 0) 
	{
		p_frontNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, p_backNode, nullptr));
		p_backNode = p_frontNode;
		p_currentNode = p_frontNode;
	}
	else
	{
		shared_ptr<DLLNode<T>> temp = p_frontNode;
		p_frontNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, temp, p_frontNode));
		temp = nullptr;
	}
	m_listSize++;
}

template<class T>
void DLL<T>::AddBack(T newBack) //!< Adds a node to the end of the list:
{
	cout << "Adding " << newBack << " to the back of the list..." << endl;
	shared_ptr<DLLNode<T>> temp = p_backNode;
	p_backNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newBack, nullptr, temp));
	temp = nullptr;
	m_listSize++;
}

template<class T>
void DLL<T>::RemNext() //!< Removes the node after the current node in the list:
{
}

template<class T>
void DLL<T>::RemPrev() //!< Removes the node prior to the current node in the list:
{
}

template<class T>
void DLL<T>::RemFront() //!< Removes the first node front of the list:
{
	if (m_listSize > 0)
	{
		shared_ptr<DLLNode<T>> temp = p_backNode;


		m_listSize--;
	}
}

template<class T>
void DLL<T>::RemBack() //!< Removes the last node from the linked list:
{
	if (m_listSize > 0) 
	{
		shared_ptr<DLLNode<T>> temp = p_frontNode;


		m_listSize--;
	}

}

template<class T>
T DLL<T>::GetFront() //!< Method to return the first node in the linked list:
{
	T data = p_frontNode->GetData();
	return data;
}

template<class T>
T DLL<T>::GetBack() //!< Method that returns the last node in the linked list:
{
	T data = p_backNode->GetData();
	return data;
}

template<class T>
unsigned int DLL<T>::GetSize() //!< Method that returns the current size of the linked list:
{
	return m_listSize;
}

template<class T>
bool DLL<T>::ListEmpty() //!< Method that checks if the list has any items in it:
{
	return m_listSize == 0;
}
