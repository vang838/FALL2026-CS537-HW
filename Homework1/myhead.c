// TODO: Add header comment; header files and helper functions as needed

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // TODO: implement myhead
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
        fputs(buff, stdout);
        count++;
    }
    return 0;
}
