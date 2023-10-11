#include <stdio.h>
int findMaxSubStringLength(char *str)
{
	int len, i, present[256], startPos = 0, endPos = -1, maxLength = 0;
 	char ch;
	for(i = 0; i < 256; i++)
		present[i] = -1;
	for(len  = 0; str[len] != '\0'; len++);
	for(endPos = 0; endPos < len; endPos++)
	{
		ch = str[endPos];
		if(present[ch] >= startPos)
		{
			startPos = present[ch] + 1;
		}
		present[ch] = endPos;
		int currentLength = endPos - startPos + 1;
		currentLength > maxLength ? maxLength = currentLength : 1;
		
	}
	return maxLength;


}
void main()
{
	char string[100];
	int stringLen;
	printf("Enter the string : ");
	scanf(" %[^\n]", string);
	printf("Max length = %d ",findMaxSubStringLength(string) );
	
}
