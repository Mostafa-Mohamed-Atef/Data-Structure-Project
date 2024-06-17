#include<iostream>
using namespace std;
class Node
{
public:
	string data;
	int priority; //the periorit number of the data
	Node* next;
	Node* prev;

};

class PQ
{
public:
	Node* front;

	PQ()
	{
		front = NULL;
	}
	void Insert();
	void Delete();
	void HP();
	void Display();

};
void PQ::Insert()
{
	Node* new_node = new Node;//first we create a new node
	cout << "Please Enter your task: ";
	cin >> new_node->data;
	cout << "Please enter your task's priority: ";
	cin >> new_node->priority;
	new_node->next = NULL;
	if (front == NULL || new_node->priority < front->priority) //here we check if the queue is empty or the priority of the newnode is less than the priority of the front 
	{
		new_node->next = front; //if the condition is true here the new node will be the front's place
		front = new_node;
	}
	else
	{
		Node* temp = front; //we make temp to not lose the front 
		while (temp->next != NULL && temp->next->priority <= new_node->priority)
		{
			temp = temp->next; //here is an iteration to walk through all the queue
		}
		new_node->next = temp->next;
		temp->next= new_node;
	}
}
void PQ::Delete()
{

	if (front == NULL)
	{
		cout << "the Queue is Empty \n";
	}
	else
	{
		int peroo;
		Node* temp = front;
		Node* prev_node = NULL;
		cout << "Please enter your priority that you want to delete:";
		cin >> peroo;
		while (temp!=NULL && temp->priority != peroo)
		{
			prev_node = temp;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << "Node not found\n";
		}
		else if (prev_node == NULL) //if perroo is the first node
		{
			front = temp->next;
			if (front != NULL)
			{
				front->prev = NULL;
			}
			delete temp;
		}
		else
		{
			prev_node->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = prev_node;
			}		

			delete temp;
		}
		
	}
}
void PQ::HP()
{
	if (front == NULL)
	{
		cout << "the Queue is Empty \n";
	}
	else
	{
		Node* temp = front;
		Node* hp = temp;
		while (temp->next!= NULL)
		{
			temp = temp->next;
		}
		cout<< "the highest priority: "<<hp->data<<endl;
	}
}
void PQ::Display()
{
	//first--->we make a variable for the front to avoid losing it
	Node* temp = front;
	while (temp != NULL) //we make a while loop move through all the elements till NULL
	{
		cout <<"Your tasks : "<< temp->data << " ( "<<temp->priority<<" ) "<<endl;
		temp = temp->next; //third---> we make teh temp change to move and take the next node 
	}
}
int main()
{
	PQ per_queue;

	
	per_queue.Insert();
	per_queue.Insert();
	per_queue.Insert();
	per_queue.Insert();
	per_queue.Display();

	per_queue.Delete();
	per_queue.Display();

	per_queue.HP();
	per_queue.Display();

}
//task manager application