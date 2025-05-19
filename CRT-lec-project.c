#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char ch;

    // Create and write to the original file
    src = fopen("original.txt", "w");
    if (src == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }
    fprintf(src, "Hello, this is a sample file!\nThis is the second line.");
    fclose(src);

    // Open the original file for reading
    src = fopen("original.txt", "r");
    if (src == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    // Open the destination file for writing
    dest = fopen("copy.txt", "w");
    if (dest == NULL) {
        printf("Unable to create destination file.\n");
        fclose(src);
        return 1;
    }

    // Copy the contents
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully!\n");

    // Close both files
    fclose(src);
    fclose(dest);

    return 0;
}
