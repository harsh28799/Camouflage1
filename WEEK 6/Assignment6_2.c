#include<stdio.h>
#include<stdlib.h>

typedef struct nodal
{
    int adj;
    int wgt;
    struct nodal *next;
}node;

int no;
int edge;
node *arr[20];

int dist[20];
int parent[20];
int status[20];

int extractmin()
{
    int i;
    int min=20;
    dist[min]=1000;
    for(i=0;i<no;i++)
    {
        if(dist[i]<dist[min]&&status[i]==0)
            min=i;
    }
    //printf("%d",min);
    return min;
}


int main()
{
    int i;

    printf("Enter the number of nodes\n");
    scanf("%d",&no);

    printf("Enter the number of edges\n");
    scanf("%d",&edge);

    for(i=0;i<no;i++)
    {
        arr[i]=NULL;
    }

    for(i=0;i<edge;i++)
    {
        int a,b;
        int w;
        scanf("%d%d%d",&a,&b,&w);

        node *ptr1=(node*)malloc(sizeof(node));
        ptr1->adj=b;
        ptr1->wgt=w;
        ptr1->next=arr[a];
        arr[a]=ptr1;

        node *ptr2=(node*)malloc(sizeof(node));
        ptr2->adj=a;
        ptr2->wgt=w;
        ptr2->next=arr[b];
        arr[b]=ptr2;

    }

    for(i=0;i<no;i++)
    {
        printf("\nThe adjacent nodes of %d and their respective weights are: ",i);
        node *ptr=arr[i];
        while(ptr!=NULL)
        {
            printf("%d %d\t",ptr->adj,ptr->wgt);
            ptr=ptr->next;
        }
    }

    for(i=0;i<no;i++)
    {
        dist[i]=1000;
        parent[i]=-1;
        status[i]=0;
    }

    int size=no;

    int source;
    printf("\nEnter the source node: ");
    scanf("%d",&source);
    dist[source]=0;

    int path=0;

    while(size>0)
    {
        int num=extractmin();

        printf("%d<--%d-->%d\n",parent[num],dist[num],num);

        status[num]=1;

        path+=dist[num];

        size--;

        node *ptr=arr[num];

        while(ptr!=NULL)
        {
            int temp=ptr->adj;
            int tempw=ptr->wgt;
            if(status[temp]==0&&dist[temp]>tempw)
            {
                dist[temp]=tempw;
                parent[temp]=num;
            }
            ptr=ptr->next;
        }
    }

    printf("The size of minimum spanning tree remains at:%d\n",path);

    return 0;
}


