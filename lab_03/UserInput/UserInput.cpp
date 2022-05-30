#include "UserInput.h"
#include <cstring>
#include <cstdio>

UserInput::UserInput(unsigned int i_buffer_size)
{
    buffer_size = i_buffer_size ? i_buffer_size : 2;
    buffer = new char[buffer_size];
}

UserInput::~UserInput()
{
    if (buffer)
        delete [] buffer;
}

UserInput::UserInput(const UserInput &ref)
{
    buffer_size = ref.buffer_size;
    buffer = new char[buffer_size];
    memcpy(buffer, ref.buffer, buffer_size);
}

const char *UserInput::GetString(const char *message)
{  
    printf("%s", message);
    char *result = fgets(buffer, buffer_size, stdin);
    bool new_line = false;

    if (!result){
        strcpy(buffer, "");
	return buffer;
    }

    buffer[buffer_size - 1] = '\0';

    while (*result){
        if (*result == '\n'){
            *result = '\0';
	    new_line = true;
	}
	result++;
    }

    if (!new_line)
        while (getchar() != '\n') {}

    return buffer;
}


int UserInput::GetNumber(int min, int max, const char *message)
{
    int result;
    printf("%s", message);

    while (scanf("%d", &result) != 1 || result < min || result > max){
        while (getchar() != '\n') {}
	printf("Enter again: ");
    }
    while (getchar() != '\n') {}
    return result;
}

int UserInput::GetInt(const char *message)
{
    int result;
    printf("%s", message);

    while (scanf("%d", &result) != 1){
        while (getchar() != '\n') {}
	printf("Enter again: ");
    }
    while (getchar() != '\n') {}
    return result;
}

double UserInput::GetDouble(const char *message)
{
    double result;
    printf("%s", message);

    while (scanf("%lf", &result) != 1){
        while (getchar() != '\n') {}
	printf("Enter again: ");
    }
    while (getchar() != '\n') {}
    return result;
}


