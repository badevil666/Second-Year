#include <stdio.h>
#define MAX_SIZE 100

static int queue[MAX_SIZE], rear = -1, front = -1;
void enqueue(int item)
{
	++rear;
	if((rear + 1)%MAX_SIZE == front)
	{
		printf("Queue Overflow. The Queue is currently full.\n");
	}
	else
	{
		if(rear == 0)
			front = 0;
		queue[rear] = item;
	}
}
int dequeue()
{
	int item;
	if(front == -1)
	{
		printf("Queue Underflow. The queue is currently empty.\n");
		return -1;
	}
	else
	{
		item = queue[front++];
		if(front == ((rear + 1)%MAX_SIZE))
			rear = front = -1;
		return item;
	}
}
void display()
{
	int i;
	if(front == -1)
	{
		printf("The queue is currently empty.\n");
		return;	
	}
	for(i = front; i <= rear - 1; i++)
	{
		printf("%d<-",queue[i]);
	}
	printf("%d\n",queue[i]);

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
                        case 2 : printf("%d\n", dequeue());
                                 break;
                        case 3 : display();
                                 break;
                        default : printf("Invalid choice.\n");
                }
                printf("\n\n\n<<<<<-------------------------------------->>>>>\n");

	}
}
