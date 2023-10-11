#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE], top = -1;
void push(char item)
{
	++top;
        if(top == MAX_SIZE)
	{
		printf("Stack overflow. The stack is currently full.\n");
	}
	else
	{
		stack[top] = item;
	}
}
char pop()
{
	if(top == -1)
	{
		printf("Stack Underflow. The stack is currently empty.\n");
		return -1;	
}
	else
	{
		return stack[top--];
    }	
}
