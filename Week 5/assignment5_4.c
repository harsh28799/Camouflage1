#include<stdio.h>
#include<stdlib.h>
typedef struct nodal
{
	int value;
	struct nodal *next;
}node;

int num;

node *arr[20];

int createAdjacencyList()
{
	int i,j;
	int n;
	int data;
	printf("enter the number of vertices\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		arr[i]=NULL;
	for(i=0;i<num;i++)
	{
		printf("enter the no of adjacent nodes of %d ",i+1);
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			printf("enter the %d adjacent node of %d ",j+1,i+1);
			scanf("%d",&data);
			node *ptr=(node*)malloc(sizeof(node));
			ptr->value=data;
			ptr->next=arr[i];
			arr[i]=ptr;
		}
	}

	printf("the adjacency list is \n");
	for(i=0;i<num;i++)
	{
		printf("%d\t",i+1);
		node *ptr=arr[i];
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}printf("\n");
	}
}

int visit[20];
int queue[20];
int front=-1,rear=-1;

int isEmpty()
{
	if(front==rear&&front==-1)
		return 0;
	else
		return 1;
}

void push(int no)
{
	if(front==rear&&front==-1)
	{
		front=rear=0;
		queue[rear]=no;
	}
	else
	{
		rear=rear+1;
		queue[rear]=no;
	}
}

int pop()
{
	int val;
	if(front==rear)
	{
		val=queue[front];
		front=rear=-1;
	}
	else
	{
		val=queue[front];
		front=front+1;
	}
	return val;
}

void traversal()
{
	int i;
	node *ptr;
	for(i=0;i<num;i++,visit[i]=0);
	int start;
	printf("enter the starting node ");
	scanf("%d",&start);
	push(start);
	visit[start-1]=1;
	while(isEmpty())
	{
		start=pop();
		printf("%d ",start);
		ptr=arr[start-1];
		while(ptr!=NULL)
		{
			if(visit[(ptr->value)-1]==0)
			{
				push(ptr->value);
				visit[(ptr->value)-1]=1;
			}
			ptr=ptr->next;
		}
	}
}

int main()
{
	createAdjacencyList();
	traversal();
	return 0;
}
