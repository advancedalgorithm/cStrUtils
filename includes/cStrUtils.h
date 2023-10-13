#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cStrUtils.c"

enum STRING_EDIT_TYPES;
typedef struct String;
String *cStrU__init(char *str);
void *cStrU__edit(const struct String *strU, const char *str, enum STRING_EDIT_TYPES *edit_type);
int cStrU__Trim(const struct String *strU);
int cStrU__CountLines(const struct String *strU);
int cStrU__replace_char(const struct String *strU, const char ch, char *replacement);
int cStrU__remove_char(const struct String *strU, const char ch);

typedef struct cStr
{
    String     *Data;
    void       (*edit)(const struct String *, const char *, enum STRING_EDIT_TYPES *);
    int        (*replace_char)(const struct String *, const char, char *);
    int        (*remove_char)(const struct String *, const char ch);
    int        (*trim_whitespaces)(const String *);
    int        (*count_lines)(const struct String *);
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
    strU->remove_char = cStrU__remove_char;
    strU->replace_char = cStrU__replace_char;
    strU->trim_whitespaces = cStrU__Trim;
    strU->count_lines = cStrU__CountLines;

    return strU;
}