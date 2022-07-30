#ifndef CAR
#define CAR
#include <iostream>

using namespace std;

class car{
    private:
        string company, name, num_plate;
        float charges_per_hr;
    public:
        car():company(),name(),num_plate(), charges_per_hr(0){}
        void set_charges(float);
        float get_charges();
        string get_company();       
        string get_name();
        string get_plate();
        friend void DELETE_CAR(string);
        void  EDIT_CAR();
        friend ostream& operator<<(ostream&, car&);
        friend istream& operator>>(istream&, car&);
        friend class admin;
        car& select_car(int);
};

#endif