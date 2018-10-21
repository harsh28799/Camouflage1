/*HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 5 QUESTION 6
 * IMPLEMENTATION OF TOPOLOGICAL SORT*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodal
{
	int value;
	struct nodal *next;
}node;

node *arr[20];
int num;

void adjacency()
{
	int data;
	int i,j;
	int no;
	printf("enter the number of nodes\n");
	scanf("%d",&num);
	for(i=0;i<num;i++,arr[i]=NULL);
	for(i=0;i<num;i++)
	{	
		printf("enter the number of adjacent nodes of %d ",i+1);
		scanf("%d",&no);
		for(j=0;j<no;j++)
		{
			printf("enter the %d adjacent node of %d ",j+1,i+1);
			scanf("%d",&data);
			node *ptr=(node*)malloc(sizeof(node));
			ptr->value=data;
			ptr->next=arr[i];
			arr[i]=ptr;
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%d:\t",i+1);
		node *ptr=arr[i];
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int visit[20];
int stack[20];
int fstack[20];
int top=-1;
int topf=-1;

int isEmpty()
{
	if(top==-1)
		return 0;
	else 
		return 1;
}

void push(int val)
{
	top++;
	stack[top]=val;
}

int pop()
{
	int val=stack[top];
	top--;
	return val;
}

int pushf(int val)
{
	topf++;
	fstack[topf]=val;
}

void topology()
{
	int k;
	int i=0;
	for(i=0;i<num;i++,visit[i]=0);
	for(i=0;i<num;i++)
	{
		if(visit[i]==0)
		{
			push(i+1);
			visit[i]=1;
			k=0;
			while(k<=top)
			{
				node *ptr=arr[stack[k]-1];
				while(ptr!=NULL)
				{
					if(visit[(ptr->value)-1]==0)
					{
						push(ptr->value);
						visit[(ptr->value)-1]=1;
					}
					ptr=ptr->next;
				}
				k++;
			}
			while(isEmpty())
			{
				int val=pop();
				pushf(val);
			}
		}
	}
	while(topf>=0)
	{
		printf("%d ",fstack[topf--]);
	}
}

int main()
{
	adjacency();
	topology();
}
