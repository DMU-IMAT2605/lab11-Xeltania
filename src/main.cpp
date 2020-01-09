

// Define and includes to show memory leak report
//#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "DoubleLinkedList.h"
#include "DLLNode.h"

void main() /** Entry point for the application */
{
	DLL<string> list;

	cout << "Empty : " << list.ListEmpty() << endl;
	list.AddBack("I");
	list.AddFront("Doubly");
	list.TraverseNext();
	list.TraversePrev();
	list.AddNext("Linked");
	list.AddPrev("Am");
	cout << "Empty : " << list.ListEmpty() << endl << "Size : " << list.GetSize() << endl;
	cout << "Front : " << list.GetFront() << endl << "Back : " << list.GetBack() << endl << "Current : " << list.GetCurrent() << endl;
	list.RemFront();
	cout << "Size : " << list.GetSize() << endl;
	list.RemBack();
	list.RemFront();
	list.RemFront();
	cout << "Size : " << list.GetSize() << endl;
	list.RemCurrent();
	cout << "Current : " << list.GetCurrent() << endl;
	cout << "Back : " << list.GetBack() << endl << "Front : " << list.GetFront() << endl;
	list.~DLL();
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
