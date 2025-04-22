#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

int main() 
{
	int thisyear = 2025,size;
	cout<<endl<<"Enter how many employees you want to add: ";
	cin>>size;
	
	employee* e=new employee[size];
	
	for(int i=0;i<size;i++)
	{
		string sur, dep;
		int year;
		float salary;
		cout<<"Employee number "<<i+1<< endl;
		cout<<"Enter surname:";
		cin>>sur;
		e[i].setsurname(sur);
		cout<<"Enter department:";
		cin>>dep;
		e[i].setdepartment(dep);
		cout<<"Enter year:";
		cin>>year;
		e[i].setyear(year);
		cout<<"Enter salary:";
		cin>>salary;
		e[i].setsalary(salary);
		e[i].calculatebonus(thisyear);
	}
	cout<<endl<<"List of employees:"<<endl;
	for (int i = 0;i < size;i++) 
	{
		cout<<e[i].getsurname()<<", Department: "<<e[i].getdepartment()<<", Salary: "<< e[i].getsalary()<< ", Experience: "<< e[i].getexperience(thisyear)<< ", Bonus: "<<e[i].getbonus()<<endl;
	}

	float averagexperience = calculatexperience(e, size, thisyear);
	cout<<"Average experience: "<<averagexperience<<endl;

	sortemploys(e, size, thisyear);
		cout<<"Sorted by experience: ";
		cout<<endl;
		for (int i = 0;i < size;i++) 
		{
			cout<<e[i].getsurname()<<", Department: "<<e[i].getdepartment()<<", Salary: "<<e[i].getsalary()<< ", Experience: "<<e[i].getexperience(thisyear)<<", Bonus: "<<e[i].getbonus()<<endl;
		}
		delete[] e;
	
	return 0;
}
