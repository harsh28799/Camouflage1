#include<bits/stdc++.h>
using namespace std;

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
        cout<<"-->"<<temp[j];
    }
}

int main()
{
    int i,j,k;

    int node;
    cout<<"enter the total number of nodes"<<endl;
    cin>>node;

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
    cout<<"enter the number of edges"<<endl;
    cin>>edge;

    for(i=0;i<edge;i++)
    {
        int a,b;
        int w;
        cin>>a>>b>>w;
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

    cout<<"Minimum distance matrix is"<<endl;
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"Path determinant matrix is"<<endl;
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            cout<<parent[i][j]<<"\t";
        }
        cout<<endl;
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
            cout<<"The minimum distance from "<<i<<" to "<<j<<":"<<dist[i][j]<<" path: ";
            print(i,j,temp);
            cout<<"-->"<<j<<endl;
        }
    }

    return 0;
}
