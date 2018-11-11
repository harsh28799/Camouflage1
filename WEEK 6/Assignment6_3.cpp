#include<bits/stdc++.h>
using namespace std;

void print(int source,int d,int parent[])
{
    if(source==d)
    {
        return;
    }
    else if(parent[d]==-1)
    {
        cout<<" No path exists";
        return;
    }
    else
    {
        print(source,parent[d],parent);
        cout<<"-->"<<parent[d];
    }
}

int main()
{
    int i,j,k,l;

    cout<<"enter the number of nodes"<<endl;
    int node;
    cin>>node;

    cout<<"enter the number of edges"<<endl;
    int edge;
    cin>>edge;

    int arr[edge][3];

    cout<<"enter the edges in order you want them to be processed with respective weights"<<endl;

    for(i=0;i<edge;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

    int dist[node];
    int parent[node];

    for(i=0;i<node;i++)
    {
        dist[i]=1000;
        parent[i]=-1;
    }

    cout<<"enter the source node"<<endl;
    int source;
    cin>>source;

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
                 cout<<"NEGETIVE WEIGHT CYCLE DETECTED"<<endl<<"SHORTED PATH CANNOT BE CALCULATED"<<endl;
                 return 0;
            }
        }

    for(i=0;i<node;i++)
    {
        cout<<"Shortest path from "<<source<<" to "<<i<<" is of weight: "<<dist[i]<<" as follows : ";
        print(source,i,parent);
        cout<<"-->"<<i<<endl;
    }

    return 0;
}
