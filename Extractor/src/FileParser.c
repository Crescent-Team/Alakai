#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../Utils/include/dynString.h"

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

void consume_for_single_line(FILE *stream, dynString *string)
{
    int lookup;
    while ((lookup = getc(stream)) != EOF && lookup != '\n')
    {
        append_char_to_dynString(string, lookup);
    }
}

void consume_for_mutli_line(FILE *stream, dynString *string)
{
    int lookup;
    while ((lookup = getc(stream)) != EOF && lookup != ']')
    {
        append_char_to_dynString(string, lookup);
    }
}
// FUTURE: Luau has support for --[=[]=] syntax, so we need to implement support for that
dynString *next_comment(FILE *stream)
{
    skip_until_next_starting(stream);

    dynString *string = new_dynString();

    int lookup = getc(stream);
    int next_lookup = getc(stream);

    if (next_lookup == EOF)
        return string;

    if (lookup == '[' && next_lookup == '[')
    {
        consume_for_mutli_line(stream, string);
        return string;
    }

    append_char_to_dynString(string, lookup);
    append_char_to_dynString(string, next_lookup);
    consume_for_single_line(stream, string);
    return string;
}