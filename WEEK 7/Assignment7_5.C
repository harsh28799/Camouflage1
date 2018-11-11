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
    if(ptr!=NULL)
    {
        traversal(ptr->left);
        traversal(ptr->right);
        printf("%c ",ptr->data);
    }
    return 0;
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
