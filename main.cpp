
using namespace std;
#include <iostream>
#include"computersnetwork.h"



//Prototypes
void findAccessibleRec(LinkedList* network, int center, ComputersNetwork::eColors* colorArr, StaticList* accessibles);
void findAccessibleIterative(LinkedList* network, int center, ComputersNetwork::eColors* colorArr, StaticList* accessibles);

//Main

int main()
{
	int numberOfComputers, numberOfConnections, center; //Declartions of varaib
														
    //Recieving input
	cin >> numberOfComputers >> numberOfConnections;

	ComputersNetwork network(numberOfComputers, numberOfConnections); //We define our computer network
	cin >> center;

	if (center < 1 || numberOfConnections < center)
	{
		cout << "no such computer " << center << endl;
		exit(-1);
	}
	findAccessibleRec(network.getNetwork(), center - 1, network.getColorArr(), network.getAccessibles()); //A call to the main function of the program


	network.getAccessibles()->print();

	network.setColorArr();
	network.getAccessibles()->emptyList();

	findAccessibleIterative(network.getNetwork(), center - 1, network.getColorArr(), network.getAccessibles()); //A call to the main function of the program
	network.getAccessibles()->print();

}

/*This function is the main function of the program.It finds the accessible list for each computer (center) in the network*/
void findAccessibleRec(LinkedList* network, int center, ComputersNetwork::eColors* colorArr, StaticList* accessibles)
{
	if (colorArr[center] == 1) //If the color is black we return
		return;
	else  //The color of the center is not black - we add it to the accessibles list
	{
		accessibles->insertToEnd(center + 1);  //We add the center to the accessibles list (We send the center+1 since the index is one less than the Id of each computer)
		colorArr[center] = (ComputersNetwork::eColors)1; //We change the color to black after we add it to the accessibles list
		if (network[center].isEmpty()) //If the center is not connected to anything we return
			return;
		//We search for the next white computer to add to the accessibles list
		ListNode* temp = network[center].getHead();
		while (temp != nullptr)
		{
			while (colorArr[temp->getData()] == 1)
			{
				temp = temp->getNext();
				if (temp == nullptr)
					return;
			}
			findAccessibleRec(network, temp->getData(), colorArr, accessibles); //We call the function with the new computer in duty of center
		}
	}
}

/*This function is the main function of the program.It finds the accessible list for each computer (center) in the network*/
void findAccessibleIterative(LinkedList* network, int center, ComputersNetwork::eColors* colorArr, StaticList* accessibles)
{
	Stack S;
	Item curr = { center, nullptr };
	S.push(curr.data); // insert to stack the first computer
	int returnFromRecursion = false;
	ListNode* temp = nullptr;
	do
	{
		if (returnFromRecursion)
		{
			curr = S.pop(); // Go back to last call
			temp = network[curr.data].getHead(); // get the head of the list of computer network for the last computetr we check
			if (temp != nullptr)
				returnFromRecursion = false;
		}
		if ((colorArr[curr.data] == 1) && !(returnFromRecursion)) // if the computer already in accessibles list and his network list not empty 
		{
			while (colorArr[temp->getData()] == 1) // find the next computer that we dont entered to the list
			{
				temp = temp->getNext();
				if (temp == nullptr)
				{
					returnFromRecursion = true;
					break;
				}
			}
			if (temp != nullptr) // if we find another computer we puse the his source and him to the list
			{
				S.push(curr.data);
				curr.data = temp->getData();
				S.push(curr.data);
			}

		}
		if (!returnFromRecursion) // enter to list
		{

			accessibles->insertToEnd(curr.data + 1); // insert new computer to accessibles list
			colorArr[curr.data] = (ComputersNetwork::eColors)1; // sign that we enter that computer in color list

			if (network[curr.data].isEmpty()) // check if there is no connection to the current computer
			{
				returnFromRecursion = true;
			}
			else
			{
				temp = network[curr.data].getHead(); // get the dirs computer from the connection list of the current computer
				while (colorArr[temp->getData()] == 1) // find the next computer that not in the accessicle list
				{
					temp = temp->getNext();
					if (temp == nullptr)
					{
						returnFromRecursion = true;
						break;
					}
				}
				if (!returnFromRecursion) // if we find new computer we enter him to the stack and countinue the search
				{
					curr.data = temp->getData();
					S.push(curr.data);
				}
				else
					returnFromRecursion = true;
			}
		}

	} while (!(S.isEmpty()));

}