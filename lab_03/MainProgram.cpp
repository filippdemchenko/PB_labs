#include "UserInput/UserInput.h"
#include "Person.h"
#include <cstdio>


int main(int argc, char *argv[])
{
    UserInput input = UserInput();
    int array_size = input.GetNumber(1, 10000, "Enter number of people: ");

    putchar('\n');

    Person *people = new Person[array_size];

    for (int i = 0; i < array_size; i++){
        people[i].FullName(input.GetString("Enter person's full name: "));
	people[i].Day(input.GetNumber(1, 31, "Enter day of birth: "));
	people[i].Month(input.GetNumber(1, 12, "Enter month of birth: "));
	people[i].Year(input.GetNumber(1900, 2022, "Enter year of birth: "));
	putchar('\n');
    }

    bool happy_dates = false;

    for (int i = 0; i < array_size; i++){
        if (people[i].CheckHappyDate()){
	    printf("%s has the happy date of birth!\n", people[i].FullName());
	    happy_dates = true;
	}
    }

    if (!happy_dates)
        printf("No one has the happy date...\n");

    delete [] people;

    return 0;
}
