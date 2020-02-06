//
//  main.c
//  HW2
//
//  Created by Peter Sarmiento on 2/5/20.
//  Copyright © 2020 Peter Sarmiento. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define N_COLUMN 8

int main(int argc, const char * argv[]) {
    FILE * fin;
    FILE * fout;
    
    if (!open_io_files(argc, argv, &fin, &fout, 3, 4,                   "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
      exit(1);
    }
    
    int c, count, spaces;
    count = 0;
    
    while((c = fgetc(fin)) != EOF) {
        if(count == N_COLUMN) {count = 0;}
        
        if(c == '\t') {
            spaces = N_COLUMN - count;
            fprintf(fout, "%*c", spaces, ' ');
            count = 0;
        }
        else if (c == ' ' || c == '\n') {;}
        else {
            fputc(c, fout);
            count++;
        }
    }
    
     closefiles(2, fin, fout);
    
    return 0;
}
