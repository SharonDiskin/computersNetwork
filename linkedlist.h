#ifndef __LINKEDLIST
#define __LINKEDLIST

#include <iostream>
using namespace std;
#include "listnode.h"

class LinkedList
{
private:
	ListNode * head;
	ListNode* tail;

public: //methods
	LinkedList(); //C'tor
	~LinkedList(); //D'tor

	bool isEmpty();
	void addNewNode(int data);

	//"get" methods
	ListNode* getHead();
	ListNode* getTail();
	
	//"set" methods
	bool setHead(ListNode* node);
	bool setTail(ListNode* node);

};

#endif // !__LIST
