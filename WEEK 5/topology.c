

// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor

     // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}



/*HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 5 QUESTION 6
 * IMPLEMENTATION OF TOPOLOGICAL SORT*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodal
{
	int value;
	struct nodal *next;
}node;

node *arr[20];
int num;

void adjacency()
{
	int data;
	int i,j;
	int no;
	printf("enter the number of nodes\n");
	scanf("%d",&num);
	for(i=0;i<num;i++,arr[i]=NULL);
	for(i=0;i<num;i++)
	{
		printf("enter the number of adjacent nodes of %d ",i+1);
		scanf("%d",&no);
		for(j=0;j<no;j++)
		{
			printf("enter the %d adjacent node of %d ",j+1,i+1);
			scanf("%d",&data);
			node *ptr=(node*)malloc(sizeof(node));
			ptr->value=data;
			ptr->next=arr[i];
			arr[i]=ptr;
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%d:\t",i+1);
		node *ptr=arr[i];
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int visit[20];
int stack[20];
int fstack[20];
int top=-1;
int topf=-1;

int isEmpty()
{
	if(top==-1)
		return 0;
	else
		return 1;
}

void push(int val)
{
	top++;
	stack[top]=val;
}

int pop()
{
	int val=stack[top];
	top--;
	return val;
}

int pushf(int val)
{
	topf++;
	fstack[topf]=val;
}

void topology()
{
	int k;
	int i=0;
	for(i=0;i<num;i++,visit[i]=0);
	for(i=0;i<num;i++)
	{
		if(visit[i]==0)
		{
			push(i+1);
			visit[i]=1;
			k=0;
			while(k<=top)
			{
				node *ptr=arr[stack[k]-1];
				while(ptr!=NULL)
				{
					if(visit[(ptr->value)-1]==0)
					{
						push(ptr->value);
						visit[(ptr->value)-1]=1;
					}
					ptr=ptr->next;
				}
				k++;
			}
			while(isEmpty())
			{
				int val=pop();
				pushf(val);
			}
		}
	}
	while(topf>=0)
	{
		printf("%d ",fstack[topf--]);
	}
}

int main()
{
	adjacency();
	topology();
}


