#ifndef PERSON_H
#define PERSON_H

class Person {
    char *full_name;
    int day, month, year;
public:
    Person(const char *i_full_name, int i_day, int i_month, int i_year);
    Person(const Person &ref);
    Person();
    ~Person();

    const char *FullName() const { return full_name; }
    int Day() const { return day; }
    int Month() const { return month; }
    int Year() const { return year; }

    void FullName(const char *i_full_name);
    void Day(int i_day) { day = i_day; }
    void Month(int i_month) { month = i_month; }
    void Year(int i_year) { year = i_year; }

    bool CheckHappyDate() const;

private:
    int SumOfDigits(int number) const;
    Person &operator=(const Person &ref);
};

#endif
