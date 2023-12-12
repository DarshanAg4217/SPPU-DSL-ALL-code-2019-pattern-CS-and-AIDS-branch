#include<iostream>
using namespace std;
const int MAX=5;

class Queue
{
	int front,rear;
	int queue[MAX];
	public:
	Queue()
	{
		front=rear=-1;
	}
	bool isEmpty();
	bool isFull();
	void insert();
	void remove();
	void display();

};
bool Queue::isEmpty()
{
	if(front>rear ||rear==-1)
		return 1;
	else return 0;
}

bool Queue::isFull()
{
	if(rear==MAX-1)
	{
		return 1;
	}
	else
		return 0;
}
void Queue::insert()
{
	int id;
	if(isFull())
	{
		cout<<"\nQueue is Full.Can not insert.";
	}
	else
	{
		cout<<"\nEnter Job ID: ";
		cin>>id;
		if(rear==-1)//empty
		{
			front++;
			rear++;
			queue[rear]=id;
		}
		else
		rear++;
		queue[rear]=id;
		cout<<"\nJob Added To Queue.";
	}
}

void Queue::remove()
{
	if(rear==-1||front>rear)
	{
		cout<<"\nQueue is Empty.Can not perform delete operation.";
	}
	else
	{
		
		cout<<"\nJob Processed From Queue: job ID: "<<queue[front];
		front++;
		cout<<"\nContents of Queue:  ";
		for(int i=front;i<=rear;i++)
		{
			cout<<" "<<queue[i]<<" ";
		}
	}
}
void Queue::display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<" "<<queue[i]<<" ";
		}
	}
}

int main()
{

	int ch;
	Queue q;

	do
	{
		cout<<"\n\n****MENU****\n";
		cout<<"1.Insert job\n";
		cout<<"2.Display jobs\n";
		cout<<"3.Remove job\n";
		cout<<"4.Exit\n";
		cout<<"Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: q.insert();
			break;

			case 2: 
			cout<<"\nContents of Queue are:\n";
			cout<<"\n\tJob ID: ";
			
			q.display();
			break;

			case 3: q.remove();
		}
	}while(ch!=4);
	return 0;
}


***************************OUTPUT**************************

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 1
Enter Job ID: 12
Job Added To Queue.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 1
Enter Job ID: 23
Job Added To Queue.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 1
Enter Job ID: 34
Job Added To Queue.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 1
Enter Job ID: 45
Job Added To Queue.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 1
Enter Job ID: 56
Job Added To Queue.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 2
Contents of Queue are:

	Job ID:  12  23  34  45  56 

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 3
Job Processed From Queue: job ID: 12
Contents of Queue:   23  34  45  56 

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 3
Job Processed From Queue: job ID: 23
Contents of Queue:   34  45  56 

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 3
Job Processed From Queue: job ID: 34
Contents of Queue:   45  56 

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 3
Job Processed From Queue: job ID: 45
Contents of Queue:   56 

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 3
Job Processed From Queue: job ID: 56
Contents of Queue:  

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 2
Contents of Queue are:

	Job ID: 
Queue is Empty.

****MENU****
1.Insert job
2.Display jobs
3.Remove job
4.Exit
Choice: 4
