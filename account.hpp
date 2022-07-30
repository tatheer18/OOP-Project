#ifndef ACC
#define ACC
#include<iostream>

using namespace std;

class account{
    protected:
        string username, password;
    public:
        account():username("\0"),password("\0"){}
        void virtual set_id_password()=0;
        bool virtual check(string)=0;
        bool virtual LOGIN()=0;
        bool compare_id(string);
        bool compare_password(string); 
        string get_username();
};

#endif