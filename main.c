#include "Extractor/include/FileParser.h"
#include "Utils/include/dynString.h"
#include <stdio.h>
int main() {

    FILE *stream = fopen("test.luau", "r");
    printf("content-> %s\n", next_comment(stream));
    printf("content-> %s\n", next_comment(stream));
        printf("content-> %s\n", next_comment(stream));


    dynString *string = new_dynString();

     for (int i = 0; i < 100; i++) {
        append_char_to_dynString(string, 'h');
    }

    printf("%s %i\n", string->buff, string->charLen);
    return 0;
}