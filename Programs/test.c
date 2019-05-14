#include <stdio.h>

int main(void)
{   int num = 2;
    printf ("%d\n", num);
    // printf("sizeof(num)");
    printf ("The size of num is %u\n", sizeof(num));
    
    
    char str[] = "This is a string array";
    int size = sizeof(str);
    printf ("The size of the str[] is %d", size);
    return 0;
}