/* HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 4 QUESTION 2
 * CIRCULAR QUEUE IMPLEMENTATION USING LINKED LIST*/

#include<stdio.h>
#include<stdlib.h>
int max_size=10;
typedef struct nodal
{
	int data;
	struct nodal *next;
}node;
node *front;
node *rear;
int ctr=0;
void createEmpty()
{
	front=NULL;
	rear=NULL;
	ctr=0;
	if(front==rear&&front==NULL)
		printf("empty queue created\n");
	else
		printf("empty queue could not be created\n");
}
void isFull()
{
	if(ctr<max_size)
		printf("the queue is not full\n");
	else
		printf("the queue is full\n");
}
void isEmpty()
{
	if(front==rear&&front==NULL)
		printf("the queue is empty\n");
	else
		printf("the queue is not empty\n");
}
void enQueue(int value)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=value;
	if(ctr<max_size)
	{
	 	if(front==rear&&front==NULL)
		{
			front=temp;
			rear=temp;
			temp->next=front;
		}
		else
		{
			rear->next=temp;
			temp->next=front;
			rear=temp;
		}
		ctr++;
	}
	else
		printf("queue is full\nelement cannot be inserted\n");
}
void deQueue()
{
	if(front==rear&&front==NULL)
		printf("the queue is empty\n");
	else if(front==rear)
	{
		node *temp=front;
		front=NULL;
		rear=NULL;
		free(temp);
		ctr--;
	}
	else
	{
		node *temp=front;
		front=front->next;
		rear->next=front;
		free(temp);
		ctr--;
	}
}
void makeEmpty()
{
	while(front!=rear||front!=NULL)
	{
		if(front==rear)
		{
			node *temp=front;
			front=NULL;
			rear=NULL;
			free(temp);
			ctr--;
		}
		else
		{
			node *temp=front;
			front=front->next;
			rear->next=front;
			free(temp);
			ctr--;
		}
	}
	printf("the queue is empty\n");
}
void display()
{
	if(front==rear&&front==NULL)
		printf("the queue is empty\n");
	else
	{
		node *temp=front;
		printf("->");
		do
		{
			printf("|%d|->",temp->data);
			temp=temp->next;
		}while(temp!=front);
		printf("||%d||",temp->data);
	}
}
int main()
{
	front=NULL;
	rear=NULL;
	int value;
	int choice;
	char ch;
	printf("MENU\n1.CREATE EMPTY QUEUE\n2.CHECK IF QUEUE IS FULL\n3.CHECK IF QUEUE IS EMPTY\n4.ENQUEUE\n5.DEQUEUE\n6.MAKE QUEUE EMPTY\n7.DISPLAY\n\n");
	do
	{
		printf("enter your choice(1-7)\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:createEmpty();break;
			case 2:isFull();break;
			case 3:isEmpty();break;
			case 4:printf("enter the element to be inserted\n");
			       scanf("%d",&value);
			       enQueue(value);
			       break;
			case 5:deQueue();break;
			case 6:makeEmpty();break;
			case 7:display();break;
			default:printf("wrong choice\n");
		}
		printf("do you want to continue with another choice(Y/N)\n");
		scanf("%s",&ch);
	}while(ch=='Y'||ch=='y');
	return 0;
}
