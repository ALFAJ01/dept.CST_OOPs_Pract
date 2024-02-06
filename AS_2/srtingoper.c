#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h> 


void strCompare(const char *str, const char *str2);
void stringConcat(const char *str, const char *str2);
void getstring();
int stringLength(const char *str);

void getstring() {
    char string[250], string2[250];
    printf("Please Enter the String 1: ");
    scanf("%s", string);
    printf("Please Enter the String 2: ");
    scanf("%s",string2);
    printf("The String 1 is: \" %s \" and and Lenght is : %d \n", string , stringLength(string));
    printf("The String 2 is:\" %s \" and and Lenght is : %d \n", string2 , stringLength(string2));
    printf("_______________Compare Strings ___________\n");
    strCompare(string, string2);
    printf("______________String Concatenation _____________\n");
    stringConcat(string, string2);
}

int stringLength(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return (ptr - str);
}

void strCompare(const char *str, const char *str2) {
    int strlen1, strlen2;
    strlen1 = stringLength(str);
    strlen2 = stringLength(str2);

    if (strlen1 > strlen2) {
        printf(" \"%s\" is longer than \" %s\" and these two are not Equal\n", str, str2);
    } 
    else if (strlen1 < strlen2) {
        printf("\"%s\" is shorter than \"%s\" and these two are not Equal\n", str, str2);
    } 
    else { 
        while (*str != '\0' && *str2 != '\0') {
            if (tolower(*str) == tolower(*str2)) {
                str++;
                str2++;
            }
            else {
                printf("Strings are of equal length but not equal in characters.\n");
                return;
            }
        }
        printf("Strings are of equal length and equal in characters ie Both are Same.\n");
    }
}

void stringConcat(const char *str, const char *str2) {
    int strlen1, strlen2;
    strlen1 = stringLength(str);
    strlen2 = stringLength(str2);

    char *result = (char *)malloc(strlen1 + strlen2 + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(result, str);
    strcat(result, str2);
    printf("The concatenation of string \" %s\" and string \"%s \"is: \"%s\"\n", str, str2, result);

    free(result); // Free the dynamically allocated memory
}

int main() {
    getstring();
    return 0;
}
