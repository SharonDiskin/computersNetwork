#ifndef __STATICNODE
#define __STATICNODE

class StaticNode
{
private:
	int data;
	int next;

public: //methos
	StaticNode() = default; //We set a default c'tor to when we create a new item (before we insert data)
	StaticNode(int data, int next); //Another c'tor

	//"get" methods
	int getData() const;
	int getNext() const;

	//"set" methods
	bool setData(int data);
	bool setNext(int next);
};

#endif // !__STATICLISTNODE
