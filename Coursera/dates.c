#include <stdio.h>

char *months[] = {"January", "February", "March", "April", "May", "June",
                  "July", "August", "September", "October", "November", "December"};
typedef enum month{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} month; //enum for months

typedef struct date //struct for date
    {
        month m;
        int day;
    }date;

date nextday(date *d); //prototype

int main() //main
{
    // Dates to be tested
    date d1 = {Feb, 28};
    date d2 = {Mar, 14};
    date d3 = {Oct, 31};
    date d4 = {Dec, 31};

    // Calling the nextday functions for each date
    nextday(&d1);
    nextday(&d2);
    nextday(&d3);
    nextday(&d4);

    return 0;
}

date nextday(date *d) //Calculates the next day and prints both the previous and new dates.
{
    month mon = d -> m; //'mon' stores the current_month
    int next_day = d -> day + 1; //'next_day' stores current_day + 1

    switch(mon) //calculates next day
    {
    case Jan: 
        next_day %= 31;
        break;
    case Feb:
        next_day %= 28;
        break;
    case Mar:
        next_day %= 31;
        break;
    case Apr:
        next_day %= 30;
        break;
    case May:
        next_day %= 31;
        break;
    case Jun:
        next_day %= 30;
        break;
    case Jul:
        next_day %= 31;
        break;
    case Aug:
        next_day %= 31;
        break;
    case Sep:
        next_day %= 30;
        break;
    case Oct:
        next_day %= 31;
        break;
    case Nov:
        next_day %= 30;
        break;
    case Dec:
        next_day %= 31;
        break;
    }

    if (next_day == 1) mon = (mon + 1) % 12; //calculates next month
    printf("Date = %s, %d\t Next_Date = %s, %d \n", months[d -> m], d -> day, months[mon], next_day); //prints results
}