/*************************************************************
Author: Matthew Vang
Created: September 9th, 2026

This program implements a simplified version of the Unix "head" command.
Program accepts a single file name as a cli argument and prints the first 6 lines of the file directly to terminal.
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // implement myhead
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
    char buff[256];
    while(count < 6 && fgets(buff, sizeof buff, file)) {
        fputs(buff, stdout); // print line to terminal directly
        count++;
    }
    return 0;
}
