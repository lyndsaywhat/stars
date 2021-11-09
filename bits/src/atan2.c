#ifndef __plan9

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil NULL

#else

#include <u.h>
#include <libc.h>

#endif

int
main(int argc, char **argv)
{
    double x, y, o;
    char *op;
    for(int i=1;i<argc;i++){
        int len=strlen(argv[i]);
        op=malloc(len);
        if(argv[i][0]=='y'){
            strncpy(op, argv[i]+1, len);
            y=strtod(op, nil);
        } else if(argv[i][0]=='x'){
            strncpy(op, argv[i]+1, len);
            x=strtod(op, nil);
        }
    }
    o=atan2(y, x);
    printf("%e", o);
}