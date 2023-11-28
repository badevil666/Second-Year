#include <stdio.h>
#include <stdlib.h>
static int count = 0;
struct node 
{
	int data;
	struct node *next;
};

static struct node *head = NULL, *tail = NULL;

void insertHead(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head;
	head = temp;
	count++;
}

void insertTail(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *ptr  = head;
	struct node *temp1 = ptr;
	while(ptr != NULL)
	{
		if(ptr->next == NULL)
			temp1 = ptr;
		ptr = ptr->next;
	}
	temp1->next = temp;
	count++;
}

void insertArbitary(int data, int pos)
{
	int tempCount = 2;
	struct node *ptr;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	ptr = head;
	while(ptr != NULL && tempCount < pos)
	{
		ptr = ptr->next;
		tempCount++;
	}
	temp->next = ptr->next;
	ptr->next = temp;
	count++;
}

int deleteHead()
{
	int temp = head->data;
	struct node* ptr = head;
	head = head->next;
	free(ptr);
	count--;
	return temp;
}

int deleteTail()
{
	int temp;
	if(head->next == NULL)
		return deleteHead();
	struct node *ptr  = head;
        struct node *prevPtr = ptr;
        while(ptr != NULL)
        {
                if(ptr->next == NULL)
		{
			break;
		}
		else
		{
			prevPtr = ptr;
			ptr = ptr->next;
		}
	}
	ptr = prevPtr->next;
	temp = ptr->data;
	prevPtr->next = NULL;
	free(ptr);
	count--;
	return temp;
}

int deleteArbitary(int pos)
{
	int tempCount = 2;
	int data;
	struct node* ptr = head;
	struct node* temp;
	while(ptr != NULL && tempCount < pos)
	{
		ptr = ptr->next;
		tempCount++;
	}
	temp = ptr->next;
	data = temp->data;
	ptr->next = temp->next;
	free(temp); 
	count--;
	return data;
}

int isEmpty()
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
	struct node* temp = head;
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

int main()
{
	int choice, data, pos;
	while(1)
	{
		printf("What would you like to do \n");
		printf("1]Insert an element at the head of the list.\n");
		printf("2]Insert an element at the tail of the list.\n");
		printf("3]Insert an element at a specified position.\n");
		printf("4]Delete an element from the head of the list.\n");
		printf("5]Delete an element from the tail of the list.\n");
		printf("6]Delete an element from a specified position.\n");
		printf("7]Display the contents of the list\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : printf("Enter the data you would like to insert : ");
				 scanf("%d", &data);
				 insertHead(data);
				 break;

			case 2 : printf("Enter the data you would like to insert : ");
                                 scanf("%d", &data);
                                 insertTail(data);
                                 break;

			case 3 : printf("Enter the data you would like to insert : ");
                                 scanf("%d", &data);
				 printf("Enter the position (1 - %d) ", count + 1);
				 scanf("%d", &pos);
				 if(pos == 1)
					insertHead(data);
				 else if(pos == count + 1)		
					insertTail(data);
				 else
                                 	insertArbitary(data, pos);
                                 break;
 
			case 4 : if(!isEmpty())
                                 {
                                        printf("%d\n", deleteHead());
                                 }
                                 else
                                 {
                                        printf("The list is empty\n");
                                 }
				 break;

			case 5 : if(!isEmpty())
				 {
					printf("%d\n", deleteTail());
				 }
				 else
				 {
					printf("The list is empty\n");
				 }
				 break;

			case 6 : if(!isEmpty())
				 {
					printf("Enter the position (1 - %d)", count);
					scanf("%d", &pos);
					if(pos == 1)
						printf("%d\n", deleteHead());
					else if(pos == count)
						printf("%d\n", deleteTail());
					else 
						printf("%d\n", deleteArbitary(pos));
				 }
				 else
				 {
					printf("The list is empty.\n");
			       	 }
				 break;

			case 7 : if(!isEmpty())
				 {
					display();
				 }
				 else
				 {
					printf("The list is empty.\n");
				 }
				 break;
			default : printf("\nInvalid choice\n");
				 break;
		}
	}
}
