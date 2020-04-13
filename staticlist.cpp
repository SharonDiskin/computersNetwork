#include "staticlist.h"

int const OUT_OF_RANGE = -1; //A const that keeps a value that shows us that the next item points at nothing

//C'tor
StaticList::StaticList(int size)
{
	this->size = size;
	A = new StaticNode[size];
	emptyList();
}

//Boolean function that checks if the list is empty
bool StaticList::isEmpty() const
{
	return (this->headlist == OUT_OF_RANGE);

}

//This function create an empty list
void StaticList::emptyList()
{
	int i;
	this->headlist = OUT_OF_RANGE; //We set the head and the tail to point at OUT_OF_RANGE
	this->tail = OUT_OF_RANGE;
	this->headFree = 0; //We set the next empty space to point at the first index

	for (i = 0; i < this->size-1; i++) //We set all items of the list to point at the next index
	{
		A[i].setNext(i + 1);
	}

	A[i].setNext(OUT_OF_RANGE); //We set the last item to point at OUT_OF_RANGE
}

//get first
int StaticList::getFirst() const
{
	return headlist;
}

//get head free
int StaticList::getHeadFree() const
{
	return headFree;
}

//get last
int StaticList::getLast() const
{
	return tail;
}

//Insert to an item to the end
void StaticList::insertToEnd(int data)
{
	if (isEmpty()) //If the list is empty we initialize the head and to tail to point at the first index
	{
		headlist = tail = 0;
	}

	int locNew = headFree; //We keep the location of the first empty space
	headFree = A[headFree].getNext(); //We change the empty space to point at the next empty space
	A[locNew].setData(data); //We set the data at locNew (the first empty space)
	A[tail].setNext(locNew); //We set the data of the tail item to point to the new last item
	A[locNew].setNext(OUT_OF_RANGE); //We set the next of the new item to point to OUT_OF_RANGE
	tail = locNew; //We set the tail to point at the last item
}

//print function
void StaticList:: print()
{
	int head = headlist;
	int fContinue = true;
	while (fContinue)
	{
		cout << A[head].getData() << " ";
		head = A[head].getNext();
		if (head == OUT_OF_RANGE)
			fContinue = false;
	}
	
	cout << endl;
}

//D'tor
StaticList::~StaticList()
{
	delete[]A;
}


