#ifndef __COMPUTERSNETWORK
#define __COMPUTERNETWORK

#include <iostream>
using namespace std;
#include "linkedlist.h"
#include "staticlist.h"
#include "stack.h"

class ComputersNetwork
{

public:
	enum eColors { WHITE, BLACK };

private: 

	int networkSize;
	int numberOfConnections;
	LinkedList* network;
	StaticList* accessibles;
	eColors* colorArr;


public: //methods

	ComputersNetwork(int size, int numberOfConnections); //C'tor

	//get methods
	int getNetworkSize() const;
	int getNumberOfConnections() const;
	LinkedList* getNetwork() const;
	StaticList* getAccessibles() const;
	eColors* getColorArr() const;

	//set methods
	bool setColorArr();
	bool setColor(int index, int color);
	bool setNetwork();

	~ComputersNetwork();

};

#endif // !__COMPUTERSNETWORK
