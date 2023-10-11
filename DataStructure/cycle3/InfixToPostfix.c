#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE], top = -1;
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

int inStackPriority(char ch)
{
	switch(ch)
	{
		case '+' : 
		case '-' : return 2; break;
		case '/' : 
		case '*' : return 4; break;
		case '(' : return 0; break;	
	}
}
int incomingPriority(char ch)
{
	switch(ch)
	{
		case '+' : 
		case '-' : return 1; break;
		case '/' : 
		case '*' : return 3; break;
		case '(' : return 7; break;
	}
}
int strLen(char *str)
{
	int len;
	for(len = 0; str[len] != '\0'; len++);
	return len;
}

char* infixToPostfix(char *expression, char *evaluatedExpression)
{
	int size = strLen(expression), i, index = 0;
	expression[size] = ')';
	expression[size + 1] = '\0'; 
	char term, top;
	push('(');
	for(i = 0; expression[i] != '\0'; i++)
	{
		term = expression[i];
		top = pop();
		//printf("top = %c term = %c\n", top, term);
		if(term >= '0' && term <= '9')	
		{
			//printf("top = %c term = %c\n", top, term);
			printf("%c ", term);
			evaluatedExpression[index++] = term;
			push(top);
			continue;
		}
		else if(term == ')')
		{
			while(top != '(')
			{
				printf("%c ", top);
				evaluatedExpression[index++] = top;
				top = pop();
			}
		}
		else if(incomingPriority(term) > inStackPriority(top))
		{
			//printf("top = %c term = %c\n", top, term);
			push(top);
			push(term);
		}
		else if(incomingPriority(term) < inStackPriority(top))
		{	
			//printf("top = %c term = %c\n", top, term);
			printf("%c ", top);
			evaluatedExpression[index++] = top;
			push(term);
		}	
	}
	printf("\n");
	evaluatedExpression[index] = '\0';
	printf("%s\n", evaluatedExpression);
	return evaluatedExpression;
}
int evaluate(char *postfix)
{
	int size = strLen(postfix), i, toppest, secondTop;
	char term;
	for(i = 0; i < size; i++)
	{
		term = postfix[i];
		if(term >= '0' && term <= '9')
		{
			push(term - '0');
		}
		else
		{
			toppest = pop();
		    secondTop = pop();
			switch(term)
			{
				case '+' : push(secondTop + toppest);
						   break;
				case '-' : push(secondTop - toppest);
						   break;
				case '/' : push(secondTop / toppest);
						   break;
				case '*' : push(secondTop * toppest);
						   break;
			}
		}
	}
	return pop();
	

}

int main()
{
	char expression[50], postfix[50];
	printf("Enter the expression to be evaluated : ");
	scanf(" %[^\n]", expression);
	infixToPostfix(expression, postfix);
	printf("\n%d\n", evaluate(postfix));
	return 0;
}













