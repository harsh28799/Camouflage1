/* HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 3 QUESTION 1
 * STACK IMPLEMENTATION USING ARRAY*/

#include<stdio.h>
int top=-1;
void push(int arr[],int num)
{
    top++;
    arr[top]=num;
}
int isStackFull(int max)
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void pop(int arr[])
{
    top--;
}
int isStackEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void display(int arr[])
{
    int temp;
	printf("-->");
    for(temp=top;temp>-1;temp--)
    {
        printf("\t|%d|\n",arr[temp]);
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
    printf("MENU\n1.PUSH\n2.CHECK FULL\n3.POP\n4.CHECK EMPTY\n5.DISPLAY\n\n");
    do
    {
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element you want to insert\n");
                   scanf("%d",&num);
                   if(isStackFull(max_size))
                       printf("Stack is full\nElement cannot be inserted\n");
                   else
                   {
                       push(arr,num);
                   }
                   break;
            case 2:if(isStackFull(max_size))
                       printf("Stack is full\n");
                   else
                       printf("Stack is not full\n");
                   break;
            case 3:if(isStackEmpty())
                       printf("Stack is Empty\nElement cannot be popped\n");
                   else
                       pop(arr);
                   break;
            case 4:if(isStackEmpty())
                       printf("Stack is empty\n");
                   else
                       printf("Stack is not empty\n");
                   break;
            case 5:if(isStackEmpty())
                       printf("Stack is Empty\n");
                   else
                       display(arr);
                   break;
            default:printf("Wrong choice\n");
        }
        printf("Do you want to continue (Y/N)\n");
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
return 0;
}
