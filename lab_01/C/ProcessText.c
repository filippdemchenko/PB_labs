#include "ProcessText.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




void process_text(FILE *input_file, FILE *output_file)
{
    fseek(input_file, 0L, SEEK_SET);

    char buffer[1024];
    while (fgets(buffer, 1024, input_file)){
        buffer[1023] = '\0';
	char *new_line = strchr(buffer, '\n');
	if (new_line)
	    *new_line = '\0';

        process_line(buffer, 1024, output_file);
    }
}


void process_line(char *line, size_t line_size, FILE *output_file)
{
    const char delimiter[] = " ";
    char *token;
    int numbers_exist = 0;
    long int current_number;
    long int max_number;
    int count_numbers = 0;

    char line_copy[1024];
    strcpy(line_copy, line);



    token = strtok(line_copy, delimiter);

    if (!token)
        return;

    if (is_true_number(token)){
        if (!numbers_exist){
            max_number = atol(token);
	    numbers_exist = 1;
	}else{
            current_number = atol(token);
            if (current_number > max_number)
		max_number = current_number;
	}
	count_numbers++;
    }

   


    while ((token = strtok(NULL, delimiter))){
        if (is_true_number(token)){
            if (!numbers_exist){
                max_number = atol(token);
		numbers_exist = 1;
	    }else{
                current_number = atol(token);
		if (current_number > max_number)
		    max_number = current_number;
	    }
	    count_numbers++;
	}
    }

    if (!numbers_exist)
        return;

    fprintf(output_file, "%ld: ", max_number);
    
    int i = 0;

    token = strtok(line, delimiter);
    if (is_true_number(token)){
        i++;
        fprintf(output_file, "%ld%s", atol(token), (i < count_numbers)? ", " : "\n");
	
    }

    while ((token = strtok(NULL, delimiter))){
        if (is_true_number(token)){
	    ++i;
            fprintf(output_file, "%ld%s", atol(token), (i < count_numbers)? ", " : "\n");
	}
    }

    return;
}

int is_true_number(const char *string)
{
    if (*string == '+' || *string == '-')
        string++;

    while (*string){
        if (!isdigit(*string))
	    return 0;
	string++;
    }

    return 1;
}

