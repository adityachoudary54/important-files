#include<stdio.h>
#include<stdlib.h>
char stack[20];
int top = -1;
void push(char x)
{stack[++top] = x;}
 char pop()
{
    if(top == -1)
     return -1;
    else
     return stack[top--];
}
int operand(char c)
{
    if(c>='a' && c<='z')
        return (1);
    return 0;
}
int Operator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$'||ch=='(')
      return(1);
    return (0);
}
int prec(char c)
{
switch(c)
{
 case '(':return(0);
 case '+':
 case '-':return(1);
 case '*':
 case '/':return(2);
}
}
char *postfixconversion(char infix[])
{
char *e,c;
e=infix;
char postfix[40];
int i,j;
i=j=0;
while(e[i]!='\0')
{
if(operand(e[i]))
 {postfix[j++]=e[i];}
else if(Operator(e[i]))
{
if(e[i] == '(')
{push(e[i]);}
else if((prec(e[i]))>(prec(stack[top])))
{push(e[i]);}
else
{
while(prec(e[i])<=prec(stack[top]))
{postfix[j++]=pop();}
push(e[i]);
}
}
else if(e[i]==')')
{
while(c=pop()!='(')
{postfix[j++]=c;}
}
i++;
}
while(top != -1)
{
postfix[j++]=pop();
}
postfix[j++]='\0';
printf("%s",postfix);
}
int main()
{
char exp[20],post[20];
char *e, x;
printf("Enter the expression :: ");
scanf("%s",exp);
postfixconversion(exp);
//printf("%s",&post);
return 0;
}
