#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/cStrUtils.h"
#include "includes/cArray.h"

typedef struct Item
{
    char    *name;
    int     id;
    char    *url;
    char    *price;
    char    *update;
} Item;

typedef struct YoGuide
{
    int  err;
    int  item_count;
    char **items;
    char **found;
} YoGuide;

YoGuide *YG__Init__()
{
    struct YoGuide *yg = (struct YoGuide *)malloc(sizeof(struct YoGuide *)*400000);
    FILE *fd = fopen("items.txt", "r");
    if(fd == NULL) 
    {
        yg->err = 1;
        return yg;
    }

    fseek(fd, 0L, SEEK_END);
    long sz = ftell(fd);
    fseek(fd, 0L, SEEK_SET);

    char *data = (char *)malloc(sz*999999999);
    fread(data, 1, sz*sz, fd);

    struct cStr *cStrU = create_string(data);
    cStrU->remove_char(cStrU->Data, '(');
    cStrU->remove_char(cStrU->Data, ')');
    cStrU->remove_char(cStrU->Data, '\'');
    int lines = cStrU->count_lines(cStrU->Data);

    printf("%s", cStrU->Data->buffer);

    cStrU->die(cStrU);
    
    free(cStrU);
    free(data);

    return yg;
}

int main()
{
    struct YoGuide *yg = YG__Init__();
    if(yg->err == 1)
    {
        printf("[ X ] Error, Unable to read file....!");
        return 0;
    }
    return 1;
}