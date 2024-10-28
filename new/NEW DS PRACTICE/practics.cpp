#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;
struct SortedLinkedList{
	int value;
	SortedLinkedList *next;  
};
void sortedInsert(struct SortedLinkedList**head , int value)
{
	SortedLinkedList*temp = *head ;
	SortedLinkedList *t = new SortedLinkedList;
	if(*head==NULL)
	{
		*head = new SortedLinkedList;
		(*head)->value = value;
		(*head)->next = NULL;
	}


	else
	{


		if(value < temp->value) //start node
		{
			t = new SortedLinkedList;
			t->value = value;
			t->next = *head;
			*head = t;
		}


		else
		{
			while(temp->next != NULL && !(value < temp->next->value && value >= temp->value))
				temp=temp->next;


			if(temp->next == NULL) 
			{
				temp->next = new SortedLinkedList;
				temp = temp->next;
				temp->value = value;
				temp->next = NULL;
			}
			else 
			{
				t = new SortedLinkedList;
				t->value = value;
				t->next = temp->next; 
				temp->next = t;
			}
		}
	}
}
void display(struct SortedLinkedList**head)
{
	struct SortedLinkedList*temp=*head;
	//calculate the sum of the elements 
	float sum=0;
	while(temp!=NULL)
	{
		if(temp->next!=NULL)
			cout<<temp->value<<" ->";
		else
			cout<<temp->value;


		sum+=temp->value;
		temp=temp->next; //move to next node
	}
	// the floating-point average of the elements.
	float average=sum/25.0;
	cout<<"\nSum = "<<sum;
	cout<<"\nAverage = "<<average;
	cout<<endl;
}




int main()
{


	struct SortedLinkedList *head = NULL; 
	/* initialize random seed: */
	srand (time(NULL));
	for(int i=0;i<25;i++){
		int randomNumber = rand() % 101;
		sortedInsert(&head,randomNumber);
	}
	cout<<"Current List is:\n";
	display(&head);
	
	int k;
	cin>>k;


	return 0;
}