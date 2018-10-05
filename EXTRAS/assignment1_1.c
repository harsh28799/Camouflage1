#include<stdio.h>
#include<math.h>
float arr[100];
float arr1[100];
float num;
float one()
{
    float i;
    int j=0;
    for(i=0.0;i<=num;i=i+5.0)
    { 
      	arr1[j]=log(i)/log(10);
       	j++;
    }
}
float two()
{
    float i;
	int j=0;
	for(i=0.0;i<=num;i=i+5.0)
	{
		arr1[j]=(5*i)+2;
		j++;
	}
}
float three()
{
	float i;
	int j=0;
	for(i=0;i<=num;i=i+5.0)
	{
		arr1[j]=i*log(i)/log(10);
		j++;
	}
}
float four()
{
	float i;
	int j=0;
	for(i=0.0;i<=num;i=i+5.0)
	{
		arr1[j]=i*i;
		j++;
	}
}
float five()
{
	float i;
	int j=0;
	for(i=0.0;i<=num;i=i+5.0)
	{
		arr1[j]=i*i*i*i;
		j++;
	}
}
float six()
{
	float i;
	int j=0;
	for(i=0.0;i<=num;i=i+5.0)
	{
		arr1[j]=pow(2,i);
		j++;
	}
}
float seven()
{
	float i;
	int j=0;
	for(i=0.0;i<=num;i=i+5.0)
	{
       		arr1[j]=i*i*i;
		j++;
	}
}
int main()
{
	int j=0;
	printf("\tENTER THE SIZE OF THE PROBLEM\n");
	scanf("%f",&num);
	float i;
	for(i=0.0;i<=num;i=i+5.0)
	{
		arr[j]=i;
		j++;
	}
	
 	char ch;
	int choice;
	printf("\tENTER YOUR CHOICE OF FUNCTION\n\tFROM 1 to 7\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:one();
				break;
			case 2:two();
				break;
			case 3:three();
				break;
			case 4:four();
				break;
			case 5:five();
				break;
			case 6:six();
				break;
			case 7:seven();
				break;
			default: printf("wrong choice");
		}
		if(choice>=1&&choice<=7)
		{
			int i=0;
			int j=0.0;
			printf("------------------YOUR REQUIRED PLOT-----------------\n");
			printf("\t\t n\t\tf(n)\n");
			printf("-----------------------------------------------------\n");
			for(j=0.0;j<=num;j=j+5)
			{
				printf("\t\t%f\t%f\n",arr[i],arr1[i]);
				i++;
			}
			printf("-----------------------------------------------------\n");
		}
	printf("\tIF YOU WANT TO CONTINUE WITH OTHER FUNCTION\n \tENTER A CHOICE FROM 1 to 7\n \tPRESS ANY OTHER NUMBER TO EXIT \n");
	scanf("%d",&choice);
	}while(choice>=1&&choice<=7);
	return 0;
}
