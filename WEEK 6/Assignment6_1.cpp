#include<iostream>
using namespace std;
int set[100];
int size[100];
int root(int p)
{
    while(p!=set[p])
        p=set[p];
    return p;
}
void link(int p,int q)
{
    int pi=root(p);
    int qi=root(q);
    if(pi==qi)
        return;
    if(size[pi]>size[qi])
    {
        set[qi]=pi;
        size[pi]+=size[qi];
    }
    else
    {
        set[pi]=qi;
        size[qi]+=size[pi];
    }
}

int main()
{
    int temp;
    int j;
    int i;

    cout<<"enter the number of nodes"<<endl;
    int node;
    cin>>node;

    for(i=0;i<node;i++)
    {
        set[i]=i;
        size[i]=1;
    }

    cout<<"enter the number of edges"<<endl;
    int edge;
    cin>>edge;

    int arr[edge][3];

    cout<<"enter the edges and their corresponding nodes"<<endl;
    for(i=0;i<edge;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

    for(i=0;i<edge;i++)
    {
        for(j=0;j<edge-i-1;j++)
        {
            if(arr[j][2]>arr[j+1][2])
            {
                temp=arr[j][0];
                arr[j][0]=arr[j+1][0];
                arr[j+1][0]=temp;

                temp=arr[j][1];
                arr[j][1]=arr[j+1][1];
                arr[j+1][1]=temp;

                temp=arr[j][2];
                arr[j][2]=arr[j+1][2];
                arr[j+1][2]=temp;

            }
        }
    }

    cout<<endl<<"The minimum spanning tree consists of these edges:"<<endl;
    for(i=0;i<edge;i++)
    {
        int a=arr[i][0];
        int b=arr[i][1];
        if(root(a)!=root(b))
        {
            link(a,b);
            cout<<a<<"<---"<<arr[i][2]<<"--->"<<b<<endl;
        }
    }

    return 0;
}
