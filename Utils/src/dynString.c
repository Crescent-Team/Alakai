#include <stdlib.h>

typedef enum ReturnCodes {
    ALLOCATION_ERROR,
    PASS,
} ReturnCodes;

typedef struct dynString {
    char *buff;
    int charLen; // number of stored characters
    float capacity; // number of slots available for characters
} dynString;

dynString *new_dynString(){
    dynString *myStr = (dynString*) malloc(sizeof(dynString));

    if(myStr == NULL)
        return NULL;

    myStr->capacity = 10;
    myStr->charLen = 0;
    myStr->buff = (char*) malloc(10 * sizeof(char));

    if(myStr->buff == NULL)
        return NULL;
    return myStr;
}

ReturnCodes append_char_to_dynString(dynString *dest, char myChar){
    if((dest->charLen + 1) > dest->capacity){
        dest->capacity *= 2;
        char *newBuff = realloc(dest->buff, dest->capacity);
        if(newBuff == NULL){
            return ALLOCATION_ERROR;
        }
        dest->buff = newBuff;
    }
    dest->buff[dest->charLen] = myChar;
    dest->buff[++dest->charLen] = '\0';
    return PASS;
}