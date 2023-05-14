#include <stdio.h>

void custom_puts(char *str);

int main(void)
{
    custom_puts("\"Programming is like building a multilingual puzzle");
    return 0;
}

void custom_puts(char *str)
{
    printf("%s\n", str);
}
