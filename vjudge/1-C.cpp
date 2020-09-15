#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int begin_month, begin_day, end_month, end_day;
        long long int num;
        cin >> begin_month >> begin_day >> num >> end_month >> end_day;
        for (int month = begin_month, day = begin_day; month != end_month && day != end_day;)
        {
            num *= 2;
            day++;
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if(day/31==1)
                {
                    month++;
                    day %= 31;
                }
            }
            else if (month == 2)
            {
                if(day/28==1)
                {
                    month++;
                    day %= 28;
                }
            }
            else if (month==4||month==6||month==9||month==11)
            {
                if(day/30==1)
                {
                    month++;
                    day %= 30;
                }
            }
        }
        cout << num*2 << endl;
    }
    return 0;
}