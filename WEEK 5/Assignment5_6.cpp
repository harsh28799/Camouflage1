#include<bits/stdc++.h>
using namespace std;
vector <int> arr[20];
int test[20];
void explore(int a)
{
    int i;
    for(i=0;i<arr[a].size();i++)
    {
        int x=arr[a][i];
        if(test[x]==0)
            explore(x);
    }
    cout<<a<<" ";
    test[a]=1;

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

    for(i=0;i<node;i++)
    {
        if(test[i]==0)
        {
            explore(i);
        }
    }

    return 0;
}
