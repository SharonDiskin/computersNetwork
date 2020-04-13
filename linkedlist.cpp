#include "linkedlist.h"

//C'tor
LinkedList::LinkedList() 
{
	this->head = NULL;
	this->tail = NULL;
}

//Boolean function - check if the list is empty
bool LinkedList::isEmpty()
{
	return (this->head == nullptr);
}

//get head
ListNode* LinkedList::getHead()
{
	return head;
}

//get tail
ListNode* LinkedList:: getTail()
{
	return tail;
}

//Set head
bool LinkedList::setHead(ListNode* node)
{
	this->head = node;
	return true;
}

//set tail
bool LinkedList::setTail(ListNode* node)
{
	this->tail = node;
	return true;
}

//This function adds new node to the array
void LinkedList::addNewNode(int data)
{
	ListNode* newNode = new ListNode(data); //We allocate the new node

	if (isEmpty()) //If the list is empty we set both the head and the tail to point to the new node
		this->head = this->tail = newNode;
	else //We set the tail to point to the new node
	{
		this->tail->setNext(newNode);
		setTail(newNode);
	}
}

//this function is called by the d'tor - it recursivly deletes the list
void deleteListRec(ListNode* head)
{
	if (head == nullptr)
		return;
	deleteListRec(head->getNext());
	delete head;
}

//d'tor
LinkedList::~LinkedList()
{
	ListNode* head = this->head;
	deleteListRec(head);
}

