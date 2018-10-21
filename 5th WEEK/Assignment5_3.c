/*HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 5 QUESTION 3
 * COMPUTE THE GRAPH MATRIX OF THE GRAPH USING WARSHALL'S ALGORITHM*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k;
	int num;
	int n;
	printf("enter the number of vertices\n");
	scanf("%d",&num);
	int arr[num][num];
/*	printf("enter the adjacency matrix of the graph\n");
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("Is %d adjacent to %d",j+1,i+1);
			scanf("%d",&n);
			arr[i][j]=n;
		}
	}
*/

	int no;
	int value;
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			arr[i][j]=0;

	for(i=0;i<num;i++)
	{
		printf("enter the number of adjacent node of %d ",i+1);
		scanf("%d",&no);
		for(j=0;j<no;j++)
		{
			printf("enter the %d adjacent node of %d ",j+1,i+1);
			scanf("%d",&value);
			arr[i][value-1]=1;
		}
	}

	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			for(k=0;k<num;k++)
			{
				arr[j][k]=arr[j][k]|(arr[j][i]&arr[i][k]);
			}
		}
	}
	printf("the path matrix is\n");
	for(i=0;i<num;i++)
	{	
		printf("%d: ",i+1);
		for(j=0;j<num;j++)
		{
			printf("%d ",arr[i][j]);
		}printf("\n");
	}

	return 0;
}
