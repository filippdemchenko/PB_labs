#include "lab_02.h"


/* linked list operations and related */

void initialize_empty_list(List *list)
{
    list->list_header = NULL;
    list->list_tail = NULL;
    list->list_length = 0;
}


int read_file_to_list(FILE *input_stream, List *list)
{
    if (list->list_header != NULL){
        return 1;
    }

    Item *new_item  = _allocate_memory_for_item();
    if (!new_item){
	exit(MEMORY_FAILURE);
    }

    while (fread(new_item, sizeof(*new_item), 1, input_stream)){
        _append_to_list(list, new_item);

	new_item = _allocate_memory_for_item();
        if (!new_item){
	    exit(MEMORY_FAILURE);
        }
    }

    free(new_item);

    return 0;
}

void write_list_to_file(FILE *file, List *list)
{
    Item *header = list->list_header;

    while (header){
        fwrite(header, sizeof(*header), 1, file);
	header = header->next;
    }
}

void clear_list(List *list)
{
    Item *header = list->list_header;
    Item *tmp_ptr;

    while (header){
        tmp_ptr = header->next;
	free(header);
	header = tmp_ptr;
    }

    initialize_empty_list(list);
}


Item *_allocate_memory_for_item(void)
{
    Item *new_item = (Item *) malloc(sizeof(*new_item));
    if (!new_item){
        fprintf(stderr, "Memory allocation error\n");
    }

    return new_item;
}

void _append_to_list(List *list, Item *new_item)
{
      new_item->next = NULL;
      new_item->prev = list->list_tail;

      if (list->list_header == NULL){
          list->list_header = new_item;
	  list->list_tail = new_item;
      }else{
          list->list_tail->next = new_item;
          list->list_tail = new_item;
      }

      list->list_length += 1;
}


int add_client(List *list, Item *new_item, int start_day, int finish_day)
{
    Item *position;
    int pos_result = _search_position(list, new_item, &position, start_day, finish_day);

    if (pos_result == -1){
        return -1;
    }
  
    Item *new_client = _allocate_memory_for_item();
    if (!new_client){
        return MEMORY_FAILURE;
    }

    copy_to_item(new_client, new_item);

    insert_into_list(list, new_client, position);

    return 0;
}

int _search_position(List *list, Item *new_item, Item **position, int start_day, int finish_day)
{
    if (_is_out_of_day(new_item, start_day, finish_day)){
        return -1;
    }

    Item *header = list->list_header;

    if (!header){
        *position = NULL;
        return 0;
    }

    int found = 0;

    while (header){
        if (header->prev == NULL && new_item->client_info.minutes_start + new_item->client_info.minutes_duration <= header->client_info.minutes_start){
	    found = 1;
	    *position = header;
        }else if (header->next == NULL && new_item->client_info.minutes_start >= header->client_info.minutes_start + header->client_info.minutes_duration){
            found = 1;
	    *position = NULL;
	}else if (header->next != NULL && new_item->client_info.minutes_start >= header->client_info.minutes_start + header->client_info.minutes_duration && new_item->client_info.minutes_start + 
		  new_item->client_info.minutes_duration <= header->next->client_info.minutes_start){
            found = 1;
	    *position = header->next;
	}
      
        header = header->next;
    }

    if (found)
        return 0;
    else
        return -1;
}

void insert_into_list(List *list, Item *new_item, Item *current_item)
{
    Item *header = list->list_header;
    Item *tmp_ptr;

    if (!current_item){
        _append_to_list(list, new_item);
    }else{
        while (header != current_item)
	    header = header->next;

	if (!header->prev){
            new_item->next = header;
	    new_item->prev = NULL;
	    list->list_header = new_item;
	}else{
	    new_item->prev = header->prev;
	    new_item->next = header;
            tmp_ptr = header;
	    header->prev->next = new_item;
	    tmp_ptr->prev = new_item;
	}
    list->list_length += 1;
    }
}


int _is_out_of_day(Item *item, int day_start_minutes, int day_end_minutes){
    return item->client_info.minutes_start < day_start_minutes ||
           item->client_info.minutes_start + item->client_info.minutes_duration > day_end_minutes;
}


void copy_to_item(Item *dest_item, const Item *src_item){
    strcpy(dest_item->client_info.client_name, src_item->client_info.client_name);
    strcpy(dest_item->client_info.client_surname, src_item->client_info.client_surname);
    dest_item->client_info.minutes_start = src_item->client_info.minutes_start;
    dest_item->client_info.minutes_duration = src_item->client_info.minutes_duration;
}


void show_list(List *list)
{
    Item *header = list->list_header;

    while (header){
        printf("%s %s %d %d\n", header->client_info.client_name, header->client_info.client_surname, 
	       header->client_info.minutes_start, header->client_info.minutes_duration);
        header = header->next;
    }
}



void cut_file(FILE *file, off_t length)
{
    ftruncate(fileno(file), length);
    fseek(file, length, SEEK_SET);
}



int delete_client_from_list(List *list, int client_no)
{
    if (client_no < 1 || client_no > list->list_length){
        return -1;
    }

    if (list->list_header == NULL){
        return -1;
    }

    Item *header = list->list_header;
    Item *tmp_ptr;
    int counter = 1;

    while (counter < client_no){
        header = header->next;
	counter++;
    }

    if (header->next == NULL && header->prev == NULL){
        free(header);
	list->list_header = NULL;
	list->list_header = NULL;
    }else if (header->next == NULL){
        tmp_ptr = header;
	list->list_tail = header->prev;
	header->prev->next = NULL;
	free(tmp_ptr);
    }else if (header->prev == NULL){
        tmp_ptr = header;
	list->list_header = header->next;
        header->next->prev = NULL;
	free(tmp_ptr);
    }else{
        Item *prev_i = header->prev;
	Item *next_i = header->next;

	prev_i->next = next_i;
	next_i->prev = prev_i;

        free(header);
    }
    
    list->list_length -= 1;

    return 0;
}


/* String operations */
char *get_string(char *buffer, int buffer_len){ 
    char *input_result = fgets(buffer, buffer_len, stdin);
    char *tmp = buffer;

    if (!input_result){
        return NULL;
    }

    buffer[buffer_len - 1] = '\0';

    while (*tmp != '\n' && *tmp != '\0')
        tmp++;
    
    if (*tmp == '\0'){
        while (getchar() != '\n');
    }else{
        *tmp = '\0';
    }

    return buffer;
}


int get_time_in_minutes(int min, int max, const char *message)
{
    int hours, minutes;
   
    printf("%s", message);
    while (scanf("%d:%d", &hours, &minutes) != 2 || hours*60 + minutes < min || hours*60 + minutes > max){
        while (getchar() != '\n');
	printf("Invalid time! Try again.\n");
	printf("%s", message);
    }

    return hours * 60 + minutes;
}


int get_number(int min, int max, const char *message)
{
    int result;

    printf("%s", message);
    while (scanf("%d", &result) != 1 || result < min || result > max){
         while (getchar() != '\n');
	 printf("Invalid input! Try again.\n");
	 printf("%s", message);
    }

    return result;
}


int enter_client_info(Item *new_item)
{
    char *input_result;

    printf("Enter client name: ");
    input_result = get_string(new_item->client_info.client_name, MAX_NAME_LEN);

    if (!input_result){
	return -1;
    }

    printf("Enter client surname: ");
    input_result = get_string(new_item->client_info.client_surname, MAX_SURNAME_LEN);

    if (!input_result){
	return -1;
    }

    new_item->client_info.minutes_start = get_time_in_minutes(0, 24 * 60 - 1, "Enter start procedure time: ");
    new_item->client_info.minutes_duration = get_number(0, 24 * 60 - 1, "Enter procedure duration in minutes: ");

    return 0;

}


void traverse_list(List *list, void (*func) (Item *item, int number))
{
    Item *header = list->list_header;
    int counter = 1;

    while (header){
        (*func)(header, counter);
	header = header->next;
	counter++;
    }
}


void print_client_info(Item *item, int number)
{
    char *name = item->client_info.client_name;
    char *surname = item->client_info.client_surname;
    int start = item->client_info.minutes_start;
    int duration = item->client_info.minutes_duration;

    printf("%d.\t%02d:%02d-%02d:%02d %s %s\n", number, start / 60, start % 60, (start + duration) / 60, 
           (start + duration) % 60, name, surname);
}


int get_first_symbol(void)
{
    int symbol;
    while (isspace(symbol = getchar()));
    while (getchar() != '\n');
    return symbol;
}


size_t get_file_length(FILE *file)
{
    size_t length = 0;
    fseek(file, 0L, SEEK_SET);

    while (getc(file) != EOF){
        length += 1;
    }

    
    return length;
}

