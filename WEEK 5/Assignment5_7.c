/*HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 5 QUESTION 7
 * DETECTING CYCLES USING ARRAY DISJOINT DATA STRUCTURE*/

#include<stdio.h>
int arr[100];
int wgt[100];
int flag=0;

int root(int a)
{
    int index,value;
    index=a;
    value=arr[index];
    while(value!=index)
    {
        index=value;
        value=arr[index];
    }
    return value;
}

void connect(int a,int b)
{
    int x=root(a);
    int p=wgt[x];
    int y=root(b);
    int q=wgt[y];
    if(x!=y)
    {
        if(p>=q)
        {
            arr[b]=x;
            wgt[x]+=wgt[y];
        }
        else
        {
            arr[a]=y;
            wgt[y]+=wgt[x];
        }
    }

    else
    {
        flag++;
        return;
    }
}

int main()
{
    char ch;
    int i;
    int nodes;
    printf("enter the total number of nodes\n");
    scanf("%d",&nodes);
    for(i=0;i<=nodes;i++,arr[i]=i,wgt[i]=1);

/*  printf("\n");
    for(i=1;i<=nodes;i++)
        printf("%d",arr[i]);
    printf("\n");
    for(i=1;i<=nodes;i++)
        printf("%d",wgt[i]);
*/

    do
    {
        printf("enter the nodes of the edge\n");
        int a,b;
        scanf("%d%d",&a,&b);
        connect(a,b);
        printf("do you have further node to connect? (y/n) \n");
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');

/*  printf("\n");
    for(i=1;i<=nodes;i++)
        printf("%d",arr[i]);
    printf("\n");
    for(i=1;i<=nodes;i++)
        printf("%d",wgt[i]);
*/
    if(flag==0)
        printf("NO CYCLE DETECTED\n");
    else
        printf("CYCLES DETECTED\n");
    return 0;
}
