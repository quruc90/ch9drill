#include "../std_lib_facilities.h"

struct Date{
    int year, month, day;
    Date(int year, int month, int day);
    void add_day(int n);
};

Date::Date(int y, int m, int d)
{
    if(y > 0)
        year = y;
    else
        error("Invalid year.");

    if(m <= 12 && m > 0)
        month = m;
    else
        error("Invalid month");

    if(d <= 31 && d > 0)
        day = d;
    else
        error("Invalid day");
}



void Date::add_day(int n)     //Hanyadika lesz n nap múlva, melyik év mely hónapjában
{                                   //Szintaxis:
    day += n;                    //          Date exampledate;
    while(day > 31)              //          init_date(exampledate,2005,12,28;
    {                               //          add_day(exampledate,5);
        month++;
        day -= 31;
        while(month > 12)
        {
            year++;
            month -=12;
        }
    }
}

void print_date(Date dd)    //Nem volt a feladatban, de hasznosnak gondoltam
{
    cout << dd.year << ". " << dd.month << ". " << dd.day << ".\n";    //Kiír bármilyen érvényes dátumot
}

/*void f()
{
    Date today{2021,12,17};
    cout << "today\n";
    init_date(today, 2021,12,18);
    add_day(today,1);
    print_date(today);
}*/

int main()
//try
{
    Date today {2001,12,11};
    cout << "birthday: ";
    print_date(today);

    int n{10000};
    today.add_day(n);
    cout << n << " days later: ";
    print_date(today);
    return 0;
}
/*catch (exception& e) {
    cerr << e.what () << '\n';
    return 1;
}*/
