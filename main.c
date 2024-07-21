#include "Extractor/include/FileParser.h"
#include "Utils/include/dynString.h"
#include "Utils/include/AlakaiError.h"
#include <stdio.h>
int main() {

    FILE *stream = fopen("test.luau", "r");
    printf("content-> %s\n", next_comment(stream)->buff);
    printf("content-> %s\n", next_comment(stream)->buff);

    exit_due_to_allocation_null();
    return 0;
}