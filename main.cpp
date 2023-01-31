#include <bits/stdc++.h>
using namespace std;

// importing the classes
#include "serviceStation.cpp"

// Driver code
int main()
{
    // stored all the car details
    map<string, Car> car_dictionary;

    string name, address;
    // creating a service station object
    ServiceStation ss_obj;

    // taking input from the user
    cout << "\nEnter the name of the Service Station: ";
    getline(cin >> ws, name);
    ss_obj.set_name(name);
    cout << "\nEnter the address of the Service Station: ";
    getline(cin >> ws, address);
    ss_obj.set_address(address);
    cout << "\n";

    // menu driven code
    bool exit = false;
    while (!exit)
    {
        int choice;
        cout << "\n----------Menu-----------\n";
        cout << "       Enter 1 to create a car\n";
        cout << "       Enter 2 to view all car details\n";
        cout << "       Enter 3 to update insurance of a car\n";
        cout << "       Enter 4 to drop a to the service station\n";
        cout << "       Enter 5 to pick up a car from the service station\n";
        cout << "       Enter 6 to exit from the menu\n";
        cout << "       Enter your choice: ";
        bool iv_input = false;
        while (!iv_input)
        {
            cin >> choice;
            if (cin.fail())
            {
                integer_validator();
            }
            else
            {
                iv_input = true;
            }
        }
        cout << "\n";

        switch (choice)
        {
        case 1:
            // create a car
            {
                string car_company_name;
                string car_model;
                string year_of_purchase;
                string number_of_owners;
                string car_registration_number;
                int odometer_reading;
                string insurance_number;
                string insurance_expiry_date;
                string insurance_type;
                float insurance_amount;
                string chassis_number;
                string engine_number;
                cout << "\n\nEnter the name of the car: ";
                getline(cin >> ws, car_company_name);
                cout << "\nEnter the car model: ";
                getline(cin >> ws, car_model);
                cout << "\nEnter the year of purchase of the car: ";
                getline(cin >> ws, year_of_purchase);
                cout << "\nEnter the number of owners of the car: ";
                getline(cin >> ws, number_of_owners);

                // checking whether the registration number already exist
                bool exist = true;
                while (exist)
                {
                    cout << "\nEnter the registration number of the car: ";
                    getline(cin >> ws, car_registration_number);
                    if (car_dictionary.find(car_registration_number) == car_dictionary.end())
                    {
                        exist = false;
                    }
                    else
                    {
                        cout << "\nThis registration number is already exist. Try again\n";
                    }
                }

                // odometer reading
                {
                    bool v_cin = false;
                    while (!v_cin)
                    {
                        cout << "\nEnter the number of kilometers the car ran: ";
                        cin >> odometer_reading;
                        if (!cin.fail())
                        {
                            v_cin = true;
                        }
                        else
                        {
                            integer_validator();
                        }
                    }
                }

                // insurance number
                bool i_num_exist = true;
                while (i_num_exist)
                {

                    cout << "\nEnter the insurance number of the car: ";
                    cin >> insurance_number;

                    // checking isurance number already exists or not
                    bool ie = false;
                    for (auto x : car_dictionary)
                    {
                        if (insurance_number == x.second.get_insurance_number())
                        {
                            ie = true;
                        }
                    }
                    if (!ie)
                    {
                        i_num_exist = false;
                    }
                    else
                    {
                        cout << "\nThis insurance number is already exist. Try again\n";
                    }
                }
                bool is_valid_date = false;
                while (!is_valid_date)
                {
                    cout << "\nEnter the insurance expiry date of the car in the dd/mm/yyyy format: ";
                    getline(cin >> ws, insurance_expiry_date);
                    if (isDate(insurance_expiry_date))
                    {
                        is_valid_date = true;
                    }
                    else
                    {
                        cout << "\nEnter a valid date in the dd/mm/yyyy format\n";
                    }
                }
                cout << "\nEnter the insurance type of the car: ";
                getline(cin >> ws, insurance_type);
                {
                    bool v_cin = false;
                    while (!v_cin)
                    {
                        cout << "\nEnter the insurance amount of the car: ";
                        cin >> insurance_amount;
                        if (!cin.fail())
                        {
                            v_cin = true;
                        }
                        else
                        {
                            integer_validator();
                        }
                    }
                }
                cout << "\nEnter the chassis number of the car: ";
                getline(cin >> ws, chassis_number);
                cout << "\nEnter the engine number of the car: ";
                getline(cin >> ws, engine_number);

                // creating a car object
                Car c_obj(
                    car_company_name,
                    car_model,
                    year_of_purchase,
                    number_of_owners,
                    car_registration_number,
                    odometer_reading,
                    insurance_number,
                    insurance_expiry_date,
                    insurance_type,
                    insurance_amount,
                    chassis_number,
                    engine_number);

                // entry of the car details in the car dictionary
                car_dictionary.insert({car_registration_number, c_obj});
            }
            break;

        case 2:
            // print all cars
            {
                if (car_dictionary.size() == 0)
                {
                    cout << "\nNo car is register till now\n";
                    break;
                }
                cout << "\nAll the details of the of all the cars which are registered are as follows:\n";
                for (auto x : car_dictionary)
                {
                    cout << "\n------------------------------------\n";
                    cout << "\n        Car Name: " << x.second.get_car_company_name() << "\n";
                    cout << "\n        Car Model: " << x.second.get_car_model() << "\n";
                    cout << "\n        Year of Purchase: " << x.second.get_year_of_purchase() << "\n";
                    cout << "\n        Number of owners: " << x.second.get_number_of_owners() << "\n";
                    cout << "\n        Car Registration Number: " << x.second.get_car_registration_number() << "\n";
                    cout << "\n        Odometer Reading: " << x.second.get_odometer_reading() << "\n";
                    cout << "\n        Insurance Number: " << x.second.get_insurance_number() << "\n";
                    cout << "\n        Insurance Expiry Date: " << x.second.get_insurance_expiry_date() << "\n";
                    cout << "\n        Insurance Type: " << x.second.get_insurance_type() << "\n";
                    printf("\n        Insurance Type: %.2f\n", x.second.get_insurance_amount());
                    cout << "\n        Chassis Number: " << x.second.get_chassis_number() << "\n";
                    cout << "\n        Engine Number: " << x.second.get_engine_number() << "\n";

                    // last service data todo
                    if (x.second.get_last_service_data().size() != 0)
                    {
                        cout << "\n        The Service Details of the car are given below:\n";
                        for (auto v : x.second.get_last_service_data())
                        {
                            cout << "\n            ======================\n";
                            cout << "            \"Odo\": " << v.odo << ",\n";
                            cout << "            \"Issues\": [";
                            for (auto is : v.issues)
                            {
                                cout << "\"" << is << "\",";
                            }
                            cout << "]\n";
                            cout << "            \"Date\": " << v.s_date << ",\n";
                            printf("            \"Amount\": %.2f\n", v.amount);
                        }
                    }
                }
            }
            break;

        case 3:
            // update insurance
            {
                bool exist = false;
                string i_num;
                cout << "\nEnter the insurance number of the car: ";
                getline(cin >> ws, i_num);
                map<string, Car>::iterator x;
                string r_num;
                for (x = car_dictionary.begin(); x != car_dictionary.end(); x++)
                {
                    if (i_num == x->second.get_insurance_number())
                    {
                        r_num = x->first;
                        exist = true;
                    }
                }
                if (exist)
                {
                    bool is_valid_date = false;
                    string new_date;
                    while (!is_valid_date)
                    {
                        cout << "\nSet the new insurance expiry date: ";
                        getline(cin >> ws, new_date);
                        if (isDate(new_date))
                        {
                            is_valid_date = true;
                        }
                        else
                        {
                            cout << "\nEnter a valid date in the dd/mm/yyyy format\n";
                        }
                    }
                    if (!date_is_greater(new_date, car_dictionary[r_num].get_insurance_expiry_date()))
                    {
                        cout << "\nSorry the new date is less or same as the previous expiry date\n";
                    }
                    else
                    {
                        car_dictionary[r_num].set_insurance_expiry_date(new_date);
                        string i_type;
                        float i_amt;
                        cout << "\nSet the new insurance type: ";
                        getline(cin >> ws, i_type);
                        cout << "\nSet the new insurance premium amount: ";
                        cin >> i_amt;
                        car_dictionary[r_num].set_insurance_type(i_type);
                        car_dictionary[r_num].set_insurance_amount(i_amt);
                    }
                }
                else
                {
                    cout << "\nSorry the insurance number does not exist\n";
                }
            }
            break;

        case 4:
            // drop a car
            {
                string reg;
                cout << "\nEnter the registration number of the car: ";
                getline(cin >> ws, reg);
                if (car_dictionary.find(reg) == car_dictionary.end())
                {
                    cout << "\nSorry there is no car exist with that registration number.Try again\n";
                }
                else
                {
                    if (ss_obj.get_current_car_list().find(reg) != ss_obj.get_current_car_list().end())
                    {
                        cout << "\nSorry the car with the same registration number is already there in the service station\n";
                    }
                    else
                    {
                        ss_obj.add_car(reg, car_dictionary[reg].get_odometer_reading());
                    }
                }
            }
            break;

        case 5:
            // pick up a car
            {
                string reg;
                cout << "\nEnter the registration number of the car: ";
                getline(cin >> ws, reg);
                if (car_dictionary.find(reg) == car_dictionary.end())
                {
                    cout << "\nSorry there is no car exist with that registration number.Try again\n";
                }
                else
                {
                    if (ss_obj.get_current_car_list().find(reg) == ss_obj.get_current_car_list().end())
                    {
                        cout << "\nSorry the car is not in the service station\n";
                    }
                    else
                    {
                        Car new_obj;
                        new_obj = ss_obj.service_car(car_dictionary[reg], reg);
                        car_dictionary[reg] = new_obj;
                    }
                }
            }
            break;

        case 6:
            exit = true;
            break;

        default:
            cout << "\n INVALID INPUT\n";
        }
    }

    return 0;
}