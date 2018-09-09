/* HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 4 QUESTION 1
 * QUEUE IMPLEMENTATION USING LINKED LIST*/

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
	temp->next=NULL;
	if(ctr<max_size)
	{
		if(front==rear&&front==NULL)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
		ctr++;
	}
	else
		printf("the queue is full\nelement could not be inserted\n");
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
			free(temp);
			ctr--;
		}
	}
	printf("the queue is empty\n");
}
void display()
{
	node *temp=front;
	if(front==rear&&front==NULL)
		printf("the queue is empty\n");
	else
	{
		printf("->");
		while(temp!=NULL)
		{
			printf("|%d|->",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	front=NULL;
	rear=NULL;
	int choice;
	int value;
	char ch;
	do
	{
		printf("enter your choice (1-7)\n");
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
}
