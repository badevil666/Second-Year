#include <stdio.h>
int strLength(char *str)
{
	int len;
	for(len = 0; str[len] != '\0'; len++);
	return len;
}
int isPresent(char ch, char *str, int size, int *pos)
{
	int i;
	for(i = 0; i < size; i++)
		if(str[i] == ch)
		{
			*pos = i;
			return 1;
		}
	*pos = -1;
	return 0;
}
void strCut(char *str, int len, int cutPos)
{
	if(cutPos == -1)
		return;
	int i;
	for(i = cutPos + 1; i < len; i++)
		str[i - cutPos - 1] = str[i];
	str[i - cutPos - 1] = '\0';
}
void strCopy(char *str1, char *str2, int size1, int size2)
{
	int i;
	for(i = 0; i < size2; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
}
void main()
{
	char string[100], longestSubString[50], presentSubString[50], ch;
	int stringLen, longestSubStringLen, presentSubStringLen, i, j, cutPos;
	printf("Enter the string : ");
	scanf(" %[^\n]", string);
	stringLen = strLength(string);
	longestSubString[0] = '\0', presentSubString[0] = '\0'; longestSubStringLen = 0, presentSubStringLen = 0;
	for(i = 0; i < stringLen; i++)
	{
		ch = string[i];
		if(isPresent(ch, presentSubString, presentSubStringLen, &cutPos))
		{
			if(presentSubStringLen > longestSubStringLen)
			{
				strCopy(longestSubString, presentSubString, longestSubStringLen, presentSubStringLen);
				longestSubStringLen = presentSubStringLen;
				strCut(presentSubString, presentSubStringLen, cutPos);
				presentSubStringLen = presentSubStringLen - cutPos;
				presentSubString[presentSubStringLen - 1] = ch;
				presentSubString[presentSubStringLen] = '\0';
			}
			else if(presentSubStringLen == longestSubStringLen)
			{
				printf("%s\n",longestSubString);
				strCopy(longestSubString, presentSubString, longestSubStringLen, presentSubStringLen);
				strCut(presentSubString, presentSubStringLen, cutPos);
				presentSubStringLen = presentSubStringLen - cutPos;
                                presentSubString[presentSubStringLen - 1] = ch;
                                presentSubString[presentSubStringLen] = '\0';
			}
			else
			{
				strCut(presentSubString, presentSubStringLen, cutPos);
				presentSubStringLen = presentSubStringLen - cutPos;
                                presentSubString[presentSubStringLen - 1] = ch;
                                presentSubString[presentSubStringLen] = '\0';
			}
		}
		else
		{
			presentSubString[presentSubStringLen++] = ch;
			presentSubString[presentSubStringLen] = '\0';
		}
	}
 	if(presentSubStringLen >= longestSubStringLen)
	{
		printf("%s\n", longestSubString);
		strCopy(longestSubString, presentSubString, longestSubStringLen, presentSubStringLen);
	}
	printf("%s", longestSubString);
}

