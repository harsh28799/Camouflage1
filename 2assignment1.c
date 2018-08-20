#include<stdio.h>
#include<stdlib.h>
struct node
{

	int info;
	struct node *next;

}*header,*ptr,*temp,*nptr;

void createEmptyList()
{

	header=NULL;

}

void checkEmptyList()
{

	if(header==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		printf("the list is not empty\n");
	}

}

void createList()
{

	int i=0;
	printf("enter the number of nodes you want to create\n");
	int num;
	scanf("%d",&num);
	printf("enter the elments\n");
	while(i<num)
	{
		if(header==NULL)
		{
		ptr=(struct node*)malloc(sizeof(struct node));
		header=ptr;
		scanf("%d",&ptr->info);
		ptr->next=NULL;
		}
		else
		{
		ptr=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&ptr->info);
		ptr->next=header;
		header=ptr;
		}
	i++;
	}

}

void insertBeginning()
{
	printf("enter the element you want to insert\n");
	ptr=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&ptr->info);
	ptr->next=header;
	header=ptr;
}

void insertEnd()
{
	printf("enter the element you want to insert\n");
 	ptr=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&ptr->info);
	temp=header;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->next=NULL;
}

void insertAfter()
{
	printf("enter the specified data\n");
	int position;
	scanf("%d",&position);
	int data;
	printf("enter the info\n");
	scanf("%d",&data);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->info=data;
	temp=header;
	while(temp!=NULL&&temp->info!=position)
	{
		temp=temp->next;
	}
	if(temp==NULL)
		printf("element not found\n");
	else
	{
		ptr->next=temp->next;
		temp->next=ptr;
	}
}


void insertBefore()
{
	printf("enter the specified data\n");
	int position;
	scanf("%d",&position);
	int data;
	printf("enter the info\n");
	scanf("%d",&data);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->info=data;
	temp=header;
	if(header->info==position)
	{
		ptr->next=header;
		header=ptr;
	}
	else
{
	while(temp!=NULL&&temp->info!=position)
	{
		nptr=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		printf("element not found");
	else
	{
		nptr->next=ptr;
		ptr->next=temp;
	}
}

}
void average()
{
	float avg=0.0;
	int sum=0;
	temp=header;
	int i=0;
	while(temp!=NULL)
	{
		sum=sum+temp->info;
		i++;
		temp=temp->next;
	}
	avg=(float)(sum/i);
	printf("the average of the elements:%f ",avg);
}

void append()
{
	int num;
  	struct node *head=NULL;
	printf("enter the number of elements you want to insert\n");
	scanf("%d",&num);
	printf("enter the elements you want to insert\n");
	while(num>0)
	{
		struct node *ptr=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&ptr->info);
		if(head==NULL)
		{
			head=ptr;
			ptr->next=NULL;
		}
		else
		{
			ptr->next=head;
			head=ptr;
		}
		num--;
	}
	if(header==NULL)
    {
        header=head;
    }
    else
    {

        struct node *temp=header;
        struct node *nptr;
        while(temp!=NULL)
        {
            nptr=temp;
            temp=temp->next;
        }
        nptr->next=head;
    }
}

void frequency()
{
	int i;
  	struct node *temp=header;
	int arr[101];
	if(header==NULL)
{printf("the list is empty\n");return;}
	for(i=0;i<101;i++)
	{
		arr[i]=0;
	}
	while(temp!=NULL)
	{
		arr[temp->info]++;
		temp=temp->next;
	}
	for(i=0;i<101;i++)
	{
		if(arr[i]>0)
			printf("the frequency of %d is\t  %d \n",i,arr[i]);
	}
}

void deleteBeginning()
{
if(header==NULL)
{printf("the list is empty\n");return;}
	temp=header;
	header=temp->next;
	free(temp);
}

void deleteEnd()
{
if(header==NULL)
{printf("the list is empty\n");return;}
	temp=header;
	while(temp->next!=NULL)
	{
		nptr=temp;
		temp=temp->next;
	}
	nptr->next=NULL;
	free(temp);
}

void deleteThe()
{
if(header==NULL)
{printf("the list is empty\n");return;}
	printf("enter the specific number\n");
	int position;
	scanf("%d",&position);
	temp=header;
	while(temp!=NULL&&temp->info!=position)
	{
		nptr=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		printf("element not found\n");
	else
	{
		nptr->next=temp->next;
		free(temp);
	}
}

void deleteList()
{
	while(header!=NULL)
	{
		temp=header;
		header=header->next;
		free(temp);
	}
}

void display()
{
	temp=header;
	printf("\n");
	if(header==NULL)
	{
		printf("the list is empty\n");
	}
else
{
	while(temp!=NULL)
	{
		printf("|%d|\t",temp->info);
		temp=temp->next;
	}
}
}
int main()
{
	int choice;
	printf("MENU OF CHOICE\n1.create empty list\n2.check if list is empty\n3.create a list\n4.insert in the beginning\n5.insert in the end\n6.insert after an element\n7.insert before an element\n8.calculate average\n9.calculate frequency\n10.append with a new list\n11.delete from end\n12.delete from beginning\n13.delete a specific node\n14.delete the complete list\n15.display the list\n");
	printf("\nenter your choice:1-15\n");
	scanf("%d",&choice);
	do
	{
	switch(choice)
	{
		case 1:createEmptyList();break;
		case 2:checkEmptyList();break;
		case 3:createList();break;
		case 4:insertBeginning();break;
		case 5:insertEnd();break;
		case 6:insertAfter();break;
		case 7:insertBefore();break;
		case 8:average();break;
		case 9:frequency();break;
		case 10:append();break;
		case 11:deleteEnd();break;
		case 12:deleteBeginning();break;
		case 13:deleteThe();break;
		case 14:deleteList();break;
		case 15:display();break;
	}
	printf("\nif you want to continue enter a choice between 1-15\n");
	scanf("%d",&choice);
	}while(choice>=1&&choice<=16);
}
