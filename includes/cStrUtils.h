#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cStrUtils.c"
#include "cArray.c"

enum STRING_EDIT_TYPES;
typedef struct String;
String *cStrU__init(char *str);
void *cStrU__edit(const struct String *strU, const char *str, enum STRING_EDIT_TYPES *edit_type);
int cStrU__Trim(const struct String *strU);
int cStrU__CountLines(const struct String *strU);
int cStrU__replace_char(const struct String *strU, const char ch, char *replacement);
int cStrU__remove_char(const struct String *strU, const char ch);
char **cStrU__split_lines(const char *str);
char **cStrU__split_string_w_char(const struct String *strU, const char *ch);

typedef struct cStr
{
    String     *Data;
    /*
        enum STRING_EDIT_TYPES *new = NEW_STRING;
        cStr->edit(cStrU->Data, "NEW STRING", new);

        enum STRING_EDIT_TYPES *append = APPEND_TO_STRING;
        cStr->edit(cStrU->Data, "ADD", append);
    */
    void       (*edit)(const struct String *, const char *, enum STRING_EDIT_TYPES *);
    
    /*
        cStr->replace_char(cStrU->Data, ':', ' ');
    */
    int        (*replace_char)(const struct String *, const char, char *);

    /*
        cStr->remove_char(cStrU->Data, '\n');
    */
    int        (*remove_char)(const struct String *, const char ch);

    /*
        cStr->trim_whitespaces(cStrU->Data)
    */
    int        (*trim_whitespaces)(const String *);

    /*
        cStr->split_lines(DATA);
    */
    char       *(*split_lines)(const char *str);

    /*
        cStr->split_string_w_char()
    */
   char        *(*split_string_w_char)(const struct String *, const char *ch);

    /*
        cStr->count_lines(cStrU->Data);
    */
    int        (*count_lines)(const struct String *);

    /*
        cStru->die(cStrU);
    */
    void       (*die)(const struct cStr *); 
} cStr;

void __close_string(const struct cStr *cStrU)
{
    free(cStrU->Data->buffer);
    free(cStrU->Data);
}

cStr *create_string(char *str)
{
    struct cStr *strU = (struct cStr *)malloc(sizeof(str)*strlen(str));
    strU->Data = cStrU__init(str);

    strU->die = __close_string;
    strU->edit = cStrU__edit;
    strU->split_lines = cStrU__split_lines;
    strU->split_string_w_char = cStrU__split_string_w_char;
    strU->remove_char = cStrU__remove_char;
    strU->replace_char = cStrU__replace_char;
    strU->trim_whitespaces = cStrU__Trim;
    strU->count_lines = cStrU__CountLines;

    return strU;
}