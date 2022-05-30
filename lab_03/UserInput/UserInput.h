#ifndef USER_INPUT_H
#define USER_INPUT_H

static const unsigned int buff_size = 1024;

class UserInput {
    char *buffer;
    unsigned int buffer_size;
public:
    UserInput(unsigned int i_buffer_size = buff_size);
    UserInput(const UserInput &ref);
    ~UserInput();

    const char *GetString(const char *message = "");
    int GetNumber(int min, int max, const char *message = "");
    int GetInt(const char *message = "");
    double GetDouble(const char *message = "");

private:
    UserInput &operator=(const UserInput &ref);
};

#endif
