#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[4096];
    size_t len1, len2, pos, nread;
    const char *str1, *str2;

    if (argc < 2) {
        fprintf(stderr, "usage: %s STRING [REPLACEMENT]\n", argv[0]);
        return 1;
    }

    str1 = argv[1];  // string to search and replace
    len1 = strlen(str1);
    str2 = "";       // default replacement is empty
    len2 = 0;
    if (len1 >= sizeof(buffer)) {
        fprintf(stderr, "%s: STRING too long\n", argv[0]);
        return 1;
    }
    if (len1 == 0) {      // special case empty string
        len1 = len2 = 1;  // replace 0 byte with itself
    } else
    if (argc > 2) {
        str2 = argv[2];
        len2 = strlen(str2);
    }

    pos = 0;
    while ((nread = fread(buffer + pos, 1, sizeof(buffer) - pos, stdin)) != 0) {
        size_t start = 0, i = 0, end = pos + nread;
        while (i + len1 <= end) {
            if (buffer[i] == *str1 && !memcmp(buffer + i, str1, len1)) {
                fwrite(buffer + start, 1, i - start, stdout);
                fwrite(str2, 1, len2, stdout);
                start = i += len1;
            } else {
                i++;
            }
        }
        fwrite(buffer + start, 1, i - start, stdout);
        memmove(buffer, buffer + i, end - i);
        pos = end - i;
    }
    fwrite(buffer, 1, pos, stdout);
    return 0;
}
