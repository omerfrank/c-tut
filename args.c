#include <stdio.h>

int main(int argc, char **argv)
{
    printf("argc=%d\n", argc);
    for (char **sp = argv; *sp; sp++) {
        printf("argv %ld = '%s\n", sp - argv, *sp);
    }
    return 0;
}

