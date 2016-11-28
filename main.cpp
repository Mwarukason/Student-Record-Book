//*******Headers for handling function inside the Program
#include<fstream>//handle files system
#include<iostream>//handle inputs/outputs
#include<conio.h>//Handle getch()function
#include<process.h>//header for handling
#include<string>//For handling string
#include<ctype.h>//for handling individual characters
#include<vector>//Library for handling Vector.
#include<time.h>//Library for handling Time function
#include<windows.h>//hand for color, and system("CLS");

using namespace std;
//function for changing color of the Command Prompt.
const int ScreenColor = system( "color 4B" );

class StudentInf//Class of student Information
{
private: //Private member
	char StudName[80];
	char ID[15];
	char Course[30];
	char Faculty[30];
	char Year[10];
	float _marks;

public://*****Public Functions****
	void input();
	void show();
	void ReadP();
	long byteNum(int recNum);

    //********To return The private Member to be used by
    //the Public functions*****************************
    char *getST(){return StudName;}
    char *getID(){return ID;}
    char *getCZ(){return Course;}
    char *getFC(){return Faculty;}
    char *getYr(){return Year;}

    char *getn(){return StudName;}

};StudentInf StudObj;//fileobj; //Initilize the Object Of The file

void StudentInf::input()//To input values in the file
{   endl(cout);
	cout<<"\t\t\tEnter Student Name: ";
	cin>>StudName;
	endl(cout);
	cout<<"\t\t\tEnter Student ID: ";
	cin >>ID;
	endl(cout);
	cout<<"\t\t\tEnter Student Course: ";
	cin>>Course;
	endl(cout);
	cout<<"\t\t\tEnter Student Faculty: ";
	cin>>Faculty;
	endl(cout);
	cout<<"\t\t\tEnter Student Year: ";
	cin>>Year;
	endl(cout);
}
void StudentInf::show()//Show the value inserted in the file
{   endl(cout);
    cout << "\t\t\tSTUDENT ADDED IN THE FILE: \n\n";
    cout << "\t\t\tStudent Name: " << StudName <<endl;
    cout << "\t\t\tStudent ID: " << ID <<endl;
    cout << "\t\t\tStudent COURSE: " << Course <<endl;
    cout << "\t\t\tStudent Faculty: " << Faculty <<endl;
    cout << "\t\t\tStudent Year Of Study: " <<Year <<endl;
    endl(cout);
    cout<< "\t\t\t-------------------------------------"<<endl;
}

//*******Function Prototyping*********
void CreateStudentFile();
void AddAnotherStudent();
void CGPA_CalculatorC();
void CGPA_CalculatorB();
void SwitchStatement();
void DisplayAllStudent();
void Disp_Partcu_Stud();
void Edit_Stud_Record();
void DeleteStudRec();
void Time();
void GoodBye();
void SayJambo();
void DisplayMenu();
void Programmers();

long byteNum(int);


fstream myfile; //Global FileName
int main()//main method
{
    //SayJambo();
    DisplayMenu();
	system("PAUSE");
	return 0;
}

void DisplayMenu()//Display menu function
{

 while(1)
	{
      system("CLS");
      cout << "\n\t\t |****************************************|";
      Time();
      cout << "\n\t\t |****************************************|";
      cout << "\n\t\t |                                        |";
      cout << "\n\t\t |      STUDENT INFORMATION CENTRE        |";
      cout << "\n\t\t |              2014/2015                 |";
      cout << "\n\t\t |                                        |";
      cout << "\n\t\t |**************MENU**********************|";
      cout << "\n\t\t |                                        |";
      cout << "\n\t\t |    [1] Create Student Data File:       |";
      cout << "\n\t\t |    [2] Add New Student Record in File  |";
      cout << "\n\t\t |    [3] Display All Records in File     |";
      cout << "\n\t\t |    [4] Search Particular Record        |";
      cout << "\n\t\t |    [5] Edit Particular Record          |";
      cout << "\n\t\t |    [6] Delete Particular Record in File|";
      cout << "\n\t\t |    [7] CGPA Calculator(Beginners)      |";
      cout << "\n\t\t |    [8] CGPA Calculator (Continue)      |";
      cout << "\n\t\t |    [9] Names of Programmers            |";
      cout << "\n\t\t |    [10]Exit From the Program           |";
      cout << "\n\t\t |                                        |";
      cout << "\n\t\t ******************************************";

      cout << "\n\t\t\tEnter ur choice: ";
      SwitchStatement();
    }
}

void SwitchStatement()//switch statement function
{

        int opt;
        cin>>opt;
        endl(cout);
		switch(opt)
		{
			case 1:
			{
				CreateStudentFile();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 2:
			{
				AddAnotherStudent();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 3:
			{
				DisplayAllStudent();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 4:
			{
				void Disp_Partcu_Stud();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 5:
			{
				Edit_Stud_Record();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 6:
			{
				DeleteStudRec();
				cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 7:
			{
			    CGPA_CalculatorB();
			    cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 8:
			{
			    CGPA_CalculatorC();
			    cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
				getch();
				break;
			}
			case 9:
			{
                system("CLS");
			    Programmers();
			    endl(cout);
			    cout<<"\t\t\tPress any Key To Return to Main Menu"<<endl;
			    getch();
			    break;
				//exit(0);
			}
			case 10:
			{
			    system("CLS");
			    GoodBye();
				exit(0);
			}
			default:
			{
				cout<<"Invalid Choice....Press Key For View the Main Menu";
				getch();
				system("CLS");
			}
		}

	}

void CreateStudentFile()//Function to Create Data File
{
    system("CLS");
	char ch='y';
	myfile.open("StudentFile.dat",ios::out| ios::out | ios::binary);
	while(ch=='y' || ch =='Y')
	{
	    //fileo.input();
		StudObj.input();
		myfile.write((char*)&StudObj, sizeof(StudObj));
		cout<<"\t\t\tDo You Want to Continue....(Yes-Y/NO-N)";
		cin>>ch;
	}
	myfile.close();
}

void AddAnotherStudent()//Function to Add New Record in Data File
{
	char ch='y';
	myfile.open("StudentFile.dat", ios::binary | ios::in |ios::out | ios::app);
	while(ch=='y' || ch =='Y')
	{
		StudObj.input();
		myfile.write((char*)&StudObj, sizeof(StudObj));
		cout<<"\t\t\tDo You Want to Continue.....(Yes-Y/No-N): ";
		cin>>ch;
	}
	myfile.close();
}

void DisplayAllStudent()//Function to Display All Record from Data File
{
	myfile.open("StudentFile.dat",ios::in| ios::out | ios::binary);
	if(!myfile)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
	    system("CLS");
		myfile.read((char*)&StudObj, sizeof(StudObj));
		while(!myfile.eof())
		{
			StudObj.show();
			cout<<"\t\t\tPress Any Key....For Next Record"<<endl;
			getch();
			myfile.read((char*)&StudObj, sizeof(StudObj));
		}
	}
	myfile.close();
}

void Disp_Partcu_Stud()//Function to view Particular Student In file
{
int number =0;
string name;
fstream dataFile;
dataFile.open("StudentFile.dat",ios::in | ios::binary);

//file fileobj //file name of my class
system("cls");
cout <<"\t\t\tPlease Enter The Name Your Want To Look: ";
cin >> name;

while(!dataFile.eof())
{
dataFile.seekg(byteNum(number),ios::beg);
dataFile.read(reinterpret_cast<char *>(&StudObj),sizeof(StudObj));

if(StudObj.getST() == name)
{
StudObj.show();
break;
}
else
{
cout <<"\t\t\tRecord still not found!"<<endl;
}
number +=1;
}

dataFile.close();
}//End of Displaying Particular Student

long byteNum(int recNum)//function itself
{
return sizeof(StudentInf) * recNum;
}

void Edit_Stud_Record()//Function to Modify Particular Record from Data File
{
	char n[80];
	cout<<"\t\t\tEnter Name You Want To Edit: ";
	//gets(n);
	cin >> n;
	myfile.open("StudentFile.dat",ios::in| ios::out|ios::binary);
	if(!myfile)
	{
		cout<<"\t\t\tFile not Found";
		exit(0);
	}
	else
	{
		myfile.read((char*)&StudObj, sizeof(StudObj));
		while(!myfile.eof())
		{
			if(strcmp(n,StudObj.getn())==0)
			{
				myfile.seekg(0,ios::cur);
				cout<<"\t\t\tEnter New Record.."<<endl;
				StudObj.input();
				myfile.seekp(myfile.tellg() - sizeof(StudObj));
				myfile.write((char*)&StudObj, sizeof(StudObj));
			}
			else
			{
				 cout<<"\t\t\tYou Want To Search Again..Press any Key"<<endl;
				 getch();
			}
			myfile.read((char*)&StudObj, sizeof(StudObj));
		}
	}
	myfile.close();
}

void DeleteStudRec()//Function to Delete Particular Record from Data File
{
	char n[80];
	cout<<"Enter Name that should be Deleted :";
	//gets(n);
	cin >>n;
	ofstream o;
	o.open("new.dat",ios::binary | ios::out);
	myfile.open("StudentFile.dat",ios::in| ios::out | ios::binary);
	if(!myfile)
	{
		cout<<"\t\t\tFile not Found";
		//exit(0);
	}
	else
	{
		myfile.read((char*)&StudObj, sizeof(StudObj));
		while(!myfile.eof())
		{
			if(strcmp(n,StudObj.getn())!=0)
			{
				o.write((char*)&StudObj, sizeof(StudObj));
				cout<<"\t\t\tStudent Information deleted completely In File:"<<endl;
			}
			else
			{
				 cout<<"\t\t\tPress Any Key....For Search Again"<<endl;
				 getch();
			}
			myfile.read((char*)&StudObj, sizeof(StudObj));
		}
	}
	o.close();
	myfile.close();
	remove("StudentFile.dat");
	rename("new.dat", "StudentFile.dat");
}

void GoodBye()//Function to say Good Bye When end Program
{
    cout<<"\n\n\n\n\n\n\n\n";
   string msg = "\t\t\tGOOD BYEEEE!\n";
   for(int i=0; i<msg.length(); i++){
      cout << msg[i] << "\a";
      Sleep(500);
      }
   //Sleep(500);
}//end of goodbye function

void SayJambo()//Function to say Jambo when Program begin
{
    cout<<"\n\n\n\n\n\n\n\n\n"<<endl;
   string msg = "\t\t\tJAMBO TO MULTIMEDIA UNIVERSITY";
   for(int i=0; i<msg.length(); i++){
      cout << msg[i] << "\a";
      Sleep(500);
   }
   Sleep(500);
}//end of goodbye function

void Programmers()//Displaying Programmers
{
            cout<< "\n\n";
            cout <<"\t\t-------------------------------------------"<< "\n\n";
            cout<<"\t\tNAMES OF PROGRAMMERS OF THIS PROJECT" << "\n\n";

            cout << "\t\t [1] AMRI SHABANI MWARUKA    \t1141123609" <<endl;
            cout << "\t\t [2] ISMAIL MOHAMED ALLY     \t114*******" << "\n\n";
            cout << "\t\t-------------------------------------------";
            cout<< "\n\n";
            endl(cout);
        }

void CGPA_CalculatorC()//CGPA Calculator for Senior Students
{
            system("CLS");
             //Setting two decimal places
             cout.setf(ios::fixed);
             cout.setf(ios::showpoint);
             cout.precision(2);

             double sum = 0;
             double previous_cgpa;
             int _size;
             vector<float> subject_marks;

             cout << "\t\tEnter Your Last Semester CGPA: ";
             cin >> previous_cgpa;
             cout <<endl;
             cout << "\t\tHow Many Subject You Want To Calculate CGPA ?: ";
             cin >>_size;
             endl(cout);
             for(int i=0;i<_size;i++)
             {
                    float input;
                    cout << "\t\tEnter Your Subject Marks: ";
                    cin >> input;
                    subject_marks.push_back(input);
                    //subject_marks.push_back(i);
                    sum += subject_marks[i];
             }
             /*float Points[]{4.0, 4.0, 3.67, 3.33, 3.0, 2.67, 2.33, 2.0,
                             1.67, 1.33, 1.0, 0.0};*/

             /*string Grades[]{"A", "A", "A-", "B+", "B", "B-", "C+", "C",
                             "C-", "D+", "D", "F"};*/

             float current_cgpa = sum / _size;
             //float current_cgpa;
             cout << endl;
             if(current_cgpa >= 90 && current_cgpa<=100){current_cgpa = 4.0;}
             else if (current_cgpa >=80 && current_cgpa<=89){current_cgpa = 4.0;}
             else if (current_cgpa >=75 && current_cgpa<=79){current_cgpa = 3.67;}
             else if(current_cgpa >=70 && current_cgpa<=74){current_cgpa = 3.33;}
             else if(current_cgpa >=65 && current_cgpa<=69){current_cgpa = 3.0;}
             else if(current_cgpa >=60 && current_cgpa<=64){current_cgpa = 2.67;}
             else if(current_cgpa >=55 && current_cgpa<=59){current_cgpa = 2.33;}
             else if(current_cgpa >=50 && current_cgpa<=54){current_cgpa = 2.0;}
             else if(current_cgpa >=47 && current_cgpa<=49){current_cgpa = 1.67;}
             else if(current_cgpa >=44 && current_cgpa<=46){current_cgpa = 1.33;}
             else if(current_cgpa >=40 && current_cgpa<=43){current_cgpa = 1.0;}
             else{current_cgpa = 0;}

             cout <<endl;
             cout<<"\t\t\t------------------------"<<endl;
             for(unsigned int i=0;i<_size;i++)
             {
                    cout << "\t\t\tYour Subject #" <<(i+1) <<" "<< subject_marks[i] <<"%"<<endl;
             }
             endl(cout);
             cout<<"\t\t\t------------------------"<<endl;
             float final_cgpa = (current_cgpa + previous_cgpa)/2;
             if(final_cgpa>(3.0))
             {
               cout << "\t\t\tCOGRATULATIONS YOU HAVE GOT GOOD \n"
                    << "\t\t\tCGPA THIS SEMESTER:\n"
                    << "\t\t\tAND YOUR CGPA IS: " << final_cgpa << endl;
             }
             else{
             cout << "\t\t\tSORRY YOUR CURRENT CGPA IS BELOW 3, \n"
                  << "\t\t\tKEEP TRYING TO IMPROVE FOR NEXT SEME: \n"
                  << "\t\t\tYOUR CGPA IS: " << final_cgpa << endl;
                 }

                 endl(cout);
     }//end of cgpa calculator

void CGPA_CalculatorB()//CGPA Calculator for New Students
{

      system("CLS");
             //Setting two decimal places
             cout.setf(ios::fixed);
             cout.setf(ios::showpoint);
             cout.precision(2);

             double sum = 0;
             //double previous_cgpa;
             int _size;
             vector<float> subject_marks;

             //cout << "\t\tEnter Your Last Semester CGPA: ";
             //cin >> previous_cgpa;
             cout <<endl;
             cout << "\t\tHow Many Subject You Want To Calculate CGPA ?: ";
             cin >>_size;
             endl(cout);
             for(int i=0;i<_size;i++)
             {
                    float input;
                    cout << "\t\tEnter Your Subjects Marks: ";
                    cin >> input;
                    subject_marks.push_back(input);
                    sum += subject_marks[i];
             }
             /*float Points[]{4.0, 4.0, 3.67, 3.33, 3.0, 2.67, 2.33, 2.0,
                             1.67, 1.33, 1.0, 0.0};*/

             /*string Grades[]{"A", "A", "A-", "B+", "B", "B-", "C+", "C",
                             "C-", "D+", "D", "F"};*/

             float current_cgpa = sum / _size;
             //float current_cgpa;
             cout << endl;
             if(current_cgpa >= 90 && current_cgpa<=100){current_cgpa = 4.0;}
             else if (current_cgpa >=80 && current_cgpa<=89){current_cgpa = 4.0;}
             else if (current_cgpa >=75 && current_cgpa<=79){current_cgpa = 3.67;}
             else if(current_cgpa >=70 && current_cgpa<=74){current_cgpa = 3.33;}
             else if(current_cgpa >=65 && current_cgpa<=69){current_cgpa = 3.0;}
             else if(current_cgpa >=60 && current_cgpa<=64){current_cgpa = 2.67;}
             else if(current_cgpa >=55 && current_cgpa<=59){current_cgpa = 2.33;}
             else if(current_cgpa >=50 && current_cgpa<=54){current_cgpa = 2.0;}
             else if(current_cgpa >=47 && current_cgpa<=49){current_cgpa = 1.67;}
             else if(current_cgpa >=44 && current_cgpa<=46){current_cgpa = 1.33;}
             else if(current_cgpa >=40 && current_cgpa<=43){current_cgpa = 1.0;}
             else{current_cgpa = 0;}

             cout <<endl;
             cout<<"\t\t\t------------------------"<<endl;
             for(unsigned int i=0;i<_size;i++)
             {
                    cout << "\t\t\tYour Subject #" <<(i+1) <<" "<< subject_marks[i]<<"%"<<endl;
             }
             endl(cout);
             cout<<"\t\t\t------------------------"<<endl;
             float final_cgpa = current_cgpa;
             if(final_cgpa>(3.0))
             {
               cout << "\t\t\tCOGRATULATIONS YOU HAVE GOT GOOD \n"
                    << "\t\t\tCGPA THIS SEMESTER:\n"
                    << "\t\t\tAND YOUR CGPA IS: " << final_cgpa << endl;
             }
             else{
             cout << "\t\t\tSORRY YOUR CURRENT CGPA IS BELOW 3, \n"
                  << "\t\t\tKEEP TRYING TO IMPROVE FOR NEXT SEME: \n"
                  << "\t\t\tYOUR CGPA IS: " << final_cgpa << endl;
                 }

                 endl(cout);
}

void Time()//Function TO show Time
{
    time_t  ptr;
       time ( &ptr );
       endl(cout);
        cout<<"\t\t\t" <<ctime (&ptr);
     }
//***********END OF PROGRAM************************
