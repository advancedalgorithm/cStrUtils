#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/cStrUtils.h"

int main() 
{

    printf("\x1b[31m[ + ]\x1b[37m cStringUtilty Library Debugging Script \x1b[31m[ + ]\x1b[0m\n");
    printf("\x1b[37m       - Created By BillyTheBob\n---------------------------------------\n\x1b[0m");

    FILE *fd = fopen("../item.txt", "r");
    if(fd == NULL)
    {
        printf("[ X ] Error, Unable to read file...!");
        exit(0);
    }

    long sz;
    fseek(fd, 0L, SEEK_END);
    sz = ftell(fd);
    fseek(fd, 0L, SEEK_SET);

    char *data = (char *)malloc(sz*sz);
    memset(data, '\0', sizeof(data));
    fread(data, 1, sz*sz, fd);

    // char temp[100];
    // strcpy(temp, "TES/TING\n /////TH/I/S/dewfewfffffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");

    struct cStr *cStrU = create_string(data);
    // printf("(strU->create_string(temp)): %s\n", cStrU->Data->buffer);
    
    // cStrU->trim_whitespaces(cStrU->Data);
    // printf("(cStrU->trim_whitespaces(cStrU->Data)): %s\n", cStrU->Data->buffer);

    cStrU->replace_char(cStrU->Data, ',', '\n');
    cStrU->remove_char(cStrU->Data, '{');
    cStrU->remove_char(cStrU->Data, '}');
    // cStrU->replace_char(cStrU->Data, ':', ' ');
    printf("(cStrU->replace_char(cStrU->Data, ',', '\\n')): %s\n", cStrU->Data->buffer);

    // cStrU->remove_char(cStrU->Data, '-');
    // printf("(cStrU->remove_char(cStrU->Data, '-')): %s\n", cStrU->Data->buffer);

    // enum STRING_EDIT_TYPE *g = NEW_STRING;
    // cStrU->edit(cStrU->Data, "NEW", g);
    // printf("(cStrU->edit(cStrU->Data, \"NEW\", g)): %s\n", cStrU->Data->buffer);

    int lines = cStrU->count_lines(cStrU->Data);
    printf("(cStrU->count_lines(cStrU->Data)): %d\n", lines);
    
    cStrU->die(cStrU);
    return 0;
}

