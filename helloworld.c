#include <stdio.h>

int main(void)
{
    int x = scanf("what is x?");
    int y = scanf("what is y?");

    if (x < y)
    {
        printf("x is less than y\n");
    }
}