#include "../std_lib_facilities.h"

const vector<string> months =
{
    "placeholder","January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

enum class Month{
    jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec
};

class Date{
public:
    class Invalid{};
    Date(int y, int m, int d): year(y), month(m), day(d) {if(!is_valid()) throw Invalid{};}
    Date(int y, Month m, int d): year(y), month(int(m)), day(d) {if(!is_valid()) throw Invalid{};}
    void add_day(int n);

    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
    bool is_valid();

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
private:
    int year, month, day;
};

bool Date::is_valid(){
    if(month < 1 || month > 12 || year < 1 || day < 1 || day > 31) return false;
    else return true;
}

void Date::add_day(int n){     //Hanyadika lesz n nap múlva, melyik év mely hónapjában                                   //Szintaxis:
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

Month operator++(Month& m)
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

ostream& operator<<(ostream& os, Month m){
    return os << months[int(m)];
}

ostream& operator<<(ostream& os, Date date){
    return os << date.get_year() << ". " << months[date.get_month()] << ". " << date.get_day();
}

int main()
try
{
    Month m = Month::dec;
    cout << m << '\n';
    ++m;
    cout << m << '\n';

    Date today{2021,Month::nov,20};
    cout << today << '\n';

    return 0;
}
catch (Date::Invalid) {
    cerr << "Exception: Invalid date." << '\n';
    return 1;
}
catch (exception& e) {
    cerr << e.what () << '\n';
    return 2;
}
