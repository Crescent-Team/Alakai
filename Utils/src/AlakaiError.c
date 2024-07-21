#include <stdlib.h>
#include <stdio.h>

void exit_due_to_allocation_null(){
    printf("[Alakai]: Insufficient memory available. Contact the developer if this issue persists.");
    exit(-1);
}