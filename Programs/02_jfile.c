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


// Other Modifiers
// Included here, for completeness, are more of the modifiers that standard C provides. For the beginning programmer, static and extern may be useful. volatile is more of interest to advanced programmers. register and auto are largely deprecated and are generally not of interest to either beginning or advanced programmers.
// static

// static is sometimes a useful keyword. It is a common misbelief that the only purpose is to make a variable stay in memory.

// When you declare a function or global variable as static, you cannot access the function or variable through the extern (see below) keyword from other files in your project. This is called static linkage.

// When you declare a local variable as static, it is created just like any other variable. However, when the variable goes out of scope (i.e. the block it was local to is finished) the variable stays in memory, retaining its value. The variable stays in memory until the program ends. While this behaviour resembles that of global variables, static variables still obey scope rules and therefore cannot be accessed outside of their scope. This is called static storage duration.

// Variables declared static are initialized to zero (or for pointers, NULL[3][4]) by default. They can be initialized explicitly on declaration to any constant value. The initialization is made just once, at compile time. 

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
    
// volatile

// volatile is a special type of modifier which informs the compiler that the value of the variable may be changed by external entities other than the program itself. This is necessary for certain programs compiled with optimizations – if a variable were not defined volatile then the compiler may assume that certain operations involving the variable are safe to optimize away when in fact they aren't. volatile is particularly relevant when working with embedded systems (where a program may not have complete control of a variable) and multi-threaded applications.
// auto

// auto is a modifier which specifies an "automatic" variable that is automatically created when in scope and destroyed when out of scope. If you think this sounds like pretty much what you've been doing all along when you declare a variable, you're right: all declared items within a block are implicitly "automatic". For this reason, the auto keyword is more like the answer to a trivia question than a useful modifier, and there are lots of very competent programmers that are unaware of its existence.

// Features of automatic variables :

    // 1. Keyword used        - auto
    // 2. Storage             - Memory
    // 3. Default value       - Garbage value (random value)
    // 4. Scope               - Local to the block in which it is defined
    // 5. Lifetime            - Value persists while the control remains within the block
    // 6. Keyword optionality - Optional

// register

// register is a hint to the compiler to attempt to optimize the storage of the given variable by storing it in a register of the computer's CPU when the program is run. Most optimizing compilers do this anyway, so use of this keyword is often unnecessary. In fact, ANSI C states that a compiler can ignore this keyword if it so desires – and many do. Microsoft Visual C++ is an example of an implementation that completely ignores the register keyword.

// Features of register variables :

    // 1. Keyword used        - register
    // 2. Storage             - CPU registers (values can be retrieved faster than from memory)
    // 3. Default value       - Garbage value
    // 4. Scope               - Local to the block in which it is defined
    // 5. Lifetime            - Value persists while the control remains within the block
    // 6. Keyword optionality - Mandatory to use the keyword