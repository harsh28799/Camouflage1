/*HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 5 QUESTION 2
 * COMPUTE THE POWER OF ADJACENCY MATRIX A^2,A^3,A^4 AND ALSO COMPUTE B^4 OF THE GIVEN MATRIX*/

#include<stdio.h>
int main()
{
	int k;
	int ch;
	int i,j;
	int num;
	printf("enter the number of nodes in the array\n");
	scanf("%d",&num);
	int arr[4][num][num];
/*	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("Is %d adjacent to %d  ",j+1,i+1);
			scanf("%d",&ch);
			if(ch==1)
				arr[0][i][j]=1;
			else
				arr[0][i][j]=0;
		}
	}	
*/
	int no;
	int value;
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			arr[0][i][j]=0;

	for(i=0;i<num;i++)
	{
		printf("enter the number of adjacent nodes of %d",i+1);
		scanf("%d",&no);
		for(j=0;j<no;j++)
		{
			printf("enter the %d adjacent node of %d ",j+1,i+1);
			scanf("%d",&value);
			arr[0][i][value-1]=1;
		}
	}	
	
	int sum=0;
	int n=0;
	for(n=0;n<3;n++)
	{
		for(i=0;i<num;i++)
		{
			for(j=0;j<num;j++)
			{
				sum=0;
				for(k=0;k<num;k++)
				{
					sum+=arr[0][i][k]*arr[n][k][j];
				}
				arr[n+1][i][j]=sum;
			}
		}
	}
	int b[num][num];

	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			b[i][j]=0;

	for(i=0;i<4;i++)
	{
		printf("the %d power is\n",i+1);
		for(j=0;j<num;j++)
		{
			for(k=0;k<num;k++)
			{
				b[j][k]+=arr[i][j][k];
				printf("%d ",arr[i][j][k]);
			}printf("\n");
		}
		printf("\n");
	}

	printf("B^4 of the adjacency matrix is\n");
	for(i=0;i<num;i++)
	{	
		for(j=0;j<num;j++)
		{	
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
return 0;
}
