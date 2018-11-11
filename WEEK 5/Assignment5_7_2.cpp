#include<bits/stdc++.h>
using namespace std;
vector <int> arr[20];
int test[20];
int m;
void explore(int a)
{
    int i;
    cout<<a<<" ";
    test[a]=1;
    for(i=0;i<arr[a].size();i++)
    {
        int x=arr[a][i];
        if(x==m)
        {
            printf(" CYCLE DETECTED ");
            break;
        }
        if(test[x]==0)
            explore(x);
    }
    return;
}
int main()
{
    int i,j;
    int node,edge;
    cout<<"enter the number of nodes"<<endl;
    cin>>node;
    cout<<"enter the number of edges"<<endl;
    cin>>edge;
    cout<<"enter the edges"<<endl;
    for(i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }
    for(i=0;i<node;i++)
    {
        cout<<"adjacent nodes of "<<i<<":";
        for(j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(j=0;j<node;j++)
    {
        m=j;
        for(i=0;i<node;i++)
        {
            test[i]=0;
        }
        explore(j);
        cout<<endl;
    }
    return 0;
}
