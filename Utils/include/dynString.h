typedef struct dynString {
    char *buff;
    int charLen; // number of stored characters
    float capacity; // number of slots available for characters
} dynString;

typedef enum ReturnCodes {
    ALLOCATION_ERROR,
    PASS,
} ReturnCodes;

dynString *new_dynString();

int append_char_to_dynString(dynString *dest, char myChar);