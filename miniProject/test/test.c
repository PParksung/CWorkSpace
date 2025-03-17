#include <stdio.h>
#include <string.h>

int main() {
    char str[11];
    strcpy(str, "");
    sprintf(str, "%s%c", str, 'a');
    sprintf(str, "%s%c", str, 'b');
    sprintf(str, "%s%c", str, 'c');

    printf("%s", str);

    strcpy(str, "");
    sprintf(str, "%s%c", str, 'd');
    sprintf(str, "%s%c", str, 'e');
    sprintf(str, "%s%c", str, 'f');

    printf("%s", str);

    return 0;
}