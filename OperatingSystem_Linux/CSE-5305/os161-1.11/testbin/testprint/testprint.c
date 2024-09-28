/**
 *
 * Test part-BCD in Lab2 CSE-5305
 */

#include <unistd.h>
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        print("\n\nTest Part C: \t, origin input is %d\n", i);

        printint(i);
    }

    return 0;
}
