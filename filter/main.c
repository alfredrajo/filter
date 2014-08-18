//
//  main.c
//  filter
//
//  Created by Alfred Herrmann on 01.02.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#define MAXSTR 4096
#define true 1
int main(int argc, char *argv[])
{ static char infile[MAXSTR], in[MAXSTR], *p= infile;
    FILE *ifd;
    if(argc>1)						/* commandline */
        strcpy(infile, argv[1]);
    ifd=fopen(infile,"r");
    while(true)
    { if(!(fgets(in, MAXSTR-1, ifd)))
        break;
        p=in + (strlen(in)-2);
        *p-- = '\0';
        while(*p-- == ' ')
            *p = '\0';
        p = in;
        
        if(strlen(p) > 2)
            p += 2;
        
        if(in[0] == 'A')
            printf("\n%s", p);
        else
            printf("\t%s", p);
    }
    fclose(ifd);
    return 0;
}
