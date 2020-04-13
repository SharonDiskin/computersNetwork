#include "listnode.h"

//C'tor
ListNode::ListNode(int data)
{
	this->data = data;
	this->next = nullptr;
}

//get data
int ListNode::getData()
{
	return data;
}

//get next
ListNode* ListNode:: getNext()
{
	return next;
}

//set data
bool ListNode:: setData(int data)
{
	this->data = data;
	return true;
}

//set next
bool ListNode:: setNext(ListNode* next)
{
	this->next = next;
	return true;
}