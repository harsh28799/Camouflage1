#include<stdio.h>
#include<stdlib.h>

typedef struct nodal
{
	int value;
	struct nodal *next;
}node;

int num;
node *arr[20];

void adjList()
{
	int data;
	int i,j;
	int no;
	printf("enter the number of vertices in the graph\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		arr[i]=NULL;
	for(i=0;i<num;i++)
	{
		printf("enter the number of adjacent nodes of %d\n",i+1);
		scanf("%d",&no);
		for(j=0;j<no;j++)
		{
			printf("enter the %d adjacent node of %d",j+1,i+1);
			scanf("%d",&data);
			node *ptr=(node*)malloc(sizeof(node));
			ptr->next=arr[i];
			ptr->value=data;
			arr[i]=ptr;
		}
	}

	printf("the adjacency list is\n");
	for(i=0;i<num;i++)
	{
		printf("%d \t:",i+1);
		node *ptr=arr[i];
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}printf("\n");
	}
}

int stack[20];
int top=-1;
int visit[20];

int isEmpty()
{
	if(top==-1)
		return 0;
	else
		return 1;
}

void push(int value)
{
	top=top+1;
	stack[top]=value;
}
int pop()
{
	int value=stack[top];
	top=top-1;
	return value;
}

void traversal()
{
	int i;
	for(i=0;i<num;i++,visit[i]=0);
	int start;
	printf("enter the first node\n");
	scanf("%d",&start);
	push(start);
	visit[start-1]=1;
	while(isEmpty())
	{
		int x=pop();
		printf("%d",x);
		node *ptr=arr[x-1];
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
	adjList();
	traversal();
	return 0;
}
