#include<stdio.h>

void print(int source,int d,int parent[])
{
    if(source==d)
    {
        return;
    }
    else if(parent[d]==-1)
    {
        printf(" No path exists");
        return;
    }
    else
    {
        print(source,parent[d],parent);
        printf("-->%d",parent[d]);
    }
}

int main()
{
    int i,j,k,l;

    printf("enter the number of nodes\n");
    int node;
    scanf("%d",&node);

    printf("enter the number of edges\n");
    int edge;
    scanf("%d",&edge);

    int arr[edge][3];

    printf("enter the edges in order you want them to be processed with respective weights\n");

    for(i=0;i<edge;i++)
        scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);

    int dist[node];
    int parent[node];

    for(i=0;i<node;i++)
    {
        dist[i]=1000;
        parent[i]=-1;
    }

    printf("enter the source node\n");
    int source;
    scanf("%d",&source);

    dist[source]=0;
    parent[source]=source;

    for(i=0;i<node-1;i++)
    {
        for(j=0;j<edge;j++)
        {
            int u=arr[j][0];
            int v=arr[j][1];
            int w=arr[j][2];
            if(dist[v]==1000&&dist[u]==1000&&w<0)
                continue;
            if(dist[v]>dist[u]+w)
            {
                 dist[v]=dist[u]+w;
                 parent[v]=u;
            }
        }
    }

        for(j=0;j<edge;j++)
        {
            int u=arr[j][0];
            int v=arr[j][1];
            int w=arr[j][2];
            if(dist[v]==1000&&dist[u]==1000&&w<0)
                continue;
            if(dist[v]>dist[u]+w)
            {
                printf("NEGETIVE WEIGHT CYCLE DETECTED\nSHORTEST PATH CANNOT BE CALCULATED\n");
                return 0;
            }
        }

    for(i=0;i<node;i++)
    {
        printf("Shortest path from %d to %d is of weight: %d as follows : ",source,i,dist[i]);
        print(source,i,parent);
        printf("-->%d\n",i);
    }

    return 0;
}

