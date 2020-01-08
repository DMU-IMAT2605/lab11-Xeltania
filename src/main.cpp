

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

	cout << list.ListEmpty() << endl;
	list.AddFront("Thing");
	list.AddFront("Stuff");
	cout << list.GetCurrent() << endl;
	list.TraverseNext();
	list.AddBack("Item");
	list.AddBack("egg");
	cout << list.ListEmpty() << endl << list.GetSize() << endl;
	cout << list.GetFront() << endl << list.GetBack() << endl << list.GetCurrent() << endl;
	//list.RemBack();
	//list.RemFront();
	list.RemCurrent();
	cout << list.GetBack() << endl << list.GetFront() << endl;
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
