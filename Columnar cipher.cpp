#include <stdio.h>
#include <string.h>
void removeSpaces(char *str) 
{
    int count = 0;
    for (int i = 0; str[i]; i++)
	 {
        if (str[i] != ' ') 
		{
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}
void columnarEncrypt(char *plaintext, char *key) 
{
    int keyLength = strlen(key);
    int plaintextLength = strlen(plaintext);
    int numRows = (plaintextLength + keyLength - 1) / keyLength;
    char matrix[numRows][keyLength];
    int index = 0;
    for (int i = 0; i < numRows; i++) 
	{
        for (int j = 0; j < keyLength; j++) 
		{
            if (index < plaintextLength) 
			{
                matrix[i][j] = plaintext[index++];
            } else 
			{
                matrix[i][j] = 'X';  
            }
        }
    }
    for (int i = 0; i < keyLength; i++) 
	{
        int col = key[i] - '0' - 1;
        for (int j = 0; j < numRows; j++) 
		{
            printf("%c", matrix[j][col]);
        }
    }
    printf("\n");
}
int main() 
{
    char plaintext[1000];
    char key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key (permutation of numbers): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    removeSpaces(plaintext);
    printf("Encrypted message: ");
    columnarEncrypt(plaintext, key);
    return 0;
}
