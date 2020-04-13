#ifndef __LISTNODE
#define __LISTNODE

#include <iostream>
using namespace std;

class ListNode
{
private: 
	int data;
	ListNode* next;

public://methods
	ListNode(int data); //C'tor

	//"get" methods
	int getData();
	ListNode* getNext();

	//"set" methods
	bool setData(int data);
	bool setNext(ListNode* next);
};

#endif // !__LISTNODE
