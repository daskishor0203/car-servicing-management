#include <bits/stdc++.h>
using namespace std;

#include "car.cpp"
#include "validator.cpp"

class ServiceStation
{
private:
    string name;
    string address;
    map<string, LastServiceData> current_car_list;

public:
    // default constructor
    // ServiceStation() {}

    // setters
    void set_name(string name)
    {
        this->name = name;
    }
    void set_address(string address)
    {
        this->address = address;
    }

    // getters
    string get_name()
    {
        return name;
    }
    string get_address()
    {
        return address;
    }
    map<string, LastServiceData> &get_current_car_list()
    {
        return this->current_car_list;
    }

    // Add car to service
    void add_car(string reg_number, int old_reading)
    {
        int reading, i_num;
        vector<string> issues;
        bool is_small = true;
        while (is_small)
        {
            cout << "\nEnter the odometer reading of the car before dropping it to the service station: ";
            cin >> reading;
            if (old_reading >= reading)
            {
                cout << "\nThe odometer is less or equal to the previous one. Try again\n";
            }
            else
            {
                is_small = false;
            }
        }
        cout << "\nEnter the number of issues of the car: ";
        cin >> i_num;
        for (int i = 1; i <= i_num; i++)
        {
            string issue;
            cout << "\nEnter issue number " << i << ": ";
            getline(cin >> ws, issue);
            issues.push_back(issue);
        }
        current_car_list[reg_number].odo = reading;
        current_car_list[reg_number].issues = issues;
    }

    // Servicing the car
    Car service_car(Car car_obj, string reg_number)
    {
        // taking input from the user
        float bill;
        string date;
        cout << "\nEnter the total billiing amount: ";
        cin >> bill;
        bool is_valid_date = false;
        while (!is_valid_date)
        {

            cout << "\nEnter the date of the pick up in dd/mm/yyyy format: ";
            getline(cin >> ws, date);
            if (isDate(date))
            {
                is_valid_date = true;
            }
            else
            {
                cout << "\nEnter a valid date in the dd/mm/yyyy format\n";
            }
        }

        int odo_reading = current_car_list[reg_number].odo;
        vector<string> issues = current_car_list[reg_number].issues;

        LastServiceData lsd_obj;
        lsd_obj.amount = bill;
        lsd_obj.issues = issues;
        lsd_obj.odo = odo_reading;
        lsd_obj.s_date = date;

        vector<LastServiceData> new_service_data = car_obj.get_last_service_data();
        new_service_data.push_back(lsd_obj);
        car_obj.set_odometer_reading(odo_reading);
        car_obj.set_last_service_data(new_service_data);

        // removing the car registration number from the current car list
        current_car_list.erase(reg_number);

        return car_obj;
    }
};