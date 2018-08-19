#include<stdio.h>
#include<stdlib.h>
typedef struct nodal
{
    int coefficient;
    int exponent;
    struct nodal *next;
}node;
void createList(node **head)
{
    int a=1;
    node *ptr,*nptr=NULL;
    printf("enter the coefficient and exponent consecutively\n");
    while(a!=0)
    {
        ptr=(node*)malloc(sizeof(node));
        scanf("%d%d",&ptr->coefficient,&ptr->exponent);
        a=ptr->exponent;
        ptr->next=NULL;
        node *temp=*head;
        if(*head==NULL)
        {
            *head=ptr;
            nptr=ptr;
        }
        else
        {
            nptr->next=ptr;
            nptr=nptr->next;
        }
    }
}
void addList(node *head1,node *head2,node **head)
{
    node *nptr=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        node *ptr=(node*)malloc(sizeof(node));
        if((head1->exponent)==(head2->exponent))
        {
            int a=head1->coefficient;
            int b=head2->coefficient;
            ptr->coefficient=a+b;
            ptr->exponent=head1->exponent;
            head1=head1->next;
            head2=head2->next;
        }
        else if((head1->exponent)<(head2->exponent))
        {
            ptr->coefficient=head2->coefficient;
            ptr->exponent=head2->exponent;
            head2=head2->next;
        }
        else
        {
            ptr->coefficient=head1->coefficient;
            ptr->exponent=head1->exponent;
            head1=head1->next;
        }
        ptr->next=NULL;
        if(*head==NULL)
        {
            *head=ptr;
            nptr=ptr;
        }
        else
        {
            nptr->next=ptr;
            nptr=nptr->next;
        }
    }
    if(head1!=NULL)
    {
        while(head1!=NULL)
        {
            node *ptr=(node*)malloc(sizeof(node));
            ptr->coefficient=head1->coefficient;
            ptr->exponent=head1->exponent;
            head1=head1->next;
            ptr->next=NULL;
            if(*head==NULL)
            {
                *head=ptr;
                nptr=ptr;
            }
            else
            {
                nptr->next=ptr;
                nptr=nptr->next;
            }
        }
    }
    if(head2!=NULL)
    {
        while(head2!=NULL)
        {
            node *ptr=(node*)malloc(sizeof(node));
            ptr->coefficient=head2->coefficient;
            ptr->exponent=head2->exponent;
            head2=head2->next;
            ptr->next=NULL;
            if(*head==NULL)
            {
                *head=ptr;
                nptr=ptr;
            }
            else
            {
                nptr->next=ptr;
                nptr=nptr->next;
            }
        }
    }
}
void display(node *head)
{
    while(head->next!=NULL)
    {
        printf("%dX^%d + ",head->coefficient,head->exponent);
        head=head->next;
    }
    printf("%dX^%d ",head->coefficient,head->exponent);
    printf("=0\n");
}
int main()
{
    node *header,*header1,*header2,*sum;
    int choice;
    char ch;
    printf("MENU\n1.Represent the polynomial using linked list\n2.Add two polynomials\n");
    do
    {
        printf("enter your choice: 1 OR 2\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:header=NULL;
                   createList(&header);
                   printf("your entered polynomial is \n");
                   display(header);
                   break;
            case 2:header1=NULL;
                   header2=NULL;
                   sum=NULL;
                   printf("enter the first polynomial\n");
                   createList(&header1);
                   display(header1);
                   printf("enter the second polynomial\n");
                   createList(&header2);
                   display(header2);
                   addList(header1,header2,&sum);
                   printf("the sum of the entered polynomial is \n");
                   display(sum);
                   break;
            default:printf("wrong choice\n");
        }
        printf("do you want to continue (Y/N)\n");
        scanf("%s",&ch);
    }while(ch=='Y'||ch=='y');
    return 0;
}


