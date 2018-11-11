#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[50]={'A','*','B','-','C','/','D'},postfix[50],stack[50];
int top=-1;

void push(char ch)
{
    top++;
    stack[top]=ch;
}

char pop()
{
    if(top==-1)
    {
        return 0;
    }
    char t=stack[top];
    top--;
    return t;
}

int precedence(char ch)
{
    switch(ch)
    {
        case '^':return 5;
        case '/':return 4;
        case '*':return 4;
        case '+':return 3;
        case '-':return 3;
        default :return 0;
    }
}



struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *stack1[100];
int top1=-1;
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
            stack1[++top1]=ptr;
        }
        else
        {
            struct node *ptr=(struct node *)malloc(sizeof(struct node));
            ptr->data=arr[i];
            ptr->right=stack1[top1--];
            ptr->left=stack1[top1--];
            stack1[++top1]=ptr;
        }
        i++;
    }
    root=stack1[top1--];
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
    char ch,cha;
    int ele,elem;
    char popped;
    int j=0;
    int i;
    int len=strlen(infix);
    push('#');
    for(i=0;i<len;i++)
    {
        ch=infix[i];
        if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='^')
            postfix[j++]=ch;
        else
        {
            ele=precedence(ch);
            cha=stack[top];
            elem=precedence(cha);
            if(elem<ele)
                push(ch);
            else
            {
                while(elem>=ele)
                {
                    if(cha=='#')
                        break;
                    popped=pop();
                    cha=stack[top];
                    postfix[j++]=popped;
                    elem=precedence(cha);
                }
                push(ch);
            }
        }
    }
        while((popped=pop())!='#')
        postfix[j++]=popped;
    postfix[j]='\0';

    insert(postfix);
    traversal(root);
}



