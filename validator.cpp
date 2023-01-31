#include <bits/stdc++.h>
using namespace std;

void integer_validator()
{
    cout << "\nInvalid input. Try again: \n";
    cin.clear();
    cin.ignore(10000, '\n');
}

bool valid_date(string date)
{
    int month = 0, day = 0;
    for (int i = 0; i < 2; i++)
    {
        day = day * 10 + int(date[i] - '0');
    }
    for (int i = 3; i < 5; i++)
    {
        month = month * 10 + int(date[i] - '0');
    }
    if (day > 31)
    {
        return false;
    }
    else if (month > 12)
    {
        return false;
    }
    return true;
}

bool isDate(string date)
{
    if (date.length() != 10)
    {
        return false;
    }

    if (date[2] != '/' || date[5] != '/')
    {
        return false;
    }
    for (int i = 0; i < date.length(); i++)
    {
        if (i == 2 || i == 5)
        {
            continue;
        }
        else if (!isdigit(date[i]))
        {
            return false;
        }
    }

    return valid_date(date);
}

bool date_is_greater(string new_date, string old_date)
{
    bool greater = false;
    int old_year = 0, old_month = 0, old_day = 0, new_year = 0, new_month = 0, new_day = 0;
    for (int i = 0; i < 2; i++)
    {
        new_day = new_day * 10 + int(new_date[i] - '0');
        old_day = old_day * 10 + int(old_date[i] - '0');
    }
    for (int i = 3; i < 5; i++)
    {
        new_month = new_month * 10 + int(new_date[i] - '0');
        old_month = old_month * 10 + int(old_date[i] - '0');
    }
    for (int i = 6; i < 10; i++)
    {
        new_year = new_year * 10 + int(new_date[i] - '0');
        old_year = old_year * 10 + int(old_date[i] - '0');
    }

    if (new_year > old_year)
    {
        greater = true;
    }
    else if (new_year == old_year)
    {
        if (new_month > old_month)
        {
            greater = true;
        }
        else if (new_month == old_month)
        {
            if (new_day > old_day)
            {
                greater = true;
            }
            else
            {
                greater = false;
            }
        }
        else
        {
            greater = false;
        }
    }
    else
    {
        greater = false;
    }

    return greater;
}
