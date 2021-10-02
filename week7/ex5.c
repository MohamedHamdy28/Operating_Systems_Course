#include <stdio.h>

int main()
{
    char foo[] = "Hello World";
    char *ss = foo;
    char **s = &ss;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %c\n", **s);
    return 0;
}
