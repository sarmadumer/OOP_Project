#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//base class
class DOB{
	int date;
	int month;
	int year;
	public:
		//defualt constructor
		DOB(){
			date=0;
			month=0;
			year=0;
		}
		//setter
		void setdate(){
		cout<<"Enter the date :";
		cin>>date;
		}
		//setter
		void setmonth(){
	    cout<<"Enter the month :";
			cin>>month;
		}
		//setter
		void setyear(){
		cout<<"Enter the year :";
			cin>>year;
		}
		int getdate(){
			return date;
			}
        int getmonth(){
        	return month;
		}
		int getyear(){
			return year;
		}
	 void write_DOB_to_file(ofstream& obj1 ){
			obj1<<"Date-of-birth : "<<date<<"/"<<month<<"/"<<year<<endl;
		}
		~DOB(){}
};
//Base class
class studentinfo{
	string name;
	string father_name;
	string CNIC;
	int age;
	int choice;
	string Gender;
	string address;
	public:
		studentinfo(){
			name="";
			father_name="";
			Gender="";
			CNIC="";
			age=0;
			choice=0;
			address="";
		}
		void INFO(){
			cout<<"Name :";
			cin.ignore();
			getline(cin,name);
			cout<<"Father name :";
			getline(cin,father_name);
			//loop start
			while(true){
			
			cout<<"Select Gender:"<<endl<<"01) Male"<<endl<<"02) Female"<<endl<<"03) other"<<endl;
			cin>>choice;
			if(choice==1){
				Gender="Male";
				break;
			}
			else if(choice==2){
				Gender="Female";
				break;
			}
			else if(choice==3){
				Gender="other";
				break;
			}
			else if(choice!=1&&choice!=2&&choice!=3){
				cout<<"Select the correct option"<<endl<<"Thank you"<<endl;
				
			}
			}//loop end
			
			cout<<"Enter student CNIC : ";
			cin>>CNIC;
			cout<<"Enter studnt Age   : ";
			cin>>age;
			cout<<"Enter the address  : ";
			cin.ignore();
			getline(cin,address);
		}
		void displayPersonalInfo(){
			cout<<"Name        :  "<<name<<endl;
			cout<<"Father name :  "<<father_name<<endl;
			cout<<"Gender      :  "<<Gender<<endl;
			cout<<"CNIC        :  "<<CNIC<<endl;
			cout<<"Age         :  "<<age<<endl;
            cout<<"Address     :  "<<address<<endl;		
		}
		void write_personalInfo_to_file(ofstream& obj1 ){
		
	        obj1<<"Name        :  "<<name<<endl;
			obj1<<"Father name :  "<<father_name<<endl;
			obj1<<"Gender      :  "<<Gender<<endl;
			obj1<<"CNIC        :  "<<CNIC<<endl;
			obj1<<"Age         :  "<<age<<endl;
			obj1<<"Address     :  "<<address<<endl;
		//studentinfo::write_to_file(obj1 );
	}
		
		~studentinfo(){}
};
//Drived class 
class student:public DOB,public studentinfo {
	 
	float marks;
	string email;
	int total_Marks;
	float percentage;
    int test_marks;
	public:
		student(){//defualt constructor
			marks=0;
			email="";
			total_Marks=0;
			percentage=0.0;
			test_marks=0;
			
		}
		
		
		void seteducationInfo(){
			cout<<"Enter entry test marks : ";
			cin>>test_marks;
			cout<<"Obtained marks in previous exam e.g(FA/FSC/A-LEVEL):"<<endl;
			cin>>marks;
			cout<<"Total marks in previous exam e.g(FA/FSC/A-LEVEL)   :"<<endl;
			cin>>total_Marks;
			percentage=marks/total_Marks*100;
		    cout<<"Student Email :"<<endl;
			cin>>email;	
				
		}
		float getpercentage(){
			return percentage;
		}
	
	void 	displayenducationInfo(){
			cout<<"Entry test          : "<<test_marks<<endl;
			cout<<"Previous exam marks : "<<marks<<"/"<<total_Marks<<endl;
			cout<<"Percentage          : "<<percentage<<endl;
            cout<<"Student Email       : "<<email<<endl;
	}
	void write_educationInfo(ofstream& obj1 ){
		//student::write_to_file(obj1); 
		obj1<<"Test marks : "<<test_marks<<endl;
		obj1<<"Marks      : "<<marks<<endl;
		obj1<<"percentage : "<<percentage<<endl;
		obj1<<"Email      : "<<email<<endl;
	}
	~student(){}
};


//Program start execution
int main(){
		
	int option,totalstudents,size=1;
	
	
	student *obj;
	obj=new student[20000];
    int choice;	
	//loop start
	while(true){
	cout<<"\t\t\t\t\t:::Welcome to fast university:::"<<endl;
	cout<<"Menu:"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"01) New admission"<<endl<<"02) Check studentinfo"<<endl<<"03) Update studentInfo"<<endl<<"04) Display all studentInfo"<<endl<<"05) Admission Cancel"<<endl<<"06) Exit"<<endl;
    cout<<"Select a option: "<<endl;
    cin>>option;
    cout<<endl;
    system("cls");
    
  //condition #  1
  // New admission
    if(option==1){
    	ofstream obj1;
    	obj1.open("Student.txt",ios::out| ios::app );
		char Option;
		cout<<"Enter the personal information of student : "<<size<<endl;
		obj[size].INFO();
		cout<<"Enter the date-of-birth : "<<endl;
		obj[size].setdate();
		obj[size].setmonth();
		obj[size].setyear();
		cout<<"Enter the acadamic information : "<<endl;
		cout<<"You have done FA/FSC/A-level (Y/N)"<<endl;
		cin>>Option;
		if(Option=='y'||Option=='Y'){
		
		obj[size].seteducationInfo();
		 if(obj[size].getpercentage()>=50){
			
			cout<<"Your admission process is done:"<<endl;
			//file handling
			if(obj1.is_open()){
				obj[size].write_personalInfo_to_file(obj1 );
				obj[size].write_DOB_to_file(obj1 );
				obj[size].write_educationInfo(obj1 );
				
			}
			obj1.close();
			size++;
			system("pause");
			system("cls");
			}
			else if(obj[size].getpercentage()<50){
				cout<<"::: You are not eligible for admission :::"<<endl;
			}
	
    }
	
    else{
    	cout<<endl;
    	cout<<"::: You are not eligible for admission :::"<<endl<<"FA/FSC/A-LEVEL is compulsory"<<endl;
	}
    
}

//condition # 2
//Check studentinfo
else if(option==2){
	
	
	cout<<"Enter the student no to check data: ";
	cin>>option;
	if(option>=size){
		
		cout<<"This No of student is not available :"<<endl;
	}

	else {
	
	for(int i=option;i<=option;i++){
		cout<<"Personal information of student : "<<i<<endl;
		obj[i].displayPersonalInfo();
		cout<<"Date-of-birth : ";
		cout<<obj[i].getdate()<<"/"<<obj[i].getmonth()<<"/"<<obj[i].getyear()<<endl;
		cout<<"Acadamic information : "<<endl;
		obj[i].displayenducationInfo();
	}
}
system("pause");
system("cls");
}




//condition # 3
//Update studentInfo
else if(option==3){

	cout<<"Enter the student no to update information:";
	cin>>option;
    if(option>size){
    	cout<<"This no of student is not available : "<<endl;
	}
	else {
	
	cout<<"01) Update personal information :"<<endl<<"02) Update date-of-birth :"<<endl<<"03) Update Acadamic information"<<endl;
    cin>>choice;
    if(choice==1){
    	for(int i=option;i<=option;i++){
    		cout<<"Update personal information of student : "<<i<<endl;
		    obj[i].INFO();
		}
	}
	else if(choice==2){
		for(int i=option;i<=option;i++){
		obj[i].setdate();
		obj[i].setmonth();
		obj[i].setyear();
		}
	}
	else if(choice==3){
		for(int i=option;i<=option;i++){
		cout<<"Update acadamic information : "<<endl;
		obj[i].seteducationInfo();
		}
	}
	
}	
}


//condition # 4
else if(option==4){
	
	    if(size>1){
		for(int i=1;i<size;i++){
			
		cout<<"Personal information of student : "<<i<<endl;
		obj[i].displayPersonalInfo();
		cout<<"Date-of-birth : "<<endl;
		cout<<obj[i].getdate()<<"/"<<obj[i].getmonth()<<"/"<<obj[i].getyear()<<endl;
		cout<<"Acadamic information : "<<endl;
		obj[i].displayenducationInfo();
}}
else{
	cout<<"First, the student must be admitted to the university."<<endl<<"So far no student has been admitted to the university."<<endl;
    cout<<endl;
}

system("pause");
	system("cls");
}

//condition # 5
else if(option==5){
student *obj2;
	obj2=new student[size];

cout<<"Enter the student no : ";
cin>>option;
if(option<=size&&option>0){
		
int j=1;
for(int i=1;i<size;i++){
	if(i==option){
		continue;
	}
	else{
		obj2[j++]=obj[i];
	}
}


delete[]obj;
size--;
obj=obj2;
}
else {
	cout<<"student is not available."<<endl;
}
}
else if(option==6){
		system("cls");
	cout<<"Thank you see you next time : "<<endl;
	cout<<"Have a nice day :"<<endl<<endl<<"--------------------"<<endl;
    break;
}

//condition # 6
else if(option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6){
	cout<<"Select the correct option :"<<endl<<"Select Again."<<endl<<"--------------------"<<endl<<endl;
	
}

}//loop end
delete[] obj;
}//the end