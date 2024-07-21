#ifndef DYNSTRING_INCLUDED_BEFORE
#define DYNSTRING_INCLUDED_BEFORE

typedef struct dynString {
    char *buff;
    int charLen; // number of stored characters
    float capacity; // number of slots available for characters
} dynString;

dynString *new_dynString();

void append_char_to_dynString(dynString *dest, char myChar);

#endif