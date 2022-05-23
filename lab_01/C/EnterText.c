#include <string.h>
#include <stdio.h>
#include "EnterText.h"

enum { buffer_size = 1024 };



void enter_text_to_input_file(FILE *input_file)
{
    char buffer[buffer_size];
    int line_counter = 1;


    printf("Enter text line by line. Press ^K and \\n at the end\n");
    do {
        printf("%d|\t", line_counter++);
	get_line(buffer, buffer_size, stdin);
        if (strcmp(buffer, "\v")){
            fputs(buffer, input_file);
	    fputs("\n", input_file);
	}

    } while (strcmp(buffer, "\v"));
}


char *get_line(char *buffer, size_t b_size, FILE *input_stream)
{
    char *result = fgets(buffer, b_size, input_stream);
    int new_line = 0;

    if (!result){
        strcpy(buffer, "");
	return buffer;
    }

    buffer[b_size - 1] = '\0';

    while (*result){
        if (*result == '\n'){
            *result = '\0';
	    new_line = 1;
	}
	result++;
    }

    if (!new_line)
        while (getc(input_stream) != '\n') {}

    return buffer;
}
