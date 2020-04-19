#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char ** splitString(char* string){
    char stringCpy[34];
    strcpy(stringCpy, string);
    char **value = malloc(sizeof(char*));
    value[0] = malloc(sizeof(char) * 16);
    value[1] = malloc(sizeof(char) * 16);
    char *delim = "\n";
    char *token = strtok(stringCpy, delim);

    int i = 0;
    while(token != NULL && i < 2){
        strncpy(value[i++], token, 16);
        token = strtok(NULL, delim);
    }
    return value;
}    

int main(int argc, char const *argv[])
{
    // char m[] = "hello";
    char *options[3] = {"Selfdriving", "Bluetooth", "Test"};
    printf("%ld\n", sizeof(options) / sizeof(options[0]));
    // char** v = splitString("hello");
    // printf("%s\n %s\n", v[0], v[1]);
    // char m1[] = "HELLO\n";
    // char** v1 = splitString("HELLO\n");
    // printf("%s\n %s\n", v1[0], v1[1]);
    // char m2[] = "Hello\nWorld";
    // char** v2 = splitString("Hello\nWorld");
    // printf("%s\n %s\n", v2[0], v2[1]);
    return 0;
}
