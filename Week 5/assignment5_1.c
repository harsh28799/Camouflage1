#include<stdio.h>
#include<stdlib.h>
typedef struct nodal
{
	int val;
	struct nodal *next;
}node;
int adjMatrix[50][50];
int main()
{
	int i,j;
	int num;
	int n;
	int value;
	printf("enter the number of vertices\n");
	scanf("%d",&num);
	node *arr[num];
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			adjMatrix[i][j]=0;
	for(i=0;i<num;i++)
	{
		arr[i]=NULL;
		printf("enter the number of adjacent nodes of %d  ",(i+1));
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			printf("enter the %d adjecent node of %d  ",j+1,i+1);
			scanf("%d",&value);

			adjMatrix[i][value-1]=1;

			node *ptr=(node*)malloc(sizeof(node));
			ptr->val=value;
			ptr->next=arr[i];
			arr[i]=ptr;

		}	
	}
		
	printf("the adjacency matrix is\n");
	for(i=0;i<num;i++)
	{
		printf("%d :",i+1);
		for(j=0;j<num;j++)
		{
			printf("%d ",adjMatrix[i][j]);
		}printf("\n");
	}

	printf("the adjacency list is \n");
	for(i=0;i<num;i++)
	{
		printf("\n%d\t",i+1);
		node *ptr=arr[i];
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->val);
			ptr=ptr->next;
		}
	}
	printf("\n");
	return 0;
}
