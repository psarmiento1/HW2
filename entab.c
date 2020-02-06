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

int main(int argc, const char * argv[]) {
    FILE * fin;
    FILE * fout;
    
    if (!open_io_files(argc, argv, &fin, &fout, 3, 4,                   "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
      exit(1);
    }
    
    int c, count;
    count = 0;
    
    while((c = fgetc(fin)) != EOF) {
        if(c == ' ') {++count;}
        else if (c == '\t' || c == '\n') {;}
        else {
            if(count != 0) {
                int t = '\t';
                fprintf(fout, "%c", t);
                count = 0;
            }
            fputc(c, fout);
        }
    }
    
    closefiles(2, fin, fout);
    
    return 0;
}
