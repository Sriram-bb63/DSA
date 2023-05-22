#include <stdio.h>
#include <stdlib.h>


#define m 5
int st[m];
int top = -1;


void push(int x)
{
    if (top >= m - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top = top + 1;
        st[top] = x;
        printf("%d pushed\n", x);
    }
}


int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d popped\n", st[top]);
        top = top - 1;
        return st[top + 1];
    }   
}


int peek()
{
    if (top >= 0)
    {
        return st[top];
    }
    else
    {
        printf("Nothing here to peek\n");
    }
    
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    pop();
    pop();
    peek();
    pop();
    pop();
    pop();
    pop();
    return 0;
}