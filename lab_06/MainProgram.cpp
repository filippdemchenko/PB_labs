#include <cstdio>
#include "BinaryTree.hpp"
#include <cstring>
#include <cstdlib>

// Max string len
constexpr int STRING_LEN = 1024;

// Creating buffer for a string
static char string[STRING_LEN];


// Count characters in string
int count_char(const char *string, char c);
// Comparator function
int comp(const void *p1, const void *p2);



int main(int argc, char *argv[])
{
    printf("Enter some text: ");
    fgets(string, STRING_LEN, stdin);
    string[STRING_LEN - 1] = '\0';

    char *new_line_pos = strchr(string, '\n');
    if (new_line_pos)
        *new_line_pos = '\0';

    qsort(string, strlen(string), sizeof(char), comp);

    BinaryTree tree;
    tree.AddNewNode('\0');

    // Counter for letters
    int counter = 0;
    
    for (int i = 0; i < strlen(string); i++){
        if (i == 0 || string[i] != string[i - 1]){
            tree.AddNewNode(string[i]);
            printf("%c - %d\n", string[i], count_char(string, string[i]));
        }
    }

    putchar('\n');
    tree.ShowTree(tree.GetRoot());

    return 0;    
}





int count_char(const char *string, char c)
{
    int result = 0;
    while (*string){
        if (*string == c)
            ++result;
        string++;
    }
    return result;
}

int comp(const void *p1, const void *p2)
{
    if (count_char(string, *(char *)p1) > count_char(string, *(char *)p2))
        return 1;
    if (count_char(string, *(char *)p1) < count_char(string, *(char *)p2))
        return -1;

    if (*(char *)p1 < *(char *)p2)
        return -1;
    else if (*(char *)p1 > *(char *)p2)
        return 1;
    else
        return 0;
}