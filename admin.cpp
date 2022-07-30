#include "admin.hpp"
#include "car.hpp"
#include "user.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

void admin::set_id_password(){
    string cnic, pswrd, temp;
        system("cls");
        cout<<"Enter your cnic number: ";
        fflush(stdin);
        do{
            getline(cin,cnic);
        }while(cnic.length() != 13);
    do{
        cout<<"\nCreat your password: ";
        fflush(stdin);
        getline(cin,pswrd);
        cout<<"Re-Enter the password: ";
        fflush(stdin);
        getline(cin,temp);
    }while(pswrd != temp);
    username = cnic;
    password = pswrd;

}

bool admin::check(string check_string){
    ifstream in("Admin Detials.txt",ios::binary);
    admin temp;
    bool flag = true;
    while( in.read((char*)&temp,sizeof(admin))){
        if(temp.username == check_string){
            flag = false;
        }
    }
    return flag;
}

void admin::view_Garage(){
    ifstream in("Garage.txt",ios::binary);
    car temp;
    in.seekg(ios::beg);
    while(in.read((char*)&temp,sizeof(car))){
        cout<<temp<<endl;
    }
    system("pause");
    in.close();
}
void admin::view_bookedcars(){
    ifstream in("User Details.txt",ios::binary);
    user temp;
    in.seekg(ios::beg);
    while(in.read((char*)&temp,sizeof(user))){
        cout<<*temp.rented_car;
    }
    system("pause");
    in.close();
}

void admin::view_allcars(){
    ifstream in("User Details.txt",ios::binary);
    user temp_user;
    in.seekg(ios::beg);
    while(in.read((char*)&temp_user,sizeof(user))){
        cout<<*temp_user.rented_car;
    }
    in.close();

    in.open("Garage.txt",ios::binary);
    car temp_car;
    in.seekg(ios::beg);
    while(in.read((char*)&temp_car,sizeof(car))){
        cout<<temp_car;
    }
    system("pause");
    in.close();
}
void admin::view_active_users(){
    ifstream in("User Details.txt",ios::binary);
    user temp;
    in.seekg(ios::beg);
    while(in.read((char*)&temp,sizeof(user))){
        cout<<temp<<endl;
    }
    in.close();
}
void admin::search_user(){
    ifstream in("User Details.txt",ios::binary);
    user temp;
    string to_search;
    int flag = 0;

    cout<<"Enter customer's cnic number to search: ";
    fflush(stdin);
        do{
            getline(cin,to_search);
        }while(to_search.length() != 13);

    in.seekg(ios::beg);
    while(in.read((char*)&temp,sizeof(user))){
        if(temp.compare_id(to_search)){
            cout<<temp<<endl;
            flag = 1;
        }
    }
    if(!flag){
        cout<<"User was not found with the cnic number entered!!!"<<endl;
    }
    system("pause");
    in.close();
}
void ADD_CAR(car& obj){
    ofstream out("Garage.txt",ios::app);
    out.seekp(ios::end);
    
    out.write((char*)&obj,sizeof(car));
    out.close();
}
void admin::ADD_ADMIN(){
    ofstream out("Admin details.txt",ios::app |ios::binary);
    out.seekp(ios::end);

    out.write((char*)this,sizeof(admin));
    out.close();
}

void DELETE_ADMIN(string cnic){
    system("cls");      
    admin temp;
    int flag = 0;
    ifstream in("Admin Details.txt",ios::in|ios::binary);   
    ofstream out("TEMP.txt",ios::out|ios::binary);

    while( in.read((char*)&temp,sizeof(admin))){
        if(temp.compare_id(cnic)){
            flag++;
        }
        else{
            out.write((char*)&temp,sizeof(admin));
        }
    }
    in.close();    out.close();
    remove("Admin Details.txt");
    rename("TEMP.txt","Admin Details.txt");
    if(!flag){
        cout<<"\n\t\t\tCnic number not in records!"<<endl;
    }
    else{
        cout<<"\n\t\tTHE ADMIN HAS BEEN REMOVED\t"; 
        system("pause");
    }
}

bool admin::LOGIN(){
    ifstream in("Admin Details.txt",ios::in|ios::binary);
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
    while(in.read((char*)this,sizeof(admin))){
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
void admin::ADD_CAR(car& obj){
    ofstream out("Garage.txt",ios::app);
    out.seekp(ios::end);
    
    out.write((char*)&obj,sizeof(car));
    out.close();
}