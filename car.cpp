#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "car.hpp"

using namespace std;

void car::set_charges(float ch){
    charges_per_hr = ch;
}
float car::get_charges(){
    return charges_per_hr;
}
string car::get_company(){
    return company;
}
string car::get_name(){
    return name;
}
string car::get_plate(){
    return num_plate;
}

void car::EDIT_CAR(){
    system("cls");
    float new_charges;
    string car_name;
    car temp;
    int k=0;
    
    cout<<"Enter car name to edit it charges: ";
    fflush(stdin);
    getline(cin, car_name);
    
    cout<<"Enter new charges for the car: ";
    cin>>new_charges;
    
    fstream file("Garage.txt", ios::in| ios::out| ios::ate| ios::binary); 
    file.seekg(ios::beg);
    
    while(file.read((char*)&temp,sizeof(car))){
        if(temp.name == car_name){
            temp.set_charges(new_charges);
            file.seekp(-sizeof(car),ios::cur);
            file.write((char*)&temp,sizeof(car));
            k++;
        }
    }
    file.close();

    if(k!=0)
    cout<<"New Charges was set successfully"<<endl;
    else
    cout<<"Car was not found"<<endl;
        
}

void DELETE_CAR(string nplate){
    system("cls");  
    int flag=0; 
    car temp;
    ifstream in("Garage.txt",ios::in|ios::binary);   
    ofstream out("TEMP.txt",ios::out|ios::binary);

    while( in.read((char*)&temp,sizeof(car))){
        if(temp.num_plate == nplate){
            flag++;   
        }
        else{
            out.write((char*)&temp,sizeof(car));
        }
    }
    in.close();    out.close();
    remove("Garage.txt");
    rename("TEMP.txt","Garage.txt");
    if(!flag){
        cout<<"\n\t\t\tCAR WAS NOT FOUND!"<<endl;
    }
    else{
        cout<<"\n\t\tTHE CAR HAS BEEN REMOVED\t"; 
        system("pause");
    }
}



ostream& operator<<(ostream& out, car& obj){
    out<<obj.company<<" "<<obj.name<<" ("<<obj.num_plate<<") Rs. "<<obj.charges_per_hr<<endl;   
    return out;
}

istream& operator>>(istream& in, car& obj){
    cout<<"Enter company: ";
    in>>obj.company;
    cout<<"Enter car name: ";
    in>>obj.name;
    cout<<"Enter car's number plate: ";
    in>>obj.num_plate;
    cout<<"Enter hourly charges of car: ";
    in>>obj.charges_per_hr;
    return in;
}

car& car::select_car(int n){
    ifstream in("Garage.txt",ios::binary);
    car temp;
    in.seekg(sizeof(car)*n-sizeof(car),ios::beg);
    in.read((char*)&temp,sizeof(car)); 
    return temp;
}