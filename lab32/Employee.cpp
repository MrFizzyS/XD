#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

employee::employee() 
{
	surname = "";
	department = "";
	hireyear = 2000;
	salary = 0.0;
	bonus = 0.0;
}
employee::employee(string sur, string dep, int year, float sal) 
{
	surname = sur;
	department = dep;
	hireyear = year;
	salary = sal;
	bonus = 0.0;
}

string employee::getsurname() 
{
	return surname;
}

string employee::getdepartment() 
{
	return department;
}

int employee::getyear() 
{
	return hireyear;
}

float employee::getsalary() 
{
	return salary;
}

float employee::getbonus() 
{
	return bonus;
}

void employee::setsurname(string sur) 
{
	surname = sur;
}
void employee::setdepartment(string dep) 
{
	department = dep;
}
void employee::setyear(int year) 
{
	hireyear = year;
}
void employee::setsalary(float sal) 
{
	salary = sal;
}

void employee::calculatebonus(int thisyear) 
{
	int experience;
	experience = thisyear - hireyear;
	if (experience < 10)
		bonus = salary * 0.10;
	else if (experience <= 20)
		bonus = salary * 0.25;
	else
		bonus = salary * 0.40;
}

int employee::getexperience(int thisyear) 
{
	return thisyear-hireyear;
}

void sortemploys(employee a[], int size, int thisyear) 
{
	for (int i=0;i<size;i++) 
	{
		for (int j=0;j<size;j++) 
		{
			if(a[i].getexperience(thisyear)>a[j].getexperience(thisyear))
				swap(a[i],a[j]);
		}
	}
}

float calculatexperience(employee a[], int size, int thisyear) {
	int sum = 0;
	for (int i = 0;i < size;i++)
		sum += a[i].getexperience(thisyear);

	return (double)sum / size;
}
