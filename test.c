#include <stdio.h>

int main()
{
    unsigned int z = 0x76543210;
    char *b = (char*) &z;

    for(int i = 0; i < sizeof(unsigned int); i++)
    {
        printf("%#x ", b[i]);
    }
    if(*b == 0x10)
        puts ("is little endian");
    else
        puts("is big endian");

    return 0;
}