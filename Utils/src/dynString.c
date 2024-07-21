#include <stdlib.h>
#include "../include/AlakaiError.h"
#include "../include/dynString.h"

dynString *new_dynString()
{
    dynString *myStr = (dynString *)malloc(sizeof(dynString));

    if (myStr == NULL)
        exit_due_to_allocation_null;

    myStr->capacity = 10;
    myStr->charLen = 0;
    myStr->buff = (char *)malloc(10 * sizeof(char));

    if (myStr->buff == NULL)
        exit_due_to_allocation_null;
    return myStr;
}

void append_char_to_dynString(dynString *dest, char myChar)
{
    if ((dest->charLen + 1) > dest->capacity)
    {
        dest->capacity *= 2;
        char *newBuff = realloc(dest->buff, dest->capacity);
        if (newBuff == NULL)
            return exit_due_to_allocation_null();

        dest->buff = newBuff;
    }
    dest->buff[dest->charLen] = myChar;
    dest->buff[++dest->charLen] = '\0';
}