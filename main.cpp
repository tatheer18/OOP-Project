#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include"account.hpp"
#include"car.hpp"
#include"admin.hpp"
#include"user.hpp"
#include<string.h>
#include<string>

using namespace std;

int main()
{
	admin A;
	user U;
	car C;
	char choice;
	
	while(1){
		system("cls");
		int i;
		cout<<"\n\n";
	
		cout<<"Enter your choice:\n1. Login as Admin \n2. Login as Customer\n3. Signup as Customer \n4. Quit Program\nEnter choice: ";
		
		switch(getche()){
			case '1':{
				system("cls");
				
				if(A.LOGIN()){
					system("cls");
					cout<<"****** STAFF CORNER ******";
					cout<<"\n1. View Available Cars \n2. View BOOKED Cars  \n3. View All Cars  \n4. View Active USERS  \n5. Search A USER  \n6. ADD a car  \n7. Delete a USER \n8.ADD new Admin \n9. Change Rates of Car"<<endl;
					switch(getche())
					{
						case '1':{
							system("cls");
							A.view_Garage();
							break;
						}
						
						case '2':{
							system("cls");
							A.view_bookedcars();
							break;
						}
						
						case '3':{
							system("cls");
							A.view_allcars();
							break;
						}
						
						case '4':{
							system("cls");
							A.view_active_users();
							break;
						}
						
						case '5':{
							system("cls");
							A.search_user();
							break;
						}
						
						case '6':{
							system("cls");
							cin>>C;
							A.ADD_CAR(C);
							system("cls");
							cout<<"Car has been ADDED Successfully"<<endl;
							system("pause");
							break;
						}

						case '7':{
							system("cls");
							string temp;
							cout<<"Enter The cnic of the user:";
        						fflush(stdin);
        						getline(cin,temp);
								U.DELETE_USER(temp);	 
								break;
						}
						
						case '8':{
						system("cls");
						A.set_id_password();
						A.ADD_ADMIN();
						break;			
						}

						case '9': {
							system("cls");
							C.EDIT_CAR();
							break;
						}
					}

				}
				break;
}			
			case '2':{
				if(U.LOGIN()){
					system("cls");
					cout<<"******Customer CORNER******"<<endl;
					cout<<"1. View My Account \n2. RENT a CAR \n3. Return a CAR "<<endl;
					
					switch(getche()){
						system("cls");
						case '1':{
							cout<<U;
							system("pause");
							break;
						}
						
						case '2':{
							HI:
							system("cls");
							car C2;
							int n=0;char carmodel;
							cout<<"Following are the available CARS:"<<endl;
							A.view_Garage();

							cout<<"Enter the serial no. of the CAR you wanted: "<<endl;
							cin>>n;
							U.rent_car(C.select_car(n));
							U.ADD_USER();
							C.DELETE_CAR();
							system("cls"); 
							cout<<"Your CAR has been booked"<<endl<<"*****Thank YOU*****";
							 system("pause");
							 break;
						}
						case '3':{
							system("cls");
							car c2;
							cin>>c2;

							A.ADD_CAR(c2);
							system("cls");
							cout<<"Car Has Successfully returned";
							system("pause");
							break;
						}
					}
				}
				break;
			}
			case '3':{
				system("cls");
				string x, y ,z;
				int n;
				U.set_id_password();
				
				system("cls");
				cout<<"Enter your name :"<<endl;
		        getline(cin,x);						

        		do{
					cout<<"Enter your phone number: ";
					fflush(stdin);
					getline(cin,y);
			    }while(y.length() != 11);				
				
				cout<<"Enter your Residential Details :"<<endl;
				getline(cin , z);
			
				U.set_details(x,y,z);
				system("cls");
				U.ADD_USER();
				cout<<"Your account has been created Successfully"<<endl;
				system("pause");
				
				goto HI;
				break;

			}

			case '4':{
				return 0;
				break;
			}

		}
	}
}