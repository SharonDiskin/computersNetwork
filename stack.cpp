#include "stack.h"

/*A note about the data stracture the stack is implemented in:
We implemented the stack in a linked list in which we push the last in to the the list as head, and the pop also returns the head
that way we comply the "fifo" practice without a need in in tail.
*/

//C'tor
Stack::Stack()
{
	makeEmpty();
}

//Make empty stack
void Stack::makeEmpty()
{
	this->head = nullptr;
}

//A check if the stack is empty
bool Stack::isEmpty()
{
	return (head == nullptr);
}

//push
bool Stack:: push(int data)
{
	Item* item = new Item; //We create a new item
	item->data = data; //We initialize the item
	item->next = this->head;
	this->head = item; //We add the item to the head (instead of the tail because in our linked list we add the last item to the the head an pop it from the head)

	return true;
}

//pop
Item Stack::pop()
{
	Item *temp = (this->head); //We keep the head (
	Item dataTemp = *temp; //We copy the data of the head to a temp
	this->head = this->head->next; //We  change the head do be the second item of on the stack
	delete temp; //We delete the temp
	return dataTemp; //We return the stack item we popped
}

//Free stack : basiclly our program pops all the items in the stack until the stack is empty but this is just in case there are things that wasn't deleted


void deleteStackRec(Item* head)
{
	if (head == nullptr)
		return;
	deleteStackRec(head->next);
	delete head;
}


//D'tor
Stack:: ~Stack()
{
	deleteStackRec(head); //We free the stack 
}
