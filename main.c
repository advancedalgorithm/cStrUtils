#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/cStrUtils.h"

int main() 
{

    char temp[100];
    strcpy(temp, "TES/TING\n /////TH/I/S/dewfewfffffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");

    struct cStr *cStrU = create_string(temp);
    printf("(strU->create_string(temp)): %s\n", cStrU->Data->buffer);
    
    cStrU->trim_whitespaces(cStrU->Data);
    printf("(cStrU->trim_whitespaces(cStrU->Data)): %s\n", cStrU->Data->buffer);

    cStrU->replace_char(cStrU->Data, ',', ' ');
    printf("(cStrU->replace_char(cStrU->Data, ',', ' ')): %s\n", cStrU->Data->buffer);

    cStrU->remove_char(cStrU->Data, '-');
    printf("(cStrU->remove_char(cStrU->Data, '-')): %s\n", cStrU->Data->buffer);

    enum STRING_EDIT_TYPE *g = NEW_STRING;
    cStrU->edit(cStrU->Data, "NEW", g);
    printf("(cStrU->edit(cStrU->Data, \"NEW\", g)): %s\n", cStrU->Data->buffer);

    int lines = cStrU->count_lines(cStrU->Data);
    printf("(cStrU->count_lines(cStrU->Data)): %d\n", lines);
    
    cStrU->die(cStrU);
    free(cStrU);
    return 0;
}