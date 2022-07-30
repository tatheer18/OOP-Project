#ifndef USER
#define USER
#include "account.hpp"
#include "car.hpp"

using namespace std;

class user : public account{
	private:
        string name, phone_no, residential_address;
        car *rented_car;
        float balance, hours_rented;
    public:
        user():name(),phone_no(),residential_address(),balance(0),hours_rented(0),account(){
            rented_car = new car;
        }
        bool LOGIN() override;
        void set_id_password() override;
        bool check(string) override;
        void set_details(string, string, string);
        void set_hours(float h);
        void calculate_balance();
        void ADD_USER();
        void rent_car(car&);
        void DELETE_USER(string);
        friend ostream& operator<<(ostream&, user&);
        friend class admin;
};

#endif