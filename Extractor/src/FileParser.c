#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../Utils/include/dynString.h"

/*
    A function to reach at the new starting of a Luau comment, which is `--`

    NOTE: This works when I think it shouldn't work.
*/
void skip_until_next_starting(FILE *stream)
{
    int lookup;
    while ((lookup = getc(stream)) != EOF)
    {
        if (lookup != '-')
            continue;

        if (getc(stream) == '-')
            break;
    }
}

ReturnCodes consume_for_single_line(FILE *stream, dynString *string)
{
    int lookup;
    while ((lookup = getc(stream)) != EOF && lookup != '\n')
    {
        ReturnCodes status = append_char_to_dynString(string, lookup);

        if(status != PASS)
            return status;
    }
}

char *next_comment(FILE *stream)
{
    skip_until_next_starting(stream);

    dynString *string = new_dynString();

    if (getc(stream) == '[' && getc(stream) == '[')
    { // Comment is multi
        char *buff = (char *)malloc(100000 * sizeof(char));
        int index = 0;

        char ch = getc(stream);
        while (ch != ']')
        {
            buff[index] = ch;
            index++;
            ch = getc(stream);
        }
        getc(stream);
        buff[index] = '\0';
        return buff;
    }
    else
    {
        consume_for_single_line(stream, string);

        return string->buff;
    }
}