#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EnterText.h"
#include "ProcessText.h"
#include "PrintFile.h"

const char input_file_name[] = "in.txt";
const char output_file_name[] = "out.txt";



int main(int argc, char *argv[])
{
    FILE *input_file = fopen(input_file_name, "w+");
    if (!input_file){
        fprintf(stderr, "Couldn't open %s\n", input_file_name);
	return 1;
    }

    FILE *output_file = fopen(output_file_name, "w+");
    if (!output_file){
        fprintf(stderr, "Counldn't open %s\n", output_file_name);
	return 2;
    }

    enter_text_to_input_file(input_file);
    
    printf("\nProcessing the file %s\n\n", input_file_name);

    process_text(input_file, output_file);

    printf("out.txt:\n");
    print_file(output_file);

    fclose(input_file);
    fclose(output_file);


    return 0;
}

