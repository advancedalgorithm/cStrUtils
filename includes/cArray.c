#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Array
{
    char **buffer;
} Array;

struct Array **cArray__split_lines(const char *str)
{
    struct Array *arr = (struct Array *)malloc(sizeof(str)*strlen(str));
    arr->buffer = (char **)malloc(sizeof(str)*strlen(str));
    memset(arr->buffer, '\0', sizeof(arr->buffer));

    char c[5];          memset(c, '\0', sizeof(c));
    char temp[1024];    memset(temp, '\0', sizeof(temp));

    int lines = 0;
    for(int i = 0; i <= strlen(str); i++)
    {

        if(str[i] == '\n' || str[i] == '\0')
        {
            arr->buffer[lines] = (char *)malloc(sizeof(temp)*strlen(temp));
            strcpy(arr->buffer[lines], temp);
            memset(temp, '\0', sizeof(temp));
            lines++;
        }

        if(str[i] != '\n')
        {
            memset(c, '\0', sizeof(c)); sprintf(c, "%c", str[i]);
            strcat(temp, c);
        }
    }

    return arr->buffer;
}