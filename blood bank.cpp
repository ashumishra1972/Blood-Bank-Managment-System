#include<iostream>
    #include<conio.h>
    #include<fstream>
    #include<stdio.h>
    #include<string.h>
    #include<process.h>

	class bank
	{
	int bano;
	char baname[500],bagroup[500];
	float baphone;
	int baage;
	int baquant;
public:
	 void add_data();
	 void read_data();
	 void mod_data();
	 void del_data();
	 void show_data();
	 };
void bank::add_data()
	 {
	 cout<<"Enter the sr no. of Donor:- "<<endl;
	 cin>>bano;
	 cout<<"Enter the Name of the Donor:- "<<endl;
	 gets(baname);
	 cout<<"Enter the Donor Blood group:- " <<endl;
	 gets(bagroup);
	 cout<<"Enter the Donor phone number:- "<<endl;
	 cin>>baphone;
	 cout<<"Enter the Donor age:- "<<endl;
	 cin>>baage;
	 cout<<"Enter the donor Blood Quantity denoted in grams       = "<<endl;       
	 cin>>baquant;
	 }
void bank::read_data()
	 {
	 cout<<bano<<endl;
	 cout<<baname<<endl;
	 cout<<bagroup<<endl;
	 cout<<baphone<<endl;
	 cout<<baage<<endl;
	 cout<<baquant<<endl;
	 }
void bank::show_data()
	 {
	 cout<<bano<<endl;
	 cout<<baname<<endl;
	 cout<<bagroup<<endl;
	 cout<<baphone<<endl;
	 cout<<baage<<endl;
	 cout<<baquant<<endl;
	 }
void bank::mod_data()
	 {
	 cout<<"Enter the sr no. of Donor:- "<<endl;
	 cin>>bano;
	 cout<<"Enter the Name of the Donor:- "<<endl;
	 gets(baname);
	 cout<<"Enter the Donor Blood group:- " <<endl;
	 gets(bagroup);
	 cout<<"Enter the Donor phone number:- "<<endl;
	 cin>>baphone;
	 cout<<"Enter the Donor age:- "<<endl;
	 cin>>baage;
	 cout<<"Enter the donor Blood Quantity denoted in grams = "<<endl;
	 cin>>baquant;
	 }
void main()
	 {
	 clrscr();
	 bank ba;
	 fstream bafile;
	 bafile.open("BLOOD BANK.DAT",ios::in|ios::out|ios::binary);
	 if(!bafile)
	 {
	 cout<<"CAN NOT OPEN THE FILE"<<endl;
	 }
	 int ch;
	 int rec_no=0,pos=0;
	 char ans='y';
	 char opt;
	 do
	 {
	 cout<<"*************WELCOME TO BLOOD BANK**************"<<endl;
	 cout<<"             MAIN MENU                 "<<endl;
	 cout<<"1.ADD RECORD"<<endl;
	 cout<<"2.READ RECORD"<<endl;
	 cout<<"3.MODIFY RECORD"<<endl;
	 cout<<"4.EXIT"<<endl<<endl;
	 cout<<"ENTER YOUR CHOICE"<<endl;
	 cin>>ch;
	 switch(ch)
	 {
	 case 1:  {
				 char opt='y';
				 clrscr();
				 cout<<"DONOR DATA ENTRY"<<endl;
				 do
				 {
				 ba.add_data();
				 bafile.write((char*)&ba,sizeof(ba));
				 cout<<"do you want to continue........"<<endl;
				 cin>>ans;
				 }while(opt=='y');  }
				 break;
	 case 2:   {
				 cout<<"THE OUTPUT OF BLOODBANK.DAT FILE IS...."<<endl;
				  bafile.read((char*)&ba,sizeof(ba));
				  while(bafile)
				  {
				  ba.read_data();
				 bafile.read((char*)&ba,sizeof(ba));
				  }
				  }
				  break;
	 case 3: { 	cout<<"enter the record number to be modify";
					cin>>rec_no;
	 pos=(rec_no-1)*sizeof(ba);
	 cout<<"pos is"<<pos;
	bafile.seekg(pos,ios::beg);
		int k=bafile.tellg();
		cout<<"k is"<<k;
	bafile.read((char*)&ba,sizeof(ba));
		cout<<"MODIFY THIS RECORD";
		cin>>opt;
		if(opt=='y')
		{
		cout<<"ENTER THE NEW DATA"<<endl;
		ba.mod_data();
		bafile.seekp(pos,ios::beg);
	bafile.write((char*)&ba,sizeof(ba));
		cout<<"RECORD MODIFIED";
		cout<<"PRESS ANY KEY TO CONTINUE";
		getch();
		}
		}
		break;
		case 4: 		break;
		  }
			 }while((ch>=1)&&(ch<=3));
		}

