#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int start;  // Starting index of the substring
    int end;    // Ending index of the substring
} Substring;

int longestSubstringWithoutRepeatingChars(char *s, Substring **result) {
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }

    int charIndex[128]; // Assuming ASCII characters
    memset(charIndex, -1, sizeof(charIndex)); // Initialize charIndex with -1

    int maxLength = 0; // Store the length of the longest substring
    int start = 0;     // Starting index of the current substring

    int numResults = 0; // Number of substrings with maximum length
    *result = NULL;     // Initialize the result array to NULL

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];
        if (charIndex[currentChar] != -1 && charIndex[currentChar] >= start) {
            // If the character is seen again and is within the current substring
            start = charIndex[currentChar] + 1;
        }
        charIndex[currentChar] = end;
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            // If a longer substring is found, reset the result array
            maxLength = currentLength;
            numResults = 1;
            free(*result);
            *result = malloc(sizeof(Substring));
            (*result)[0].start = start;
            (*result)[0].end = end;
        } else if (currentLength == maxLength) {
            // If another substring of the same length is found, add it to the result array
            numResults++;
            *result = realloc(*result, numResults * sizeof(Substring));
            (*result)[numResults - 1].start = start;
            (*result)[numResults - 1].end = end;
        }
    }

    return maxLength;
}

int main() {
    char inputString[50];
    printf("Enter the string : ");
    scanf(" %[^\n]",inputString);
    Substring *result;
    int maxLength = longestSubstringWithoutRepeatingChars(inputString, &result);

    printf("Length of the longest substring without repeating characters: %d\n", maxLength);

    if (maxLength > 0) {
        printf("Longest substring(s) without repeating characters:\n");
        for (int i = 0; i < maxLength; i++) {
            printf("%.*s\n", result[i].end - result[i].start + 1, &inputString[result[i].start]);
        }
        free(result);
    }

    return 0;
}
