#include "alloInfo.h"


int main() {
    
    void *memory = malloc(4096); 
    if (memory == NULL) {
        perror("malloc failed");
        return 1;
    }

    
    address_info(memory);

    
    free(memory);

    return 0;
}