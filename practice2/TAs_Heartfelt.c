#include <stdio.h>

int main() 
{
    /****************************************************/
    /*  float is stored as follows:                     */
    /*  float: |01000010|00000001|01000111|10101110|    */
    /*                                                  */
    /*  when we do p = (int*)&x,                        */
    /*  p is an int pointer                             */
    /*  that points to the previous float;              */
    /*  however, p is now an int pointer:               */
    /*  p ->   |01000010|00000001|01000111|10101110|    */
    /*                                                  */
    /*  1 (an int) in the memory looks like:            */
    /*  1:     |00000000|00000000|00000000|00000001|    */
    /*                                                  */
    /*  1 << i (bitwise) left shifts i bits             */
    /*  For examples,                                   */
    /*  1<<0:  |00000000|00000000|00000000|00000001|    */
    /*  1<<1:  |00000000|00000000|00000000|00000010|    */
    /*  1<<2:  |00000000|00000000|00000000|00000100|    */
    /*   ...      ...       ...      ...     ...        */
    /*  1<<31: |10000000|00000000|00000000|00000000|    */
    /*                                                  */
    /*  so (*p & 1 << i ) is true only if               */
    /*  the (i+1)-th bit of *p and 1<<i are both 1,     */
    /*                                                  */
    /*  For examples,                                   */
    /*  p ->   |01000010|00000001|01000111|10101110|    */
    /*  1<<2:  |10000000|00000000|00000000|00000100|    */
    /*  the 3nd bit of *p and 1<<2 are both 1,          */
    /*  and therefore (*p & 1 << 2 ) is true            */
    /****************************************************/

    float x;

    // we need an int* because only int* can perform bitwise operation
    int *p;

    while (scanf("%f", &x) != EOF) {
        p = (int*)&x;
        // p points to the memory location of x
        for (int i = 31; i >= 0; i--) {
            if (*p & 1 << i)
                putchar('1');
            else
                putchar('0');
        }
        putchar('\n');
    }

    return 0;
}
