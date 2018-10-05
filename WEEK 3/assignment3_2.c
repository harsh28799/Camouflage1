/* HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 3 QUESTION 2
 * STACK IMPLEMENTATION USING LINKED LIST*/

#include<stdio.h>
#include<stdlib.h>
typedef struct nodal
{
    int info;
    struct node *next;
}node;
node *top;
int max_size=10;
int ctr=0;
void push(int num)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->info=num;
    ptr->next=NULL;
    if(top==NULL)
        top=ptr;
    else
    {
        ptr->next=top;
        top=ptr;
    }
    ctr++;
}
void pop()
{
    node *ptr=top;
    top=top->next;
    free(ptr);
    ctr--;
}
int isStackEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
int isFull()
{
	if(ctr<max_size)
		return 1;
	else
		return 0;
}
void display()
{
    node *ptr=top;
    printf("-->");
    while(ptr!=NULL)
    {
        printf("\t|%d|\n",ptr->info);
        ptr=ptr->next;
    }
}
int main()
{
    char ch;
    int num;
    top=NULL;
    int choice;
    printf("MENU\n1.PUSH\n2.POP\n3.CHECK EMPTY\n4.CHECK FULL\n5.DISPLAY\n\n");
    do
    {
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(isFull())
		   {
			printf("enter the element you want to insert\n");
                      	scanf("%d",&num);
                        push(num);
		   }
		   else
			   printf("stack is full\nelement cannot be inserted\n");
		   break;
            case 2:if(isStackEmpty())
                       printf("Stack is Empty\nElement cannot be popped\n");
                   else
                       pop(top);
                   break;
            case 3:if(isStackEmpty(top))
                       printf("Stack is empty\n");
                   else
                       printf("Stack is not empty\n");
                   break;
	    case 4:if(isFull())
			   printf("stack is not full\n");
		   else
			   printf("stack is full");
		   break;
            case 5:if(isStackEmpty(top))
                       printf("Stack is Empty\n");
                   else
                       display(top);
                   break;
            default:printf("Wrong choice\n");
        }
        printf("Do you want to continue (Y/N)\n");
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}

