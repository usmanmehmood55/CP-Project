/*
 * CPProject.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: Usman
 */

#include <iostream>
#include <fstream>
using namespace std;
void add()
{
	cout<<"Add a new record."<<endl;
	cout<<"Please enter the following data about the student: "<<endl;

	//Name
	string name[2];
	cout<<"First name:\t"<<endl;	cin>>name[0];
	cout<<"Last name:\t"<<endl;		cin>>name[1];
	cout<<endl;

	//Date of birth.
	int dob[3];
	cout<<"Date of birth:-"<<endl;
	cout<<"Date:\t"<<endl;		cin>>dob[0];
	cout<<"Month:\t"<<endl;		cin>>dob[1];
	cout<<"Year:\t"<<endl;		cin>>dob[2];
	cout<<endl;

	//Age.
	int age;
	age=(2017*12-((dob[2]*12)+dob[1]))/12;

	//Address.
	string address[4];
	cout<<"Address:-"<<endl;
	cout<<"City:\t"<<endl;		cin>>address[0];
	cout<<"Colony:\t"<<endl;		cin>>address[1];
	cout<<"Street:\t"<<endl;		cin>>address[2];
	cout<<"House:\t"<<endl;		cin>>address[3];
	cout<<endl;

	//Courses.
	cout<<"Enter number of courses: "; int coursenum; cin>>coursenum;
	string course[coursenum], grade[coursenum]; int marks[coursenum];
	for (int temp1;temp1<coursenum;temp1++)
	{
		cout<<"Enter name of course "<<temp1+1<<":\t"<<endl;	cin>>course[temp1];
		cout<<"Enter marks in that course.\t"<<endl;			cin>>marks[temp1];
		if (marks[temp1] <= 100 && marks[temp1] >= 80)
		{
			grade [temp1] = 'A';
		} else if  (marks[temp1] <= 79 && marks[temp1] >= 60)
		{
			grade [temp1] = 'B';
		} else if (marks[temp1] <= 59 && marks[temp1] >= 50)
		{
			grade [temp1] = 'C';
		} else if (marks[temp1] <= 49 && marks[temp1] >= 40)
		{
			grade [temp1] = 'D';
		} else if (marks[temp1] <= 39)
		{
			grade [temp1] = 'F';
		}
	}



	ofstream database;
	database.open ("database.txt");
	database <<name[0]<<endl<<name[1]<<endl<<dob[0]<<endl;
	database <<dob[1]<<endl<<dob[2]<<endl<<age<<endl<<address[0];
	database <<endl<<address[1]<<endl<<address[2]<<endl<<address[3];
	for (int temp2=0;temp2<coursenum;temp2++)
	{
		database <<course[temp2]<<endl<<grade[temp2]<<endl;
	}
	database.close();
}


void display()
{
	string name[2];
	int dob[3];
	int age;
	string address[4];
	string line;

	ifstream databasein ("database.txt");
	if (databasein.is_open())
	{ while( databasein>>name[0]>>name[1]>>dob[0]>>dob[1]>>dob[2]>>age>>address[0]>>address[1]>>address[2]>>address[3] )
		databasein.close();
	} else
	{
		cout << "Unable to open file";
	}

	//Name
	cout<<"Name:-"<<endl<<name[0]<<" "<<name[1]<<endl<<endl;
	//Date of birth
	cout<<"Date of birth:-"<<endl;
	cout<<dob[0]<<" - "<<dob[1]<<" - "<<dob[2]<<endl<<endl;
	//Age
	cout<<"Age:- "<<endl<<age<<endl<<endl;
	//Address
	cout<<"Address:-"<<endl;
	cout<<"House "<<address[3]<<", "<<"Street "<<address[2]<<", "<<address[1]<<" Colony"<<", "<<address[0]<<endl<<endl;
/*	for (int temp2=0;temp2<coursenum;temp2++)
	{
		cout<<"Your grade in "<<course[temp2]<<" is "<<grade[temp2]<<endl;
	} */


}


int main()
{
	cout<<"Welcome to student management system."<<endl;
	cout<<"Please enter:\n1 to add a record,\n2 to display/search a record,";
	cout<<"\n3 to edit a record and \n4 to delete a record"<<endl;
	int menu; cin>>menu;
	switch (menu)
	{
	case 1:
		add();
		break;
	case 2:
		display();
		break;
	}

}
