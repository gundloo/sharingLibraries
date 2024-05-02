#include <stdio.h>
#include "../include/mohitilities.h"
#include "../include/lib.h"
int main() {
    printhw();
    int num  = 14;
    printf("Enter a number less than %d\n", num);
    dataValidation(num);
    return 0;
}
