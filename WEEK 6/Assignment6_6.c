#include<stdio.h>

void print(int i,int j,int temp[])
{
    if(temp[j]<0)
    {
        return;
    }
    else if(i==temp[j])
    {
        return;
    }
    else
    {
        print(i,temp[j],temp);
        printf("-->%d",temp[j]);
    }
}

int main()
{
    int i,j,k;

    int node;
    printf("enter the number of nodes\n");
    scanf("%d",&node);

    int dist[node][node];
    int parent[node][node];

    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            parent[i][j]=-1;
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=1000;
        }
    }

    int edge;
    printf("enter the number of edges\n");
    scanf("%d",&edge);

    for(i=0;i<edge;i++)
    {
        int a,b;
        int w;
        scanf("%d%d%d",&a,&b,&w);
        dist[a][b]=w;
        parent[a][b]=a;
    }

    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            for(k=0;k<node;k++)
            {
                if((dist[j][i]+dist[i][k])<dist[j][k])
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                    if(i>=1)
                        parent[j][k]=parent[i][k];
                }
            }
        }
    }

    printf("Minimum distance matrix is\n");
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }

    printf("Path determinant matrix is\n");
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            printf("%d\t",parent[i][j]);
        }
        printf("\n");
    }

    /*for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            cout<<"The minimum distance from "<<i<<" to "<<j<<":"<<dist[i][j]<<" path: ";

            int temp[node];
            int ctr=0;
            int flag=parent[i][j];
            while(flag!=i)
            {
                temp[ctr++]=flag;
                flag=parent[i][flag];
            }
            for(k=0;k<ctr;k++)
                cout<<"-->"<<temp[k];
            cout<<"-->"<<j<<endl;
        }
    }*/

    for(i=0;i<node;i++)
    {
        int temp[node];
        for(k=0;k<node;k++)
            temp[k]=parent[i][k];

        for(j=0;j<node;j++)
        {
            printf("The minimum distance from %d to %d is: %d and path: ",i,j,dist[i][j]);
            print(i,j,temp);
            printf("-->%d\n",j);
        }
    }

    return 0;
}

