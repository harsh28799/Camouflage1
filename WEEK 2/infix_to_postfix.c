#include<stdio.h>
#include<string.h>
char infix[50],postfix[50],stack[50];
int top=-1;
void push(char ch)
{
    top++;
    stack[top]=ch;
    printf("%c inserted\ntop %d\n",ch,top);
    display();
}
char pop()
{
    if(top==-1)
    {
        return 0;
    }
    char t=stack[top];
    top--;
    printf("popped element %c\n",t);
    display();
    return t;
}
void display()
{
    int temp=0;
    while(temp!=top+1)
    {
        printf("%c\t",stack[temp]);
        temp--;
    }printf("\n");
}
int check_braces()
{
    int i=0;
    int obr=0,cbr=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            obr++;
        else if(infix[i]==')')
            cbr++;
        i++;
    }
    if(obr>cbr)
        return 1;
    else if(obr<cbr)
        return -1;
    else
        return 0;
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^':return 5;
        case '/':return 4;
        case '*':return 4;
        case '+':return 3;
        case '-':return 3;
        default :return 0;
    }
}
int main()
{
    char ch,cha;
    int ele,elem;
    char popped;
    int j=0;
    int i;
    printf("enter the infix expression\n");
    scanf("%s",infix);
    printf("%s\n",infix);
    int len=strlen(infix);
    if(infix[len]=='\0')
        printf("IS FINE\n");
    int count=check_braces();
    if(count==0)
        printf("no of braces are equal\n");
    else
    {
        count==1?printf("opening braces more"):printf("closing braces more");
        return 0;
    }
    push('#');
    for(i=0;i<len;i++)
    {
        ch=infix[i];
        if(ch!='('&&ch!=')'&&ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='^')
            postfix[j++]=ch;
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while((popped=pop())!='(')
            {
                postfix[j++]=popped;
            }
        }
        else
        {
            ele=precedence(ch);
            cha=stack[top];
            elem=precedence(cha);
            if(elem<ele)
                push(ch);
            else
            {
                while(elem>=ele)
                {
                    if(cha=='#')
                        break;
                    popped=pop();
                    cha=stack[top];
                    postfix[j++]=popped;
                    elem=precedence(cha);
                }
                push(ch);
            }
        }
    }
        while((popped=pop())!='#')
        postfix[j++]=popped;
    postfix[j]='\0';
    for(i=0;postfix[i]!='\0';i++)
        printf("%c",postfix[i]);
    return 0;
}
