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
DLL<T>::~DLL() //!< Deconstructor - Makes sure the list is emptied and memory is released at the end.
{
	p_currentNode = p_frontNode;
	while (p_currentNode != nullptr) //!< Loops through setting the list to empty by nulling all items.
	{
		p_currentNode->SetNext(nullptr);
		p_currentNode = p_currentNode->GetPrev();
	}
	p_frontNode = nullptr;
	p_backNode = nullptr;
}
template <class T>
void DLL<T>::AddNext(T newNext) //!< Adds a node between the current and next nodes in the list:
{
	if (m_listSize > 0) //!< If there are items in the list : add after current item
	{
		cout << "Adding " << newNext << " after " << p_currentNode->GetData() << endl;
		shared_ptr<DLLNode<T>> tempNext = p_currentNode->GetNext(); //!< Sets a pointer to the next item from the current node.
		shared_ptr<DLLNode<T>> tempPrev = p_currentNode; //!< Sets a pointer to the current node so that it may be referenced as new previous.
		shared_ptr<DLLNode<T>> tempCurrent = shared_ptr<DLLNode<T>>(new DLLNode<T>(newNext, p_currentNode, tempNext)); //!< Creates a pointer to the new node.
		p_currentNode->SetNext(tempCurrent); //!< Set the next node from the current to the new node.
		tempCurrent->GetNext()->SetPrev(tempCurrent); //!< Sets the previous of the node in front of the current to the new node.
		p_currentNode = tempCurrent; //!< Sets the current pointer to the new node.
		m_listSize++; //!< Increment the list size.
	}
	else cout << "Cannot add after - No existing items in list!" << endl;
}

template<class T>
void DLL<T>::AddPrev(T newPrev) //!< Adds a node between the current and previous nodes in the list:
{
	if (m_listSize > 0) //!< If there are items in the list : add before current item
	{
		cout << "Adding " << newPrev << " before " << p_currentNode->GetData() << endl;
		shared_ptr<DLLNode<T>> tempNext = p_currentNode; //!< Sets a pointer to the current node to become the next node.
		shared_ptr<DLLNode<T>> tempPrev = p_currentNode->GetPrev(); //!< Sets a pointer to the node before the current.
		shared_ptr<DLLNode<T>> tempCurrent = shared_ptr<DLLNode<T>>(new DLLNode<T>(newPrev, tempPrev, p_currentNode)); //!< Creates a pointer for the new node.
		tempPrev->SetNext(tempCurrent); //!< Sets the next node for the old previous to point to the new node.
		tempNext->SetPrev(tempCurrent); //!< Sets the previous node form the current to the new node.
		p_currentNode = tempCurrent; //!< Sets the current pointer as the new node.
		m_listSize++; //!< Increments the list size.
	}
	else cout << "Cannot add before - No existing items in list!" << endl;
}

template<class T>
void DLL<T>::AddFront(T newFront) //!< Adds a node to the start of the list:
{
	cout << "Adding " << newFront << " to the front of the list..." << endl;
	shared_ptr<DLLNode<T>> temp = shared_ptr<DLLNode<T>>(new DLLNode<T>(newFront, p_frontNode, nullptr));
	if (p_frontNode != nullptr) //!< If there is a node at the front already:
	{
		p_frontNode->SetNext(temp); //!< Set the old front to have its next as the new item.
	}
	if (p_backNode == nullptr) //!< If the back is empty:
	{
		p_backNode=temp; //!< Set the new item as the back as well, as it is the first in the list.
	}
	//!< Set the front and current to the new item.
	p_frontNode = temp; 
	p_currentNode = temp;
	m_listSize++; //!< Increment the list size by 1.
}

template<class T>
void DLL<T>::AddBack(T newBack) //!< Adds a node to the end of the list:
{

	cout << "Adding " << newBack << " to the back of the list..." << endl;
	shared_ptr<DLLNode<T>> temp = shared_ptr<DLLNode<T>>(new DLLNode<T>(newBack, nullptr, p_backNode)); //!< Creates a temporary pointer of the new node.
	//temp->SetNext(p_backNode);
	if (p_backNode != nullptr)  //!< If there is a back node already:
	{
		p_backNode->SetPrev(temp); //!< Set the previous to the back node to the new temp.
	}
	if (p_frontNode == nullptr) //!< If the front is empty:
	{
		p_frontNode = temp; //!< Set the front to the new node as this means the list is empty.
	}
	p_currentNode = temp; //!< Set the new node as the current.
	p_backNode = temp; //!< Set the new node as the back node.
	m_listSize++; //!< Increase the size of the list by 1.
	
}

template<class T>
void DLL<T>::RemCurrent() //!< Removes the node after the current node in the list:
{

	if (m_listSize > 0) //!< If the list is populated : run the remove current steps: 
	{
		cout << "Removing " << p_currentNode->GetData() << " from the list ... " << endl;
		shared_ptr<DLLNode<T>> tempPrev = p_currentNode->GetPrev();
		shared_ptr<DLLNode<T>> tempCurrent = p_currentNode;
		if (tempPrev != nullptr) 
		{
			tempPrev->SetNext(p_currentNode->GetNext());
			tempPrev->SetPrev(p_currentNode->GetPrev());
		}
		else 
		{
			p_frontNode = p_currentNode->GetNext();
			p_backNode = p_currentNode->GetPrev();
		}
		tempPrev = p_currentNode->GetNext();
		if (p_currentNode->GetNext() == nullptr)
		{
			p_currentNode = p_currentNode->GetPrev();
		}
		else
		{
			p_currentNode = p_currentNode->GetNext();
		}
		m_listSize--;
	}
	else cout << "Cannot remove : no items left in the list!" << endl; //!< Otherwise tell the user that you cannot remove as list is empty.
}


template<class T>
void DLL<T>::RemFront() //!< Removes the first node front of the list:
{
	if (m_listSize == 1) //!< If there is only one item in the list: 
	{
		cout << "Removing " << p_frontNode->GetData() << " from the list..." << endl; //!< State that the item is being removed.
		//! Set a temp to the current node, and set all pointers to null.
		shared_ptr<DLLNode<T>> temp = p_currentNode;
		p_frontNode = nullptr;
		p_backNode = nullptr;
		p_currentNode = nullptr;
		temp = nullptr;
		m_listSize--; //!< Decrement the size of the list.
	}
	else if (m_listSize > 0) //!< If the list has more than one item:
	{
		cout << "Removing " << p_frontNode->GetData() << " from the list..." << endl;
		shared_ptr<DLLNode<T>> temp = p_frontNode; //!< Set the temp to the front node.
		p_frontNode = p_frontNode->GetPrev(); //!< Set the front node to the previous node.
		p_frontNode->SetNext(nullptr); //!< Set the next to null as this is now the front.
		p_currentNode = temp->GetPrev(); //!< set the current node to the temp's previous.
		m_listSize--; //!< Decrement the list by 1.
	}
	else cout << "Cannot remove : no items left in the list!" << endl;
}

template<class T>
void DLL<T>::RemBack() //!< Removes the last node from the linked list:
{
	if (m_listSize == 1) //!< If there is only one item in the list : 
	{
		cout << "Removing " << p_frontNode->GetData() << " from the list..." << endl;
		//! Set all pointers to null to remove reference and set list to empty.
		shared_ptr<DLLNode<T>> temp = p_currentNode;
		p_frontNode = nullptr;
		p_backNode = nullptr;
		p_currentNode = nullptr;
		temp = nullptr;
		m_listSize--; //!< Decrement list size to be empty.
	}
	if (m_listSize > 0) //!< If there are multiple items in the list:
	{
		cout << "Removing " << p_backNode->GetData() << " from the list..." << endl;
		shared_ptr<DLLNode<T>> temp = p_backNode; //!< Create a temp to the back of the list.
		p_backNode = p_backNode->GetNext(); //!< Set the new back to be the next node from the back of the list.
		p_backNode->SetPrev(nullptr); //!< Set the previous to null.
		p_currentNode = temp->GetNext(); //!< Set the next node to be the next from the temp.
		m_listSize--; //!< Decrement the list by 1.
	}
	else cout << "Cannot remove : no items left in the list!" << endl;

}

template<class T>
T DLL<T>::GetFront() //!< Method to return the first node in the linked list:
{
	if (m_listSize == 0) 
	{
		return (T)"List is Empty..."; //!< If the list is empty, return empty to the console.
	}
	else 
	{
		T data = p_frontNode->GetData();
		return data;
	}
}

template<class T>
T DLL<T>::GetBack() //!< Method that returns the last node in the linked list:
{
	if (m_listSize == 0) 
	{
		return (T)"List is Empty...";
	}
	else 
	{
		T data = p_backNode->GetData();
		return data;
	}
}

template<class T>
T DLL<T>::GetCurrent()//!< Method that returns the current node in the linked list:
{
	if (m_listSize == 0)
	{
		return (T)"List is Empty...";
	}
	else 
	{
		T data = p_currentNode->GetData();
		return data;
	}
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
void DLL<T>::TraverseNext() //!< Method that moves to the next node in the list if possible:
{
	if (m_listSize != 0) 
	{
		if (p_currentNode->GetNext() != nullptr) //!< If the current node is not the front:
		{
			cout << p_currentNode->GetData() << " going to next : ";
			cout << p_currentNode->GetNext()->GetData() << endl;
			p_currentNode = p_currentNode->GetNext(); //!< Set the current node to the next item.
		}
		else cout << "Cannot traverse any further, at the front!" << endl;
	}
	else cout << "Cannot traverse - No items in list!" << endl;
}

template<class T>
void DLL<T>::TraversePrev() //!< Method that moves to the previous node in the list if possible:
{
	if (m_listSize != 0)
	{
		if (p_currentNode->GetPrev() != nullptr) //!< If the current node is not the back:
		{
			cout << p_currentNode->GetData() << " going to previous : ";
			cout << p_currentNode->GetPrev()->GetData() << endl;
			p_currentNode = p_currentNode->GetPrev(); //!< Set the current node to the previous item.
		}
		else cout << "Cannot traverse any further, at the back!" << endl;
	}
	else cout << "Cannot traverse - No items in list!" << endl;
}
