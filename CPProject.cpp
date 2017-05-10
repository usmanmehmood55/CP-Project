/*
 * CPProject.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: Usman
 */

#include <iostream>
#include <fstream>
#include <sstream> //Only used for converting int to string.
#include <stdio.h> //For removing files.
using namespace std;
void add(int rollnum)
{
	cout<<"Add a new record."<<endl;
	cout<<"Student's roll number: "<<rollnum<<endl;
	cout<<"Please enter the following data about the student: "<<endl;

	//Name
	string name[2];
	cout<<"First name:\t"<<endl;	cin>>name[0];
	cout<<"Last name:\t"<<endl;		cin>>name[1];
	cout<<endl;

	//Date of birth.
	int dob[3];
	cout<<"Date of birth:-"<<endl;
	dateofbirth: //Program will be redirected here to re-enter values through goto.
	cout<<"Date:\t"<<endl;		cin>>dob[0];
	cout<<"Month:\t"<<endl;		cin>>dob[1];
	cout<<"Year:\t"<<endl;		cin>>dob[2];
	cout<<endl;

	if ( dob[0]<0 || dob[0]>32 || dob[1]<0 || dob[1]>13 || dob[2]<0 )
	{
		cout<<"Please enter valid values."<<endl;
		goto dateofbirth; //Will redirect to "dateofbirth" label.
	}

	//Age.
	int age;
	age=(2017*12-((dob[2]*12)+dob[1]))/12; //Only accurate for months.

	//Address.
	string address[4];
	cout<<"Address:-"<<endl;
	cout<<"City:\t"<<endl;		cin>>address[0];
	cout<<"Colony:\t"<<endl;		cin>>address[1];
	cout<<"Street:\t"<<endl;		cin>>address[2];
	cout<<"House:\t"<<endl;		cin>>address[3];
	cout<<endl;

	//Courses.
	Course: //Program will be redirected here to re-enter values through goto.
	cout<<"Enter number of courses: "; int coursenum; cin>>coursenum;
	string course[coursenum], grade[coursenum]; int marks[coursenum];
	if ( coursenum <= 10 && coursenum > 0 )
	{

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
	} else
	{
		cout<<"Number of courses must be equal to or less than 10 and greater than 0."<<endl;
		goto Course; //Will redirect to "Course" label.
	}


	cout<<"Making a file for roll number "<<rollnum<<endl;

	//Making a file and writing to it.
	int number=rollnum;
	string rolli;
	stringstream convert;
	convert << number;
	rolli = convert.str();
    rolli += ".txt"; // important to create .txt file.
    ofstream database;
    database.open(rolli.c_str());

	int temp2;
	database <<name[0]<<endl<<name[1]<<endl<<dob[0]<<endl<<dob[1];
	database <<endl<<dob[2]<<endl<<age<<endl<<address[0]<<endl<<address[1];
	database <<endl<<address[2]<<endl<<address[3]<<endl<<coursenum<<endl;
	for (temp2=0; temp2<coursenum; temp2++)
	{
		database <<course[temp2]<<endl<<grade[temp2]<<endl;
	}
	database.close();

	cout<<"File created."<<endl;
}


void display()
{
	string name[2];
	int dob[3];
	int age;
	int coursenum;
	string address[4];
	string course[10], grade[10];


	//Reading from the database file.
	cout<<"Enter roll number."<<endl;
	string rollnum; cin>>rollnum;
    rollnum += ".txt";

	ifstream database (rollnum.c_str());
	if (database)
	{
		while( database>>name[0]>>name[1]>>dob[0]>>dob[1]>>dob[2]>>
				age>>address[0]>>address[1]>>address[2]>>address[3]>>coursenum
				>>course[0]>>grade[0]>>course[1]>>grade[1]
				>>course[2]>>grade[2]>>course[3]>>grade[3]
				>>course[4]>>grade[4]>>course[5]>>grade[5]
				>>course[6]>>grade[6]>>course[7]>>grade[7]
				>>course[8]>>grade[8]>>course[9]>>grade[9] )
		database.close();
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
	for (int temp2=0;temp2<coursenum;temp2++)
	{
		cout<<"Your grade in "<<course[temp2]<<" is "<<grade[temp2]<<endl;
	}


}

//This part manages roll numbers.
void roll()
{
	int rollnum;
	ifstream roll("roll.txt");
	if (roll)
	{
		ifstream roll ("roll.txt");
		while( roll>>rollnum )
		{
			rollnum++;
			ofstream roll;
			roll.open ("roll.txt");
			roll<<rollnum;
		}
		roll.close();
		add(rollnum);

	} else
	{
		ofstream roll;
		roll.open ("roll.txt");
		rollnum=1;
		roll <<rollnum;
		roll.close();
		add(rollnum);
	}
}



void edit()
{
	cout<<"Please enter the roll number of student: ";
	string rollnum; cin>>rollnum;
	rollnum += ".txt";
	remove(rollnum.c_str( )); //Removing previous file
	cout<<"Please enter new data about the student: "<<endl;


	//Name
	string name[2];
	cout<<"First name:\t"<<endl;	cin>>name[0];
	cout<<"Last name:\t"<<endl;		cin>>name[1];
	cout<<endl;

	//Date of birth.
	int dob[3];
	cout<<"Date of birth:-"<<endl;
	dateofbirth: //Program will be redirected here to re-enter values through goto.
	cout<<"Date:\t"<<endl;		cin>>dob[0];
	cout<<"Month:\t"<<endl;		cin>>dob[1];
	cout<<"Year:\t"<<endl;		cin>>dob[2];
	cout<<endl;

	if ( dob[0]<0 || dob[0]>32 || dob[1]<0 || dob[1]>13 || dob[2]<0 )
	{
		cout<<"Please enter valid values."<<endl;
		goto dateofbirth; //Will redirect to "dateofbirth" label.
	}

	//Age.
	int age;
	age=(2017*12-((dob[2]*12)+dob[1]))/12; //Only accurate for months.

	//Address.
	string address[4];
	cout<<"Address:-"<<endl;
	cout<<"City:\t"<<endl;		cin>>address[0];
	cout<<"Colony:\t"<<endl;		cin>>address[1];
	cout<<"Street:\t"<<endl;		cin>>address[2];
	cout<<"House:\t"<<endl;		cin>>address[3];
	cout<<endl;

	//Courses.
	Course: //Program will be redirected here to re-enter values through goto.
	cout<<"Enter number of courses: "; int coursenum; cin>>coursenum;
	string course[coursenum], grade[coursenum]; int marks[coursenum];
	if ( coursenum <= 10 && coursenum > 0 )
	{

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
	} else
	{
		cout<<"Number of courses must be equal to or less than 10 and greater than 0."<<endl;
		goto Course; //Will redirect to "Course" label.
	}


	cout<<"Editing the file of the student."<<endl;
    ofstream database;
    database.open(rollnum.c_str( ));

	int temp2;
	database <<name[0]<<endl<<name[1]<<endl<<dob[0]<<endl<<dob[1];
	database <<endl<<dob[2]<<endl<<age<<endl<<address[0]<<endl<<address[1];
	database <<endl<<address[2]<<endl<<address[3]<<endl;
	for (temp2=0; temp2<coursenum; temp2++)
	{
		database <<course[temp2]<<endl<<grade[temp2]<<endl;
	}
	database.close();
	cout<<"File edited."<<endl;

}



void removeit()
{
	cout<<"Enter roll number: ";
	string rollnum; cin>>rollnum;
	rollnum += ".txt";
	remove(rollnum.c_str( ));
	cout<<"Student's record has been deleted."<<endl;
}



void menu()
{
	//Main menu.
	cout<<endl;
	cout<<"Please enter:\n1 to add a record,\n2 to display/search a record,";
	cout<<"\n3 to edit a record and \n4 to delete a record"<<endl;
	int menu; cin>>menu;
	switch (menu)
	{
	case 1:
		cout<<endl;
		roll();
		break;
	case 2:
		display();
		break;
	case 3:
		edit();
		break;
	case 4:
		removeit();
		break;
	}
}


int main()
{
	cout<<"Welcome to student management system."<<endl;
	MENU:	//This is the menu label, the goto statement redirects here.
	menu();
	cout<<"Press 1 to go to menu, press 2 to exit."<<endl;
	int temp; cin>>temp;
	switch (temp)
	{
	case 1:
		goto MENU;	//This will redirect to "MENU" label.
		break;
	case 2:
		break;

	}
	cout<<"Exiting";
	return 0;
}
