#ifndef STRINGLIB_H_INCLUDED
#define STRINGLIB_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define SPACE 2

int isValidCharacter(char* character);
int countCharacters(char* string);
void copyString(char* string, char* string2);
void normalizeString(char* string);
int countWords(char* string);

#endif // STRINGLIB_H_INCLUDED
