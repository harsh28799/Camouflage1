#include<bits/stdc++.h>
using namespace std;

vector <int> arr[20],wgt[20];

int dist[20];
int parent[20];
int status[20];

int node,edge;

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

int extractmin()
{
    int i;
    int min=20;
    dist[min]=1000;
    for(i=0;i<node;i++)
    {
        if(dist[i]<dist[min]&&status[i]==0)
            min=i;
    }
    status[min]=1;
    return min;
}

int main()
{
    int i,j;

    int path=0;

    cout<<"enter the number of nodes"<<endl;
    cin>>node;

    int ans[3*(node)];
    int ctr=0;

    cout<<"enter the number of edges"<<endl;
    cin>>edge;

    cout<<"enter the edges with their weights"<<endl;
    for(i=0;i<edge;i++)
    {
        int a,b;
        int w;
        cin>>a>>b>>w;
        arr[a].push_back(b);
        wgt[a].push_back(w);
    }

    for(i=0;i<node;i++)
    {
        cout<<"The adjacent nodes and their corresponding weights of "<<i<<"are: ";
        for(j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" "<<wgt[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(i=0;i<node;i++)
    {
        dist[i]=1000;
        parent[i]=-1;
        status[i]=0;
    }

    int size=node;

    int source;
    cout<<"Enter the source node"<<endl;
    cin>>source;
    dist[source]=0;

    while(size>0)
    {
        int num=extractmin();

        size--;

        for(i=0;i<arr[num].size();i++)
        {
            int temp=arr[num][i];
            int tempw=wgt[num][i];
            if(dist[temp]>tempw+dist[num])
            {
                dist[temp]=tempw+dist[num];
                parent[temp]=num;
            }
        }
    }

    for(i=0;i<node;i++)
    {
        cout<<dist[i]<<"\t";
    }
    cout<<endl;

    for(i=0;i<node;i++)
    {
        cout<<parent[i]<<"\t";
    }
    cout<<endl;

    for(i=0;i<node;i++)
    {
        cout<<"Shortest path from "<<source<<" to "<<i<<" is of weight: "<<dist[i]<<" as follows : ";
        print(source,i,parent);
        cout<<"-->"<<i<<endl;
    }

    return 0;
}
