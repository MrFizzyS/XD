#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

int main() 
{
	int year = 2025, size;
	employee e1;
	e1.setsurname("Katren");
	e1.setdepartment("Shop");
	e1.setyear(2010);
	e1.setsalary(7500);
	e1.calculatebonus(year);

	employee e2("Anton", "Office", 2008, 9000);
	e2.calculatebonus(year);

	cout<<"Employee 1: "<<e1.getsurname()<<", Department: "<<e1.getdepartment()<<", Experience: "<<e1.getexperience(year)<<", Salary: "<<e1.getsalary()<<", Bonus: "<<e1.getbonus();
	cout<<endl;
	cout<<"Employee 2: "<<e2.getsurname()<<", Department: "<<e2.getdepartment()<<", Experience: "<<e2.getexperience(year)<<", Salary: "<<e2.getsalary()<<", Bonus: "<< e2.getbonus();
	
	cout<<endl<<"Input n: ";
	cin>>size;
	
	employee* e=new employee[size];
	
	for(int i=0;i<size;i++)
	{
		string sur, dep;
		int year;
		float salary;
		cout<<"Employee number "<<i+1<< endl;
		cout<<"Input surname:";
		cin>>sur;
		e[i].setsurname(sur);
		cout<<"Input department:";
		cin>>dep;
		e[i].setdepartment(dep);
		cout<<"Input year:";
		cin>>year;
		e[i].setyear(year);
		cout<<"Input salary:";
		cin>>salary;
		e[i].setsalary(salary);
		e[i].calculatebonus(2025);
	}
	cout<<endl<<"List of employees:"<<endl;
	for (int i = 0;i < size;i++) 
	{
		cout<<e[i].getsurname()<<", Department: "<<e[i].getdepartment()<<", Salary: "<< e[i].getsalary()<< ", Experience: "<< e[i].getexperience(year)<< ", Bonus: "<<e[i].getbonus()<<endl;
	}

	float averagexperience = calculatexperience(e, size, 2025);
	cout<<"Average experience: "<<averagexperience<<endl;

	sortemploys(e, size, 2025);
		cout<<"Sorted by experience: ";
		cout<<endl;
		for (int i = 0;i < size;i++) 
		{
			cout<<e[i].getsurname()<<", Department: "<<e[i].getdepartment()<<", Salary: "<<e[i].getsalary()<< ", Experience: "<<e[i].getexperience(year)<<", Bonus: "<<e[i].getbonus()<<endl;
		}
		delete[] e;
	
	return 0;
}
