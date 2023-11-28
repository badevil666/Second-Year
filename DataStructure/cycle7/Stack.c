#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *top = NULL;

void insertHead(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = top;
	top = temp;
}

int deleteHead()
{
	int temp = top->data;
	struct node* ptr = top;
	top = top->next;
	free(ptr);
	return temp;
}

void push(int item)
{
	insertHead(item);
}	
int  pop()
{
	return deleteHead();
}


void display()
{
	struct node* temp = top;
	while(temp != NULL)
	{
		if(temp->next == NULL)
		{
			printf("%d\n", temp->data);
			break;
		}
		printf("%d->", temp->data);
		temp = temp->next;
	}
}



int isEmpty()
{
	return top == NULL ? 1 : 0;
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
			case 2 : if(!isEmpty())
				 	printf("%d\n", pop());
				else
					printf("Stack UnderFlow.");
				break;
			case 3 : if(!isEmpty())
					display();
				else
					printf("Stack Empty.");
				 break;
			default : printf("Invalid choice.\n");
		}
		printf("\n\n\n<<<<<-------------------------------------->>>>>\n");

	}
}
