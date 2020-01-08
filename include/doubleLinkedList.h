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
	void RemCurrent();
	void RemFront();
	void RemBack();
	//! Getters : 
	T GetFront();
	T GetBack();
	T GetCurrent();
	unsigned int GetSize();
	bool ListEmpty();
	//! Traversal Methods :
	void TraverseNext();
	void TraversePrev();

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
	/* Old method for adding to the front of the list, less efficient:
	if (m_listSize == 0) 
	{
		p_frontNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, nullptr, nullptr));
		
		p_currentNode = p_frontNode;
		p_backNode = p_currentNode;
	}
	else
	{
		shared_ptr<DLLNode<T>> temp = p_frontNode;
		p_frontNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, temp, nullptr));
		temp->SetNext(p_frontNode);
		
	}*/
	shared_ptr<DLLNode<T>> temp = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, p_frontNode, nullptr));
	if (p_frontNode != nullptr) 
	{
		p_frontNode->SetNext(temp);
	}
	if (p_backNode == nullptr) {
		p_backNode=temp;
	}
	p_frontNode = temp;
	p_currentNode = temp;
	m_listSize++;
}

template<class T>
void DLL<T>::AddBack(T newBack) //!< Adds a node to the end of the list:
{
	if (m_listSize > 0)
	{
		cout << "Adding " << newBack << " to the back of the list..." << endl;
		shared_ptr<DLLNode<T>> temp = p_backNode;
		p_backNode = shared_ptr<DLLNode<T>>(new DLLNode<T>(newBack, nullptr, temp));
		m_listSize++;
	}
}

template<class T>
void DLL<T>::RemCurrent() //!< Removes the node after the current node in the list:
{
	if (m_listSize > 0)
	{
		cout << "Removing " << p_currentNode->GetData() << " from the list ... " << endl;
		shared_ptr<DLLNode<T>> tempPrev = p_currentNode->GetPrev();
		shared_ptr<DLLNode<T>> tempNext = p_currentNode->GetNext();
		shared_ptr<DLLNode<T>> tempCurrent = p_currentNode;
		if (tempNext != nullptr) 
		{
			tempNext->SetPrev(tempPrev);
			p_currentNode = tempNext;
		}
		else 
		{
			p_frontNode = p_currentNode;
		};
		if (tempPrev != nullptr) 
		{
			tempPrev->SetNext(tempNext);
			p_currentNode= tempPrev;
		}
		else 
		{
			p_frontNode = p_currentNode;
		};

		m_listSize--;
	}
	else cout << "Cannot remove : no items left in the list!" << endl;
}


template<class T>
void DLL<T>::RemFront() //!< Removes the first node front of the list:
{
	if (m_listSize > 0)
	{
		cout << "Removing " << p_frontNode->GetData() << " from the list..." << endl;
		shared_ptr<DLLNode<T>> temp = p_frontNode;
		p_frontNode = p_frontNode->GetPrev();
		p_frontNode->SetNext(nullptr);

		m_listSize--;
	}
	else cout << "Cannot remove : no items left in the list!" << endl;
}

template<class T>
void DLL<T>::RemBack() //!< Removes the last node from the linked list:
{
	if (m_listSize > 0)
	{
		cout << "Removing " << p_backNode->GetData() << " from the list..." << endl;
		shared_ptr<DLLNode<T>> temp = p_backNode;
		p_backNode = p_backNode->GetNext();
		p_backNode->SetPrev(nullptr);

		m_listSize--;
	}
	else cout << "Cannot remove : no items left in the list!" << endl;

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
T DLL<T>::GetCurrent()
{
	T data = p_currentNode->GetData();
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

template<class T>
void DLL<T>::TraverseNext()
{
	if (p_currentNode->GetNext() != nullptr)
	{
		cout << p_currentNode << " going to next : ";
		cout << p_currentNode->GetNext() << endl;
		p_currentNode = p_currentNode->GetNext();
	}
	else cout << "Cannot traverse any further, at the front!" << endl;
}

template<class T>
void DLL<T>::TraversePrev()
{
	if (p_currentNode->GetPrev() != nullptr)
	{
		cout << p_currentNode << " going to previous : ";
		cout << p_currentNode->GetPrev() << endl;
		p_currentNode = p_currentNode->GetPrev();
	}
	else cout << "Cannot traverse any further, at the back!" << endl;
}
