#pragma once


using namespace std;

template <class T> //!< Generic template class.
class DLLNode
{

private :

	T m_nodeData; //!< The data stored in the node.

	shared_ptr<DLLNode<T>> p_nextNode; //!< Shared pointer to the next node in the list.
	shared_ptr<DLLNode<T>> p_prevNode; //!< Shared pointer to the previous node in the list.

public :
	DLLNode(T nodeData, shared_ptr<DLLNode<T>> prev, shared_ptr<DLLNode<T>> next);
	~DLLNode();

	//! Getters :
	shared_ptr<DLLNode<T>> GetNext(); //!< Gets the next node pointer.
	shared_ptr<DLLNode<T>> GetPrev(); //!< Gets the previous node pointer.
	void SetPrev(shared_ptr<DLLNode> newPrev);
	void SetNext(shared_ptr<DLLNode> newNext);
	T GetData();
};

template <class T>
DLLNode<T>::DLLNode(T nodeData, shared_ptr<DLLNode<T>> prev, shared_ptr<DLLNode<T>> next) //!< Default constructor for the Linked List Node.
{
	m_nodeData = nodeData; //!< Sets the data stored in the node to the entered parameter.
	p_prevNode = prev; //!< Sets the previous node to point to.
	p_nextNode = next; //!< Sets the next node to point to.
}
template <class T>
DLLNode<T>::~DLLNode()  //!< Default destructor for the Linked List Node.
{
	
}
template <class T>
shared_ptr<DLLNode<T>> DLLNode<T>::GetNext() //!< Gets the next node in the list:
{
	return p_nextNode;
}
template <class T>
shared_ptr<DLLNode<T>> DLLNode<T>::GetPrev() //!< Gets the previous node in the list:
{
	return p_prevNode;
}

template<class T>
void DLLNode<T>::SetPrev(shared_ptr<DLLNode> newPrev)
{
	p_prevNode = newPrev;
}

template<class T>
void DLLNode<T>::SetNext(shared_ptr<DLLNode> newNext)
{
	p_nextNode = newNext;
}

template<class T>
T DLLNode<T>::GetData() //!< Returns the data from the selected node:
{
	return m_nodeData;
}
