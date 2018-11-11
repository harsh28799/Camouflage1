#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *root;
struct node *arr[100];
int front=-1,rear=-1;

struct node *stack[100];
int top=-1;

void insert(char ch)
{
    if(front==rear&&front==-1)
    {
        front++;
        rear++;
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=ch;
        ptr->left=NULL;
        ptr->right=NULL;
        arr[rear++]=ptr;
        root=ptr;
    }
    else
    {
        if(arr[front]->left==NULL)
        {
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=ch;
            ptr->left=NULL;
            ptr->right=NULL;
            arr[front]->left=ptr;
            arr[rear++]=ptr;
        }
        else if(arr[front]->right==NULL)
        {
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=ch;
            ptr->left=NULL;
            ptr->right=NULL;
            arr[front]->right=ptr;
            arr[rear++]=ptr;
        }
        else
        {
            front++;
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=ch;
            ptr->left=NULL;
            ptr->right=NULL;
            arr[front]->left=ptr;
            arr[rear++]=ptr;
        }
    }
}

char traversal(struct node *ptr)
{
    stack[++top]=NULL;
    while(ptr!=NULL)
    {
        printf("%c ",ptr->data);
        if(ptr->right!=NULL)
             stack[++top]=ptr->right;
        if(ptr->left!=NULL)
            ptr=ptr->left;
        else
            ptr=stack[top--];
    }
}

int main()
{
    insert('A');
    insert('B');
    insert('C');
    insert('D');
    insert('E');
    insert('F');
    insert('G');
    traversal(root);
}
