#include<stdio.h>
#include<stdlib.h>

typedef struct Minstack
{
    int capacity;
    int* elements;
    int* min_stack;
    int top;
    int mintop;
}Minstack; 

 Minstack* createMinsatck(int capacity)
 {
    Minstack* stack = (Minstack*)malloc(sizeof(Minstack));
    stack->capacity = capacity;
    stack->elements = (int*)malloc(sizeof(int)*capacity);
    stack->min_stack = (int*)malloc(sizeof(int)*capacity);
    stack->top = -1;
    stack->mintop = -1;
    return stack;
 }

 void push(Minstack* stack,int data)
 {
    if(stack->top == stack->capacity-1)

    {
        printf("Overflow");
        return;
    }
    stack->top++;
    stack->elements[stack->top] = data;

    if(stack->mintop = -1 || data<= stack->min_stack[stack->mintop])
    {
        stack->mintop++;
        stack->min_stack[stack->mintop] = data;
    }


 }

 int pop(Minstack* stack)
 {
    if(stack->top == -1)
    {
        printf("Underflow");
        return 0;
    }
    int ele = stack->elements[stack->top];
    stack->top--;
    if(ele = stack->min_stack[stack->mintop])
    {
        stack->mintop--;
    }
    return ele;
 }

 int peek(Minstack* stack)
 {
    if(stack->top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    return stack->elements[stack->top];
 }

 int get_min(Minstack* stack)
 {
    if(stack->mintop == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    return stack->min_stack[stack->mintop];
 }

 void display(Minstack* stack)
 {
    if(stack->top == -1)
    {
        printf("Stack is empty");
        return;
    }
    printf("Elements: ");
    for(int i=stack->top; i>=0; i--)
    {
        printf("%d",stack->elements[i]);
    }
    printf("\n Minstack elements: ");
    for(int i= stack->mintop; i>=0; i--)
    {
        printf("%d",stack->min_stack[i]);
    }
 }

 void freemin(Minstack* stack)
 {
    free(stack->elements);
    free(stack->min_stack);
    free(stack);
 }

 void main()
 {
    int capacity = 100;
    Minstack* stack = createMinsatck(capacity);
    push(stack,10);
    push(stack,8);
    push(stack,11);
    push(stack,5);
    push(stack,1);

    display(stack);
    int min = get_min(stack);
    printf("\nMinimum ele: %d\n",min);

    printf("Poped ele: %d\n",pop(stack));
    printf("Poped ele: %d\n",pop(stack));

    printf("After Poping: ");
   
 }

