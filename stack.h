#ifndef __STACK
#define __STACK
#include <iostream>
using namespace std;

//Defining a stack item
typedef struct item 
{
	int data;
	item* next;
}Item;

//Defining the stack clas
class Stack {

private:
	Item * head;

public: //methods
	Stack();
	~Stack();
	void makeEmpty();
	bool push(int data);
	Item pop();
	bool isEmpty();
};

#endif // !__STACK