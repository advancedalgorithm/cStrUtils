#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum STRING_EDIT_TYPES
{
    NO_STRING = 0,
    NEW_STRING = 1,
    APPEND_TO_STRING = 2
};

typedef struct String
{
    char    *buffer;
} String;

String *cStrU__init(char *str)
{
    String *strU = (struct String *)malloc(sizeof(str)*strlen(str));
    if(strlen(str) < 1) return strU;

    strU->buffer = (char *)malloc(sizeof(str)*strlen(str));
    strcpy(strU->buffer, str);

    return strU;
}

void *cStrU__edit(const struct String *strU, const char *str, enum STRING_EDIT_TYPES *edit_type)
{
    enum STRING_EDIT_TYPES new_str = NEW_STRING;
    enum STRING_EDIT_TYPES append = APPEND_TO_STRING;

    if(edit_type == new_str)
        strcpy(strU->buffer, str);

    if(edit_type == append)
        strcat(strU->buffer, str);
}

int cStrU__Trim(const struct String *strU)
{
    if(strlen(strU->buffer) < 1) return 0;
    char *n = (char *)malloc(sizeof(strU->buffer)*strlen(strU->buffer));
    memset(n, '\0', sizeof(n));

    // Loop string to ignore whitespaces and add the remaining tokens
    char c[5];
    for(int i = 0; i <= strlen(strU->buffer); i++)
    {
        if(strU->buffer[i] != '\r' && strU->buffer[i] != '\n' && strU->buffer[i] != '\t')
        {
            memset(c, '\0', sizeof(c));
            sprintf(c, "%c", strU->buffer[i]);
            strcat(n, c);
        }
    }

    // Set new string
    memset(strU->buffer, '\0', sizeof(strU->buffer));
    strcpy(strU->buffer, n);

    // Cleaning up Chars
    free(n);
    memset(c, '\0', sizeof(c));

    return 1;
}

int cStrU__CountLines(const struct String *strU)
{
    if(strlen(strU->buffer) < 1) return 0;
    int lines = 0;
    for(int i = 0; i <= strlen(strU->buffer); i++)
    {
        if(strU->buffer[i] == '\n')
            lines++;
    }

    return lines;
}

int cStrU__replace_char(const struct String *strU, const char ch, char *replacement)
{
    if(strlen(strU->buffer) < 1) return 0;

    char c[5];
    char *n = (char *)malloc(sizeof(strU->buffer)*strlen(strU->buffer));
    memset(n, '\0', sizeof(n));

    for(int i = 0; i <= strlen(strU->buffer); i++)
    {
        if(strU->buffer[i] == ch) {
            strcat(n, &replacement);
        } else {
            memset(c, '\0', sizeof(c));
            sprintf(c, "%c", strU->buffer[i]);
            strcat(n, c);
        }
    }
    // Clear & Set New Buffer
    memset(strU->buffer, '\0', sizeof(strU->buffer));
    strcpy(strU->buffer, n);

    // Clean Chars
    memset(c, '\0', sizeof(c));
    memset(n, '\0', sizeof(n));
    free(n);

    return 1;
}

int cStrU__remove_char(const struct String *strU, const char ch)
{
    if(strlen(strU->buffer) < 1) return 0;

    char c[5];
    char *n = (char *)malloc(sizeof(strU->buffer)*strlen(strU->buffer));
    memset(n, '\0', sizeof(n));

    for(int i = 0; i <= strlen(strU->buffer); i++)
    {
        if(strU->buffer[i] != ch) {
            memset(c, '\0', sizeof(c));
            sprintf(c, "%c", strU->buffer[i]);
            strcat(n, c);
        }
    }
    // Clear & Set New Buffer
    memset(strU->buffer, '\0', sizeof(strU->buffer));
    strcpy(strU->buffer, n);

    // Clean Chars
    memset(c, '\0', sizeof(c));
    memset(n, '\0', sizeof(n));
    free(n);

    return 1;
}

char **cStrU__split_lines(const char *str)
{
    char *arr = (char *)malloc(sizeof(str)*strlen(str));
    memset(arr, '\0', sizeof(arr));

    char c[5];          memset(c, '\0', sizeof(c));
    char temp[1024];    memset(temp, '\0', sizeof(temp));

    int lines = 0;
    for(int i = 0; i <= strlen(str); i++)
    {

        if(str[i] == '\n' || str[i] == '\0')
        {
            arr[lines] = (char *)malloc(sizeof(temp)*strlen(temp));
            strcpy(arr, temp);
            memset(temp, '\0', sizeof(temp));
            lines++;
        }

        if(str[i] != '\n')
        {
            memset(c, '\0', sizeof(c)); sprintf(c, "%c", str[i]);
            strcat(temp, c);
        }
    }

    return arr;
}

char **cStrU__split_string_w_char(const struct String *strU, const char *ch)
{

    char **new = (char **)malloc(sizeof(strU->buffer)*strlen(strU->buffer));
    memset(new, '\0', sizeof(new));

    char c[5];          memset(c, '\0', sizeof(c));
    char temp[1024];    memset(temp, '\0', sizeof(temp));

    int lines = 0;
    for(int i = 0; i <= strlen(strU->buffer); i++)
    {

        if(strU->buffer[i] == ch || strU->buffer[i] == '\0')
        {
            new[lines] = (char *)malloc(sizeof(temp)*strlen(temp));
            strcpy(new[lines], temp);
            memset(temp, '\0', sizeof(temp));
            lines++;
        }

        if(strU->buffer[i] != ch)
        {
            memset(c, '\0', sizeof(c)); sprintf(c, "%c", strU->buffer[i]);
            strcat(temp, c);
        }
    }

    return new;
}