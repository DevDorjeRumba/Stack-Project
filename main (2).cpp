                                        //Making  Linear Queue Using C Programming
#include <stdio.h>
#define SIZE 5

void enqueue(int);
int dequeue();
void display();
int is_empty();
int is_full();

int queue[SIZE];
int rear = -1, front = -1;

int main()
{
    
    int choice, data, ret;
    
    while(1)
    {
    printf("\nEnter \n1 for Enqueue \n2 for Denqueue \n3 for Display \n4 for Exit: ");
    scanf("%d", &choice);
    
    
    switch(choice)
    {
    case 1:
        printf("\nEnter data: ");
        scanf("%d", &data);
        enqueue(data);
        break;
    case 2:
        ret = dequeue();
        if(ret !=0)
            printf("\n%d is enqueued successfully", ret);
        break;
    case 3:
    display();
        break;
    case 4:
        printf("\nExited from the system");
        return 0;
    default:
        printf("\nInvalid Input");
    }
        
    }
    
    return 0;
}

int is_empty()
{
    if(rear == -1 && front == -1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if(rear == SIZE-1)
       return 1;
    else
       return 0;
}

void enqueue(int val)
{
    if(is_full())
    {
        printf("\nQueue Overflow");
        return;
    }
    else if(is_empty())
    {
        rear++;
        front++;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
    printf("\n%d is enqueued successfully", queue[rear]);
}

int dequeue()
{
  if(is_empty())
  {
      printf("\nQueue Underflow");
      return 0;
  }
  else if(rear == front)
  {
     int f = queue[front];
      rear = -1;
      front = -1;
      return f;
  }
  else
  {
      return queue[front++];
  }
}

void display()
{
    int i;
    if(is_empty())
        printf("\nQueue is empty");
    else
    {
    printf("\nQueue Element are: ");
    for(i=front; i<=rear; i++)
    {
        printf("\n%d", queue[i]);
    }
    } 
}
