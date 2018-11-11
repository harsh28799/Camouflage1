#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *stack[100];
int top=-1;
struct node *root;

void insert(char arr[])
{
    int i=0;
    while(arr[i]!='\0')
    {
        if(arr[i]!='+'&&arr[i]!='-'&&arr[i]!='*'&&arr[i]!='/'&&arr[i]!='^')
        {
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=arr[i];
            ptr->left=NULL;
            ptr->right=NULL;
            stack[++top]=ptr;
        }
        else
        {
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=arr[i];
            ptr->left=stack[top--];
            ptr->right=stack[top--];
            stack[++top]=ptr;
        }
        i++;
    }
    root=stack[top--];
}

char traversal(struct node *ptr)
{
    if(ptr!=NULL)
    {
        traversal(ptr->left);
        printf("%c ",ptr->data);
        traversal(ptr->right);
    }
    return 0;
}

int main()
{
    char ch[100]={'A','B','*','C','D','/','-'};
    insert(ch);
    traversal(root);
}

