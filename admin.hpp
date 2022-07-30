#ifndef ADMIN
#define ADMIN
#include "account.hpp"
#include"car.hpp"

using namespace std;

class admin: public account{
    public:
        admin():account(){}
        void set_id_password() override;
        bool check(string) override;
        bool LOGIN() override;
        void view_Garage();
        void view_bookedcars();
        void view_allcars();
        void view_active_users();
        void search_user();
        void ADD_ADMIN();
        friend void DELETE_ADMIN();
        void ADD_CAR(car&);
};

#endif