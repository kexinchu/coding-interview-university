/**
 * 
 * Test part-BCD in Lab2 CSE-5305
 */

#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Test Part B: \n");

    _exit(0);

    print("\n\nTest Part C: \n");

    printint(10);
    printint(11);

    print("\n\nTest Part D: \n");

    const char *test_str = "HelloOS161";
    int len = 10;

    int result = reversestring(test_str, len);
    
    if (result == 1) {
        printf("Length is a multiple of 5\n");
    } else {
        printf("Length is not a multiple of 5\n");
    }
    
    return 0;
}
