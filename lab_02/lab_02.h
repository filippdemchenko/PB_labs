#ifndef LAB_02_H
#define LAB_02_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


#define MAX_NAME_LEN	20
#define MAX_SURNAME_LEN	30



enum errors {
    NO_FILE_NAME = 1,
    MEMORY_FAILURE = 2
};


typedef struct item {
    struct client {
        char client_name[MAX_NAME_LEN];
	char client_surname[MAX_SURNAME_LEN];
        int minutes_start;
	int minutes_duration;
    } client_info;

    struct item *next;
    struct item *prev;
} Item;


typedef struct list {
    Item *list_header;
    Item *list_tail;
    int list_length;
} List;



/* Linked list operation and related */

void initialize_empty_list(List *list); 

int read_file_to_list(FILE *input_stream, List *list);

Item *_allocate_memory_for_item(void);

void _append_to_list(List *list, Item *new_item);

int _is_out_of_day(Item *new_item, int start_day, int finish_day);

void insert_into_list(List *list, Item *new_item, Item *current_item);

int _search_position(List *list, Item *new_item, Item **position, int start_day, int finish_day);

void copy_to_item(Item *dest_item, const Item *src_item);


int add_client(List *list, Item *new_item, int start_day, int finish_day);

void cut_file(FILE *file, off_t length);

int delete_client_from_list(List *list, int client_no);

void traverse_list(List *list, void (*func) (Item *item, int number));

void clear_list(List *list);

void write_list_to_file(FILE *file, List *list);

/* String operations */

char *get_string(char *buffer, int buffer_len);

int get_time_in_minutes(int min, int max, const char *message);

int get_number(int min, int max, const char *message);

int enter_client_info(Item *new_item);

void print_client_info(Item *item, int number);

int get_first_symbol(void);


/* File stream operations */

size_t get_file_length(FILE *file);


#endif
