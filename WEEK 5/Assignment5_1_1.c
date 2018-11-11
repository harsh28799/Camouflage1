#include<stdio.h>
#include<stdlib.h>

typedef struct nodal
{
    int adj;
    struct nodal *next;
}node;

node *arr[20];

int main()
{
    int i,j;

    int node;
    printf("enter the number of nodes\n");
    scanf("%d",&node);

    int edge;
    printf("enter the number of edges\n");
    scanf("%d",&edge);

    int adjarr[node][node];
    for(i=0;i<node;i++)
    {
        arr[i]->next=NULL;
        for(i=0;i<node;i++)
        {
            adjarr[i][j]=0;
        }
    }

    int ch=0;
    printf("Is the graph directed or undirected?\n0-directed\n1-undirected\n");
    scanf("%d",&ch);

    printf("enter the edges\n");
    for(i=0;i<edge;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(ch==0)
        {
            node *ptr=(node*)malloc(sizeof(node));
            ptr->adj=b;
            ptr->next=arr[a];
            arr[a]=ptr;

            adjarr[a][b]=1;
        }

        else
        {
            node *ptr1=(node*)malloc(sizeof(node));
            ptr1->adj=b;
            ptr1->next=arr[a];
            arr[a]=ptr1;

            node *ptr2=(node*)malloc(sizeof(node));
            ptr2->adj=a;
            ptr2->next=arr[b];
            arr[b]=ptr2;

            adjarr[a][b]=1;
            adjarr[b][a]=1;
        }
    }

    printf("The adjacency matrix is:\n");
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<edge;i++)
    {
        printf("The adjacent nodes of %d are : ");
        node *ptr=arr[i];
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->adj);
            ptr=ptr->next;
        }
        printf("\n");
    }
    return 0;
}
