
/*
 * Author      : Mayuri Yamagarne
 * Project Name: Lexical Analyzer
 * Description : Reads source code and identifies keywords,
 *               identifiers, constants, operators, symbols,
 *               and unknown characters.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of predefined C keywords
char keywords[][10] =
{
    "int", "float", "if", "else", "while",
    "return", "char", "for", "void"
};

// Function to check whether a word is a keyword
int isKeyword(char *word)
{
    // Compare the given word with each keyword
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;   // Word is a keyword
    }

    return 0;   // Word is not a keyword
}

int main()
{
    char input[200], token[50];
    int i = 0, j = 0;

    // Read a line of source code from the user
    printf("Enter source code:\n");
    fgets(input, sizeof(input), stdin);

    // Process the input character by character
    while (input[i] != '\0')
    {
        // Ignore whitespace characters
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        // Identify keywords and identifiers
        if (isalpha(input[i]))
        {
            j = 0;

            // Collect letters and digits into a token
            while (isalnum(input[i]))
            {
                token[j++] = input[i++];
            }

            // Add the null character to end the string
            token[j] = '\0';

            // Check whether the token is a keyword
            if (isKeyword(token))
                printf("%s → Keyword\n", token);
            else
                printf("%s → Identifier\n", token);
        }

        // Identify integer constants
        else if (isdigit(input[i]))
        {
            j = 0;

            // Collect consecutive digits
            while (isdigit(input[i]))
            {
                token[j++] = input[i++];
            }

            // Terminate the token string
            token[j] = '\0';

            // Display the constant
            printf("%s → Constant\n", token);
        }

        // Identify arithmetic and assignment operators
        else if (strchr("+-*/=%", input[i]))
        {
            printf("%c → Operator\n", input[i]);
            i++;
        }

        // Identify symbols such as semicolons and brackets
        else if (strchr(";{}()", input[i]))
        {
            printf("%c → Symbol\n", input[i]);
            i++;
        }

        // Classify any unrecognized character
        else
        {
            printf("%c → Unknown\n", input[i]);
            i++;
        }
    }

    return 0;   // Indicate successful program execution
}
