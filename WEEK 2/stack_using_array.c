#include<stdio.h>
void push(int arr[],int *top,int num)
{
    (*top)++;
    arr[*top]=num;
}
int isStackFull(int top,int max)
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void pop(int arr[],int *top)
{
    (*top)--;
}
int isStackEmpty(int top)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void display(int arr[],int top)
{
    int temp;
    for(temp=top;temp>-1;temp--)
    {
        printf("|%d|<--",arr[temp]);
    }
}
int main()
{
    int max_size=10;
    int arr[max_size];
    int top=-1;
    int choice;
    int num;
    char ch;
    do
    {
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element you want to insert\n");
                   scanf("%d",&num);
                   if(isStackFull(top,max_size))
                       printf("Stack is full\nElement cannot be inserted\n");
                   else
                   {
                       push(arr,&top,num);
                   }
                   break;
            case 2:if(isStackFull(top,max_size))
                       printf("Stack is full\n");
                   else
                       printf("Stack is not full\n");
                   break;
            case 3:if(isStackEmpty(top))
                       printf("Stack is Empty\nElement cannot be popped\n");
                   else
                       pop(arr,&top);
                   break;
            case 4:if(isStackEmpty(top))
                       printf("Stack is empty\n");
                   else
                       printf("Stack is not empty\n");
                   break;
            case 5:if(isStackEmpty(top))
                       printf("Stack is Empty\n");
                   else
                       display(arr,top);
                   break;
            default:printf("Wrong choice\n");
        }
        printf("Do you want to continue (Y/N)\n");
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}
