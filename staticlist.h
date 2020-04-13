#ifndef __STATICLIST
#define __STATICLIST

#include <iostream>
using namespace std;
#include "staticnode.h"

class StaticList
{
private:
	int size;
	int headlist;
	int headFree;
	int tail;
	StaticNode* A;

public: //methods
	StaticList(int size); //C'tor

	void emptyList();
	bool isEmpty() const;
	void insertToEnd(int data);
	void print();

	//get methods
	int getFirst() const;
	int getHeadFree() const;
	int getLast() const;

	~StaticList(); //D'tor

};
#endif // !__STATICLIST
