#include "user.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void user::set_id_password(){
    string cnic, pswrd, temp;
        system("cls");
        cout<<"\nEnter your cnic number: ";
        fflush(stdin);
        do{
            getline(cin,cnic);
        }while(cnic.length() != 13);
    do{
        cout<<"\nCreate you password: ";
        fflush(stdin);
        getline(cin,pswrd);
        cout<<"Re-Enter the password: ";
        fflush(stdin);
        getline(cin,temp);
    }while(pswrd != temp);

    this->username = cnic;
    this->password = pswrd;
}
bool user::check(string check_string){
    ifstream in("User Details.txt",ios::in | ios::binary);
    user temp;
    bool flag = true;
    in.seekg(ios::beg);
    while( in.read((char*)&temp,sizeof(user))){
        if(temp.username == check_string){
            flag = false;
        }
    }
    return flag;
}
void user::set_details(string n, string p, string r){
    name = n;
    phone_no = p;
    residential_address = r;    
}
void user::set_hours(float h){
    hours_rented = h;
}
void user::calculate_balance(){
    balance = rented_car->get_charges() * hours_rented;
}
void user::ADD_USER(){
    ofstream out("User details.txt",ios::app |ios::binary);
    out.seekp(ios::end);

    out.write((char*)this,sizeof(user));
    out.close();
}


void user::DELETE_USER(string cnic){
    system("cls");
    int flag = 0;
    ifstream in("User Details.txt",ios::in|ios::binary);   
    ofstream out("TEMP.txt",ios::out|ios::binary);
    in.seekg(ios::beg);
    out.seekp(ios::beg);
    while( in.read((char*)this,sizeof(user))){
        if(compare_id(cnic)){
            flag++;
        }
        else{
            out.write((char*)this,sizeof(user));
        }
    }
    in.close();    out.close();
    remove("User Details.txt");
    rename("TEMP.txt","User Details.txt");
    if(!flag){
        cout<<"\n\t\t\tCnic number not in records!"<<endl;
       system("pause");
    }
    else{
        cout<<"\n\t\tTHE USER HAS BEEN REMOVED\t"; 
        system("pause");
    }
}
ostream& operator<<(ostream& out, user& obj){
    out <<"\nName: "<<obj.name
        <<"\tCNIC: "<<obj.username
        <<"\nAddress: "<<obj.residential_address
        <<"\nRented Car: "<<obj.rented_car->get_company()<<" "
        <<obj.rented_car->get_name()<<" ("<<obj.rented_car->get_plate()<<endl;
        return out;
}
void user::rent_car(car& temp){        
    *rented_car = temp;
}

bool user::LOGIN(){
    ifstream in("User Details.txt",ios::in|ios::binary);
    in.seekg(ios::beg);
    string cnic, pswrd;
    do{
        system("cls");
        cout<<"Enter your cnic number: ";
        fflush(stdin);
        getline(cin,cnic);
    }while(cnic.length() != 13);
    cout<<"Enter your password: ";
    fflush(stdin);
    getline(cin,pswrd);
    while(in.read((char*)this,sizeof(user))){
        if(compare_id(cnic)){
            if(compare_password(pswrd)){
                return true;
            }
            else{
                cout<<"Wrong password!!! Try again";
                system("pause");
                return false;
            }
        }
    }
    cout<<"CNIC number does not exist in record!!!"<<endl;
    system("pause");
    return false;
}