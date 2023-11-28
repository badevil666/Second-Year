#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

static struct node *rear = NULL;

void insertRear(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = rear;
	rear = temp;
}

int deleteHead()
{
	int temp = rear->data;
	struct node* ptr = rear;
	rear = rear->next;
	free(ptr);
	return temp;
}

int deleteFront()
{
	int temp;
	if(rear->next == NULL)
		return deleteHead();
	struct node *ptr  = rear;
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
	return temp;
}


void enqueue(int item)
{
	insertRear(item);
}
int dequeue()
{
	int item;
	item = deleteFront();
}
void display()
{
    struct node* temp = rear;
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
    return rear == NULL ? 1 : 0; 
}
void main()
{
	int choice, item;
        while(1)
        {
                printf("What would you like to do : \n1]Enqueue an element into the queue.\n2]Dequeue an element into the queue.\n3]Traverse through the Queue.\nEnter your choice : ");
                scanf("%d", &choice);
                printf("<<<<<-------------------------------------->>>>>\n\n\n");
                switch(choice)
                {
                        case 1 : printf("Enter the element you want to push into the queue : ");
                                 scanf("%d", &item);
                                 enqueue(item);
                                 break;
                        case 2 : if(!isEmpty())
                                    printf("%d\n", dequeue());
                                 else   
                                    printf("Queue Undeflow\n");
                                 break;
                                
                        case 3 : if(!isEmpty())
                                    display();
                                else
                                    printf("Queue Empty");
                                 break;
                        default : printf("Invalid choice.\n");
                }
                printf("\n\n\n<<<<<-------------------------------------->>>>>\n");

	}
}