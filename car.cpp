#include <bits/stdc++.h>
using namespace std;

// importing the last service data
#include "lastServiceData.cpp"

class Car
{
private:
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

    // last service data
    vector<LastServiceData> last_service_data;

public:
    // default constructor
    Car() {}
    // Intializing list constructor
    Car(string car_company_name,
        string car_model,
        string year_of_purchase,
        string number_of_owners,
        string car_registration_number,
        int odometer_reading,
        string insurance_number,
        string insurance_expiry_date,
        string insurance_type,
        float insurance_amount,
        string chassis_number,
        string engine_number) : car_company_name(car_company_name),
                                car_model(car_model),
                                year_of_purchase(year_of_purchase),
                                number_of_owners(number_of_owners),
                                car_registration_number(car_registration_number),
                                odometer_reading(odometer_reading),
                                insurance_number(insurance_number),
                                insurance_expiry_date(insurance_expiry_date),
                                insurance_type(insurance_type),
                                insurance_amount(insurance_amount),
                                chassis_number(chassis_number),
                                engine_number(engine_number) {}

    // parameterised constructor
    // Car(string car_company_name,
    //     string car_model,
    //     string year_of_purchase,
    //     int number_of_owners,
    //     int car_registration_number,
    //     int odometer_reading,
    //     int insurance_number,
    //     string insurance_expiry_date,
    //     string insurance_type,
    //     float insurance_amount,
    //     int chassis_number,
    //     int engine_number)
    // {
    //     this->car_company_name = car_company_name;
    //     this->car_model = car_model;
    //     this->year_of_purchase = year_of_purchase;
    //     this->number_of_owners = number_of_owners;
    //     this->car_registration_number = car_registration_number;
    //     this->odometer_reading = odometer_reading;
    //     this->insurance_number = insurance_number;
    //     this->insurance_expiry_date = insurance_expiry_date;
    //     this->insurance_type = insurance_type;
    //     this->insurance_amount = insurance_amount;
    //     this->chassis_number = chassis_number;
    //     this->engine_number = engine_number;
    // }

    // setters
    void set_car_company_name(string car_company_name)
    {
        this->car_company_name = car_company_name;
    }
    void set_car_model(string car_model)
    {
        this->car_model = car_model;
    }
    void set_year_of_purchase(string year_of_purchase)
    {
        this->year_of_purchase = year_of_purchase;
    }
    void set_number_of_owners(string number_of_owners)
    {
        this->number_of_owners = number_of_owners;
    }
    void set_car_registration_number(string car_registration_number)
    {
        this->car_registration_number = car_registration_number;
    }
    void set_odometer_reading(int odometer_reading)
    {
        this->odometer_reading = odometer_reading;
    }
    void set_insurance_number(string insurance_number)
    {
        this->insurance_number = insurance_number;
    }
    void set_insurance_expiry_date(string insurance_expiry_date)
    {
        this->insurance_expiry_date = insurance_expiry_date;
    }
    void set_insurance_type(string insurance_type)
    {
        this->insurance_type = insurance_type;
    }
    void set_insurance_amount(float insurance_amount)
    {
        this->insurance_amount = insurance_amount;
    }
    void set_chassis_number(string chassis_number)
    {
        this->chassis_number = chassis_number;
    }
    void set_engine_number(string engine_number)
    {
        this->engine_number = engine_number;
    }

    void set_last_service_data(vector<LastServiceData> new_data)
    {
        this->last_service_data = new_data;
    }

    // getters
    string get_car_company_name()
    {
        return this->car_company_name;
    }
    string get_car_model()
    {
        return this->car_model;
    }
    string get_year_of_purchase()
    {
        return this->year_of_purchase;
    }
    string get_number_of_owners()
    {
        return this->number_of_owners;
    }
    string get_car_registration_number()
    {
        return this->car_registration_number;
    }
    int get_odometer_reading()
    {
        return this->odometer_reading;
    }
    string get_insurance_number()
    {
        return this->insurance_number;
    }
    string get_insurance_expiry_date()
    {
        return this->insurance_expiry_date;
    }
    string get_insurance_type()
    {
        return this->insurance_type;
    }
    float get_insurance_amount()
    {
        return this->insurance_amount;
    }
    string get_chassis_number()
    {
        return this->chassis_number;
    }
    string get_engine_number()
    {
        return this->engine_number;
    }

    // getting the whole vector
    vector<LastServiceData> get_last_service_data()
    {
        return this->last_service_data;
    }
};