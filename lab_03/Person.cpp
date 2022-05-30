#include "Person.h"
#include <cstring>

Person::Person(const char *i_full_name, int i_day, int i_month, int i_year)
{
    full_name = new char[strlen(i_full_name) + 1];
    strcpy(full_name, i_full_name);

    day = i_day;
    month = i_month;
    year = i_year;
}

Person::Person(const Person &ref)
{
    full_name = new char[strlen(ref.full_name) + 1];
    strcpy(full_name, ref.full_name);

    day = ref.day;
    month = ref.month;
    year = ref.year;
}

Person::Person()
{
    full_name = 0;
    year = 0;
    month = 0;
    day = 0;
}

Person::~Person()
{
    if (full_name)
        delete [] full_name;
}


void Person::FullName(const char *i_full_name)
{
    if (full_name)
         delete [] full_name;
    full_name = new char [strlen(i_full_name) + 1];
    strcpy(full_name, i_full_name);
}

int Person::SumOfDigits(int number) const 
{
    int sum = 0;

    while (number)
        { sum += number % 10; number /= 10; }

    return sum;
}

bool Person::CheckHappyDate() const 
{
    return SumOfDigits(year) % 7 == SumOfDigits(month) % 7 && SumOfDigits(year) % 7 == SumOfDigits(day) % 7
           && SumOfDigits(month) % 7 == SumOfDigits(day) % 7;
}

