#include"computersnetwork.h"

//C'tor
ComputersNetwork::ComputersNetwork(int size, int numberOfConnections)
{
	//We initi
	this->networkSize = size;
	this->numberOfConnections = numberOfConnections;
	this->network = new LinkedList[networkSize];
	this->colorArr = new eColors[networkSize];
	setNetwork();
	setColorArr();
	this->accessibles = new StaticList(networkSize);

}

//Set network: we build the connection array of lists
bool ComputersNetwork::setNetwork()
{
	int source, destination;
	for (int i = 0; i < numberOfConnections; i++) 
	{
		cin >> source >> destination;
		if (source<1 || source > networkSize)
		{
			cout << "no such computer " << source << endl;
			exit(-1);
		}
		if (destination<1 || destination> networkSize)
		{
			cout << "no such computer " << destination << endl;
			exit(-1);
		}
		network[source - 1].addNewNode(destination-1); //We add each connection to according to the index of source - 1
	}
	return true;
}


//Set color array: We initialize all the colors to white
bool ComputersNetwork::setColorArr()
{
	for (int i = 0; i < networkSize; i++)
		colorArr[i] = (eColors)0;
	return true;
}

//This functions sets the color of a computer to a given color
bool ComputersNetwork::setColor(int index, int color)
{
	colorArr[index] = (ComputersNetwork::eColors)color;
	return true;
}

//get Networksize
int ComputersNetwork::getNetworkSize() const
{
	return networkSize;
}

//get number of connections
int ComputersNetwork::getNumberOfConnections() const
{
	return numberOfConnections;
}

//get array of lists (network)
LinkedList* ComputersNetwork::getNetwork() const
{
	return network;
}

StaticList* ComputersNetwork::getAccessibles() const
{
	return accessibles;
}

//get colors array
ComputersNetwork::eColors* ComputersNetwork::getColorArr() const
{
	return colorArr;
}

//D'tor
ComputersNetwork:: ~ComputersNetwork()
{
	delete []network; 
	delete []colorArr;
}