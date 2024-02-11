#include <stdio.h>
#include <string.h>

int findPattern(char text[], char pattern[]) {
    int c, d, e, text_length, pattern_length, position = -1;
    text_length = strlen(text);
    pattern_length = strlen(pattern);

    if (pattern_length > text_length) {
        return -1;
    }

    for (c = 0; c <= text_length - pattern_length; c++) {
        position = e = c;
        for (d = 0; d < pattern_length; d++) {
            if (pattern[d] == text[e]) {
                e++;
            } else {
                break;
            }
        }
        if (d == pattern_length) {
            return position;
        }
    }
    return -1;
}

void replacePattern(char str[], char pat[], char rep[]) {
    int position = findPattern(str, pat);
    while (position != -1) {
        memmove(&str[position + strlen(rep)], &str[position + strlen(pat)], strlen(str) - position - strlen(pat) + 1);
        memcpy(&str[position], rep, strlen(rep));
        position = findPattern(str, pat);
    }
}

int main() {
    char mainString[100], patternString[100], replaceString[100];

    printf("Enter the main string: ");
    gets(mainString);

    printf("Enter the pattern string: ");
    gets(patternString);

    printf("Enter the replace string: ");
    gets(replaceString);

    int position = findPattern(mainString, patternString);
    if (position != -1) {
        replacePattern(mainString, patternString, replaceString);
        printf("Modified string: %s\n", mainString);
    } else {
        printf("Pattern not found in the main string.\n");
    }

    return 0;
}
