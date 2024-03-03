// implementation of stack using array
#include<stdio.h>
#include<stdlib.h>
#define N 5;
//int N
int stack[N];
int top =-1;

void main()
{
    void push()
    {
        int x;
        printf("Enter the no: ");
        scanf("%d",&x);
        if(top==N-1)
        {
            printf("Stack is full, Overflow condition");
        }
        else
        {
            top++;
            stack[top]=x;
        }
    }

    void pop()
    {
        int item;
        if(top==-1)
        {
            printf("Stack is empty, Underflow condition");
        } 
        else{
            item=stack[top];
            top--;
        }
        printf("%d",item);
    }

    void peek()
    {
        if(top==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            printf("The top most element is %d",&stack[top]);
        }
    }

    void display()
    {
    int i;
    for(i=top; i>=0; i--)
    {
        printf("%d",stack[i]);
    }
    }

}