#include "imlib_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static char sprint_buf[1024];
int imlib_printf(int level,char *fmt, ...)
{
va_list args;
int n;
va_start(args, fmt);
n = vsprintf(sprint_buf, fmt, args);
va_end(args);
    switch (level)
    {
    case 0:
        fprintf(stderr,"%s", sprint_buf);
        abort();
        break;
    case 5:
        fprintf(stdout,"%s", sprint_buf);
        break;
    default:
        break;
    }
return n;
}
