#include <stdio.h>
int isPresent(char *str, int startPos, int endPos, char ch)
{
	
	for(int i = startPos; i <= endPos; i++)
	{
		if(str[i] == ch)
			return i + 1;
	}
	return -1;
}

void main()
{
	char string[50], ch;
	int indices[50][2];
	int i, len, tempLen = 0, startPos = 0, endPos = -1, cutPos, k = 0;
	printf("Enter the string : ");
	scanf("%[^\n]", string);
	for(len = 0; string[len] != '\0'; len++);

	for(i = 0; i < len; i++)
	{
		ch = string[i];
		if((cutPos = isPresent(string, startPos, endPos, ch)) != -1)
		{
			indices[k][0] = startPos;
			indices[k++][1] = endPos;
			startPos = cutPos;
			endPos++;

		}
		else
		{
			endPos++;
		}
		
	}
	indices[k][0] = startPos;
		indices[k++][1] = endPos;
	indices[k][0] = 100;
	for(i = 0; indices[i][0] !=100; i++)
		printf("%d, %d\n",indices[i][0], indices[i][1]);

}