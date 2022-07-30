#include"account.hpp"

bool account::compare_id(string uname){
    if(uname == this->username){
        return true;
    }
    else{
        return false;
    }
}

bool account::compare_password(string pword){
    if(pword == this->password){
        return true;
    }
    else{
        return false;
    }
}
string account::get_username(){
    return username;
}