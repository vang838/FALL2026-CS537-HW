/*************************************************************
Author: Matthew Vang
Created: September 9th, 2026

This program implements a simplified version of the Unix "uniq" command.
Program accepts a single file name as a cli argument, reads the file line by line, and prints only non-duplicate adjacent lines.
Program uses two line buffers so that current line can be compared with previously printed lines without modifying the file.
*************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    int count = 0;
    char buff [2][256];
    char *prev = NULL, *curr = buff[count%2];
    
    while(fgets(curr, sizeof buff[0], file)) { 
        if(!prev || strcmp(prev, curr) != 0) { // process first line or different line from prev
            fputs(curr, stdout);
            prev = curr;
            count++;
            curr = buff[count%2];
        }
    } 
    
    fclose(file);
    return 0;
}
