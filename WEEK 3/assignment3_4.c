/* HARSH MOHAN
 * 117CS0232
 *
 * ASSIGNMENT 3 QUESTION 4
 * EVALUATION OF POSTFIX EXPRESSION*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array) return NULL;
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
int peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
int pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}
int evaluatePostfix(char* exp)
{
    struct Stack* stack = createStack(strlen(exp));
    int i;
    if (!stack) return -1;
    for (i = 0; exp[i]; ++i)
    {
        if(exp[i]==' ')continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i])) 
            {
            num=num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;
            push(stack,num);
         }
         else
         {
            int val1 = pop(stack);
            int val2 = pop(stack);
   
          
             switch (exp[i])
             {
             case '+': push(stack, val2 + val1); break;
             case '-': push(stack, val2 - val1); break;
             case '*': push(stack, val2 * val1); break;
             case '/': push(stack, val2/val1); break;
             
             }
          }
     }
     return pop(stack);
}
int main()
{
	printf("enter the postfix expression to be evaluated\n");
	char exp[100];
	gets(exp);
    printf ("%d", evaluatePostfix(exp));
    return 0;
}
