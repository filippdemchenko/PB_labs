#ifndef PROCESS_TEXT_H
#define PROCESS_TEXT_H

#include <string.h>
#include <stdio.h>


void process_text(FILE *input_file, FILE *output_file);
void process_line(char *line, size_t line_size, FILE *output_file);
int is_true_number(const char *);


#endif
