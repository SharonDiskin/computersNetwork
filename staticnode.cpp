#include "staticnode.h"

//C'or
StaticNode::StaticNode(int data, int next)
{
	this->data = data;
	this->next = next;
}

//get data
int StaticNode::getData() const
{
	return data;
}

//get next
int StaticNode::getNext() const
{
	return next;
}

//set data
bool StaticNode:: setData(int data)
{
	this->data = data;
	return true;
}

//set next
bool StaticNode:: setNext(int next)
{
	this->next = next;
	return true;
}