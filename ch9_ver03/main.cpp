#include "../std_lib_facilities.h"

class Date{
    int year, month, day;
public:
    Date(int y, int m, int d);
    void add_day(int n);

    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}

    void set_year(int y)
    {
        if(y > 0)
        year = y;
    else
        error("Invalid year in set_year");
    }

    void set_month(int m)
    {
        if(m <= 12 && m > 0)
        month = m;
    else
        error("Invalid month in set_month");
    }

    void set_day(int d)
    {
        if(d <= 31 && d > 0)
        day = d;
    else
        error("Invalid day in set_day");
    }
};

Date::Date(int y, int m, int d)
{
    if(y > 0)
        year = y;
    else
        error("Invalid year");

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
    cout << dd.get_year() << ". " << dd.get_month() << ". " << dd.get_day() << ".\n";    //Kiír bármilyen érvényes dátumot
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
try
{
    Date today {2001,12,11};
    cout << "birthday: ";
    print_date(today);

    int n{500};
    today.add_day(n);
    cout << n << " days later: ";
    print_date(today);

    today.set_year(1950);
    print_date(today);



    return 0;
}
catch (exception& e) {
    cerr << e.what () << '\n';
    return 1;
}
