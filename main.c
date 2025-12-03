#include <stdio.h>
#include <string.h>

int main() {
    char text[256];
    char words[100][50];
    int count = 0;

    printf("Enter an sentence: ");
    scanf("%[^\n]", text);

    const int len = (int)strlen(text);
    char word[50];
    int pos = 0;

    for (int i = 0; i <= len; i++) {

        if (text[i] != ' ' && text[i] != ',' && text[i] != '.' &&
            text[i] != '!' && text[i] != '?' && text[i] != '\0') {
            word[pos] = text[i];
            pos++;
            }

        else if (pos > 0) {

            int found = 0;
            for (int j = 0; j < count; j++) {
                if (strcmp(words[j], word) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(words[count], word);
                count++;
            }

            pos = 0;
        }
    }

    printf("\nResult:\n");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }

    return 0;
}
