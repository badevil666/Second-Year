#include <stdio.h>
#define MAX_SIZE 100
static int stack[MAX_SIZE], top = -1;
void push(int item)
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
int pop()
{
	int item;
	if(top == -1)
	{
		printf("Stack Underflow. The stack is currently empty.\n");
		return -1;	
}
	else
	{
		item = stack[top--];
		return item;
	}
}
void display()
{
	if(top == -1)
	{
		printf("The stack is empty.\n");
		return;
	}
	int i;
	for(i = 0; i <= top - 1; i++)
		printf("%d->", stack[i]);
	printf("%d\n", stack[i]);
}
void main()
{
	int choice, item;
	while(1)
	{
		printf("What would you like to do : \n1]Push an element into the stack.\n2]Pop an element from the stack.\n3]Traverse through the stack.\nEnter your choice : ");
		scanf("%d", &choice);
		printf("<<<<<-------------------------------------->>>>>\n\n\n");
		switch(choice)
		{
			case 1 : printf("Enter the element you want to push into the stack : ");
				 scanf("%d", &item);
				 push(item);
				 break;
			case 2 : printf("%d\n", pop());
				 break;
			case 3 : display();
				 break;
			default : printf("Invalid choice.\n");
		}
		printf("\n\n\n<<<<<-------------------------------------->>>>>\n");

	}
}
