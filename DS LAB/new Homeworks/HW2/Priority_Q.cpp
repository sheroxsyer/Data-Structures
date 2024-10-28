#include <assert.h>
#include<ctime>
#include<iostream>
using namespace std;
class MaxHeap
{
private:
		// Can be node class 
	struct Node
	{
        int  key;
		int Date;
        string Msg;
        int Priority;
	};
	Node *arr;
	int capacity; // Size of Heap
	int totalItems; // 
	void doubleCapacity() // Increase the size
	{
		if (this->arr==NULL)
		{
			this->arr = new Node[1];
			this->capacity = 1;
			return;
		}
		int newCapacity = capacity*2;
		Node *newArr = new Node[newCapacity];
		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}
		if (this->arr!=NULL)
			delete this->arr;
		this->capacity = newCapacity;
		this->arr = newArr;
	}
	void shiftUp(int index)
	{
		if (index < 1)
			return;
		int parent = (index-1) / 2;
		//if (this->arr[index].key//date > this->arr[parent].date) && this.arr[index].pri > this.arr[parent].pri
		if(this->arr[index].key > this->arr[parent].key)
		{
		   swap(this->arr[index], this->arr[parent]);
		   shiftUp(parent);

		}
	        return;
	}
	void shiftDown(int index)
	{
		int maxIndex = -1; 
		int lChildIndex = index * 2+1;   
		int rChildIndex = (index * 2) + 2;
		if (lChildIndex < totalItems)
		{
			if (arr[index].key < arr[lChildIndex].key)
			{
				maxIndex = lChildIndex;
			}
		}
		if (rChildIndex < totalItems)
		{
			int newindex= (maxIndex == -1 ? index : maxIndex);
			if (arr[newindex].key < arr[rChildIndex].key)
			{
				maxIndex = rChildIndex;
			}
		}
		if (maxIndex == -1)
			return;
		swap(arr[index], arr[maxIndex]);
		shiftDown(maxIndex);
	}
public:

bool CheckStatus(bool user)
{
	if(user==false)
	{
	cout<<"Offline : No Messages are displayed"<<endl;
	return false;
	}
	
	else
	{
	cout<<"Online : Messages are :"<<endl;
	return true;
	}
	

}
	MaxHeap()
	{
		this->arr = NULL;
		this->capacity = 0;
		this->totalItems = 0;
	}
	MaxHeap(int _capacity)
	{
		assert(_capacity >= 1);
		this->arr = new Node[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}
	void insert(int key)
	{
		if (this->totalItems == this->capacity)
		{
			doubleCapacity();
		}
		this->arr[totalItems].key = key;
		shiftUp(totalItems);
		this->totalItems++;
	}
	void getMax(int & key)
	{
		assert(totalItems != 0);
		key = this->arr[0].key;
	}
// 	void priorityCheck(int Date,string Msg,int Priority)
// 	{

// 	string Messages[totalItems]={"Hello","Hy","AOA"};
	
// 	for(int i =0;i<totalItems;i++)

// {
// 	cout<<Messages[capacity]<<endl;
	
// }
// int PriorityArr[]={5,3,1};
// cout<<"Enter Message priority:"<<endl;

// 	for(int i =0; i<totalItems;i++)

// {
// 		// cin>>Priority;

// 	cout<<PriorityArr[i]<<endl;
	
// }

void fun(int Date,string Msg,int Priority)
{
	//current date/time based on current system
   time_t now = time(0);
   //convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

//    time_t curr_time;
// 	curr_time = time(NULL);

// 	char *tm = ctime(&curr_time);

	int priority;
	string msg;
	string Messages[totalItems]={"Hello","Hy","AOA"};
	
int PriorityArr[]={5,3,1};
int i;
int index;
cout << "Read User Input into Array"<<endl; 	
for(i=0;i<totalItems;i++)
{
	cout<<"Enter Priority:"<<endl;
	cin>>priority;
	cout<<"Enter Message:"<<endl;
	cin>>msg;

	while(PriorityArr[0]<PriorityArr[1])
	{
		index++;
		if(PriorityArr[0]<PriorityArr[1])
		swapPri(PriorityArr[0],PriorityArr[1],PriorityArr);
	}

	for(int i =0; i<totalItems;i++)

{
		// cin>>Priority;

	cout<<PriorityArr[i]<<endl;
	
}


while(Messages[0]<Messages[1])
	{
		index++;
		if(Messages[0]<Messages[1])
		swapMsg(0,1,Messages);
		
	}

	for(int i =0; i<totalItems;i++)

{
		// cin>>Priority;

	cout<<Messages[i]<<endl;
	
}


}

	


// CheckStatus(true)){

for (int i = 0; i <totalItems; i++)
{


	received_fun(Messages[i]);

}


	// }
}
int timestamp()
{
	int msg1,msg2;




//So compare timestamps.
    if (msg1.timestamp < msg2.timestamp)
        return -1;
    if (msg1.timestamp == msg2.timestamp)
        return 0;
    return 1;


}
	
void swapMsg(int msg1,int msg2,string Messages[])
{
	string temp = Messages[msg1];
	Messages[msg1]=Messages[msg2];
	Messages[msg2]=temp;
}

void swapPri(int a,int b,int PriorityArr[])
{
	int temp = PriorityArr[a];
	PriorityArr[a]=PriorityArr[b];
	PriorityArr[b]=temp;
}

void received_fun(string messages){
	cout<<"THe message we got : "+ messages<<endl;
	
}

	
	
// void compare(string msg1,string  msg2)
// {
// 	int priority;
// // returns -1, 0, 1 to indicate if msg1 is less than, equal to,
// // or greater than msg2.

//     if (msg1.priority == true)
//     {
//         if (msg2.priority == false)
//             return -1; // msg1 has priority flag set and msg2 doesn't
//     }
//     else if (msg2.priority == true)
//         return 1; // msg2 has priority flag set and msg1 doesn't
//     // At this point, we know that the priority flag is the same
//     // for both messages.
//     // So compare timestamps.
//     if (msg1.timestamp < msg2.timestamp)
//         return -1;
//     if (msg1.timestamp == msg2.timestamp)
//         return 0;
//     return 1;
// }
	};

	
int main()
{

	MaxHeap obj;
	obj.fun();


return 0;
}


