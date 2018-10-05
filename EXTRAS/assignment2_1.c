//implementation of linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct nodal
{
    int info;
    struct node *next;
}node;
void createNewList(node **head)
{
    *head=NULL;
    if(*head==NULL)
        printf("empty list created\n");
    else
        printf("list creation unsuccessful\n");
}
void checkEmptyList(node *head)
{
    if(head==NULL)
        printf("the list is empty\n");
    else
        printf("the list is not empty");
}
void createList(node **head,int num)
{

    while(num>0)
    {
        node *ptr=(node*)malloc(sizeof(node));
        printf("enter the %d number\n",num);
        scanf("%d",&ptr->info);
        ptr->next=*head;
        *head=ptr;
        num--;
    }
}
void insertBeginning(node **head)
{
    node *ptr=(node*)malloc(sizeof(node));
    printf("enter the element to be inserted\n");
    scanf("%d",&ptr->info);
    ptr->next=*head;
    *head=ptr;
}
void insertEnd(node **head)
{
    node *ptr=(node*)malloc(sizeof(node));
    printf("enter the element to be inserted\n");
    scanf("%d",&ptr->info);
    ptr->next=NULL;
    node *temp=*head;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void insertAfter(node *head)
{
    int datapos;
    printf("enter the element after which you want to insert an element\n");
    scanf("%d",&datapos);
    node *ptr=(node*)malloc(sizeof(node));
    printf("enter the element to be inserted\n");
    scanf("%d",&ptr->info);
    while(head!=NULL&&head->info!=datapos)
    {
        head=head->next;
    }
    if(head==NULL)
        printf("element not found\n");
    else
    {
        ptr->next=head->next;
        head->next=ptr;
    }
}
void insertBefore(node **head)
{
    node *temp=*head;
    int datapos;
    printf("enter the element before which you want to insert the element\n");
    scanf("%d",&datapos);
    node *ptr=(node*)malloc(sizeof(node));
    printf("enter the element to be inserted\n");
    scanf("%d",&ptr->info);
    node *nptr;
    if((*head)->info==datapos)
    {
        ptr->next=*head;
        *head=ptr;
    }
    else
    {
            while(temp!=NULL&&temp->info!=datapos)
            {
                nptr=temp;
                temp=temp->next;
            }
            if(temp==NULL)
                printf("element not found\n");
            else
            {
                ptr->next=temp;
                nptr->next=ptr;
            }
    }
}
void deleteEnd(node *head)
{
    node *temp;
    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
    }
    temp->next=NULL;
    free(head);
}
void deleteBeginning(node **head)
{
    node *ptr=*head;
    *head=(*head)->next;
    free(ptr);
}
void deleteThe(node **head)
{
    int datapos;
    printf("enter the element you want to delete\n");
    scanf("%d",&datapos);
    node *temp=*head;
    if(temp->info==datapos)
    {
        *head=(*head)->next;
        free(temp);
    }
    else
    {
        node *ptr;
        while(temp!=NULL&&temp->info!=datapos)
        {
            ptr=temp;
            temp=temp->next;
        }
        if(temp==NULL)
            printf("element not found\n");
        else
        {
            ptr->next=temp->next;
            free(temp);
        }
    }
}
void deleteList(node **head)
{
    node *ptr=*head;
    while(*head!=NULL)
    {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}
void average(node *head)
{
    int i=0;
    int sum=0;
    while(head!=NULL)
    {
        i++;
        sum+=head->info;
        head=head->next;
    }
    float avg=(float)sum/i;
    printf("%f",avg);
}
void frequency(node *head)
{
    node *ptr=head;
    int max=head->info;
    int i;
    while(head!=NULL)
    {
        if((head->info)>max)
            max=head->info;
        head=head->next;
    }
    int arr[max+1];
    for(i=0;i<=max;i++)
        arr[i]=0;
    while(ptr!=NULL)
    {
        arr[ptr->info]++;
        ptr=ptr->next;
    }
    for(i=0;i<=max;i++)
    {
        if(arr[i]!=0)
        {
            printf("the frequency of %d\t is \t %d\n",i,arr[i]);
        }
    }
}
void append(node *head)
{
    node *newhead=NULL;
    int num;
    printf("enter the number of elements for the new list\n");
    scanf("%d",&num);
    createList(&newhead,num);
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=newhead;
}
void display(node *head)
{
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        while(head!=NULL)
        {
            printf("%d\t",head->info);
            head=head->next;
        }
        printf("\n");
    }
}
int main()
{
    node *header;
    int choice;
    char ch='y';
    printf("MENU OF CHOICES \n1.Create new list\n2.Check if the list is empty\n3.Create list with a given number of elements\n4.Insert element at the beginning of the list\n5.Insert element at the end of the list\n6.Insert element after a given element\n7.Insert element before a given element\n8.Delete element from the end\n9.Delete element from the beginning\n10.Delete a specific node\n11.Delete the complete list\n12.Calculate average of elements\n13.Calculate and display frequency of each element\n14.Append the linked list with another list\n15.Display the elements in the list\n");
    do
    {
        printf("enter your choice between 1-15\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:createNewList(&header);break;
            case 2:checkEmptyList(header);break;
            case 3:createList(&header,10);break;
            case 4:insertBeginning(&header);break;
            case 5:insertEnd(&header);break;
            case 6:insertAfter(header);break;
            case 7:insertBefore(&header);break;
            case 8:deleteEnd(header);break;
            case 9:deleteBeginning(&header);break;
            case 10:deleteThe(&header);break;
            case 11:deleteList(&header);break;
            case 12:average(header);break;
            case 13:frequency(header);break;
            case 14:append(header);break;
            case 15:display(header);break;
            default:printf("\nNot a valid choice\n");
        }
        printf("do you want to continue with another choice (Y/N)\n");
        scanf("%s",&ch);
    }while(ch=='Y'||ch=='y');
    return 0;
}
