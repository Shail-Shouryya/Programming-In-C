#include <stdio.h>

static int j = 0;

void up (void)
{
    /* k is set to 0 when the program starts.
     * The line is then "ignored" for the rest of the program
     * i.e. k is not set to 0 every time up() is called    
     */
     static int k = 0;
     j++;
     k++;
     printf("up() called. k =%2d, j =%2d\n", k, j);
}

void down (void)
{
    static int k = 0;
    j--;
    k--;
    printf ("down() called. k =%2d, j =%2d\n", k, j);
}

int main (void)
{
    int i;
    
    /* call the up function 3 times, then the down function 2 times
     */
    for (i=0; i<3; i++)
        up();
    for (i=0; i<2; i++)
        down();
    
    return 0;
}



// Features of static variables :
    // 1. Keyword used        - static
    // 2. Storage             - Memory
    // 3. Default value       - Zero
    // 4. Scope               - Local to the block in which it is declared
    // 5. Lifetime            - Value persists between different function calls
    // 6. Keyword optionality - Mandatory to use the keyword

// extern
// extern is used when a file needs to access a variable in another file that it may not have #included directly. Therefore, extern does not actually carve out space for a new variable, it just provides the compiler with sufficient information to access the remote variable.

// Features of extern variable :
    // 1. Keyword used        - extern
    // 2. Storage             - Memory
    // 3. Default value       - Zero
    // 4. Scope               - Global (all over the program)
    // 5. Lifetime            - Value persists till the program's execution comes to an end
    // 6. Keyword optionality - Optional if declared outside all the functions
