#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");  // Creates or overwrites the file
    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeToFile(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "w");  // Overwrites existing content
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fputs(data, fp);
    printf("Data written to '%s' successfully.\n", filename);
    fclose(fp);
}

void appendToFile(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "a");  // Appends to the file
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    fputs(data, fp);
    printf("Data appended to '%s' successfully.\n", filename);
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");  // Opens the file for reading
    if (fp == NULL) {
        printf("Error: File '%s' does not exist or cannot be opened.\n", filename);
        return;
    }

    char ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

int main() {
    const char *filename = "example.txt";

    // Create file
    createFile(filename);

    // Write data
    writeToFile(filename, "Hello, this is the first line.\n");

    // Append data
    appendToFile(filename, "This line is appended.\n");

    // Read file
    readFile(filename);

    return 0;
}

