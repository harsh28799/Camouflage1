#include<stdio.h>

struct student
{
    char name[20];
    int roll;
    float cgpa;
};
int main()
{
    int i;
    int num;
    printf("enter the number of students:\n");
    scanf("%d",&num);

    struct student no[num];
    struct student *ptr;
    ptr=&no[0];

    printf("enter the details of students:\n\n");

    for(i=0;i<num;i++)
    {
        scanf("%s",ptr->name);
        scanf("%d",&ptr->roll);
        scanf("%f",&ptr->cgpa);
        ptr++;
    }

    printf("\n\n:  STUDENT DETAILS  :\n\n");

    ptr=&no[0];
    for(i=0;i<num;i++)
    {
        printf("%s\t",ptr->name);
        printf("%d\t",ptr->roll);
        printf("%f\n",ptr->cgpa);
        ptr++;
    }

    return 0;
}

