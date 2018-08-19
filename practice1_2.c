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

    printf("enter the details of the students:\n\n");

    for(i=0;i<num;i++)
    {
        scanf("%s",&no[i].name);
        scanf("%d",&no[i].roll);
        scanf("%f",&no[i].cgpa);
    }

    printf(":  DETAILS OF STUDENTS  :\n\n");

    for(i=0;i<num;i++)
    {
        printf("%s\t",no[i].name);
        printf("%d\t",no[i].roll);
        printf("%f\n",no[i].cgpa);
    }

    return 0;
}


