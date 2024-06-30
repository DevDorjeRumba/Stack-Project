
#include <stdio.h>                             //Stack using C
#define SIZE 5

int stack[SIZE];
int top = -1;

int is_empty();
int is_full();
void push(int);
void pop ();
void display();

int i;

int main()
{

    int choice, data;

    while(1)
    {

    printf("\nEnter \n1 for Push \n2 for Pop \n3 for Peek \n4 for Display \n5 for Exit: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        printf("\nEnter data: ");
        scanf("%d", &data);
        push(data);
        break;
    case 2:
        pop();
        break;
    case 3:
        if(!is_empty())
            printf("\nTop element is %d", stack[top]);
        else
            printf("\nStack is_empty");
        break;
    case 4:
        display();
        break;
    case 5:
        return 0;
    default:
    printf("\nInvalid Choice");

    }
  }
    return 0;
}

int is_full()
{
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int val)
{
    if(is_full())
    {
        printf("\nStack Overflow");
        return;
    }

    top++;
    stack[top] = val;
    printf("\n%d is pushed successfully", stack[top]);
}

void pop()
{
    if(is_empty())
    {
        printf("\nStack Underflow");
        return;
    }

    printf("\n%d is popped successfully", stack[top]);
    top--;
}

void display()
{

    if(is_empty())
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nElement on the stack are: \n");
    for(i=0; i<=top; i++)
    {
       printf("\n%d", stack[i]);
    }
    }
}
