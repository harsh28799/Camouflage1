#include<stdio.h>
#include<math.h>
char postfix[50],stack[50];
int top=-1;
char pop(char ch)
{
    display();
    int a=(int)stack[top--];
    display();
    int b=(int)stack[top--];
    display();
    switch(ch)
    {
        case '^':return (pow(a,b));
        case '+':return (a+b);
        case '-':return (a-b);
        case '/':return (a/b);
        case '*':return (a*b);
        default :printf("wrong operator\n");exit(0);
    }
}
void push(char ch)
{
    top++;
    stack[top]=ch;
    display();
}
void display()
{
    int temp;
    for(temp=top;temp>=0;temp--)
        printf("%c\t",stack[temp]);
}
int main()
{
    char c;
    int i,j=0;
    printf("enter the postfix expression separated into lines ) to exit\n");
    scanf("%s",postfix);
    char ch;
    char result;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(ch!='^'&&ch!='/'&&ch!='*'&&ch!='+'&&ch!='-')
            push(ch);
        else
        {
            result=pop(ch);
            push(result);
        }
    }
    int res=(int)stack[0];
    if(top==0)
        printf("%d",res);
    else
        printf("invalid postfix\n");
    return 0;
}
