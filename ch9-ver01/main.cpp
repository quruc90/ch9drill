#include "../std_lib_facilities.h"

struct Date
{
    int y;
    int m;
    int d;
};

void init_date(Date& date, int y, int m, int d)
{
    if(y > 0)
        date.y = y;
    else
        error("Invalid year.");

    if(m <= 12 && m > 0)
        date.m = m;
    else
        error("Invalid month");

    if(d <= 31 && d > 0)
        date.d = d;
    else
        error("Invalid day");
}



void add_day(Date& date, int n)     //Hanyadika lesz n nap múlva, melyik év mely hónapjában
{                                   //Szintaxis:
    date.d += n;                    //          Date exampledate;
    while(date.d > 31)              //          init_date(exampledate,2005,12,28;
    {                               //          add_day(exampledate,5);
        date.m++;
        date.d -= 31;
        while(date.m > 12)
        {
            date.y++;
            date.m -=12;
        }
    }
}

void print_date(Date dd)    //Nem volt a feladatban, de hasznosnak gondoltam
{
    cout << dd.y << "." << dd.m << "." << dd.d << ".\n";    //Kiír bármilyen érvényes dátumot
}

void f()
{
    Date christmas;
    init_date(christmas, 2005,12,24);
    add_day(christmas,1);
    cout << "Christmas: ";
    print_date(christmas);
}

int main()
try
{
    f();
    return 0;
}
catch (exception& e) {
    cerr <<e.what () << '\n';
    return 1;
}
