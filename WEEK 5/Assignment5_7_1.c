/*HARSH MOHAN
  117CS0232

  ASSIGNMENT 5 QUESTION 7
  DETECTION OF CYCLES IN A GRAPH USING ARRAY DISJOINT DATA STRUCTURE*/

#include<stdio.h>
int arr[100];
int test(int p,int q);
int flag=0;
int root(int p)
{
    while(p!=arr[p])
        p=arr[p];
    return p;
}
void link(int p,int q)
{
	if(test(p,q))
	{
    		int pi=root(p);
    		int qi=root(q);
    		arr[pi]=qi;
	}
	else
		return;
}
int test(int p,int q)
{
    if(root(p)==root(q))
    {
        flag++;
        return 0;
    }
	else
	 	return 1;
}
int main()
{
    int i;
    int p,q;
    char ch;
    int choice;
    for(i=0;i<100;i++)
    {
        arr[i]=i;
    }
    do
    {
       	printf("enter the two objects to link:");
        scanf("%d%d",&p,&q);
        link(p,q);
        printf("do you want to continue(y/n)\n");
        scanf("%s",&ch);
    }while(ch=='Y'||ch=='y');

	if(flag==0)
		printf("no cycle detected");
	else
		printf(" cycles detected");

return 0;
}

