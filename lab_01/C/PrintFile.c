#include "PrintFile.h"
#include <stdio.h>

void print_file(FILE *output_file)
{
    fseek(output_file, 0L, SEEK_SET);
 
    char buffer[1024];
    while (fgets(buffer, 1024, output_file)){
        buffer[1023] = '\0';
        fputs(buffer, stdout);
    }
}

