#include<bits/stdc++.h>
using namespace std;

vector <int> arr[20],wgt[20];

int dist[20];
int parent[20];
int status[20];

int node,edge;

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

    cout<<"enter the edges with therie weights"<<endl;
    for(i=0;i<edge;i++)
    {
        int a,b;
        int w;
        cin>>a>>b>>w;
        arr[a].push_back(b);
        wgt[a].push_back(w);
        arr[b].push_back(a);
        wgt[b].push_back(w);
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

        cout<<parent[num]<<"<--"<<dist[num]<<"-->"<<num<<endl;

        status[num]=1;

        path+=dist[num];

        size--;

        for(i=0;i<arr[num].size();i++)
        {
            int temp=arr[num][i];
            int tempw=wgt[num][i];
            if(status[temp]==0&&dist[temp]>tempw)
            {
                dist[temp]=tempw;
                parent[temp]=num;
            }
        }
    }

    cout<<"The size of minimum spanning tree remains at:"<<path<<endl;

    return 0;
}
