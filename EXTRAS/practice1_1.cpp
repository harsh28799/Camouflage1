#include<stdio.h>
int main()
{
    int i;
    int num;
    printf("enter the number of students:\n");
    scanf("%s",&num);
    char name[num][10];
    int roll[num];
    char *name_ptr[num];
    int *roll_ptr[num];
    for(i=0;i<num;i++)
    {
        name_ptr[i]=&name[i][0];
        roll_ptr[i]=&roll[i];
    }
    printf("\n Enter the Details of students: \n");
    for(i=0;i<num;i++)
    {
        scanf("%s",name_ptr[i]);
        scanf("%d",roll_ptr[i]);
    }
    printf("\n DETAILS ARE: \n");
    for(i=0;i<num;i++)
    {
        printf("%d.\n\t%s\n\t%d\n",i,*name_ptr[i],*roll_ptr[i]);
    }
}
