#include "lab_02.h"


const char filename[] = "lab_02.dat";

/* menu */
int show_menu_and_get_choice(void);

/* options */
void option_add_new_client(List *clients_list, Item *new_item, int start_work_day, int end_work_day);
void option_remove_client(List *clients_list);
void option_show_list(List *clients_list);

int main(int argc, char *argv[]){
    FILE *data_file = fopen(filename, "r+");

    if (!data_file){
        fprintf(stderr, "%s: no such file\n", filename);
	exit(NO_FILE_NAME);
    }
    

    /* Create List and read from data file */
    List clients_list;
    Item new_item;

    initialize_empty_list(&clients_list);
 
   
    int start_work_day, end_work_day;
    int run_program = 1;
    int choice;

    if (!get_file_length(data_file)){
        start_work_day = get_time_in_minutes(0, 60 * 24 - 1, "Enter start work day time: ");
        end_work_day = get_time_in_minutes(start_work_day, 60 * 24 - 1, "Enter end work day time: ");
    }else{
        fseek(data_file, 0L, SEEK_SET);
        fread(&start_work_day, sizeof(int), 1, data_file);
        fread(&end_work_day, sizeof(int), 1, data_file);
    }

    read_file_to_list(data_file, &clients_list);


    while (run_program){
        choice = show_menu_and_get_choice();
	system("clear");

	if (choice == 'a'){
	    option_add_new_client(&clients_list, &new_item, start_work_day, end_work_day);
	}else if (choice == 'r'){
	    option_remove_client(&clients_list);
	}else if (choice == 'l'){
	    option_show_list(&clients_list);
	}else if (choice == 'c'){
            clear_list(&clients_list);
	}else if (choice == 'q'){
            run_program = 0;
	}else{
            printf("Invalid command!\n\n");
	}
    }

    cut_file(data_file, 0);
    fseek(data_file, 0L, SEEK_SET);
    if (clients_list.list_length){
        fwrite(&start_work_day, sizeof(int), 1, data_file);
        fwrite(&end_work_day, sizeof(int), 1, data_file);
    }

    
    write_list_to_file(data_file, &clients_list);
    clear_list(&clients_list);

    fclose(data_file);

    return 0;
}

int show_menu_and_get_choice(void)
{
    int choice;

    printf("a - add new client\n");
    printf("r - remove client\n");
    printf("l - show clients list\n");
    printf("c - clear clients list\n");
    printf("q - quit\n");

    printf("Your choice: "); choice = get_first_symbol();

    putchar('\n');

    return choice;
}



void option_add_new_client(List *clients_list, Item *new_item, int start_work_day, int end_work_day)
{
    int result = enter_client_info(new_item);
    if (result == -1){
        printf("Input error!\n\n");
    }else{
        result = add_client(clients_list, new_item, start_work_day, end_work_day);
        if (result == -1){
            printf("Not enougth time for this client!\n\n");
	}else{
            printf("Done!\n\n");
	}
   }
}


void option_remove_client(List *clients_list)
{
    int result;
    if (!clients_list->list_length){
        printf("List is empty...\n\n");
	return;
    }

    int client_no = get_number(1, clients_list->list_length, "Enter client number to remove: ");
    result = delete_client_from_list(clients_list, client_no);

    if (result == -1){
        printf("Invalid client number!\n\n");
    }else{
        printf("Done!\n\n");
    }
}


void option_show_list(List *clients_list)
{
    if (!clients_list->list_length){
        printf("List is empty...\n\n");
    }else{
        traverse_list(clients_list, print_client_info);
    }
}
