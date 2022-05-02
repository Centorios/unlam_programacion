#include "stringlib.h"

int isValidCharacter(char *character)
{
    if ((*character >= 65 && *character <= 90) || (*character >= 97 && *character <= 122))
    {
        return VERDADERO;
    }

    if (*character == 32)
    {
        return SPACE;
    }
    return FALSO;
}

int countCharacters(char *string)
{
    int counter = 0;
    while (*string != '\0')
    {
        counter++;
        string++;
    }
    return counter;
}

void copyString(char *string, char *string2)
{
    while (*string2 != '\0')
    {
        *string = *string2;
        string++;
        string2++;
    }
    *string = '\0';
}

void normalizeString(char *string)
{
    char *inicioCadena = string;

    int counter = countCharacters(string);

    char outString[counter];
    char *outStringStart = outString;
    char *outStringPinter = outString;

    while (*string != '\0')
    {
        if (isValidCharacter(string) == 1) // 1 = verdadero
        {
            *outStringPinter = *string;
            outStringPinter++;
        }

        if (isValidCharacter(string) == 2) // 2 = espacio
        {
            if (*(outStringPinter - 1) != ' ')
            {
                *outStringPinter = ' ';
                outStringPinter++;
            }
        }

        if (isValidCharacter(string) == 0) // 0 = falso
        {
            if (*(outStringPinter - 1) != ' ')
            {
                *outStringPinter = ' ';
                outStringPinter++;
            }
            string++;
        }
        string++;
    }

    if (*(outStringPinter - 1) == ' ')
    {
        *(outStringPinter - 1) = '\0';
    }
    else
    {
        *outStringPinter = '\0';
    }
    // si el ultimo caracter es un espacio, lo piso con fin de linea

    copyString(inicioCadena, outStringStart);
}

int countWords(char *string)
{
    int counter = 0;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            counter++;
        }
        string++;
    }
    counter++;
    return counter;
}